#ifndef Spegetti_GUI_H
#define Spegetti_GUI_H

#include <iostream>
#include <Spegetti.h>

using namespace Spegetti;

namespace Spegetti_GUI
{

	class Theme
	{

	public:

		Theme();
		~Theme();

	};

	class Window
	{

	public:

		Math::Transform2 Transform;

		Window();
		~Window();

	};

	class Tab
	{

	public:

		Math::Transform2 Transform;

		Tab();
		~Tab();

	};

	class ViewPort
	{

	public:

		Math::Transform2 Transform;

		ViewPort();
		~ViewPort();

	};

	class Text
	{

	public:

		Math::Transform2 Transform;

		Text();
		~Text();

	};

	class Button
	{

	public:

		Math::Transform2 Transform;

		Button();
		~Button();

	};

	class Menu
	{

	public:

		Math::Transform2 Transform;

		Menu();
		~Menu();

	};

}

#endif