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

			int getRamUsagePercentage() ;

			const double getTotalRamGB() ;
			const double getAvailableRamGB() ;
			const double getUsedRamGB() ;


			const double getVirtualRamGB() ;
			const double getUsedVirtualRamGB() ;
		};
	}
}
