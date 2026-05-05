using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;

namespace UI.Desktop.services
{
    namespace hardwareSevices {
        public class clsCPU
        {
            public double GetCpuUsage()
            {
                try
                {
                    clsCpuWrapper CPU = new clsCpuWrapper();
                    return CPU.getCPUUsage();

                }
                catch (Exception ex)
                {
                    return 0;
                }

            }
        }
    }

    
}
