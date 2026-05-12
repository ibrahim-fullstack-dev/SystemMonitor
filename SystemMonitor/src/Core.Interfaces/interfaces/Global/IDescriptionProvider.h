#pragma once
namespace System {

	namespace Interface {

		namespace Global
		{
			class IDescriptionMessageProvider {

			public:
				virtual ~IDescriptionMessageProvider() = default;

				virtual const wchar_t* GetMessage() const = 0;

			};

			class IAdvancedDescriptionProvider : public IDescriptionMessageProvider {

			public:
				virtual ~IAdvancedDescriptionProvider() = default;

				virtual const wchar_t* GetDescription() const = 0;
			};
		}
	}
}
