using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;

namespace UI.Desktop.services.hardwareSevices
{
    public class clsRAMService : IDisposable
    {
        private readonly clsRamWrapper _RAMBridge = new clsRamWrapper();

        public double GetTotalRamGB()
        {
            try
            {
                return _RAMBridge.getTotalRamGB();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public double GetRamUsagePercentage()
        {
            try
            {
                return _RAMBridge.getRamUsagePercentage();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public double GetUsedRamGB()
        {
            try
            {
                return _RAMBridge.getUsedRamGB();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public double GetAvailableRamGB()
        {
            try
            {
                return _RAMBridge.getAvailableRamGB();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public double GetVirtualRamGB()
        {
            try
            {
                return _RAMBridge.getVirtualRamGB();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public double GetUsedVirtualRamGB()
        {
            try
            {
                return _RAMBridge.getUsedVirtualRamGB();

            }
            catch (Exception ex)
            {
                // Log the error message for debugging purposes
                System.Diagnostics.Debug.WriteLine($"RAM Error: {ex.Message}");

                // To log error internally or send it to an error tracking service.
                Console.WriteLine($"Hardware Access Failed: {ex.Message}");

                // Return a default value or handle the error as needed
                return double.NaN;
            }

        }

        public void Dispose()
        {
            _RAMBridge.Dispose(); // Ensure that the unmanaged resources are released when the service is disposed
        }

    }


}
