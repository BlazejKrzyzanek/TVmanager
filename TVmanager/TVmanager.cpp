// TVmanager.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <vector>

#include "MainMenu.h"
#include "TvObject.h"
#include "TvCollection.h"


int main()
{
	vector<string> buttons;
	buttons.push_back("(A) DODAJ");
	buttons.push_back("(D) USUN");
	buttons.push_back("(E) EDYTUJ");
	buttons.push_back("(S) WYSWIETL STATYSTYKI");
	buttons.push_back("(R) REKOMENDACJE");
	buttons.push_back("(K) WYJDZ Z PROGRAMU");
	MainMenu menu(buttons);

	TvObject film1("teletubisie na wojnie", 5, 50);
	TvObject film2("terminator 45", 3, 123);
	TvObject film3("superman 6", 1, 332);

	TvCollection<TvObject> movies;
	movies.add_object(film1);
	movies.add_object(film2);
	movies.add_object(film3);

	movies.remove_object("terminator 45");
	movies.display_all();

	// Main loop
	int state = true;
	while (state)
	{
		state = menu.display();
	} 
    return 0;
}

