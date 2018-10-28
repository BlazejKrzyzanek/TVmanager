#include "stdafx.h"
#include "MainMenu.h"
#define line "___________________________________________________________________________________________________"
#define space "                                       "

MainMenu::MainMenu(string title, TvCollection<Movie>* movies, TvCollection<Series>* tvSeries, TvCollection<Live>* lives) {
	this->title = title;
	this->movies = movies;
	this->tvSeries = tvSeries;
	this->lives = lives;


}

void MainMenu::add_button(string b) {
	buttons.push_back(b);
}

bool MainMenu::display() {
	this->header(this->title);
	int length = buttons.size();
	for (int i = 0; i < length; i++) {
		cout << "\n" <<
				space << buttons[i] << "\n" <<
				line << "\n";
	}
	cout << "\tWYBOR: ";
	char* choice = new char[1]; // reading first char instead of all
	cin >> choice;
	// clear console
	system("CLS");
	switch (toupper(choice[0]))
	{
	case 'A':
	{
		header("DODAWANIE NOWEGO DZIELA");
		this->add_tv();
		break;
	}
	case 'D':
	{
		header("USUWANIE DZIELA KINEMATOGRAFI");
		this->delete_tv();
		break;
	}
	case 'E':
	{
		header("EDYCJA DZIELA KINEMATOGRAFI");
		this->edit_tv();
		break;
	}
	case 'S':
	{
		header("STATYSTYKI");
		this->statistics();
		break;
	}
	case 'R':
	{
		header("REKOMENDACJE");
		this->recommended();
		break;
	}
	case 'W':
	{
		header("WYSWIETL WSZYSTKO");
		this->show_all();
		break;
	}
	case 'Q':
	{	
		system("CLS");
		return false;
	}
	default:
		//header("Bledna komenda, sproboj ponownie");
		break;
	}
	return true;
}

void MainMenu::add_tv(){
	char choice = question("dodac");
	if (choice == 'Q') return;
	switch (toupper(choice)) {
	case 'S': {
		bool state;
		do {
			this->tvSeries->add_object(createSeries(0));
			state = menuAnother("\nCzy chcesz dodac kolejny serial? y/n: ");
		} while (state);
		break;
	}
	case 'M': {
		bool state;
		do {
			this->movies->add_object(createMovie(0));
			state = menuAnother("\nCzy chcesz dodac kolejny film? y/n: ");
		} while (state);
		break;
	}
	case 'L': {
		bool state;
		do {
			this->lives->add_object(createLive(0));
			state = menuAnother("\nCzy chcesz dodac kolejna transmisje? y/n: ");
		} while (state);
		break;
	}
	default:
		cout << "Bledna komenda";
		break;
	}
	
}

void MainMenu::delete_tv() {
	char choice = question("usunac");
	if (choice == 'Q') return;
	switch (toupper(choice)) {
	case 'S': {
		bool state; // FIX ME
		do {
			this->removeSeries();
			state = menuAnother("\nCzy chcesz usunac kolejny serial? y/n: ");
		} while (state);
		break;
	}
	case 'M': {
		int id;
		bool state = true;
		while (state) {
			this->showMovies();
			cout << "\nKtory film chcesz usunac? Podaj nr ID, -1 aby anulowac: ";
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
		break;
	}
	case 'L': {
		// TODO
		break;
	}
	default:
		cout << "Bledna komenda";
		break;
	}
	

}

void MainMenu::edit_tv() {
	header("EDYCJA DZIELA");
	char choice = question("edytowac");
	switch (choice){
	case 'S': {
		bool state;
		do {
			this->showTvSeries();
			int id;
			do {
				cout << "Podaj id serialu do edycji: ";
				cin >> id;
				cin.clear();
			} while (this->tvSeries->not_exist(id));
			Series myseries = createSeries(id);  // EDIT
			cout << myseries.getTitle() << "\n";
			this->tvSeries->edit_object(myseries);
			tvSeries->save();
			state = menuAnother("\nCzy chcesz edytowac kolejny serial? y/n: ");
		} while (state);
		break;
	}
	case 'M': {
		this->showMovies();
		int id;
		do {
			cout << "Podaj id filmu do edycji: ";
			cin >> id;
			cin.clear();
		} while (this->movies->not_exist(id));
		this->movies->edit_object(createMovie(0));
		break;
	}
	case 'L': {
		this->showLives();
		int id;
		do {
			cout << "Podaj id transmisji do edycji: ";
			cin >> id;
			cin.clear();
		} while (this->lives->not_exist(id));
		this->lives->edit_object(createLive(0));
		break;
	}
	default:
		break;
	}
}

void MainMenu::statistics() {
	cout << "statystyki" << "\n";
}

void MainMenu::recommended() {
	cout << "Rekomendacje" << "\n";
}

void MainMenu::show_all() {
	char choice = question("wyswietlic");
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

char MainMenu::question(string action) {
	char choice;
	do {
		cout << "Co chcesz " << action <<"?, (Q) aby anulowac:\n" <<
			"\t(S) Seriale\n" <<
			"\t(M) Filmy\n" <<
			"\t(L) Transmisje na zywo\n\n" <<
			"WYBOR: ";
		cin >> choice;
		choice = toupper(choice);
	} while (!(choice == 'S' || choice == 'M' || choice == 'L' || choice == 'Q'));
	return choice;
}

void MainMenu::header(string title) {
	system("CLS");
	cout << line << "\n" <<
		space << title << "\n\n" <<
		line << endl;
}

void MainMenu::showTvSeries() {
	header("TWOJA BAZA SERIALI");
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
	header("TWOJA BAZA FILMOW");
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
	header("TWOJA BAZA TRANSMISJI LIVE");
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
	this->header("DODAJ NOWY SERIAL");
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
	this->header("DODAJ NOWY FILM");
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
	this->header("DODAJ NOWY LIVE");
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

bool MainMenu::menuAnother(string question) {
	cout << question;
	char tmp;
	cin >> tmp;
	cin.clear();
	if (toupper(tmp) == 'Y') {
		return true;
	}
	else {
		cout << "Nie to nie :)\n";
		return false;
	}
}

void MainMenu::removeSeries() {
	int state;
	int id;
	int notRemoved;
	this->showTvSeries();
	do {
		cout << "\nKtory serial chcesz usunac? Podaj nr ID, -1 aby anulowac: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		cin >> id;
		if (id == -1) return;
		notRemoved = this->tvSeries->remove_object(id);
		if (notRemoved) {
			cout << "Taki serial nie istnieje w twojej kolekcji\n";
		}
	} while (notRemoved);
}

void MainMenu::removeMovie() {
	int state;
	int id;
	int notRemoved;
	do {
		this->showMovies();
		cout << "\nKtory film chcesz usunac? Podaj nr ID, -1 aby anulowac: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		cin >> id;
		notRemoved = this->movies->remove_object(id);
		if (notRemoved) {
			cout << "Taki film nie istnieje w twojej kolekcji\n";
		}
	} while (notRemoved);
}

void MainMenu::removeLive() {
	int state;
	int id;
	int notRemoved;
	do {
		this->showLives();
		cout << "\nKtora transmisje chcesz usunac? Podaj nr ID, -1 aby anulowac: ";
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		cin >> id;
		notRemoved = this->lives->remove_object(id);
		if (notRemoved) {
			cout << "Taka transmisja nie istnieje w twojej kolekcji\n";
		}
	} while (notRemoved);
}