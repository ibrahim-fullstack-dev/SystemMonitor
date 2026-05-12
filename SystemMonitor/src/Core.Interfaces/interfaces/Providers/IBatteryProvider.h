#pragma once
#include "../../Enums/BatteryState.h"

namespace System {
	namespace Interface {
			class IBatteryProvider {

			public:
				virtual ~IBatteryProvider() = default;
				virtual Enums::enBatteryState GetState() const = 0;
			};
		
	}
}
