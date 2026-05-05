using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;
using UI.Desktop.global;
using UI.Desktop.Interfaces;


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
