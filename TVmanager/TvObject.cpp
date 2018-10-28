#include "stdafx.h"
#include "TvObject.h"

TvObject::TvObject(int id, string title) {
	TvObject(id, title, false);
}

TvObject::TvObject(int id, string title, bool favourite) {
	TvObject(id, title, -1, favourite);
}

TvObject::TvObject(int id, string title, int rating) {
	TvObject(id, title, rating, false);
}

TvObject::TvObject(int id, string title, int rating, bool favourite) {
	this->id = id;
	this->title = title;
	this->rating = rating;
	this->favourite = favourite;
}

void TvObject::setTitle(string t) {
	title = t;
}

string TvObject::getTitle() {
	return this->title;
}

void TvObject::setRating(int r) {
	this->rating = r;
}

int TvObject::getRating() {
	return this->rating;
}

void TvObject::setId(int i) {
	this->id = i;
}

int TvObject::getId() {
	return this->id;
}

void TvObject::setFavourite(bool f) {
	this->favourite = f;
}

bool TvObject::getFavourite() {
	return this->favourite;
}

string TvObject::tvToString() {
	string text;
	text.append(to_string(this->getId()));
	text.append("\t");
	text.append(this->getTitle());
	text.append("\t");
	text.append(to_string(this->getRating()));
	text.append("\t");
	text.append(to_string(this->getFavourite() ? 1 : 0));
	text.append("\n");
	return text;
}

vector<string> TvObject::showFields() {
	vector<string> data;
	data.push_back(to_string(this->getId()));
	data.push_back(this->getTitle());
	data.push_back(to_string(this->getRating()));
	data.push_back(this->getFavourite() ? "tak" : "nie");
	return data;
}