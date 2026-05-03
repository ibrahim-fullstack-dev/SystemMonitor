#pragma once // include guard

namespace hardwares {
	namespace ram {

		class ram_reader {
			
		public:
			// RAM usage percentage
			int getRamUsagePercentage() const;

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