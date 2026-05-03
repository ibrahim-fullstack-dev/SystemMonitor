#pragma once
#include "../../Core.Native/include/storage_reader.h"

namespace share {
	namespace core {
		class clsStorageWrapper {
		private:
			hardwares::storage::clsStorage_reader storageReader;
		public:
			std::vector<std::wstring> getDriveList() ;

			double getTotalSpaceGB(const std::wstring& drivePath) ;
			double getFreeSpaceGB(const std::wstring& drivePath) ;
			double getUsedSpaceGB(const std::wstring& drivePath) ;
			int getUsagePercentage(const std::wstring& drivePath) ;

		};
	}
}

