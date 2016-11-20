

/*
Title			: contact.h
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: This is the implementation for the contact class
Modifications	:
Notes		: 
*/

#include "contact.h"

Contact::Contact()
{
}
Contact::Contact(Name person, string telNum, string emailAddr)
{
	name.setFirst(person.first());
	name.setLast(person.last());
	telephone = telNum;
	email = emailAddr;
}

void Contact::set(string fname, string lname, string telNum, string emailAddr)
{
	name.setFirst(fname);
	name.setLast(lname);
	telephone = telNum;
	email = emailAddr;
}

void Contact::getName(Name &fullname)
{
	fullname.setFirst(name.first());
	fullname.setLast((name.last()));
}

void Contact::getTel(string &telNum)
{
	telNum = telephone;
}

void Contact::getEmail(string &emailAddr)
{
	emailAddr = email;
}

void Contact::setName(Name fullname)
{
	name.setFirst(fullname.first());
	name.setLast(fullname.last());
}

void Contact::setTel(string tellNum)
{
	telephone = tellNum;
}

void Contact::setEmail(string emailAddr)
{
	email = emailAddr;
}


