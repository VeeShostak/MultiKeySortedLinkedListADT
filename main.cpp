
/*
Title			: main.cpp
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: main program file includes the contactlist.h class that represents an ADT
Purpose		: program runs according to the specifications in the project description
Modifications	:
Build  : g++ -o myprogram main.cpp contactlist.cpp contact.cpp name.cpp

Notes		: unnecessarily created interface and implementation for contact class and 
              name class (which contactlist.h both includes and uses) - their methods could have 
			  been better defined inline in the implementation

*/

#include <iostream>
#include <string>
#include "contactlist.h"


using namespace std;

// function prototypes:

void getLongestValidPrefix(string &name);

int main(int argc, const char* argv[])
{
	ContactList officePatients;
	Contact tempContact;
	Name tempName;
	string tempTelephone, tempEmail;
	string firstname, lastname;

	string command = "";
	int num;

	while (command != "quit") 
	{
		cout << "\n\tType a command:\n";
		cout << "list\n" << "insert\n" << "delete\n" << "find\n" << "save\n" << "quit\n\n";
		getline(cin, command);

		if (command == "list")
		{
			num = officePatients.display(cout);
			cout << "Number of entries listed: " << num;
		}
		else if (command == "insert")
		{
			cout << "enter first name:\n";
			getline(cin, firstname);

			getLongestValidPrefix(firstname);

			cout << "enter last name:\n";
			getline(cin, lastname);

			getLongestValidPrefix(lastname);

			tempName.setFirst(firstname);
			tempName.setLast(lastname);


			cout << "enter telephone (optional):\n";
			getline(cin, tempTelephone); 
			cout << "enter email (optional):\n";
			getline(cin, tempEmail);

			tempContact.set(firstname, lastname, tempTelephone, tempEmail);

			// write to list
			num = officePatients.insert(tempContact);
			if (num > 0) {
				cout << "Contact was inserted\n";
			}
			else {
				cout << "Contact was NOT inserted\n";
			}
		}
		else if (command == "delete")
		{
			cout << "enter first name:\n";
			getline(cin, firstname);

			getLongestValidPrefix(firstname);

			cout << "enter last name:\n";
			getline(cin, lastname);

			getLongestValidPrefix(lastname);

			tempName.setFirst(firstname);
			tempName.setLast(lastname);


			cout << "enter telephone (optional):\n";
			getline(cin, tempTelephone); // allow user to enter null
			cout << "enter email (optional):\n";
			getline(cin, tempEmail); // allow user to enter null

			tempContact.set(firstname, lastname, tempTelephone, tempEmail);

			// delete from list
			num = officePatients.remove(tempContact);
			cout << "Number of entries deleted: " << num;
		}
		else if (command == "find")
		{
			cout << "enter first name (optional):\n";
			getline(cin, firstname);

			getLongestValidPrefix(firstname);

			cout << "enter last name (optional):\n";
			getline(cin, lastname);

			getLongestValidPrefix(lastname);

			tempName.setFirst(firstname);
			tempName.setLast(lastname);


			cout << "enter telephone (optional):\n";
			getline(cin, tempTelephone); 
			cout << "enter email (optional):\n";
			getline(cin, tempEmail); 

			tempContact.set(firstname, lastname, tempTelephone, tempEmail);
			
			officePatients.find(cout, tempContact);
		}
		else if (command == "save")
		{
			num = officePatients.save();
			if (num < 0)
			{
				cerr << "the file could not be opened\n";
			}
		}
		else if (command == "quit")
		{
			break;
		}
	}

	return 0;
}

/** void getLongestValidPrefix(string &name)
* obtain longest valid prefix from string
* @param string &name [inout] manipulate the string
* so it holds the longest valid prefix.
* @pre
* @post the past string parameter by reference holds the
longest valid prefix.
* @returns none
*/
void getLongestValidPrefix(string &name)
{
	
		string cleanStr = "";
		for (int i = 0; i < name.length(); i++)
		{
			if (tolower(name[i]) >= 'a' && tolower(name[i]) <= 'z')
			{
				cleanStr += tolower(name[i]);
			}
			else
			{
				// captured longest possible prefix
				break;
			}
		}

		name = cleanStr;
		return;
	
}

