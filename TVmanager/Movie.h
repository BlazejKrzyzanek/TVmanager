#ifndef Movie_h
#define Movie_h

#include "TvObject.h"

class Movie : public TvObject {
private:
	int imdbRank;
public:
	void setImdbRank(int rank);
	int getImdbRank();
};
#endif // !Movie_h
