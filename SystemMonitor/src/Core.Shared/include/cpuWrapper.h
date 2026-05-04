#pragma once
namespace hardwares { namespace cpu { class clsCpu_Reader; } }


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