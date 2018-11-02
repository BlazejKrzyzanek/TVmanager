#ifndef TvObject_h
#define TvObject_h

#include <string>
#include <vector>
using namespace std;

class TvObject {
protected:
	int id;
	string title;
	int rating;
	bool favourite;
public:
	TvObject() {};
	TvObject(int id, string title);
	TvObject(int id, string title, bool favourite);
	TvObject(int id, string title, int rating);
	TvObject(int id, string title, int rating, bool favourite);
	void setId(int id);
	int getId();
	void setTitle(string title);
	string getTitle();
	void setRating(int rating);
	int getRating();
	void setFavourite(bool favourite);
	bool getFavourite();
	virtual string tvToString();
	virtual vector<string> showFields();
};
#endif // !TvObject_h
