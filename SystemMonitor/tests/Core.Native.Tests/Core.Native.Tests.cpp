#include <iostream>
#include <Windows.h>
#include "cpu_reader.h"
#include "ram_reader.h"


using namespace std;

int main()
{
    hardwares::cpu::clsCpu_Reader cpu;
    hardwares::ram::clsRam_reader ram;


    cout << "========================================" << endl;
    cout << "   System Monitor - Hardware Test       " << endl;
    cout << "========================================" << endl;

    for (short i = 0; i < 10; i++)
    {
        double cpuUsage = cpu.getCpuUsage();
        int ramPercent = ram.getRamUsagePercentage();
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
    return 0;
}


