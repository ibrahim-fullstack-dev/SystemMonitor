#pragma once
namespace System {
	namespace Interface {
		namespace Global
		{
			class IDescriptionProvider {

			public:
				virtual ~IDescriptionProvider() = default;

				virtual const wchar_t* GetStatusMessage() const = 0;

			};

			class IAdvancedDescriptionProvider {

			public:
				virtual ~IAdvancedDescriptionProvider() = default;

				virtual const wchar_t* GetDescription() const = 0;
			};
		}
	}
}
