//
// Declaration of the car class.
//

#pragma once

#include "car.g.h"

namespace winrt::BlankApp1::implementation
{
	struct car : carT<car>
	{
		car() = default;
		Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> wheels();
		void wheels(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> const& value);

		winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;

	private:

		Windows::Foundation::Collections::IObservableVector<IInspectable> m_wheels = winrt::single_threaded_observable_vector<IInspectable>();

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
	struct car : carT<car, implementation::car>
	{
	};
}
