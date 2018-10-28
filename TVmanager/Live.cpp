#include "stdafx.h"
#include "Live.h"


void Live::setDay(int day) {
	this->day = day;
}

int Live::getDay() {
	return this->day;
}

void Live::setHour(int hour) {
	if (0 <= hour < 24)
		this->hour = hour;
	else this->hour = 0;
}

int Live::getHour() {
	return this->hour;
}

string Live::tvToString() {
	string text;
	text.append(to_string(this->getId()));
	text.append("\t");
	text.append(this->getTitle());
	text.append("\t");
	text.append(to_string(this->getFavourite() ? 1 : 0));
	text.append("\t");
	text.append(to_string(this->getDay()));
	text.append("\t");
	text.append(to_string(this->getHour()));
	text.append("\n");
	return text;
}

vector<string> Live::showFields() {
	vector<string> data;
	string day;
	int iDay = this->getDay();
	switch (iDay) {
	case 1: 
		day = "poniedzialek";
		break;
	case 2:
		day = "wtorek";
		break;
	case 3:
		day = "sroda";
		break;
	case 4:
		day = "czwartek";
		break;
	case 5:
		day = "piatek";
		break;
	case 6:
		day = "sobota";
		break;
	case 7:
		day = "niedziela";
	default:
		day = "niezdefiniowany";
		break;
	}
	string hour;
	hour.append(to_string(this->getHour()));
	hour.append(":00");

	data.push_back(to_string(this->getId()));
	data.push_back(this->getTitle());
	data.push_back(this->getFavourite() ? "tak" : "nie");
	data.push_back(day);
	data.push_back(hour);
	return data;
}