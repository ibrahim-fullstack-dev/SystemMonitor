using System;
using LiveChartsCore.SkiaSharpView;
using LiveChartsCore.SkiaSharpView.Painting;
using SkiaSharp;
using UI.Desktop.Global;
using UI.Desktop.Models;
using UI.Desktop.Services.HardwareSevices;
using LiveChartsCore;


namespace UI.Desktop.ViewModels;

public class clsCPUViewModel: clsGeneralViewModel_Chart, IDisposable
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
        : base("CPU Usage", SKColors.GreenYellow, SKColors.Green)
    {
        _cpuService = new clsCPUService();
        UpdateCPUData();
        // Initialize properties or start monitoring CPU data here
    }

    public void UpdateCPUData()
    {
        _cpuModel = GetFullReport();
        base.Update(_cpuModel.CpuUsagePercentage);

        // Implement logic to update CPU usage and temperature data here
    }

    public void Dispose()
    {
            _cpuService?.Dispose();
        // Clean up any resources if necessary when the ViewModel is disposed
    }

}
