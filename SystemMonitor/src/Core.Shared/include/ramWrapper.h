#pragma once
#include "../../Core.Native/include/ram_reader.h"

namespace share{
	namespace core {
		public ref class clsRamWrapper {

		private:
			hardwares::ram::clsRam_reader* ramReader;
		public:
			clsRamWrapper();
			~clsRamWrapper();
			!clsRamWrapper();

			int getRamUsagePercentage();

			 double getTotalRamGB();
			 double getAvailableRamGB();
			 double getUsedRamGB();


			 double getVirtualRamGB();
			 double getUsedVirtualRamGB();
		};
	}
}
