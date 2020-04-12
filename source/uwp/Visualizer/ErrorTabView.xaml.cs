using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

namespace AdaptiveCardVisualizer
{
    public sealed partial class ErrorTabView : UserControl
    {
        public ErrorTabView()
        {
            this.InitializeComponent();
            this.Loaded += ErrorTabView_Loaded;
        }

        private void ErrorTabView_Loaded(object sender, RoutedEventArgs e)
        {
            Focus(FocusState.Keyboard);
        }
    }
}
