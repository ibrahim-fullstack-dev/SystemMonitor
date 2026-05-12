#pragma once // Ensure the header is included only once during compilation
#include "../../Enums/ThermalState.h"

namespace System {

	namespace Interface {

		// use virtual inheritance to allow for multiple inheritance from IHardwareComponent without ambiguity
		class IThermalProvider  {
		public:
			virtual ~IThermalProvider() = default; // Virtual destructor for proper cleanup of derived classes .
			virtual double GetTemperature() const = 0;
		};

		class IAdvancedThermalProvider  {
		public:
			virtual ~IAdvancedThermalProvider() = default; // Virtual destructor for proper cleanup of derived classes .
			virtual Enums::ThermalState GetThermalState() const = 0;
			virtual const wchar_t* GetTemperatureMessage() const = 0;
			
		};
	}
}


