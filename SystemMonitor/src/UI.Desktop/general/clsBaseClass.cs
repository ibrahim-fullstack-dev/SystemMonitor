using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Documents;

namespace UI.Desktop.Global;
public abstract class clsBaseClass: INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected void OnPropertyChanged([CallerMemberName] string propertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    protected double ExecuteSafe(Func<double> action)
    {
        try
        {
            return action();
        }
        catch (Exception ex)
        {
            // Log the error message for debugging purposes.
            System.Diagnostics.Debug.WriteLine($"Error: {ex.Message}");

            // Return a default value or handle the error as needed
            return double.NaN;
        }
    }

    protected List<T> ExecuteSafe<T>(Func<List<T>> action)
    {
        try
        {
            return action();
        }
        catch (Exception ex)
        {
            // Log the error message for debugging purposes.
            System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

            // Return a default value or handle the error as needed
            return null;
        }
    }

}
