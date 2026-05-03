#pragma once
#include "../../Core.Native/include/cpu_reader.h"

namespace share {
	namespace core {
		public ref class clsCpuWrapper {

		private:
			hardwares::cpu::clsCpu_Reader* cpuReader;
		public:
			clsCpuWrapper();
			~clsCpuWrapper();
			!clsCpuWrapper();

			double getCPUUsage();

		};
	}
}