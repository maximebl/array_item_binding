#include "pch.h"
#include "MainPage.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BlankApp1::implementation
{
	MainPage::MainPage()
	{
		InitializeComponent();

		auto vec = single_threaded_observable_vector<IInspectable>();
		vec.Append(box_value(hstring{L"first wheel"}));
		vec.Append(box_value(hstring{L"second wheel"}));
		my_car().wheels(vec);
	}

	BlankApp1::car MainPage::my_car()
	{
		return m_my_car;
	}

	void MainPage::my_car(BlankApp1::car const& value)
	{
		m_my_car = value;
	}
}
