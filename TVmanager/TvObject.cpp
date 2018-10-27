#include "stdafx.h"
#include "TvObject.h"

TvObject::TvObject(string t, int r, int len) {
	title = t;
	rating = r;
	length = len;
}

void TvObject::setTitle(string t) {
	title = t;
}

string TvObject::getTitle() {
	return title;
}

void TvObject::setLength(int len) {
	length = len;
}

int TvObject::getLength() {
	return length;
}

void TvObject::setRating(int r) {
	rating = r;
}

int TvObject::getRating() {
	return rating;
}