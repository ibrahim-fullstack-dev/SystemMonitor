#include <iostream>
#include <Windows.h>
#include "cpu_reader.h"
#include "ram_reader.h"
#include "storage_reader.h"


using namespace std;

int main()
{
    hardwares::cpu::clsCpu_Reader cpu;
    hardwares::ram::clsRam_reader ram;
    hardwares::storage::clsStorage_reader storage;


    cout << "========================================" << endl;
    cout << "   System Monitor - Hardware Test       " << endl;
    cout << "========================================" << endl;

    for (short i = 0; i < 10; i++)
    {
        double cpuUsage = cpu.getCpuUsage();
        double ramPercent = ram.getRamUsagePercentage();
        double totalRam = ram.getTotalRamGB();
        double usedRam = ram.getUsedRamGB();
        double totalVirtual = ram.getVirtualRamGB();
        double usedVirtual = ram.getUsedVirtualRamGB();

        system("cls"); // clear console

        cout << "[CPU]: " << cpuUsage << "%" << endl;
        cout << "[RAM]: " << ramPercent << "% (" << usedRam << "GB / " << totalRam << "GB)" << endl;
        cout << "[VRM]: " << usedVirtual << "GB / " << totalVirtual << "GB (Virtual)" << endl;

        cout << "----------------------------------------" << endl;


        Sleep(1000); // sleep for 1 second.
    }

    for (const wstring& drive : storage.getDriveList()) {

        double totalSpace = storage.getTotalSpaceGB(drive);
        double freeSpace = storage.getFreeSpaceGB(drive);
        double usedSpace = storage.getUsedSpaceGB(drive);
        int usagePercent = storage.getUsagePercentage(drive);

        wcout << "Drive: " << drive.c_str() << endl;
        cout << "  Total Space: " << totalSpace << " GB" << endl;
        cout << "  Free Space: " << freeSpace << " GB" << endl;
        cout << "  Used Space: " << usedSpace << " GB" << endl;
		cout << "  Usage Percentage: " << usagePercent << "%" << endl;
    }
    return 0;
}


