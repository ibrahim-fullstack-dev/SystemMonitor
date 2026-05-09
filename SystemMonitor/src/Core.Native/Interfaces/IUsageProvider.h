#pragma once // Ensure the header is included only once during compilation

namespace Interfaces {
	class IUsageProvider{
	public :
		virtual ~IUsageProvider() = default; // Virtual destructor for proper cleanup of derived classes (cleanup resources from vTable).
		virtual double GetUsage() = 0;
	};
}

