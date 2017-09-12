﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using XamlCardVisualizer.Helpers;
using XamlCardVisualizer.ViewModel;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

namespace XamlCardVisualizer
{
    public sealed partial class DocumentView : UserControl
    {
        public DocumentViewModel ViewModel
        {
            get { return DataContext as DocumentViewModel; }
        }

        public DocumentView()
        {
            this.InitializeComponent();
        }
    }
}
