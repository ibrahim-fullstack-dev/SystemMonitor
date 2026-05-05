using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using share.core;
using UI.Desktop.Services.Interfaces;
using UI.Desktop.Base;


namespace UI.Desktop.Services.HardwareSevices;

    public class clsRAMService : clsBaseClass, IRAMService, IDisposable
    {
        private readonly clsRamWrapper _RAMBridge = new clsRamWrapper();

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



