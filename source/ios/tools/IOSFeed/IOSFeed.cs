using System;
using System.IO;
using System.Threading.Tasks;
using Microsoft.Azure.Storage;
using Microsoft.Azure.Storage.Blob;

namespace IOSFeedNS
{
    class IOSFeed
    {
        public static void Main()
        {
            // Run the examples asynchronously, wait for the results before proceeding
            ProcessAsync().GetAwaiter().GetResult();
        }

        private static async Task ProcessAsync()
        {
            string storageConnectionString;

            var connectionStringPath = "source/ios/tools/IOSFeed/ConnectString.txt";
            using (StreamReader sr = File.OpenText(connectionStringPath))
            {
                storageConnectionString = sr.ReadToEnd();
            }

            // Check whether the connection string can be parsed.
            CloudStorageAccount storageAccount;
            if (CloudStorageAccount.TryParse(storageConnectionString, out storageAccount))
            {
                // If the connection string is valid, proceed with operations against Blob
                // storage here.
                // Create the CloudBlobClient that represents the 
                // Blob storage endpoint for the storage account.
                CloudBlobClient cloudBlobClient = storageAccount.CreateCloudBlobClient();

                var containerId = "adaptivecardsiosblobs";
                CloudBlobContainer cloudBlobContainer =
                    cloudBlobClient.GetContainerReference(containerId);
                await cloudBlobContainer.CreateIfNotExistsAsync();

                // Set the permissions so the blobs are public.
                BlobContainerPermissions permissions = new BlobContainerPermissions
                {
                    PublicAccess = BlobContainerPublicAccessType.Blob
                };

                await cloudBlobContainer.SetPermissionsAsync(permissions);

                var localPath = "source/ios/AdaptiveCards/AdaptiveCards";
                var localFileName = "AdaptiveCards.framework";
                var option = ".zip";
                var sourceFile = Path.Combine(localPath, localFileName + option);
                var blobGuid = Guid.NewGuid().ToString();
                var cloudFileName = localFileName + blobGuid + option;

                CloudBlockBlob cloudBlockBlob = cloudBlobContainer.GetBlockBlobReference(cloudFileName);

                await cloudBlockBlob.UploadFromFileAsync(sourceFile);

                BlobContinuationToken blobContinuationToken = null;
                do
                {
                    var results = await cloudBlobContainer.ListBlobsSegmentedAsync(null, blobContinuationToken);
                    // Get the value of the continuation token returned by the listing call.
                    blobContinuationToken = results.ContinuationToken;
                    foreach (IListBlobItem item in results.Results)
                    {
                        var uriString = item.Uri.ToString();
                        if (uriString.Contains(blobGuid))
                        {
                            UpdatePodSpec(uriString);
                        }
                    }
                } while (blobContinuationToken != null);
            }
            else
            {
                Console.WriteLine("missing valid connection string");
            }
        }

        private static void UpdatePodSpec(string uri)
        {
            var localPath = "./source/ios/tools/";
            var targetPath = "./source/ios/";
            var localFileName = "AdaptiveCards.podspec";
            var sourceFile = Path.Combine(localPath, localFileName);
            var targetFile = Path.Combine(targetPath, localFileName);
            // Open the stream and read it back.
            using (StreamReader sr = File.OpenText(sourceFile))
            {
                string s = "";
                string output = "";
                while ((s = sr.ReadLine()) != null)
                {
                    if (s.Length != 0)
                    {
                        var splits = s.Split('=');
                        if (splits.Length > 0)
                        {
                            if (splits[0].Contains("spec.source"))
                            {
                                s = splits[0] + "= { :http => " + "'" + uri + "' }";
                            }
                            else if (splits[0].Contains("spec.version"))
                            {
                                var adaptiveVersion = Environment.GetEnvironmentVariable("ADCVERSION");
                                s = splits[0] + "= '" + adaptiveVersion + "'" ;
                            }
                        }

                        output += (s + "\n");
                    } else
                    {
                        output += "\n";
                    }
                }

                File.WriteAllText(targetFile, output);
            }
        }
    }
}
