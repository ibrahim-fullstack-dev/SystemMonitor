using System;
using share.core;

namespace Core.Shared.Tests
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {

                clsCpuWrapper cpu = new clsCpuWrapper();
                clsRamWrapper ram = new clsRamWrapper();
                clsStorageWrapper storage = new clsStorageWrapper();

                /////////////// CPU & RAM TESTS ///////////////

                for (short i = 0; i < 1000; i++)
                {
                    Console.Clear(); // clear console

                    Console.WriteLine("=== Testing System Monitor Storage Bridge ===\n");


                    double cpuUsage = cpu.getCPUUsage();
                    int ramPercent = ram.getRamUsagePercentage();
                    double totalRam = ram.getTotalRamGB();
                    double usedRam = ram.getUsedRamGB();
                    double totalVirtual = ram.getVirtualRamGB();
                    double usedVirtual = ram.getUsedVirtualRamGB();


                    Console.WriteLine($"[CPU]: {cpuUsage}%");
                    Console.WriteLine($"[RAM]: {ramPercent}% ({usedRam}GB / {totalRam}GB)");
                    Console.WriteLine($"[VRM]: {usedVirtual}GB / {totalVirtual}GB (Virtual)"); 
                    Console.WriteLine( "----------------------------------------\n\n");

                    System.Threading.Thread.Sleep(1000); // wait 1 second before next update

                }

                ////////////// STORAGE TESTS ///////////////


                List<String> drives = storage.getDriveList();

                Console.WriteLine($"Found {drives.Count} logical drives:");

                foreach (String drive  in drives)
                {
                    Console.WriteLine($"\n--- Testing Drive: {drive} ---");


                    double total = storage.getTotalSpaceGB(drive);
                    double free = storage.getFreeSpaceGB(drive);
                    double used = storage.getUsedSpaceGB(drive);
                    int percent = storage.getUsagePercentage(drive);

                    Console.WriteLine($"Total: {total:F2} GB");
                    Console.WriteLine($"Free:  {free:F2} GB");
                    Console.WriteLine($"Used:  {used:F2} GB");
                    Console.WriteLine($"Usage: {percent}%");
                }

                storage.Dispose();
                Console.WriteLine("\nTest Completed Successfully!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Test Failed: {ex.Message}");
            }
        }
    }
}
