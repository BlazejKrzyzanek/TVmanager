#include "stdafx.h"
#include "MainMenu.h"
#define line "_______________________________________________________________________"

MainMenu::MainMenu(string t, TvCollection<TvObject>* m) {
	title = t;
	movies = m;
}

void MainMenu::add_button(string b) {
	buttons.push_back(b);
}

bool MainMenu::display() {
	cout << line << "\n" <<
			"-----------------------------" << title << "--------------------------------" << "\n" <<
			 line << "\n";
	int length = buttons.size();
	for (int i = 0; i < length; i++) {
		cout << "\n" <<
				"                          " << buttons[i] << "\n" <<
				line << "\n";
	}
	cout << "WYBOR: ";
	char* choice = new char[1]; // reading first char instead of all
	cin >> choice;
	// clear console
	system("CLS");
	cout << line << "\n" <<
			"-------------------------------WYNIKI----------------------------------" << endl;
	switch (toupper(choice[0]))
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
	case 'W':
	{
		this->show_all();
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
	string title;
	int rating;
	int year;
	bool state = true;
	while (state) {
		rating = -1;
		year = -1;
		cout << "Podaj tytul filmu: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		getline(cin, title);
		while (rating < 1 || rating > 10) {
			cout << "Podaj ocene filmu <1-10>: ";
			cin >> rating;
			cin.clear();
			cin.ignore(numeric_limits < streamsize >::max(), '\n');
		}
		while (year < 1 || year > 2100) {
			cout << "Podaj rok produkcji: ";
			cin >> year;
			cin.clear();
			cin.ignore(numeric_limits < streamsize >::max(), '\n');
		}

		TvObject movie(0, title, rating, year);
		movies->add_object(movie);
		cout << "Czy chcesz dodac kolejny film? y/n: ";
		char tmp;
		cin >> tmp;
		cin.clear();
		if (toupper(tmp) == 'Y') {
			state = true;
		}
		else {
			cout << "Nie to nie :)\n";
			state = false;
		}
	}
}

void MainMenu::delete_tv() {
	int id;
	bool state = true;
	while (state) {
		movies->show_all();
		cout << "Jaki film chcesz usunac? Podaj nr ID, -1 aby anulowac: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		cin >> id;
		if (id == -1) return;
		int removed = movies->remove_object(id);
		if (removed) {
			cout << "Taki film nie istnieje w twojej kolekcji\n";
		}
		cout << "Czy chcesz usunac kolejny film? y/n: ";
		char tmp;
		cin >> tmp;
		cin.clear();
		if (toupper(tmp) == 'Y') {
			state = true;
		}
		else {
			cout << "Nie to nie :)\n";
			state = false;
		}
	}
	

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

void MainMenu::show_all() {
	movies->show_all();
}