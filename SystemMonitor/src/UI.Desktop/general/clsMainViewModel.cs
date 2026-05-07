using UI.Desktop.ViewModels;
namespace UI.Desktop.Global;

public class clsMainViewModel
{
    public clsCPUViewModel CPUVM { get; }
    public clsRAMViewModel RAMVM { get; }
    public clsStorageViewModel StorageVM { get;  }
    public clsMainViewModel()
    {
        CPUVM = new clsCPUViewModel();
        RAMVM = new clsRAMViewModel();
        StorageVM = new clsStorageViewModel();
        
        StartMonitoring();
    }
    private void StartMonitoring()
    {
        // Implement logic to start monitoring CPU, RAM, and Storage data

        var timer = new System.Windows.Threading.DispatcherTimer();

        timer.Interval = TimeSpan.FromSeconds(1);
        timer.Tick += (sender, e) =>
        {
            // Update CPU, RAM, and Storage data here
                    
            CPUVM.UpdateCPUData();
            RAMVM.UpdateRAMReport();
            StorageVM.UpdateStorageReport();
        };
        timer.Start();
    }

}
