#include "stdafx.h"
#include "Visual.h"
#define line "___________________________________________________________________________________________________"
#define space "                                       "


void Visual::header(string title) {
	system("CLS");
	cout << line << "\n" <<
		space << title << "\n\n" <<
		line << endl;
}

bool Visual::yesOrNot(string question) {
	cout << question;
	bool doLoop = 1;
	while (doLoop) {
		char choice = readChar();
		switch (choice)
		{
		case 'Y': {
			return true;
		}
		case 'N': {
			return false;
		}
		default:
			cout << "Bledna komenda, podaj y lub n: ";
			break;
		}
	}
}

void Visual::question(string question) {
	cout << question <<
		"\t(S) Seriale\n" <<
		"\t(M) Filmy\n" <<
		"\t(L) Transmisje na zywo\n\n" <<
		"WYBOR: ";
}

char Visual::readChar() {
	string input;
	getline(cin, input);
	return toupper(input[0]);
}