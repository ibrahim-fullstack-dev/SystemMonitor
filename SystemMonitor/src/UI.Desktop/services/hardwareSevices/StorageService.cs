using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;
using UI.Desktop.Services.Interfaces;
using UI.Desktop.Base;


namespace UI.Desktop.Services.HardwareSevices;

public class clsStorageService : clsBaseClass, IStorageService, IDisposable
{
    private readonly clsStorageWrapper _StorageBridge = new clsStorageWrapper();
    public List<string> GetStoragePaths() => ExecuteSafe(() => _StorageBridge.getDriveList());

    public double GetTotalStorageGB(string path) => ExecuteSafe(() => _StorageBridge.getTotalSpaceGB(path));

    public double GetStorageUsagePercentage(string path ) => ExecuteSafe(() => _StorageBridge.getUsagePercentage(path));

    public double GetUsedStorageGB(string path) => ExecuteSafe(() => _StorageBridge.getUsedSpaceGB(path));

    public double GetAvailableStorageGB(string path) => ExecuteSafe(() => _StorageBridge.getFreeSpaceGB(path));

    public void Dispose()
    {
        _StorageBridge.Dispose(); // Ensure that the unmanaged resources are released when the service is disposed
    }

}



