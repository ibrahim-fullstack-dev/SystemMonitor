#pragma once
#include "../../Enums/UnitType.h"

namespace System {

    namespace Interface {


            class IUnitProvider {
            public:
                virtual ~IUnitProvider() = default;

                virtual Enums::enUnitType GetUnitType() = 0;

                virtual const char* GetUnitSymbol() = 0;
            };
        
    }
}