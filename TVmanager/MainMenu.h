#ifndef MainMenu_h
#define MainMenu_h
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 

using namespace std;

class MainMenu {
private:
	vector<string> buttons;
	char choice;
public:
	MainMenu(const vector<string>);
	bool display();
private:
	void add_tv();
	void delete_tv();
	void edit_tv();
	void statistics();
	void recommended();
};
#endif // !MainMenu_h
