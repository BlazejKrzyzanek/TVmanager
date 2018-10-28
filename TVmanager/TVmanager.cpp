// TVmanager.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <vector>

#include "MainMenu.h"
#include "TvObject.h"
#include "Movie.h"
#include "Series.h"
#include "Live.h"
#include "TvCollection.h"


int main()
{
	TvCollection<Movie> movies;
	TvCollection<Series> tvSeries;
	TvCollection<Live> lives;
	movies.read_file("movies.txt");
	tvSeries.read_file("tvSeries.txt");
	lives.read_file("lives.txt");

	MainMenu menu("TV MANAGER", &movies, &tvSeries, &lives);
	menu.add_button("(A) DODAJ");
	menu.add_button("(D) USUN");
	menu.add_button("(E) EDYTUJ");
	menu.add_button("(W) WSZYSTKIE");
	menu.add_button("(S) STATYSTYKI");
	menu.add_button("(R) REKOMENDACJE");
	menu.add_button("(Q) WYJDZ Z PROGRAMU");

	// Main loop
	bool state = true;
	while (state)
	{
		state = menu.display();
		movies.save();
		tvSeries.save();
		lives.save();
		cout << "\nPliki sa aktualne\n";
	}
    return 0;
}

