using audino_control.Util;
using System.ComponentModel;
using System.Windows.Input;
using System;
using Microsoft.Maker.Serial;
using Microsoft.Maker.RemoteWiring;
using System.Diagnostics;
using Microsoft.Maker.Firmata;
using System.Runtime.InteropServices.WindowsRuntime;

namespace audino_control.ViewModels
{
    public class MainViewModel : INotifyPropertyChanged
    {
        public DelegateCommand ToggleLedCommand { get; private set; }
        public bool ArduinoAvailable
        {
            get
            {
                return _arduinoAvailable;
            }
            private set
            {
                _arduinoAvailable = value;
                ToggleLedCommand.RaiseCanExecuteChanged();
            }
        }

        private UsbSerial _connection;
        private RemoteDevice _arduino;
        private UwpFirmata _firmata;
        private bool _arduinoAvailable;

        private const string USB_VID = "VID_2341";
        private const string USB_PID = "PID_0043";
        private const byte TOGGLE_LED_COMMAND = 0x42;

        public MainViewModel()
        {
            ToggleLedCommand = new DelegateCommand(ToggleLedExecute, ToggleLedCanExecute);
        }

        public void Initialize()
        {
            _connection = new UsbSerial(USB_VID, USB_PID);
            _firmata = new UwpFirmata();
            _arduino = new RemoteDevice(_firmata);

            _firmata.begin(_connection);
            _connection.ConnectionEstablished += ArduinoConnectionEstablished;
            _connection.begin(57600, SerialConfig.SERIAL_8N1);
        }

        private void ArduinoConnectionEstablished()
        {
            Debug.WriteLine("Conenction Established");
            ArduinoAvailable = true;
        }

        private bool ToggleLedCanExecute(object arg)
        {
            return ArduinoAvailable;
        }

        private void ToggleLedExecute(object obj)
        {
            // PinState currentState = _arduino.digitalRead(13);
            // _arduino.digitalWrite(13, currentState == PinState.HIGH ? PinState.LOW : PinState.HIGH);
            _firmata.sendSysex(TOGGLE_LED_COMMAND, new byte[0].AsBuffer());
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void notifyPropertyChanged(string property)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }
    }
}
