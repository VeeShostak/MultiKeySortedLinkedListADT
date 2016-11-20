
/*
Title			: contact.h
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: This is the interface (specification) for the contact class.
              It incorporates the Name class as a  private variable
Modifications	:
Notes		: This class is not documented because the methods are simple accessors and mutators.
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

#include "name.h"
using namespace std;

class Contact {
private:
	Name name;
	string telephone;
	string email;
	
	//// point to next node
	//Contact* next;
	//int size;



public:
	// default constructor
	Contact();

	// constructor sets private members name, telephone, and email
	Contact(Name person, string telNum, string emailAddr);

	void set(string fname, string lname, string telNum, string emailAddr);

	void getName(Name &fullname);

	void getTel(string &telNum);

	void getEmail(string &emailAddr);

	void setName(Name fullname);

	void setTel(string tellNum);

	void setEmail(string emailAddr);

	//// inline - setter
	//void setnext(contact* node)
	//{
	//	next = node;
	//}

	//// inline - accessor
	//contact* getnext() {
	//	return next;
	//}

	//// inline - accessor
	//int getsize() {
	//	return size;
	//}
	//
	
};




#endif
