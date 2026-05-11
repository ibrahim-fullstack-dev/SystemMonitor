#pragma once // include guard

namespace hardwares {
	namespace ram {

		class clsRam_reader {
			
		public:
			// RAM usage percentage
			double getRamUsagePercentage() const;

			// RAM information in GB
			double getTotalRamGB() const;
			double getAvailableRamGB() const;
			double getUsedRamGB() const;

			// Virtual RAM (page file usage) information
			double getVirtualRamGB() const;
			double getUsedVirtualRamGB() const;


		};
	}
}