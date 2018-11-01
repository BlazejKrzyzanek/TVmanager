#include "stdafx.h"
#include "MainMenu.h"
#define line "___________________________________________________________________________________________________"
#define space "                                       "

MainMenu::MainMenu(string title, TvCollection<Movie>* movies, TvCollection<Series>* tvSeries, TvCollection<Live>* lives, TvCollection<TvObject>* TvObjects) {
	this->title = title;
	this->movies = movies;
	this->tvSeries = tvSeries;
	this->lives = lives;
	this->tvObjects = TvObjects;
}

void MainMenu::add_button(string b) {
	buttons.push_back(b);
}

bool MainMenu::display() {
	Visual::header(this->title); // Display header
	int length = buttons.size();
	for (int i = 0; i < length; i++) { // Display menu
		cout << "\n" <<
				space << buttons[i] << "\n" <<
				line << "\n";
	}
	cout << "\tWYBOR: ";
	char choice = Visual::readChar();
	system("CLS");
	switch (choice)
	{
	case 'A':
	{
		this->add_tv();
		break;
	}
	case 'D':
	{
		Visual::header("USUWANIE DZIELA KINEMATOGRAFII");
		this->delete_tv();
		break;
	}
	case 'E':
	{
		Visual::header("EDYCJA DZIELA KINEMATOGRAFII");
		this->edit_tv();
		break;
	}
	case 'S':
	{
		Visual::header("STATYSTYKI");
		this->statistics();
		break;
	}
	case 'R':
	{
		Visual::header("REKOMENDACJE");
		this->recommended();
		break;
	}
	case 'W':
	{
		Visual::header("WYSWIETL WSZYSTKO");
		this->show_all();
		break;
	}
	case 'Q':
	{	
		system("CLS");
		return false;
	}
	default:
		// header("Bledna komenda, sproboj ponownie");
		break;
	}
	return true;
}

void MainMenu::add_tv(){
	bool doLoop = true;
	bool state;
	while(doLoop){
		state = true;
		Visual::header("DODAWANIE NOWEGO DZIELA");
		Visual::question("Co chcesz dodac do puli?, (Q) aby anulowac: \n");
		char choice = Visual::readChar();
		switch (choice) {
		case 'S': {
			while (state){
				this->tvSeries->add_object(createSeries(0));
				state = Visual::yesOrNot("\nCzy chcesz dodac kolejny serial? y/n: ");
			}
			break;
		}
		case 'M': {
			while(state){
				this->movies->add_object(createMovie(0));
				state = Visual::yesOrNot("\nCzy chcesz dodac kolejny film? y/n: ");
			}
			break;
		}
		case 'L': {
			do {
				this->lives->add_object(createLive(0));
				state = Visual::yesOrNot("\nCzy chcesz dodac kolejna transmisje? y/n: ");
			} while (state);
			break;
		}
		case 'Q': {
			doLoop = false;
			break;
		}
		default:
			// system("CLS");
			// cout << "Bledna komenda, sprobuj ponownie.\n\n";
			break;
		}
	}
}

void MainMenu::delete_tv() {
	bool doLoop = true;
	bool state;
	while (doLoop) {
		Visual::header("USUWANIE DZIELA");
		state = true;
		Visual::question("Co chcesz usunac z puli?, (Q) aby anulowac: \n");
		char choice = Visual::readChar();
		switch (choice) {
		case 'S': {
			while(state){
				this->removeTvObject<Series>("serial", tvSeries);
				state = Visual::yesOrNot("\nCzy chcesz usunac kolejny serial? y/n: ");
			}
			break;
		}
		case 'M': {
			while (state) {
				this->removeTvObject<Movie>("film", movies);
				state = Visual::yesOrNot("\nCzy chcesz usunac kolejny film? y/n: ");
			}
			break;
		}
		case 'L': {
			while (state) {
				this->removeTvObject<Live>("live", lives);
				state = Visual::yesOrNot("\nCzy chcesz usunac kolejna transmisje? y/n: ");
			}
			break;
		}
		case 'Q': {
			doLoop = false;
			break;
		}
		default:
			// system("CLS");
			// cout << "Bledna komenda, sprobuj ponownie.\n\n";
			break;
		}
	}
}

