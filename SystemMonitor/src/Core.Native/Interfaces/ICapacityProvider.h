#pragma once // Ensure the header is included only once during compilation

namespace Interfaces {
	class ICapacityProvider {
	public:
		virtual ~ICapacityProvider() = default; // Virtual destructor for proper cleanup of derived classes (cleanup resources from vTable).
		virtual double GetCapacity() = 0;
		virtual double GetAvailableCapacity() = 0;
	};
}

