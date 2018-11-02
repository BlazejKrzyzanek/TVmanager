#ifndef Visual_h
#define Visual_h
#include <string>
#include <iostream>
using namespace std;

class Visual {
public:
	static void header(string header);
	static void question(string question); 
	static bool yesOrNot(string question);
	static char readChar();
	static int readInt(string question);
};

#endif // !Visual_h
