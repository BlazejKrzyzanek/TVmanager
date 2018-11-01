#include "stdafx.h"
#include "TvObject.h"
#include "Movie.h"

void Movie::setImdbRank(int r) {
	this->imdbRank = r;
}

int Movie::getImdbRank() {
	return this->imdbRank;
}

string Movie::tvToString() {
	string text;
	text.append(to_string(this->getId()));
	text.append("\t");
	text.append(this->getTitle());
	text.append("\t");
	text.append(to_string(this->getRating()));
	text.append("\t");
	text.append(to_string(this->getFavourite() ? 1 : 0)); // NEED checking
	text.append("\t");
	text.append(to_string(this->getImdbRank()));
	text.append("\n");
	return text;
}

vector<string> Movie::showFields() {
	vector<string> data;
	data.push_back(to_string(this->getId()));
	data.push_back(this->getTitle());
	data.push_back(to_string(this->getRating()));
	data.push_back(this->getFavourite() ? "tak" : "nie");
	data.push_back(to_string(this->getImdbRank()));
	return data;
}