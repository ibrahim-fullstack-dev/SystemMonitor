using System;

namespace UI.Desktop.Models
{
    public class clsRamModel
    {
        public double UsagePercentage { get; set; }

        public double TotalRamGB { get; set; }
        public double AvailableRamGB { get; set; }
        public double UsedRamGB { get; set; } = 0;
        public double VirtualRamGB { get; set; }
        public double UsedVirtualRamGB { get; set; } 
        public double VirtualVirtualRamGB { get; } = 0;
    }
}
