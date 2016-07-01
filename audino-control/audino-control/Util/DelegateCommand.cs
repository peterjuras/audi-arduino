using System;

namespace audino_control.Util
{
    public class DelegateCommand : System.Windows.Input.ICommand
    {
        private Func<object, bool> _canExecute;
        private Action<object> _execute;

        public DelegateCommand(Action<object> execute, Func<object, bool> canExecute)
        {
            _canExecute = canExecute;
            _execute = execute;
        }

        public DelegateCommand(Action<object> execute) : this(execute, (obj) => true)
        {

        }

        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            return _canExecute(parameter);
        }

        public void Execute(object parameter)
        {
            if (_canExecute(parameter))
            {
                _execute.Invoke(parameter);
            }
        }

        public void RaiseCanExecuteChanged()
        {
            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
        }
    }
}
