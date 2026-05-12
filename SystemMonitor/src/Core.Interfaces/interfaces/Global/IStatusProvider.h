#pragma once
#include "../../Enums/StatusLevel.h"

namespace System {

	namespace Interface {
		namespace Global
		{
			class IStatusProvider {
			public:



				// Virtual destructor for proper cleanup of derived classes.
				virtual ~IStatusProvider() = default;

				virtual Enums::enStatusLevel GetStatus() const = 0;
				virtual const wchar_t* GetStatusMessage() const = 0;
			};
		}

	}
}
