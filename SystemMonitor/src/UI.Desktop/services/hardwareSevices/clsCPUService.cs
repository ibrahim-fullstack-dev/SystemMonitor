using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;
using UI.Desktop.Global;
using UI.Desktop.Interfaces;


namespace UI.Desktop.Services.HardwareSevices;

public class clsCPUService :clsBaseClass, ICPUService, IDisposable
{
    clsCpuWrapper _CPU = new clsCpuWrapper();
    public double GetCpuUsage() => ExecuteSafe(() => _CPU.getCPUUsage());
     public void Dispose()
    {
        _CPU?.Dispose(); // Ensure that the unmanaged resources are released when the service is disposed
    }

}
