#pragma once

namespace interface {
	namespace global
	{
		class IStatusProvider {
		public:

			enum class Status { Good, Warning, Critical, Unkown };

			// Virtual destructor for proper cleanup of derived classes.
			virtual ~IStatusProvider() = default;

			virtual const wchar_t* GetLabel() const = 0;
			virtual const wchar_t* GetCategory() const = 0;
		};
	}

}