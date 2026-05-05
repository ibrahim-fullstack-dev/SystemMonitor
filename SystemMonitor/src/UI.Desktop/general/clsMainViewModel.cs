using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UI.Desktop.ViewModels;

namespace UI.Desktop.General;

public class clsMainViewModel
{
    private clsCPUViewModel clsCPUViewModel { get; }
    private clsRAMViewModel clsRAMViewModel { get; }
    private clsStorageViewModel clsStorageViewModel { get;  }

    clsMainViewModel()
    {
        clsCPUViewModel = new clsCPUViewModel();
        clsRAMViewModel = new clsRAMViewModel();
        clsStorageViewModel = new clsStorageViewModel();
    }

    private void StartMonitoring()
    {
        // Implement logic to start monitoring CPU, RAM, and Storage data

        var timer = new System.Windows.Threading.DispatcherTimer();

        timer.Interval = TimeSpan.FromSeconds(1);
        timer.Tick += (sender, e) =>
        {
            // Update CPU, RAM, and Storage data here

            clsCPUViewModel.UpdateCPUData();
            clsRAMViewModel.UpdateRAMReport();
            clsStorageViewModel.UpdateStorageReport();
        };
        timer.Start();
    }

}
