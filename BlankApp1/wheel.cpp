#include "pch.h"
#include "wheel.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BlankApp1::implementation
{
    hstring wheel::wheel_val()
    {
		return m_wheel_val;
    }

    void wheel::wheel_val(hstring value)
    {
		m_wheel_val = value;
    }

	winrt::event_token wheel::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_property_changed.add(handler);

	}

	void wheel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_property_changed.remove(token);
	}
}
