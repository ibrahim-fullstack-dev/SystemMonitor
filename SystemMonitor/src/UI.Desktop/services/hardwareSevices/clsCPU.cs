using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;

namespace UI.Desktop.Services.HardwareSevices;

public class clsCPU
{
    public double GetCpuUsage()
    {
        try
        {
            using (clsCpuWrapper CPU = new clsCpuWrapper())
            {
                return CPU.getCPUUsage();

            }

        }
        catch (Exception ex)
        {
            // Log the error message for debugging purposes
            System.Diagnostics.Debug.WriteLine($"CPU Error: {ex.Message}");

            // To log error internally or send it to an error tracking service.
            Console.WriteLine($"Hardware Access Failed: {ex.Message}");

            // Return a default value or handle the error as needed
            return double.NaN;
        }

    }
}
