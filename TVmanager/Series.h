#ifndef Series_h
#define Series_h
#include <string>
#include <vector>
using namespace std;

class Series : public TvObject {
private:
	int episodes;
public:
	Series() {};
	Series(int id, string title, int rating, bool favourite, int episodes) : TvObject(id, title, rating, favourite) { this->episodes = episodes; };
	void setEpisodes(int episodes);
	int getEpisodes();
	string tvToString();
	vector<string> showFields();
};
#endif // !Series_h
