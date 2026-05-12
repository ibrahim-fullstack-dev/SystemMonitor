#pragma once // Ensure the header is included only once during compilation

namespace System {

	namespace Interface {
		// use virtual inheritance to allow for multiple inheritance from IHardwareComponent without ambiguity
		class IUsageProvider  {
		public:
			virtual ~IUsageProvider() = default; // Virtual destructor for proper cleanup of derived classes.
			virtual double GetUsage() const = 0;
		};
	}
}


