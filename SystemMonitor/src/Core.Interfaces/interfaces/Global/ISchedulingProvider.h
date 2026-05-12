#pragma once

namespace System {
	namespace Interface {
		namespace Global
		{
            class ISchedulingProvider {
            public:
                virtual ~ISchedulingProvider() {}

                virtual int GetRecommendedUpdateIntervalMS() = 0;

                virtual bool IsStaticData() = 0;
            };
		}
	}
}
