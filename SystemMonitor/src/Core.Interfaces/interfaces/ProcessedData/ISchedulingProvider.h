#pragma once

namespace System {

	namespace Interface {

		namespace RawData
		{
			class ISchedulingProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~ISchedulingProvider() = default;
				virtual int GetPreferredUpdateIntervalMS() const = 0;
			};
		}

		namespace ProcessedData{

			class ISchedulingAdvancedProvider : public RawData::ISchedulingProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~ISchedulingAdvancedProvider() = default;
				virtual bool IsHighPriority() const = 0;

			};
		}
	}
}
