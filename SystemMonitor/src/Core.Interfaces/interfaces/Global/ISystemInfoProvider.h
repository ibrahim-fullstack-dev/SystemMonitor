#pragma once

namespace System {

	namespace Interface {

		namespace Global
		{
			class ILabelCategoryProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~ILabelCategoryProvider() = default;

				virtual const wchar_t* GetLabel() const = 0;
				virtual const wchar_t* GetCategory() const = 0;
			};

			class IErrorProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~IErrorProvider() = default;

				virtual bool IsAvailable() const = 0;

				virtual int GetErrorCode() const = 0;
			};

			class ITimestampProvider {
			public:
				// Virtual destructor for proper cleanup of derived classes.
				virtual ~ITimestampProvider() = default;
				virtual long long GetTimestamp() const = 0; // Return timestamp in milliseconds since epoch
			};
		}

	}
}
