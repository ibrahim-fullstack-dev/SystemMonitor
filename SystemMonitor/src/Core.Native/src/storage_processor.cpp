#include "../pch.h"
#include "../include/storage_reader.h"
#include <cwchar>
#include <Windows.h>

namespace hardwares {
	namespace storage {

		std::vector <std::wstring> clsStorage_reader::getDriveList() const {
			std::vector <std::wstring> drivesList;

			DWORD bufferSize = GetLogicalDriveStringsW(0, NULL);

			if (bufferSize == 0) return drivesList;

			std::vector<wchar_t> buffer(bufferSize);

			if (GetLogicalDriveStringsW(bufferSize,buffer.data()))
			{
				wchar_t* currentDrive = buffer.data();
				while (*currentDrive) {
				    
					drivesList.push_back(currentDrive);
					currentDrive += wcslen(currentDrive) + 1;
				};
			}
			return drivesList;
		}

		double clsStorage_reader::getTotalSpaceGB(const std::wstring& drivePath) const
		{
			ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
			GetDiskFreeSpaceEx(drivePath.c_str(), &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes);
			return static_cast<double>(totalNumberOfBytes.QuadPart) / (1024 * 1024 * 1024);
		}
		double clsStorage_reader::getFreeSpaceGB(const std::wstring& drivePath) const
		{
			ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
			GetDiskFreeSpaceEx(drivePath.c_str(), &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes);
			return static_cast<double>(totalNumberOfFreeBytes.QuadPart) / (1024 * 1024 * 1024);
		}
		double clsStorage_reader::getUsedSpaceGB(const std::wstring& drivePath) const
		{
			double total = getTotalSpaceGB(drivePath);
			double free = getFreeSpaceGB(drivePath);
			return total - free;
		}
		int clsStorage_reader::getUsagePercentage(const std::wstring& drivePath) const
		{
			double total = getTotalSpaceGB(drivePath);
			double used = getUsedSpaceGB(drivePath);
			return static_cast<int>((used / total) * 100);
		}
	}
}