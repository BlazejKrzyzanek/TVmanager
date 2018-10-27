#include "stdafx.h"
#include "TvObject.h"

TvObject::TvObject(int i, string t, int r, int yr) {
	id = i;
	title = t;
	rating = r;
	year = yr;
}

void TvObject::setTitle(string t) {
	title = t;
}

string TvObject::getTitle() {
	return title;
}

void TvObject::setYear(int yr) {
	year = yr;
}

int TvObject::getYear() {
	return year;
}

void TvObject::setRating(int r) {
	rating = r;
}

int TvObject::getRating() {
	return rating;
}

void TvObject::setId(int i) {
	id = i;
}

int TvObject::getId() {
	return id;
}