void MainMenu::edit_tv() {
	bool doLoop = true;
	bool state;
	while (doLoop) {
		Visual::header("EDYCJA DZIELA");
		state = true;
		Visual::question("Co chcesz edytowac?, (Q) aby anulowac: \n");
		char choice = Visual::readChar();
		switch (choice) {
		case 'S': {
			while(state){
				this->editSeries();
				state = Visual::yesOrNot("\nCzy chcesz edytowac kolejny serial? y/n: ");
			}
			break;
		}
		case 'M': {
			while (state) {
				this->editMovie();
				state = Visual::yesOrNot("\nCzy chcesz edytowac kolejny film? y/n: ");
			}
			break;
		}
		case 'L': {
			while (state) {
				this->editLive();
				state = Visual::yesOrNot("\nCzy chcesz edytowac kolejny live? y/n: ");
			}
			break;
		}
		case 'Q': {
			doLoop = false;
			break;
		}
		default:
			break;
		}
	}
}

void MainMenu::statistics() {
	cout << "statystyki" << "\n";
}

void MainMenu::recommended() {
	cout << "Rekomendacje" << "\n";
}

void MainMenu::show_all() {
	Visual::question("Co chcesz wyswietlic?, (Q) aby anulowac: \n");
	char choice = Visual::readChar();
	cout << "CHAR: " << choice;
	if (choice == 'Q') return;
	switch (choice){
	case 'S': {
		this->showTvSeries();
		break;
	}
	case 'M': {
		this->showMovies();
		break;
	}
	case 'L': {
		this->showLives();
		break;
	}
	default:
		break;
	}
	cout << "Dowolny klawisz aby kontynuowac... ";
	_getch();  // FIXME
}

void MainMenu::showTvSeries() {
	Visual::header("TWOJA BAZA SERIALI");
	cout << setw(10) << "| ID |";
	cout << setw(50) << "| TYTUL |";
	cout << setw(10) << "| OCENA |";
	cout << setw(15) << "| ULUBIONY |";
	cout << setw(15) << "| ODCINKOW |";
	cout << "\n" << line << "\n";
	vector<int> width{ 10, 50, 10, 15, 15 };
	tvSeries->show_all(width);
}

void MainMenu::showMovies() {
	Visual::header("TWOJA BAZA FILMOW");
	cout << setw(10) << "| ID |";
	cout << setw(50) << "| TYTUL |";
	cout << setw(10) << "| OCENA |";
	cout << setw(15) << "| ULUBIONY |";
	cout << setw(15) << "| NA IMDB |";
	cout << "\n" << line << "\n";
	vector<int> width{ 10, 50, 10, 15, 15 };
	movies->show_all(width);
}

void MainMenu::showLives() {
	Visual::header("TWOJA BAZA TRANSMISJI LIVE");
	cout << setw(7) << "| ID |";
	cout << setw(45) << "| TYTUL |";
	cout << setw(13) << "| ULUBIONY |";
	cout << setw(20) << "| DZIEN |";
	cout << setw(15) << "| GODZINA |";
	cout << "\n" << line << "\n";
	vector<int> width{ 7,45,13,20,15 };
	lives->show_all(width);
}

