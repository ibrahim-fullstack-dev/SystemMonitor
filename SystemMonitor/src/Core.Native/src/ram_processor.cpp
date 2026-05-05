#include "../pch.h" // precompile header
#include "../include/ram_reader.h"
#include <Windows.h>

namespace hardwares {
	namespace ram {

		bool getMemoryStatus(MEMORYSTATUSEX& memStatus) {
			memStatus.dwLength = sizeof(MEMORYSTATUSEX);
			return GlobalMemoryStatusEx(&memStatus) != 0;
		}

		double clsRam_reader::getRamUsagePercentage() const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.dwMemoryLoad);
			}
			return 0;
		}

		double clsRam_reader::getTotalRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double clsRam_reader::getAvailableRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullAvailPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}


		double clsRam_reader::getUsedRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPhys - memInfo.ullAvailPhys) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double clsRam_reader::getVirtualRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPageFile) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}

		double clsRam_reader::getUsedVirtualRamGB()const {
			MEMORYSTATUSEX memInfo;
			if (getMemoryStatus(memInfo))
			{
				return static_cast<double>(memInfo.ullTotalPageFile - memInfo.ullAvailPageFile) / (1024.0 * 1024.0 * 1024.0);
			}
			return 0.0;
		}
	}
}