#MultiKeySortedLinkedListADT

##Program Description:

The contact list is kept in ascending sorted order by last name as primary key, first name as secondary
key, telephone number as tertiary key, and email address as quaternary key. 


The display() operation makes no more than a single pass through the list. The list uses a singly linked 
representation. The implementations of insertions and deletions make a single pass through the list
in the worst case.


##Program Tasks:

The program ensures that only valid names are stored in the contact list. It assumes that the user 
enters at least one correct character, so that a name is never an empty string. The program should 
use the longest valid prefix of the entered text as the name. For
example, all of these entered strings should be stored as the name john: john653, john, john$%^, and
john___.


The main program enters interactive mode, repeatedly displaying a prompt and waiting for the user 
to enter a command. After a command is entered and the program responds to it, the prompt is 
displayed again, unless the command was the quit command. The set of commands that the application
 supports is listed below. The commands are case-sensitive; they must be entered in lower case only.


| Command      | Description    |
| :----------- |:-------------|
| list     | List the entire contact list on standard output (the terminal window) <br/> followed by the number of entries listed. | 
| insert   | Prompt the user to enter contact info: last name, first name, telephone <br/> number, and email address. The user should be allowed to omit  <br/> the telephone number and/or the email address. It will display a simple  <br/>  message indicating whether the contact was inserted or not.  <br/> (E.g. recordinserted/record not inserted.)     | 
| delete | Prompt the user to enter information to delete a record. The user must <br/> supply a last name and a first name, and optionally, a telephone number <br/> and/or email address. It will search for entries that match all of the <br/> non-null data supplied by the user and delete them. It displays how many <br/> were deleted.      | 
| find | Prompt the user to enter information to find a record. The user can leave <br/> any member blank. This will display on the standard output all records <br/> whose non-null members match the non-null data items entered by the <br/> user.     | 
| save | Save the current state of the contact list to a file named contactlist.bkp <br/> in the current working directory, replacing that file if it already exists.     | 
| quit | Terminate the application.     | 




