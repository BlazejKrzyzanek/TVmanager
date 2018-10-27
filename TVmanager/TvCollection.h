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
public:
	int read_file(string filename) {
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
			int maxId = 0;
			vector<string> tokens;
			istringstream iss(line);
			string token;
			while (getline(iss, token, '\t')) {
				tokens.push_back(token);
			}
			int tokens_length = tokens.size();
			switch (tokens_length)
			{
			case 4: {
				int tmpId = stoi(tokens[0]);
				T tmp(tmpId, tokens[1], stoi(tokens[2]), stoi(tokens[3]));
				if (tmpId > maxId) {
					maxId = tmpId;
				}
				tvObjects.push_back(tmp);
				break;
			}
			case 5: {
				// T tmp(tokens[0], stoi(tokens[1]), stoi(tokens[2]), stoi(tokens[3]));
				// tvObjects.push_back(tmp);
				break;
			}
			default:
				return 1;
				break;
			}

		}
		file.close();
		return 0;
	}

	int save(string filename) {
		ofstream file;
		try {
			file.open(filename, ios::in | ios::trunc);
			for (int i = 0; i < tvObjects.size(); i++) {
				file << tvObjects[i].getId() << "\t" << tvObjects[i].getTitle() << "\t" << tvObjects[i].getRating() << "\t" << tvObjects[i].getYear() << "\n";
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
	int remove_object(int id) {
		for (int i = 0; i < tvObjects.size(); i++) {
			if (id == tvObjects[i].getId()) {
				// movies with the same title!?
				tvObjects.erase(tvObjects.begin() + i);
				return 0;
			}
			else continue;
		}
		return 1;
	}
	void show_all() {
		cout << setw(6) << "| ID |";
		cout << setw(35) << "| TYTUL |";
		cout << setw(15) << "| OCENA |";
		cout << setw(15) << "| ROK |";
		cout << "\n";
		for (int i = 0; i < tvObjects.size(); i++) {
			cout << setw(6) << tvObjects[i].getId();
			cout << setw(35) << tvObjects[i].getTitle();
			cout << setw(15) << tvObjects[i].getRating();
			cout << setw(15) << tvObjects[i].getYear();
			cout << "\n";
		}
	}

};
#endif // !TvCollection_h
