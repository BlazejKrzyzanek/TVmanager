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
	TvCollection<TvObject> movies;
	movies.read_file("movies.txt");

	MainMenu menu("TV MANAGER", &movies);
	menu.add_button("(A) DODAJ");
	menu.add_button("(D) USUN");
	menu.add_button("(E) EDYTUJ");
	menu.add_button("(W) WSZYSTKIE");
	menu.add_button("(S) STATYSTYKI");
	menu.add_button("(R) REKOMENDACJE");
	menu.add_button("(K) WYJDZ Z PROGRAMU");

	// Main loop
	bool state = true;
	while (state)
	{
		state = menu.display();
		movies.save("movies.txt");
		cout << "\nPliki sa aktualne\n";
	} 
    return 0;
}

