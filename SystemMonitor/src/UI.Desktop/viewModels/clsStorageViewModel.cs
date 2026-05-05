using System;
using System.Collections.Generic;   
using System.Collections.ObjectModel;
using UI.Desktop.Global;
using UI.Desktop.Models;
using UI.Desktop.Services.HardwareSevices;

namespace UI.Desktop.ViewModels;

public class clsStorageViewModel: clsBaseClass, IDisposable
{
    private readonly clsStorageService _storageService;
    private ObservableCollection<clsStorageModel> _storageReport;

    private ObservableCollection<clsStorageModel> GetFullStorageReport()
    {
        List<string> paths = _storageService.GetStoragePaths();
        ObservableCollection<clsStorageModel> storageModels = new ObservableCollection<clsStorageModel>();

        foreach (string path in paths)
        {
            clsStorageModel model = new clsStorageModel
            {
                DriveLetter = path,
                TotalSizeGB = _storageService.GetTotalStorageGB(path),
                UsedSizeGB = _storageService.GetUsedStorageGB(path),
                FreeSizeGB = _storageService.GetAvailableStorageGB(path),
                UsagePercentage = _storageService.GetStorageUsagePercentage(path)
            };
            storageModels.Add(model);
        }
        return storageModels;
    }

    public clsStorageViewModel()
    {
        _storageService = new clsStorageService();
        UpdateStorageReport();
    }

    public ObservableCollection<clsStorageModel> StorageReport
    {
        get => _storageReport;
        set
        {
            _storageReport = value; OnPropertyChanged();
            // NotifyPropertyChanged if implementing INotifyPropertyChanged
        }
    }

    public void UpdateStorageReport()
    {
        _storageReport = GetFullStorageReport();
    }

    public void Dispose()
    {
        _storageService?.Dispose();
    }

}
