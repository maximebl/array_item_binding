//
// Declaration of the wheel class.
//

#pragma once

#include "wheel.g.h"

namespace winrt::BlankApp1::implementation
{
	struct wheel : wheelT<wheel>
	{
		wheel() = default;
		hstring wheel_val();
		void wheel_val(hstring value);

		winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;

	private:
		hstring m_wheel_val = L"";

		winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_property_changed;

		void raise_property_changed(hstring const& property_name)
		{
			m_property_changed(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(property_name));
		}

		template <class T>
		void update_value(hstring const& property_name, T & var, T value)
		{
			if (var != value)
			{
				var = value;
				raise_property_changed(property_name);
			}
		}
	};
}

namespace winrt::BlankApp1::factory_implementation
{
	struct wheel : wheelT<wheel, implementation::wheel>
	{
	};
}
