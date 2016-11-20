/*
Title			: name.h
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: This is the interface (specification) for the contact class
Modifications	:
Notes		: 
*/

#include "name.h"

string Name::first()
{
	return fname;
}

string Name::last()
{
	return lname;
}

void Name::setFirst(string firstname)
{
	fname = firstname;
}

void Name::setLast(string lastname)
{
	lname = lastname;
}