Series MainMenu::createSeries(int id) {
	string title;
	int rating;
	int episodes;
	Visual::header("DODAJ NOWY SERIAL");
	do {
		cout << "Podaj tytul serialu: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		getline(cin, title);
	} while (title.length() > 50);
	do {
		cout << "Podaj ocene serialu <1-10>: ";
		cin >> rating;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (rating < 1 || rating > 10);
	cout << "Czy to Twoj ulubiony serial? y/n: ";
	char tmp;
	bool fav;
	cin >> tmp;
	cin.clear();
	if (toupper(tmp) == 'Y') {
		fav = true;
	}
	else {
		fav = false;
	}
	do {
		cout << "Ile odcinkow ma ten serial?: ";
		cin >> episodes;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (episodes < 0);

	Series series(id, title, rating, fav, episodes);
	return series;
}

Movie MainMenu::createMovie(int id) {
	string title;
	int rating;
	int imdb;
	Visual::header("DODAJ NOWY FILM");
	cout << "Podaj tytul filmu: ";
	cin.clear();
	cin.ignore(numeric_limits < streamsize >::max(), '\n');
	getline(cin, title);
	do {
		cout << "Podaj ocene filmu <1-10>: ";
		cin >> rating;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (rating < 1 || rating > 10);
	cout << "Czy to Twoj ulubiony film? y/n: ";
	char tmp;
	bool fav;
	cin >> tmp;
	cin.clear();
	if (toupper(tmp) == 'Y') {
		fav = true;
	}
	else {
		fav = false;
	}
	do {
		cout << "Podaj miejsce w rankingu IMDb: ";
		cin >> imdb;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (imdb < 0);

	Movie movie(id, title, rating, fav, imdb);
	return movie;
}

Live MainMenu::createLive(int id) {
	string title;
	int day;
	int hour;
	Visual::header("DODAJ NOWY LIVE");
	cout << "Podaj tytul live: ";
	cin.clear();
	cin.ignore(numeric_limits < streamsize >::max(), '\n');
	getline(cin, title);
	do {
		cout << "Podaj dzien ktorego odbedzie sie transmisja (1 = poniedzialek, ..., 7 = niedziela): ";
		cin >> day;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (day < 1 || day > 7);
	do {
		cout << "Podaj godzine o ktorej odbedzie sie transmisja (0-23): ";
		cin >> hour;
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
	} while (hour < 0 || hour > 23);
	cout << "Czy zalezy ci na tym live? y/n: ";
	char tmp;
	bool fav;
	cin >> tmp;
	cin.clear();
	if (toupper(tmp) == 'Y') {
		fav = true;
	}
	else {
		fav = false;
	}
	Live live(id, title, fav, day, hour);
	return live;
}

// MERGE THEESE 
void MainMenu::editSeries() {
	this->showTvSeries();
	string choice;
	int id;
	bool doLoop = true;
	while(doLoop) {
		cout << "\nKtory serial chcesz edytowac? Podaj nr ID, (Q) aby anulowac: ";
		getline(cin, choice);
		if (toupper(choice[0]) == 'Q') return;
		try {
			id = stoi(choice);
			doLoop = !(this->tvSeries->exist(id));
		}
		catch (...) {
			doLoop = true;
		}
		if (doLoop) {
			cout << "Taki serial nie istnieje w twojej kolekcji!\n";
		}
		Series mySeries = createSeries(id);
		this->tvSeries->edit_object(mySeries);
		tvSeries->save();
	}
}

void MainMenu::editMovie() {
	this->showMovies();
	string choice;
	int id;
	bool doLoop = true;
	while (doLoop) {
		cout << "\nKtory film chcesz edytowac? Podaj nr ID, (Q) aby anulowac: ";
		getline(cin, choice);
		if (toupper(choice[0]) == 'Q') return;
		try {
			id = stoi(choice);
			doLoop = !(this->movies->exist(id));
		}
		catch (...) {
			doLoop = true;
		}
		if (doLoop) {
			cout << "Taki serial nie istnieje w twojej kolekcji!\n";
		}
		Movie myMovie = createMovie(id);
		this->movies->edit_object(myMovie);
		tvSeries->save();
	}
}

void MainMenu::editLive() {
	this->showLives();
	string choice;
	int id;
	bool doLoop = true;
	while (doLoop) {
		cout << "\nKtory live chcesz edytowac? Podaj nr ID, (Q) aby anulowac: ";
		getline(cin, choice);
		if (toupper(choice[0]) == 'Q') return;
		try {
			id = stoi(choice);
			doLoop = !(this->lives->exist(id));
		}
		catch (...) {
			doLoop = true;
		}
		if (doLoop) {
			cout << "Taki live nie istnieje w twojej kolekcji!\n";
		}
		Live myLive = createLive(id);
		this->lives->edit_object(myLive);
		tvSeries->save();
	}
}


// ERROR CHECKING cin.fail();