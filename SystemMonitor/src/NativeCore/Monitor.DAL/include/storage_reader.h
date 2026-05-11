#pragma once
#include <string>
#include <vector>

namespace hardwares
{
	namespace storage {
		class clsStorage_reader {
		public:

			std::vector<std::wstring> getDriveList() const;

			double getTotalSpaceGB(const std::wstring& drivePath) const;
			double getFreeSpaceGB(const std::wstring& drivePath) const;
			double getUsedSpaceGB(const std::wstring& drivePath) const;
			int getUsagePercentage(const std::wstring& drivePath) const;
		};
	}
}
