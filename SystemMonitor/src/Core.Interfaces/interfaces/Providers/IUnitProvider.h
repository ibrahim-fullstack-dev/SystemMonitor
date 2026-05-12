#pragma once
#include "../../Enums/UnitType.h"

namespace System {

    namespace Interface {

        namespace Global {

            class IUnitProvider {
            public:
                virtual ~IUnitProvider() {}

                virtual Enums::enUnitType GetUnitType() = 0;

                virtual const char* GetUnitSymbol() = 0;
            };
        }
    }
}