#include "pch.h"
#include "Utils.h"
#include "Menu.h"
#include "FKeys.h"

Menu::Menu() :startPosition_(), itemColor_(mainColor), currentColor_(infoColor), menuItems_() {}

Menu::Menu(const COORD startPosition, const vector<MenuItem>& menuItems, Palette itemColor, Palette currentColor):
	startPosition_(startPosition),
	itemColor_(itemColor),
	currentColor_(currentColor),
    menuItems_(menuItems)
{
	menuItems_[0].selected(true);
}

short Menu::itemColor() const { return itemColor_; }
void Menu::itemColor(short value) { itemColor_ = value; }
short Menu::currentColor() const { return currentColor_; }
void Menu::currentColor(short value) { currentColor_ = value; }

int Menu::getMaxLen() {
	return (int)max_element(menuItems_.begin(), menuItems_.end(),
		[](MenuItem& mi1, MenuItem& mi2) { return mi1.text().length() < mi2.text().length();  })->text().length();
}

void Menu::show() {
	int maxLen = getMaxLen();
	cout << left;
	int rowOffset = 0;
	for (auto mi:menuItems_) {
		cout<< pos(startPosition_.X, startPosition_.Y + rowOffset++)
			<< color(mi.isSelected()?currentColor_:itemColor_)
			<< "    " << setw(maxLen)<< mi.text() << "    ";
	}
	cout << right;
}

int Menu::navigate() {
	int cmd = -1;
	cout << nocursor;
	auto it = find_if(menuItems_.begin(), menuItems_.end(), 
		[](const MenuItem& mi) { return mi.isSelected(); });

	while (true) {
		show();
		short key = _getch();
		if (key == 0 || key == 224) key = _getch();
		if (key == VK_RETURN) { cmd = it->command(); break; }
		if (key == VK_ESCAPE || key == K_F10) { cmd = CMD_QUIT; break; }
		switch (key) {
		case K_DOWN: it->selected(false); if (it == menuItems_.end() - 1) it = menuItems_.begin(); else it++; break;
		case K_UP: it->selected(false); if (it == menuItems_.begin()) it = menuItems_.end() - 1; else it--; break;
		case K_HOME: if (it != menuItems_.begin()) { it->selected(false); it = menuItems_.begin(); } break;
		case K_END: if (it != menuItems_.end() - 1) { it->selected(false); it = menuItems_.end() - 1; } break;
		}
		it->selected(true);
	}
	cout << cursor << color(mainColor);
	return cmd;
}
