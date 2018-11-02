#ifndef Live_h
#define Live_h
#include <string>
#include <vector>
using namespace std;

class Live : public TvObject {
private:
	int day;
	int hour;
public:
	Live() {};
	Live(int id, string title, bool favourite, int day, int hour) : TvObject(id, title, -1, favourite) {
		this->day = day;
		this->hour = hour;
	};
	void setDay(int day);
	int getDay();
	void setHour(int hour);
	int getHour();
	string tvToString();
	vector<string> showFields();
};
#endif // !Live_h
