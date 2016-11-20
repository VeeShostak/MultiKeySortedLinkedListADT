
/*
Title			: contactlist.h
Author			: Vlad Shostak
Created On		: November 14, 2016
Description	: This is the implementation for the contactlist class
Modifications	:
Notes		:
*/

#include "contactlist.h"
#include <iostream>
#include <iomanip> // cout formatting
#include <fstream>


ContactList::ContactList()
{
	head = NULL;
	size = 0;

}

ContactList::~ContactList()
{
	
	ListNode *nodeToDelete; // will point to the node that will be deleted
	
	while (size > 0)
	{
		// first node will be deleted
		nodeToDelete = head;
		head = head->next;
		
		// empty data, clear next link, then delete
		nodeToDelete->personData.set("","","","");
		nodeToDelete->next = NULL;
		delete nodeToDelete;
		nodeToDelete = NULL;
		size--;
	}

	
}

int ContactList::display(ostream &output)
{
	// linked list is kept in sorted order, so just display the list

	Name tempName; 
	string tempTelephone, tempEmail;
	unsigned int inserted = 0;

	ListNode *curr = head;
	for (int i = size; i > 0; i--)
	{
		curr->personData.getName(tempName);
		output << setw(16) << left << tempName.last() << " ";
		output << setw(16) << left << tempName.first() << " "; 

		curr->personData.getTel(tempTelephone);
		output << setw(16) << left << tempTelephone << " ";

		curr->personData.getEmail(tempEmail);
		output << setw(32) << left << tempEmail << "\n";

		inserted++;
		// move to next node
		curr = curr->next;
	}
	return inserted;
}

