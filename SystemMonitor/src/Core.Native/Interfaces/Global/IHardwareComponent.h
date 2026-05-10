#pragma once

namespace interfaces {
	class IHardwareComponent {
		public:
		virtual ~IHardwareComponent() = default; // Virtual destructor for proper cleanup of derived classes.
		virtual const wchar_t* GetLabel() const = 0;
		virtual const wchar_t* GetCategory() const = 0;
	};
}