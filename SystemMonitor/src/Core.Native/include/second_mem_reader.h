#pragma once
#include <string>

namespace hardwares
{
	namespace storage {
		class clsStorage_reader {
		public:

			double getTotalSpaceGB(const std::wstring& drivePath) const;
			double getFreeSpaceGB(const std::wstring& drivePath) const;
			double getUsedSpaceGB(const std::wstring& drivePath) const;
			int getUsagePercentage(const std::wstring& drivePath) const;
		};
	}
}
