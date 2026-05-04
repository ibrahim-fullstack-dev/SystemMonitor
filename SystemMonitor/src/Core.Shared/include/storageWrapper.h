#pragma once
#include "../../Core.Native/include/storage_reader.h"
using namespace System;
using namespace System::Collections::Generic;

namespace share {
	namespace core {

		public ref class clsStorageWrapper  {
		private:
			hardwares::storage::clsStorage_reader* storageReader;

		public:

			clsStorageWrapper();
			~clsStorageWrapper();
			!clsStorageWrapper();

			double getTotalSpaceGB(String^ drivePath) ;
			double getFreeSpaceGB(String^ drivePath) ;
			double getUsedSpaceGB(String^ drivePath) ;
			int getUsagePercentage(String^ drivePath) ;

			List<String^>^ getDriveList();
			
		};
	}
}

