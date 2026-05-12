#pragma once

namespace System {
	namespace Interface {
		namespace Global
		{
			class ISchedulingProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~ISchedulingProvider() = default;
				virtual const int GetRemainingTimeMinutes() const = 0;
			};
		}
	}
}
