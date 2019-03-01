//
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "car.h"
#include "wheel.h"

namespace winrt::BlankApp1::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		MainPage();

		BlankApp1::car my_car();
		void my_car(BlankApp1::car const& value);

	private:
		BlankApp1::car m_my_car = winrt::make<BlankApp1::implementation::car>();
	};
}

namespace winrt::BlankApp1::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{
	};
}
