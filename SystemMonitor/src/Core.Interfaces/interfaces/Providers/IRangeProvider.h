#pragma once // Ensure the header is included only once during compilation
#include "../Global/ISystemInfoProvider.h"  

namespace System {

	namespace Interface {
		// use virtual inheritance to allow for multiple inheritance from IHardwareComponent without ambiguity
		class IRangeProvider  {
		public:
			virtual ~IRangeProvider() = default; // Virtual destructor for proper cleanup of derived classes.
			virtual double GetMin() const = 0;
			virtual double GetMax() const = 0;

		};
	}
}


