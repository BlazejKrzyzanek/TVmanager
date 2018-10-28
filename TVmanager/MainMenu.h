#ifndef MainMenu_h
#define MainMenu_h
#include "TvObject.h"
#include "Movie.h"
#include "Series.h"
#include "Live.h"
#include "TvCollection.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib> 
#include <conio.h>

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
	void add_button(string button_name);
	bool display();
private:
	void header(string title);
	char question(string action);
	bool menuAnother(string type);
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
	void removeSeries();
	void removeMovie();
	void removeLive();


};
#endif // !MainMenu_h
