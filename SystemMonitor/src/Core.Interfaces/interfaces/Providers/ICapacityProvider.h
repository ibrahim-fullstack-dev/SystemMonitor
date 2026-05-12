#pragma once // Ensure the header is included only once during compilation
#include "../Global/ISystemInfoProvider.h" 

namespace System {

	namespace Interface {

		// use virtual inheritance to allow for multiple inheritance from IHardwareComponent without ambiguity
		class ICapacityProvider  {
		public:
			virtual ~ICapacityProvider() = default; // Virtual destructor for proper cleanup of derived classes.
			virtual double GetCapacity() const = 0;
			virtual double GetUsedCapacity() const = 0;
		};

	}
}


