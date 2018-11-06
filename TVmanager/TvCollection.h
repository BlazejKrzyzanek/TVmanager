#pragma once
#ifndef TvCollection_h
#define TvCollection_h
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
class TvCollection {
private:
	vector<T> tvObjects;
	int maxId = 0;
	string filename;
	void quicksort(int l, int r, char key);
	int partition(int l, int r, char key);
public:
	int read_file(string filename);
	int save();

	TvCollection<T> & operator +=(T & obj) {
		obj.setId(maxId++);
		tvObjects.push_back(obj);
		return *this;
	}
	TvCollection<T> & operator -=(T & obj) {
		int id = obj.getId();
		for (int i = 0; i < tvObjects.size(); i++) {
			if (id == tvObjects[i].getId()) {
				tvObjects.erase(tvObjects.begin() + i);
			}
		}
		return *this;
	}
	bool remove_object(int id);
	void show_all(vector<int> textFields);
	bool exist(int id);
	T findObject(int id);
	T getObject(int pos);
	void edit_object(T obj);
	int getLength();
	void sortCollection(char choice);
};

template<class T>
int TvCollection<T>::read_file(string filename) {
	this->filename = filename;
	ifstream file;
	try {
		file.open(filename);
	}
	catch (...) {
		cout << "Error when loading a file";
		return 1;
	}
	string line;
	while (getline(file, line)) {
		vector<string> tokens;
		istringstream iss(line);
		string token;
		while (getline(iss, token, '\t')) {
			tokens.push_back(token);
		}
		//  MOVIE: int id, string title, int rating, bool favourite, int imdbRank
		// SERIES: int id, string title, int rating, bool favourite, int episodes
		//	 LIVE: int id, string title, bool favourite, int day, int hour;
		int tmpId = stoi(tokens[0]);
		T tmp(tmpId, tokens[1], stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]));
		this->tvObjects.push_back(tmp);
		if (tmpId >= this->maxId) {
			this->maxId = tmpId + 1;
		}

	}
}

template<class T>
int TvCollection<T>::save() {
	ofstream file;
	try {
		file.open(this->filename, ios::in | ios::trunc);
		for (int i = 0; i < this->tvObjects.size(); i++) {
			file << this->tvObjects[i].tvToString();
		}
	}
	catch (...) {
		cout << "write error\n";
		return 1;
	}
	return 0;
}

template<class T>
bool TvCollection<T>::remove_object(int id) {
	for (int i = 0; i < tvObjects.size(); i++) {
		if (id == tvObjects[i].getId()) {
			tvObjects.erase(tvObjects.begin() + i);
			return true;
		}
		else continue;
	}
	return false;
}

template<class T>
void TvCollection<T>::show_all(vector<int> textFields) {
	for (int i = 0; i < tvObjects.size(); i++) {
		vector<string> data = tvObjects[i].showFields();
		for (int j = 0; j < textFields.size(); j++) {
			cout << setw(textFields[j]) << data[j];
		}
		cout << "\n";
	}
}

template<class T>
bool  TvCollection<T>::exist(int id) {
	for (int i = 0; i < tvObjects.size(); i++) {
		if (id == tvObjects[i].getId())
			return true;
		else continue;
	}
	return false;
}

template<class T>
T TvCollection<T>::findObject(int id) {
	for (int i = 0; i < tvObjects.size(); i++) {
		if (id == tvObjects[i].getId())
			return tvObjects[i];
		else continue;
	}
	T *p = NULL;
	return *p;
}

template<class T>
T TvCollection<T>::getObject(int i) {
	return tvObjects[i];
}

template<class T>
void TvCollection<T>::edit_object(T obj) {
	int id = obj.getId();
	for (int i = 0; i < tvObjects.size(); i++) {
		if (id == tvObjects[i].getId()) {
			tvObjects.at(i) = obj;
		}
		else continue;
	}
}

template<class T>
int TvCollection<T>::getLength() {
	return this->tvObjects.size();
}

template<class T>
void TvCollection<T>::sortCollection(char key) {
		quicksort(0, tvObjects.size() - 1, key);
}

template<class T>
void TvCollection<T>::quicksort(int l, int r, char key) {
	int p;
	if (l < r) {
		p = TvCollection<T>::partition( l, r, key);
		TvCollection<T>::quicksort(l, p, key);
		TvCollection<T>::quicksort(p+1, r, key);
	}
}

template<class T>
int TvCollection<T>::partition(int l, int r, char key) {
	if (key == 'I') {
		int x = tvObjects[l].getId();
		int i = l, j = r;
		T w;
		while (true)
		{
			while (tvObjects[j].getId() > x)
				j--;
			while (tvObjects[i].getId() < x)
				i++;
			if (i < j) {
				w = tvObjects[i];
				tvObjects[i] = tvObjects[j];
				tvObjects[j] = w;
				i++;
				j--;
			}
			else
				return j;
		}
	}
	else if (key == 'R') {
		int x = tvObjects[l].getRating();
		int i = l, j = r;
		T w;
		while (true)
		{
			while (tvObjects[j].getRating() < x)
				j--;
			while (tvObjects[i].getRating() > x)
				i++;
			if (i < j) {
				w = tvObjects[i];
				tvObjects[i] = tvObjects[j];
				tvObjects[j] = w;
				i++;
				j--;
			}
			else
				return j;
		}
	}
}
#endif // !TvCollection_h
