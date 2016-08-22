using audino_control.Util;
using System.ComponentModel;
using Microsoft.Maker.Serial;
using Microsoft.Maker.RemoteWiring;
using System.Diagnostics;
using Microsoft.Maker.Firmata;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Runtime.CompilerServices;
using System;
using Windows.UI.Xaml.Media;

namespace audino_control.ViewModels
{
    public class MainViewModel : INotifyPropertyChanged
    {
        public DelegateCommand SendCommand { get; private set; }
        public DelegateCommand StartVideoDelegateCommand { get; private set; }
        public DelegateCommand ConnectCommand { get; private set; }
        public DelegateCommand DisconnectCommand { get; private set; }

        public bool ArduinoAvailable
        {
            get
            {
                return _arduinoAvailable;
            }
            private set
            {
                _arduinoAvailable = value;
                SendCommand.RaiseCanExecuteChanged();
                StartVideoDelegateCommand.RaiseCanExecuteChanged();
                ConnectCommand.RaiseCanExecuteChanged();
                DisconnectCommand.RaiseCanExecuteChanged();
            }
        }

        private UsbSerial _connection;
        private RemoteDevice _arduino;
        private UwpFirmata _firmata;
        private bool _arduinoAvailable;

        // Mega
        private const string USB_VID = "VID_2A03";
        private const string USB_PID = "PID_0042";

        // Uno
        // private const string USB_VID = "VID_2341";
        // private const string USB_PID = "PID_0043";

        private const byte DECISION_MODE_COMMAND = 0xF8;
        private const byte AMBIENT_MODE_COMMAND = 0xF9;
        private const byte START_VIDEO_COMMAND = 0xFB;

        // private const string VIDEO_FILENAME = "AudiPreseVideo2.mov";
        private const string VIDEO_FILENAME = "AudiFinalPresentationVideo.mp4";

        public byte AmbientMode
        {
            get
            {
                return AMBIENT_MODE_COMMAND;
            }
        }

        public byte DecisionMode
        {
            get
            {
                return DECISION_MODE_COMMAND;
            }
        }

        public byte StartVideo
        {
            get
            {
                return START_VIDEO_COMMAND;
            }
        }

        private Uri _video;
        public Uri Video
        {
            get
            {
                return _video;
            }
            set
            {
                _video = value;
                NotifyPropertyChanged();
            }
        }

        private bool _videoVisible;
        public bool VideoVisible
        {
            get
            {
                return _videoVisible;
            }
            set
            {
                _videoVisible = value;
                NotifyPropertyChanged();
            }
        }

        public MainViewModel()
        {
            SendCommand = new DelegateCommand(SendCommandExecute, SendCommandCanExecute);
            StartVideoDelegateCommand = new DelegateCommand(StartVideoCommandExecute, SendCommandCanExecute);
            ConnectCommand = new DelegateCommand(ConnectCommandExecute, ConnectCommandCanExecute);
            DisconnectCommand = new DelegateCommand(DisconnectCommandExecute, DisconnectCommandCanExecute);
        }

        private bool DisconnectCommandCanExecute(object arg)
        {
            return ArduinoAvailable;
        }

        private void DisconnectCommandExecute(object obj)
        {
            _firmata.finish();
            _connection.end();
        }

        private bool ConnectCommandCanExecute(object arg)
        {
            return !ArduinoAvailable;
        }

        private void ConnectCommandExecute(object obj)
        {
            _firmata.begin(_connection);
            _connection.begin(57600, SerialConfig.SERIAL_8N1);
        }

        public void Initialize()
        {
            _connection = new UsbSerial(USB_VID, USB_PID);
            _firmata = new UwpFirmata();
            _arduino = new RemoteDevice(_firmata);

            _connection.ConnectionEstablished += ArduinoConnectionEstablished;
            _connection.ConnectionFailed += ArduinoConnectionFailed;
            _connection.ConnectionLost += ArduinoConnectionLost;
        }

        private void ArduinoConnectionLost(string message)
        {
            Debug.WriteLine("Connection Lost: " + message);
            ArduinoAvailable = false;
        }

        private void ArduinoConnectionFailed(string message)
        {
            Debug.WriteLine("Connection Failed: " + message);
            ArduinoAvailable = false;
        }

        private void ArduinoConnectionEstablished()
        {
            Debug.WriteLine("Connection Established");
            ArduinoAvailable = true;
        }

        private bool SendCommandCanExecute(object arg)
        {
            return ArduinoAvailable && arg is byte;
        }

        private void SendCommandExecute(object obj)
        {
            _firmata.sendSysex((byte)obj, new byte[0].AsBuffer());
        }

        private void StartVideoCommandExecute(object obj)
        {
            VideoVisible = true;
            PlayVideo?.Invoke(this, EventArgs.Empty);
            SendCommandExecute(obj);
        }

        public void OnVideoPlayerStateChanged(MediaElementState state)
        {
            if (state == MediaElementState.Closed ||
                state == MediaElementState.Paused ||
                state == MediaElementState.Stopped)
            {
                StopVideo();
            }
        }

        public void StopVideo()
        {
            VideoVisible = false;
            // TODO: Stop Video in Arduino?
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public event EventHandler PlayVideo;

        private void NotifyPropertyChanged([CallerMemberName]string property = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }
    }
}
