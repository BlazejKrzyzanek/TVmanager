#ifndef MainMenu_h
#define MainMenu_h
#include "TvObject.h"
#include "Movie.h"
#include "Series.h"
#include "Live.h"
#include "TvCollection.h"
#include "Visual.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib> 
#include <conio.h>
#include <typeinfo>

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
	void editSeries();
	void editMovie();
	void editLive();
	template <class T> 
	void removeTvObject(string objName, TvCollection<T>* tvCollection) {
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
			cout << "\nKtory "<< objName << "  chcesz usunac? Podaj nr ID, (Q) aby anulowac: ";
			getline(cin, choice);
			if (toupper(choice[0]) == 'Q') return;
			try {
				id = stoi(choice);
				doLoop = !(tvCollection->exist(id));
			}
			catch (...) {
				doLoop = true;
			}
			if (doLoop) {
				cout << "Taki " << objName << " nie istnieje w twojej kolekcji!\n";
			}
		}
		*tvCollection -= tvCollection->findObject(id);
	};
};
#endif // !MainMenu_h
