#include "../pch.h" // precompile header
#include "../include/ram_reader.h"
#include <Windows.h>

namespace hardwares {
	namespace ram {

		bool getMemoryStatus(MEMORYSTATUSEX& memStatus) {
			memStatus.dwLength = sizeof(MEMORYSTATUSEX);
			return GlobalMemoryStatusEx(&memStatus) != 0;
		}

		int ram_reader::getRamUsagePercentage() const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<int>(memInfo.dwMemoryLoad);
			}
			return 0;
		}

		double ram_reader::getTotalRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double ram_reader::getAvailableRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullAvailPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}


		double ram_reader::getUsedRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double ram_reader::getVirtualRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPageFile) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double ram_reader::getUsedVirtualRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPageFile - memInfo.ullAvailPageFile) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}
	}
}