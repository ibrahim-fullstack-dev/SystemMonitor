#include "../pch.h"

#include "../../Core.Native/include/ram_reader.h"

#include "../include/ramWrapper.h"

namespace share {
	namespace core {

		clsRamWrapper::clsRamWrapper() {
			ramReader = new hardwares::ram::clsRam_reader();
		}
		clsRamWrapper::~clsRamWrapper() {
			this->!clsRamWrapper();
		}
		clsRamWrapper::!clsRamWrapper() {
			if (ramReader != nullptr) {
				delete ramReader;
				ramReader = nullptr;
			}
		}

		double clsRamWrapper::getRamUsagePercentage() {
			return ramReader->getRamUsagePercentage();
		}
		double clsRamWrapper::getTotalRamGB() {
			return ramReader->getTotalRamGB();
		}
		double clsRamWrapper::getUsedRamGB() {
			return ramReader->getUsedRamGB();
		}
		double clsRamWrapper::getAvailableRamGB() {
			return ramReader->getAvailableRamGB();
		}
		double clsRamWrapper::getVirtualRamGB() {
			return ramReader->getVirtualRamGB();
		}
		double clsRamWrapper::getUsedVirtualRamGB() {
			return ramReader->getUsedVirtualRamGB();
		}

	}
}
		