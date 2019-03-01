#include "pch.h"
#include "car.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BlankApp1::implementation
{
	Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> car::wheels()
	{
		return m_wheels;
	}

	void car::wheels(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> const& value)
	{
		m_wheels = value;
	}

	winrt::event_token car::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_property_changed.add(handler);

	}

	void car::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_property_changed.remove(token);
	}
}
