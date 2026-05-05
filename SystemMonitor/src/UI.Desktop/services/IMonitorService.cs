using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UI.Desktop.Services
{
   public interface IMonitorService
    {
        double GetCpuUsage();
        double GetTotalRamGB();
        double GetRamUsagePercentage();
        double GetUsedRamGB();
        double GetAvailableRamGB();
        double GetVirtualRamGB();
        double GetUsedVirtualRamGB();
    }
}
