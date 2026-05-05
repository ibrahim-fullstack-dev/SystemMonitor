using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UI.Desktop.Models;

namespace UI.Desktop.Interfaces;

public interface ICPUService
{
    double GetCpuUsage();
}
public interface IRAMService
{
    double GetTotalRamGB();
    double GetRamUsagePercentage();
    double GetUsedRamGB();
    double GetAvailableRamGB();
    double GetVirtualRamGB();
    double GetUsedVirtualRamGB();
}
public interface IStorageService
{
    List<string> GetStoragePaths();
    double GetTotalStorageGB(string path);
    double GetStorageUsagePercentage(string path);
    double GetUsedStorageGB(string path);
    double GetAvailableStorageGB(string path);
}