int ContactList::insert(Contact recordToInsert)
{
	int inserted = 0;
	// Variables to hold values from recordToInsert, current node
	// each prefixed to describe from where they store from.
	Name currName, toInsertName;
	string currTelephone, currEmail, toInsertTelephone, toInsertEmail;

	ListNode *prev = NULL;
	ListNode *curr = head;

	// obtain values from recordToInsert
	recordToInsert.getName(toInsertName);
	recordToInsert.getTel(toInsertTelephone);
	recordToInsert.getEmail(toInsertEmail);

	if (head != NULL)
	{
		// obtain values from curr node
		curr->personData.getName(currName);
		curr->personData.getTel(currTelephone);
		curr->personData.getEmail(currEmail);
	}
	else {
		currName.setFirst("");
		currName.setLast("");
		currTelephone = "";
		currEmail = "";
	}

	// === if list empty, or if recordToInsert is smaller than first record,
	// then insert it in the front

	if (head == NULL || toInsertName.last() <= currName.last())
	{
		
			if (toInsertName.last() == currName.last())
			{
				if (toInsertName.first() <= currName.first())
				{
					if (toInsertName.first() == currName.first())
					{
						if (toInsertTelephone <= currTelephone)
						{
							if (toInsertTelephone == currTelephone)
							{
								if (toInsertEmail <= currEmail)
								{

									if (toInsertEmail == currEmail)
									{
										// duplicate found, exit
										return inserted;
									}
									else
									{
										ListNode *insertNode = new ListNode;
										if (insertNode == NULL) {
											return 0;
										}
										// store data
										insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

										insertNode->next = head;
										head = insertNode;

										size++;
										inserted++;
										return inserted;
									}

								}
							}
							else
							{
								ListNode *insertNode = new ListNode;
								if (insertNode == NULL) {
									return 0;
								}
								// store data
								insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

								insertNode->next = head;
								head = insertNode;

								size++;
								inserted++;
								return inserted;
							}
						}
						
					}
					else
					{
						ListNode *insertNode = new ListNode;
						if (insertNode == NULL) {
							return 0;
						}
						// store data
						insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

						insertNode->next = head;
						head = insertNode;

						size++;
						inserted++;
						return inserted;
					}
				}
			}
			else
			{
				ListNode *insertNode = new ListNode;
				if (insertNode == NULL) {
					return 0;
				}
				// store data
				insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

				insertNode->next = head;
				head = insertNode;

				size++;
				inserted++;
				return inserted;
			}
		
		
	} // end if head == null

	// list not empty and first item is not larger than recordToInsert
	// it is already in the list, so do not insert
	if (toInsertName.last() == currName.last() &&
			toInsertName.first() == currName.first() &&
			toInsertTelephone == currTelephone &&
			toInsertEmail == currEmail)
	{

		return inserted; // returns 0
	}

	// first item data is less than recordToInsert data
	// so begin at 2nd node if it exists, and insert new node with 
	// recordToInsert data in it in sorted order

	prev = head;
	curr = head->next;
	while (curr != NULL)
	{
		// obtain values from curr node
		curr->personData.getName(currName);
		curr->personData.getTel(currTelephone);
		curr->personData.getEmail(currEmail);

		// if recordToInsert data > curr data, proceed traversing

		if (toInsertName.last() >= currName.last())
		{
			if (toInsertName.last() == currName.last())
			{
				if (toInsertName.first() >= currName.first())
				{
					if (toInsertName.first() == currName.first())
					{
						if (toInsertTelephone >= currTelephone)
						{
							if (toInsertTelephone == currTelephone)
							{
								if (toInsertEmail >= currEmail)
								{
									prev = curr;
									curr = curr->next;

								}
							}
							else
							{
								prev = curr;
								curr = curr->next;
							}
						}

					}
					else
					{
						prev = curr;
						curr = curr->next;
					}
				}
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}


		// if recordToInsert data < curr data, insert node with 
		// recordToInsert data before curr
		else if (toInsertName.last() <= currName.last())
		{
			if (toInsertName.last() == currName.last())
			{
				
				if (toInsertName.first() <= currName.first())
				{
					if (toInsertName.first() == currName.first())
					{
						if (toInsertTelephone <= currTelephone)
						{
							if (toInsertTelephone == currTelephone)
							{
								if (toInsertEmail <= currEmail)
								{
									if (toInsertEmail == currEmail)
									{
										// record is a duplicate, exit
										return inserted;
									}
									else
									{
										ListNode *insertNode = new ListNode;
										if (insertNode == NULL) {
											return 0;
										}
										// store data
										insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

										insertNode->next = curr; // or prev->next
										prev->next = insertNode;

										size++;
										inserted++;
										return inserted;
									}

								}
							}
							else
							{
								ListNode *insertNode = new ListNode;
								if (insertNode == NULL) {
									return 0;
								}
								// store data
								insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

								insertNode->next = curr; // or prev->next
								prev->next = insertNode;

								size++;
								inserted++;
								return inserted;
							}
						}

					}
					else
					{
						ListNode *insertNode = new ListNode;
						if (insertNode == NULL) {
							return 0;
						}
						// store data
						insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

						insertNode->next = curr; // or prev->next
						prev->next = insertNode;

						size++;
						inserted++;
						return inserted;
					}
				}
			}
			else
			{
				ListNode *insertNode = new ListNode;
				if (insertNode == NULL) {
					return 0;
				}
				// store data
				insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

				insertNode->next = curr; // or prev->next
				prev->next = insertNode;

				size++;
				inserted++;
				return inserted;
			}
		}


	} // end while

	// we are now at the end of the list since the recordToInsert data was
	// larger than everything in the list. Here, prev point to last node.
	// Now insert node with recordToInsert data at the end of the list

	ListNode *insertNode = new ListNode;
	if (insertNode == NULL) {
		return 0;
	}
	// store data
	insertNode->personData.set(toInsertName.first(), toInsertName.last(), toInsertTelephone, toInsertEmail);

	insertNode->next = prev->next; // points to NULL
	prev->next = insertNode;
	
	size++;
	inserted++;

	return inserted;
}

int ContactList::insert(ContactList contactListInsert)
{
	// NOTE: in c++ objects of the same class have access to each others private data
	// use deep copy (allow copied pointers to be distinctivly referenced in existing list)

	ListNode *curr;
	
	unsigned int inserted = 0;

	Name currName;
	string currTelephone, currEmail;
	
	curr = contactListInsert.head;

	for (int i = contactListInsert.size; i > 0; i--)
	{

		ListNode *deepCopyNode = new ListNode;
		if (deepCopyNode == NULL) {
			throw("Out of memory. deepCopyNode not created.");
		}

		// obtain values from curr node
		curr->personData.getName(currName);
		curr->personData.getTel(currTelephone);
		curr->personData.getEmail(currEmail);

		// store data
		deepCopyNode->personData.set(currName.first(), currName.last(), currTelephone, currEmail);
		deepCopyNode->next = NULL;

		inserted += insert(deepCopyNode->personData);
		curr = curr->next;
	}
	return inserted;
}

int ContactList::remove(Contact recordToDelete)
{
	unsigned int deleted = 0;
	ListNode *curr, *prev;

	Name currName, toDelName;
	string currTelephone, currEmail, toDelTelephone, toDelEmail;

	// if list empty, do not do anything
	if (head != NULL)
	{
		curr = head;
		prev = NULL;

		// obtain values from recordToDelete
		recordToDelete.getName(toDelName);
		recordToDelete.getTel(toDelTelephone);
		recordToDelete.getEmail(toDelEmail);

		// detect null-data to exclude
		bool excludePhone = false, excludeEmail = false;
		
		if (toDelEmail == "") {
			excludeEmail = true;
		}
		if (toDelTelephone == "") {
			excludePhone = true;
		}

		while (curr != NULL)
		{
			// obtain values from curr node
			curr->personData.getName(currName);
			curr->personData.getTel(currTelephone);
			curr->personData.getEmail(currEmail);

			// =================================================
			// if curr item data < item to delete
			// item data larger than curr item data, advance pointers
			// ===============================================
			// else if curr item data > item data
			// item to delete data is smaller than curr item data, so
			// it cannot be in remainder of the list, stop searching

			if (toDelName.last() >= currName.last())
			{
				
				if (toDelName.last() == currName.last())
				{
					
					if (toDelName.first() >= currName.first())
					{
						if (toDelName.first() == currName.first())
						{
							
							if ((toDelTelephone >= currTelephone) || excludePhone)
							{
						
								if ((toDelTelephone == currTelephone) || excludePhone)
								{
									
									if ((toDelEmail > currEmail))
									{
										prev = curr;
										curr = curr->next;
									}
									else if((toDelEmail < currEmail) && !excludeEmail) 
									{
										break;
									}
									// equal
									else if ((toDelEmail == currEmail) || excludeEmail) 
									{
										// handle match in first node
										if (prev == NULL)
										{
											head = curr->next;
											curr->personData.set("", "", "", "");
											curr->next = NULL;
											delete curr;
											curr = head; // start from beg
											deleted++;
										}
										else
										{
											curr = curr->next;
											prev->next->personData.set("", "", "", "");
											prev->next->next = NULL;
											delete prev->next;
											prev->next = curr;
											deleted++;

										}
									}
									
								}
								else
								{
									prev = curr;
									curr = curr->next;
								}
							}// telephoneNumber
							else if ((toDelTelephone < currTelephone))
							{
								break;
							}
						}
						else
						{
							prev = curr;
							curr = curr->next;
						}
					}// firstName
					else if ((toDelName.first() < currName.first()))
					{
						break;
					}
				}
				else
				{
					prev = curr;
					curr = curr->next;
				}
			}// lastname
			else if (toDelName.last() < currName.last())
			{
				break;
			}
			
		} // end while
	} // end if head != NULL
	
	size -= deleted;
	return deleted;
}

unsigned int ContactList::sizeOfList()
{
	return size;
}

int ContactList::save()
{
	ofstream contactListCopy;
	contactListCopy.open("contactlist.bkp");
	if (contactListCopy.fail())
	{
		// failed to open file
		return -1;
	}

	Name tempName;
	string tempTelephone, tempEmail;
	unsigned int inserted = 0;

	ListNode *curr = head;

	while (curr != NULL)
	{
		curr->personData.getName(tempName);
		contactListCopy << setw(16) << left << tempName.last() << " ";
		contactListCopy << setw(16) << left << tempName.first() << " ";

		curr->personData.getTel(tempTelephone);
		contactListCopy << setw(16) << left << tempTelephone << " ";

		curr->personData.getEmail(tempEmail);
		contactListCopy << setw(32) << left << tempEmail << "\n";

		inserted++;
		// move to next node
		curr = curr->next;
	}
	contactListCopy.close();
	return inserted;


}

int ContactList::find(ostream &output, string lastname, string firstname)
{
	unsigned int inserted = 0;

	ListNode *curr;

	Name currName, toDelName;
	string currTelephone, currEmail;

	// if list empty, do not do anything
	if (head != NULL)
	{
		curr = head;

		while (curr != NULL)
		{
			// obtain values from curr node
			curr->personData.getName(currName);
			curr->personData.getTel(currTelephone);
			curr->personData.getEmail(currEmail);

			// =================================================
			// if curr item data < item to delete
			// item data larger than curr item data, advance pointers
			// ===============================================
			// else if curr item data > item data
			// item to delete data is smaller than curr item data, so
			// it cannot be in remainder of the list, stop searching

			if ((toDelName.last() >= currName.last()))
			{

				if ((toDelName.last() == currName.last()))
				{

					if ((toDelName.first() >= currName.first()))
					{
						if ((toDelName.first() == currName.first()))
						{

							output << setw(16) << left << currName.last() << " ";
							output << setw(16) << left << currName.first() << " ";

							output << setw(16) << left << currTelephone << " ";

							output << setw(32) << left << currEmail << "\n";
							
							inserted++;
							// move to next node
							curr = curr->next;
						} 
						else
						{
							curr = curr->next;
						}
					}// firstName
					else if ((toDelName.first() < currName.first()))
					{
						break;
					}
				}
				else
				{
					curr = curr->next;
				}
			}// lastname
			else if (toDelName.last() < currName.last())
			{
				break;
			}

		} // end while
	} // end if head != NULL

	return inserted;
}

int ContactList::find(ostream & output, Contact recordToFind)
{
	unsigned int inserted = 0;

	ListNode *curr;

	Name currName, toDelName;
	string currTelephone, currEmail, toDelTelephone, toDelEmail; 

	// if list empty, do not do anything
	if (head != NULL)
	{
		curr = head;
		// obtain values from recordToDelete
		recordToFind.getName(toDelName);
		recordToFind.getTel(toDelTelephone);
		recordToFind.getEmail(toDelEmail);

		// detect null-data to exclude
		bool excludePhone = false, excludeEmail = false;
		bool excludeFirstName = false, excludeLastName = false;

		if (toDelEmail == "") {
			excludeEmail = true;
		}
		if (toDelTelephone == "") {
			excludePhone = true;
		}
		if (toDelName.last() == "") {
			excludeLastName = true;
		}
		if (toDelName.first() == "") {
			excludeFirstName = true;
		}

		while (curr != NULL)
		{
			// obtain values from curr node
			curr->personData.getName(currName);
			curr->personData.getTel(currTelephone);
			curr->personData.getEmail(currEmail);

			// =================================================
			// if curr item data < item to delete
			// item data larger than curr item data, advance pointers
			// ===============================================
			// else if curr item data > item data
			// item to delete data is smaller than curr item data, so
			// it cannot be in remainder of the list, stop searching

			if ((toDelName.last() >= currName.last()) || excludeLastName)
			{

				if ((toDelName.last() == currName.last()) || excludeLastName)
				{

					if ((toDelName.first() >= currName.first()) || excludeFirstName)
					{
						if ((toDelName.first() == currName.first()) || excludeFirstName)
						{

							if ((toDelTelephone >= currTelephone) || excludePhone)
							{

								if ((toDelTelephone == currTelephone) || excludePhone)
								{

									if ((toDelEmail > currEmail))
									{
										curr = curr->next;
									}
									else if ((toDelEmail < currEmail) && !excludeEmail)
									{
										break;
									}
									// equal
									else if ((toDelEmail == currEmail) || excludeEmail)
									{
										output << setw(16) << left << currName.last() << " ";
										output << setw(16) << left << currName.first() << " ";

										output << setw(16) << left << currTelephone << " ";

										output << setw(32) << left << currEmail << "\n";
										
										inserted++;
										// move to next node
										curr = curr->next;
									}
								}
								else
								{
									curr = curr->next;
								}
							}// telephoneNumber
							else if ((toDelTelephone < currTelephone) )
							{
								break;
							}
						}
						else
						{
							curr = curr->next;
						}
					}// firstName
					else if ((toDelName.first() < currName.first()) )
					{
						break;
					}
				}
				else
				{
					curr = curr->next;
				}
			}// lastname
			else if (toDelName.last() < currName.last() )
			{
				break;
			}

		} // end while
	} // end if head != NULL

	return inserted;
}

int ContactList::makeEmpty()
{
	ListNode *nodeToDelete; // will point to the node that will be deleted
	int deleted = 0;
	while (size > 0)
	{
		// first node will be deleted
		nodeToDelete = head;
		head = head->next;

		// empty data, clear next link, then delete
		nodeToDelete->personData.set("", "", "", "");
		nodeToDelete->next = NULL;
		delete nodeToDelete;
		nodeToDelete = NULL;
		size--;
		deleted++;
	}

	return deleted;
}



