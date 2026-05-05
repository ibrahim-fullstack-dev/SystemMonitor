using UI.Desktop.Models;
using UI.Desktop.Services.HardwareSevices;
using UI.Desktop.Global;


namespace UI.Desktop.ViewModels;

public class clsRAMViewModel: clsBaseClass, IDisposable
{
    private readonly clsRAMService _ramService;
    private clsRamModel _ramReport;

    private clsRamModel GetFullRAMReport()
    {
        return new clsRamModel
        {
            UsagePercentage = _ramService.GetRamUsagePercentage(),
            TotalRamGB = _ramService.GetTotalRamGB(),
            AvailableRamGB = _ramService.GetAvailableRamGB(),
            UsedRamGB = _ramService.GetUsedRamGB(),
            VirtualRamGB = _ramService.GetVirtualRamGB(),
            UsedVirtualRamGB = _ramService.GetUsedVirtualRamGB()
        };
    }

    public clsRAMViewModel()
    {
        _ramService = new clsRAMService();
        UpdateRAMReport();
    }

    public clsRamModel RAMReport
    {
        get => _ramReport;
        set
        {
            _ramReport = value; OnPropertyChanged();
            // NotifyPropertyChanged if implementing INotifyPropertyChanged
        }
    }

    private void UpdateRAMReport()
    {
        _ramReport = GetFullRAMReport();
    }

    public void Dispose()
    {
        _ramService?.Dispose();
    }

}
