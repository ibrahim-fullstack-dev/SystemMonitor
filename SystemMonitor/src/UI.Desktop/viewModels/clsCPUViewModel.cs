using System;
using UI.Desktop.Global;
using UI.Desktop.Models;
using UI.Desktop.Services.HardwareSevices;

namespace UI.Desktop.ViewModels;

public class clsCPUViewModel: IDisposable
{
    private readonly clsCPUService _cpuService;
    private clsCpuModel _cpuModel;
    public clsCpuModel CPUUsagePercentage
    {
        get => _cpuModel;
        set
        {
            _cpuModel = value;
        }
    }

    private clsCpuModel GetFullReport()
    {
        return new clsCpuModel
        {
            CpuUsagePercentage = _cpuService.GetCpuUsage(),
        };
    }

    public clsCPUViewModel()
    {
        _cpuService = new clsCPUService();
        UpdateCPUData();
        // Initialize properties or start monitoring CPU data here
    }

    public void UpdateCPUData()
    {
        
        _cpuModel = GetFullReport();
        // Implement logic to update CPU usage and temperature data here
    }

    public void Dispose()
    {
            _cpuService?.Dispose();
        // Clean up any resources if necessary when the ViewModel is disposed
    }

}
