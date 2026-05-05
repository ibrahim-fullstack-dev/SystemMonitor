using System;

namespace UI.Desktop.Models
{
    public class clsStorageModel
    {
        public string DriveLetter { get; set; }    
        public double TotalSizeGB { get; set; }
        public double UsedSizeGB { get; set; } = 0;
        public double FreeSizeGB { get; set; }
        public double UsagePercentage { get; set; }
    }
}
