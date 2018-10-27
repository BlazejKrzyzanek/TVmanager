#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu(const vector<string> a) {
	int length = a.size();
	for (int i = 0; i < length; i++) {
		buttons.push_back(a[i]);
	}
}

bool MainMenu::display() {
	cout << "_________________________________________________________________" << "\n" <<
			"--------------------------TV MANAGER-----------------------------" << "\n" <<
			"_________________________________________________________________" << "\n";
	int length = buttons.size();
	for (int i = 0; i < length; i++) {
		cout << "\n" <<
				"                      " << buttons[i] << "\n" <<
				"_________________________________________________________________" << "\n";
	}
	cout << "WYBOR: ";
	cin >> choice;

	// clear console
	system("CLS");
	cout << "_________________________________________________________________" << "\n" <<
			"----------------------------WYNIKI-------------------------------" << endl;
	choice = toupper(choice);
	switch (choice)
	{
	case 'A':
	{
		this->add_tv();
		break;
	}
	case 'D':
	{
		this->delete_tv();
		break;
	}
	case 'E':
	{
		this->edit_tv();
		break;
	}
	case 'S':
	{
		this->statistics();
		break;
	}
	case 'R':
	{
		this->recommended();
		break;
	}
	case 'K':
	{	
		system("CLS");
		return false;
	}
	default:
		cout << "Bledna komenda, sproboj ponownie" << "\n";
		break;
	}
	return true;
}

void MainMenu::add_tv(){
	cout << "DODANO FILM" << "\n";
}

void MainMenu::delete_tv() {
	cout << "Usunieto film" << "\n";
}

void MainMenu::edit_tv() {
	cout << "edytowano film" << "\n";
}

void MainMenu::statistics() {
	cout << "statystyki" << "\n";
}

void MainMenu::recommended() {
	cout << "Rekomendacje" << "\n";
}