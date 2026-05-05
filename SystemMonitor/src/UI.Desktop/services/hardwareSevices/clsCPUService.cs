using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;
using UI.Desktop.Services.Interfaces;
using UI.Desktop.Base;


namespace UI.Desktop.Services.HardwareSevices;

public class clsCPUService :clsBaseClass, ICPUService
{
    public double GetCpuUsage() => ExecuteSafe(() => { 

     using(clsCpuWrapper _CPU = new clsCpuWrapper())
     {
         return _CPU.getCPUUsage();
     }

    });

}
