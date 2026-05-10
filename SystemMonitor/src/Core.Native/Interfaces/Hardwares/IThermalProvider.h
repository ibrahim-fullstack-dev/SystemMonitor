#pragma once // Ensure the header is included only once during compilation
#include "../Global/IHardwareComponent.h" 


namespace Interface {

	// use virtual inheritance to allow for multiple inheritance from IHardwareComponent without ambiguity
	class IThermalProvider : virtual public interface::global::ILabelCategoryProvider {
	public:
		virtual ~IThermalProvider() = default; // Virtual destructor for proper cleanup of derived classes .
		virtual double GetTemperature() const = 0;
	};
}

