#ifndef TvObject_h
#define TvObject_h

#include <string>
using namespace std;

class TvObject {
protected:
	string title;
	int id;
	int year;
	int rating;
public:
	TvObject(int id, string title, int rating, int year);
	void setId(int id);
	int getId();
	void setTitle(string title);
	string getTitle();
	void setYear(int year);
	int getYear();
	void setRating(int rating);
	int getRating();
};
#endif // !TvObject_h
