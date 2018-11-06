#ifndef MainMenu_h
#define MainMenu_h
#include "TvObject.h"
#include "Movie.h"
#include "Series.h"
#include "Live.h"
#include "TvCollection.h"
#include "Visual.h"
#include "MyException.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib> 
#include <conio.h>
#include <typeinfo>
#include <random>
#include <Windows.h>

using namespace std;

class MainMenu {
private:
	TvCollection<Movie>* movies;
	TvCollection<Series>* tvSeries;
	TvCollection<Live>* lives;
	string title;
	vector<string> buttons;
public:
	MainMenu(const string title, TvCollection<Movie>* movies, TvCollection<Series>* tvSeries, TvCollection<Live>* lives);
	virtual void add_button(string button_name);
	virtual bool display();
private:
	void add_tv();
	void delete_tv();
	void edit_tv();
	void statistics();
	void recommended();
	void show_all();
	void showMovies();
	void showTvSeries();
	void showLives();
	Series createSeries(int id);
	Movie createMovie(int id);
	Live createLive(int id);
	bool editSeries();
	bool editMovie();
	bool editLive();
	template <class T> 
	bool removeTvObject(string objName, TvCollection<T>* tvCollection);
};

template <class T>
bool MainMenu::removeTvObject(string objName, TvCollection<T>* tvCollection) {
	int id;
	string choice;
	bool doLoop = true;

	if (typeid(T) == typeid(Series)) {
		this->showTvSeries();
	}
	else if (typeid(T) == typeid(Movie)) {
		this->showMovies();
	}
	else {
		this->showLives();
	}

	while (doLoop) {
		cout << "\nKtory " << objName << "  chcesz usunac? Podaj nr ID, (Q) aby anulowac: ";
		getline(cin, choice);
		if (toupper(choice[0]) == 'Q') return false;
		try {
			id = stoi(choice);
			doLoop = !(tvCollection->exist(id));
		}
		catch (const out_of_range& oor) {
			cout << "Liczba wykracza poza zakres!\n";
			doLoop = true;
		}
		catch (const invalid_argument& ia) {
			cout << "Niepoprawne argumenty\n";
			doLoop = true;
		}
		catch (...) {
			cout << "Wystapil nieoczekiwany blad, sproboj ponownie\n";
			doLoop = true;
		}
		if (doLoop) {
			cout << "Taki " << objName << " nie istnieje w twojej kolekcji!\n";
		}
	}
	*tvCollection -= tvCollection->findObject(id);
	return true;
};
#endif // !MainMenu_h
