#ifndef MainMenu_h
#define MainMenu_h
#include "TvObject.h"
#include "TvCollection.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib> 

using namespace std;

class MainMenu {
private:
	TvCollection<TvObject>* movies;
	string title;
	vector<string> buttons;
public:
	MainMenu(const string title, TvCollection<TvObject>* movies);
	void add_button(string button_name);
	bool display();
private:
	void add_tv();
	void delete_tv();
	void edit_tv();
	void statistics();
	void recommended();
	void show_all();
};
#endif // !MainMenu_h
