#ifndef Movie_h
#define Movie_h
#include <string>
#include <vector>
using namespace std;

class Movie : public TvObject {
private:
	int imdbRank;
public:
	Movie(int id, string title, int rating, bool favourite, int imdbRank) : TvObject(id, title, rating, favourite) { this->imdbRank = imdbRank; };
	void setImdbRank(int rank);
	int getImdbRank();
	string tvToString();
	vector<string> showFields();
};
#endif // !Movie_h
