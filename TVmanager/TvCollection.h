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
public:
	int read_file(string filename) {
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
		file.close();
		return 0;
	}
	int save() {
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
	void add_object(T obj) { 
		obj.setId(maxId++);
		tvObjects.push_back(obj); 
	}
	bool remove_object(int id) {
		for (int i = 0; i < tvObjects.size(); i++) {
			if (id == tvObjects[i].getId()) {
				tvObjects.erase(tvObjects.begin() + i);
				return true;
			}
			else continue;
		}
		return false;
	}
	void show_all(vector<int> textFields) {
		for (int i = 0; i < tvObjects.size(); i++) {
			vector<string> data = tvObjects[i].showFields();
			for (int j = 0; j < textFields.size(); j++) {
				cout << setw(textFields[j]) << data[j];
			}
			cout << "\n";
		}
	}
	bool exist(int id) {
		for (int i = 0; i < tvObjects.size(); i++) {
			if (id == tvObjects[i].getId())
				return true;
			else continue;
		}
		return false;
	}
	void edit_object(T obj) {
		int id = obj.getId();
		for (int i = 0; i < tvObjects.size(); i++) {
			if (id == tvObjects[i].getId()) {
				tvObjects.at(i) = obj;
			}
			else continue;
		}
	}
};
#endif // !TvCollection_h
