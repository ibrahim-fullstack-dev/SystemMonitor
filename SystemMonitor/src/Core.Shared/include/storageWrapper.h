#pragma once

namespace hardwares { namespace storage { class clsStorage_reader; } }

namespace share {
	namespace core {

		public ref class clsStorageWrapper  {
		private:
			void* storageReader;

		public:

			clsStorageWrapper();
			~clsStorageWrapper();
			!clsStorageWrapper();

			double getTotalSpaceGB(System::String^ drivePath) ;
			double getFreeSpaceGB(System::String^ drivePath) ;
			double getUsedSpaceGB(System::String^ drivePath) ;
			int getUsagePercentage(System::String^ drivePath) ;

			System::Collections::Generic::List<System::String^>^ getDriveList();
			
		};
	}
}

