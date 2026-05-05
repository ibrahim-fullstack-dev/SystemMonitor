using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UI.Desktop.Services.Interfaces
{
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
}
