#include "stdafx.h"
#include "Series.h"

void Series::setEpisodes(int e) {
	this->episodes = e;
}

int Series::getEpisodes() {
	return this->episodes;
}

string Series::tvToString() {
	string text;
	text.append(to_string(this->getId()));
	text.append("\t");
	text.append(this->getTitle());
	text.append("\t");
	text.append(to_string(this->getRating()));
	text.append("\t");
	text.append(to_string(this->getFavourite() ? 1 : 0)); // NEED checking
	text.append("\t");
	text.append(to_string(this->getEpisodes()));
	text.append("\n");
	return text;
}

vector<string> Series::showFields() {
	vector<string> data;
	data.push_back(to_string(this->getId()));
	data.push_back(this->getTitle());
	data.push_back(to_string(this->getRating()));
	data.push_back(this->getFavourite() ? "tak" : "nie");
	data.push_back(to_string(this->getEpisodes()));
	return data;
}