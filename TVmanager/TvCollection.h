#pragma once
#ifndef TvCollection_h
#define TvCollection_h
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
class TvCollection {
private:
	vector<T> tvObjects;
public:
	void add_object(T obj) { tvObjects.push_back(obj); }
	void remove_object(string title) {
		for (int i = 0; i < tvObjects.size(); i++) {
			if (!title.compare(tvObjects[i].getTitle())) {
				// EXCEPTIONS
				tvObjects.erase(tvObjects.begin() + i);
				return;
			}
			else continue;
		}
	}
	void display_all() {

		cout << setw(35) << "| TYTUL |";
		cout << setw(15) << "| OCENA |";
		cout << setw(15) << "| DLUGOSC |";
		cout << "\n";
		cout << "_________________________________________________________________" << "\n";
		for (int i = 0; i < tvObjects.size(); i++) {
			cout << setw(35) << tvObjects[i].getTitle();
			cout << setw(15) << tvObjects[i].getRating();
			cout << setw(15) << tvObjects[i].getLength();
			cout << "\n";
		}
	}


};
#endif // !TvCollection_h
