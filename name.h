
/*
Title			: name.h
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: This is the interface (specification) for the name class
Modifications	:
Notes		: This class is not documented because the methods are simple accessors and mutators.
*/

#ifndef NAME_H
#define NAME_H


#include <string>
using namespace std;

class Name {
private:
	/* Data members*/
	string fname;
	string lname;

public:
	string first();
	string last();
	void setFirst(string firstname);
	void setLast(string lastname);

};




#endif
