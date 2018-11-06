#ifndef MyException_h
#define  MyException_h
#include <string>
using namespace std;

class MyException {
private:
	string message;
public:
	MyException(string message);
	string getMessage();
};
#endif // !MyException_h

