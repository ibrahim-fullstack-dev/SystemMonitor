using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;

namespace UI.Desktop.Services.HardwareSevices;

    public class clsRAMService : IDisposable
    {
        private readonly clsRamWrapper _RAMBridge = new clsRamWrapper();

        private double ExecuteSafe(Func<double> action)
        {
            try
            {
                return action();
            }
            catch (Exception ex)
            {
            // Log the error message for debugging purposes.
            System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

            // Return a default value or handle the error as needed
            return double.NaN;
            }
        }

        public double GetTotalRamGB() => ExecuteSafe(() => _RAMBridge.getTotalRamGB());

        public double GetRamUsagePercentage() => ExecuteSafe(() => _RAMBridge.getRamUsagePercentage());

        public double GetUsedRamGB() => ExecuteSafe(() => _RAMBridge.getUsedRamGB());

        public double GetAvailableRamGB() => ExecuteSafe(() => _RAMBridge.getAvailableRamGB());

        public double GetVirtualRamGB() => ExecuteSafe(() => _RAMBridge.getVirtualRamGB());

        public double GetUsedVirtualRamGB() => ExecuteSafe(() => _RAMBridge.getUsedVirtualRamGB());

        public void Dispose()
        {
            _RAMBridge.Dispose(); // Ensure that the unmanaged resources are released when the service is disposed
        }

    }



