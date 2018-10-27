#ifndef TvObject_h
#define TvObject_h

#include <string>
using namespace std;

class TvObject {
protected:
	string title;
	int length;
	int rating;
public:
	TvObject(string title, int rating, int length);
	void setTitle(string title);
	string getTitle();
	void setLength(int length);
	int getLength();
	void setRating(int rating);
	int getRating();
};
#endif // !TvObject_h
