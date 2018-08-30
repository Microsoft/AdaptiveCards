﻿using System;
using System.Collections.Generic;
using System.Globalization;
using Newtonsoft.Json;

namespace AdaptiveCards
{
    public class StringSizeWithUnitConverter : JsonConverter, ILogWarnings
    {
        public List<AdaptiveWarning> Warnings { get; set; } = new List<AdaptiveWarning>();

        readonly JsonSerializer defaultSerializer = new JsonSerializer();

        public override bool CanConvert(Type objectType)
        {
            // Only use this converter for string types that match our format
            return (objectType == typeof(string));
        }

        public override object ReadJson(JsonReader reader, Type objectType, object existingValue, JsonSerializer serializer)
        {
            if (reader.TokenType == JsonToken.String)
            {
                var dimension = defaultSerializer.Deserialize(reader) as string;
                if (dimension.Length < 3)
                {
                    Warnings.Add(new AdaptiveWarning(-1,
                        $"The Value \"{reader.Value}\" for field \"{reader.Path}\" was not specified as a proper dimension in the format (\\d+(.\\d+)?px), it will be ignored."));
                    return 0U;
                }

                var unit = dimension.Substring(dimension.Length - 2);
                if (String.Compare(unit, "px", false) != 0)
                {
                    Warnings.Add(new AdaptiveWarning(-1,
                        $"The Value \"{unit}\" was not specified as a proper unit(px), it will be ignored."));
                    return 0U;
                }

                if (double.TryParse(dimension.Substring(0, dimension.Length - 2), NumberStyles.AllowDecimalPoint ,null, out double dimensionInPix))
                {
                    // we need check this because AllowDecimalPoint flags allows TryParse to accept number in .\d+ format
                    if(dimension[0] == '.')
                    {
                        Warnings.Add(new AdaptiveWarning(-1,
                            $"The Value \"{reader.Value}\" for field \"{reader.Path}\" was not specified as a proper dimension in the format (\\d+(.\\d+)?px), it will be ignored."));
                    }
                    return (uint) dimensionInPix;
                }
                else
                {
                    Warnings.Add(new AdaptiveWarning(-1,
                        $"The Value \"{reader.Value}\" for field \"{reader.Path}\" was not specified as a proper dimension in the format (\\d+(.\\d+)?px), it will be ignored."));
                    return 0U;
                }
            }

            Warnings.Add(new AdaptiveWarning(-1, $"The Value \"{reader.Value}\" for field \"{reader.Path}\" of type \"{reader.TokenType}\" was not proper type, it will be ignored."));
            return 0U;
        }

        public override bool CanWrite { get { return false; } }

        public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
        {
            throw new NotImplementedException();
            //writer.WriteValue(value.ToString());
        }              
    }
}
