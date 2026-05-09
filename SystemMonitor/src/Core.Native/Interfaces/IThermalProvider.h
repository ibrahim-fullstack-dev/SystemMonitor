#pragma once // Ensure the header is included only once during compilation

namespace Interfaces {
	class IThermalProvider {
	public:
		virtual ~IThermalProvider() = default; // Virtual destructor for proper cleanup of derived classes .
		virtual double GetTemperature() = 0;
	};
}

