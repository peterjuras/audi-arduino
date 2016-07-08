using audino_control.ViewModels;
using System;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace audino_control
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            InitializeComponent();
        }

        private MainViewModel ViewModel { get { return DataContext as MainViewModel; } }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            if (DataContext == null)
            {
                MainViewModel viewModel = new MainViewModel();
                viewModel.Initialize();
                RegisterToEvents(viewModel);
                DataContext = viewModel;
            }

            ApplicationView.GetForCurrentView().TryEnterFullScreenMode();
        }

        protected override void OnNavigatingFrom(NavigatingCancelEventArgs e)
        {
            base.OnNavigatingFrom(e);

            UnregisterFromEvents(DataContext as MainViewModel);
        }

        private void RegisterToEvents(MainViewModel viewModel)
        {
            if (viewModel == null)
            {
                return;
            }
            viewModel.PlayVideo += OnViewModelPlayView;
        }

        private void UnregisterFromEvents(MainViewModel viewModel)
        {
            if (viewModel == null)
            {
                return;
            }

            viewModel.PlayVideo -= OnViewModelPlayView;
        }

        private void OnViewModelPlayView(object sender, EventArgs e)
        {
            VideoPlayer.Position = TimeSpan.FromSeconds(0);
            VideoPlayer.Play();
            ApplicationView.GetForCurrentView().TryEnterFullScreenMode();
        }

        private void VideoPlayer_CurrentStateChanged(object sender, Windows.UI.Xaml.RoutedEventArgs e)
        {
            ViewModel.OnVideoPlayerStateChanged(VideoPlayer.CurrentState);
        }
    }
}
