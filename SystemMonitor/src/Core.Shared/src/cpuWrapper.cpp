#include "../pch.h"
#include "../include/cpuWrapper.h"

namespace share {
		namespace core {
		clsCpuWrapper::clsCpuWrapper() {
			cpuReader = new hardwares::cpu::clsCpu_Reader();
		}
		clsCpuWrapper::~clsCpuWrapper() {
			this->!clsCpuWrapper();
		}
		clsCpuWrapper::!clsCpuWrapper() {
			if (cpuReader != nullptr) {
				delete cpuReader;
				cpuReader = nullptr;
			}
		}
		double clsCpuWrapper::getCPUUsage() {
			return cpuReader->getCpuUsage();
		}
		}
}