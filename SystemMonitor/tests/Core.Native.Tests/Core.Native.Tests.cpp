
#include <iostream>
#include <Windows.h>
#include "cpu_reader.h"
#include "cpu_reader.h"


using namespace std;

int main()
{
    hardwares::cpu::clsCpu_Reader cpu_reader;


    std::cout << "--- System Monitor: CPU Test Bench ---\n" << std::endl;

    for (short i = 0; i < 10; i++)
    {
        double cpu_usage = cpu_reader.getCpuUsage();

        cout << "CPU Usage: " << cpu_usage << " %" << endl;

        Sleep(1000); // sleep for 1 second.
    }
    return 0;
}


