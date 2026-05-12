#pragma once // Ensure the header is included only once during compilation

namespace System {

	namespace Interface {

		namespace RawData
		{
			class ICapacityProvider {
			public:
				virtual ~ICapacityProvider() = default; // Virtual destructor for proper cleanup of derived classes.
				virtual double GetCapacity() const = 0;
				virtual double GetUsedCapacity() const = 0;
			};
		}

	}
}


