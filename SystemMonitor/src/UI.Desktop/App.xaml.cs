using System.Configuration;
using System.Data;
using System.Windows;
using UI.Desktop.Global;

namespace UI.Desktop;

/// <summary>
/// Interaction logic for App.xaml
/// </summary>
public partial class App : Application
{

    protected override void OnStartup(StartupEventArgs e) { 

        base.OnStartup(e);

        clsMainViewModel mainViewModel = new clsMainViewModel();
        MainWindow mainWindow = new MainWindow();
        mainWindow.DataContext = mainViewModel;

        mainWindow.Show();
    }
}
