﻿using AdaptiveCards.XamlCardRenderer;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Storage;
using XamlCardVisualizer.Helpers;

namespace XamlCardVisualizer.ViewModel
{
    public class HostConfigEditorViewModel : GenericDocumentViewModel
    {
        private HostConfigEditorViewModel(MainPageViewModel mainPageViewModel) : base(mainPageViewModel) { }

        public event EventHandler<AdaptiveHostConfig> HostConfigChanged;

        public AdaptiveHostConfig HostConfig { get; private set; }

        protected override void LoadPayload(string payload)
        {
            try
            {
                HostConfig = AdaptiveHostConfig.FromJsonString(payload);

                HostConfigChanged?.Invoke(this, HostConfig);
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.ToString());
                SetSingleError(new ErrorViewModel()
                {
                    Message = "Invalid Host Config payload",
                    Type = ErrorViewModelType.ErrorButRenderAllowed
                });
            }
        }

        public static async Task<HostConfigEditorViewModel> LoadAsync(MainPageViewModel mainPageViewModel)
        {
            try
            {
                StorageFile file = await StorageFile.GetFileFromApplicationUriAsync(new Uri("ms-appx:///HostConfigs/DefaultHostConfig.json"));
                string text = await FileIO.ReadTextAsync(file);

                return new HostConfigEditorViewModel(mainPageViewModel)
                {
                    Payload = text
                };
            }
            catch
            {
                return new HostConfigEditorViewModel(mainPageViewModel);
            }
        }
    }
}
