/*
 * Usage example for SDatabase class
 *
 *      Author : Mohamed El Sayed
 *      email  : m.elsayed4420@gmail.com
 *      lowlevelcode.blogspot.com
 */


#include <iostream>
#include "SDatabase.h"
#include <cstdlib>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif
}
int main(int argc, char** argv)
{
	// Initializing and creating db object from SDatabase class
	SDatabase db;
	//Set the database entries to 5, Maximum is 20
	db.entry_count = 5;
	//Creating text file to be our database called database.txt
	db.createDB("database.txt");
	//Disable duplication, addNew() function will check for the existence of the id, it it exists the function will return false
	//and abort adding
	db.enable_duplication=false;

	//local variables
	char input[1];
	char confirm[1];
	string id;


	//String array to inform the user what to enter, 5 string for 5 d atabase entries
	string printed_msgs[]={"Enter ID : ", "Enter Name : ", "Enter Address : ", "Enter Age : ", "Enter Gender : "};

	do{
	clearScreen();
	cout<<"1-Add\n2-Delete By ID\n3-Search By ID\n4-View All\n5-Clear Database\n6-Exit\n";
	cout<<"\nYour Choice >> ";
	//Get input from the user
	cin.getline(input, 20);

	if(input[0]=='1')
	{
		do{
			clearScreen();
			//Loop from 0 to the number of entries selected, each time print a message from printed_msgs array
			//and read input and save it into db.entries[i];
			//Note the the first input must be the id
			for(int i = 0; i < db.entry_count; i++)
			{
				cout<<printed_msgs[i];
				getline(cin, db.entries[i]);
			}
			//If the function returned false, print error message
			if(db.addNew()==false)
			{
				cout<<"An error occurred\n";
				cin.ignore();
				break;
			}
			else
			{
				cout<<"Done\nAdd more [y/n] ? ";
				cin.getline(confirm, 20);
			}

		  }
		while(tolower(confirm[0])=='y');
	}
	else if(input[0]=='2')
	{
	do{
		clearScreen();
		//Ask the use to enter the id he wants to delete
		cout<<"Enter the user ID : ";
		getline(cin, id);
		//If the id exists, Delete its row data
		if(db.deleteById(id)==true)
			{
				cout<<endl<<"Done\nDelete more [y/n] ? ";
				cin.getline(confirm, 20);
			}
		else
		{
			//If not, print error message, you can change it for something like "ID not found", you are free
			cout<<"An error occurred\nDelete more [y/n] ?";
			cin.getline(confirm, 20);
		}

	  }
	  while(tolower(confirm[0])=='y');
	}
	else if(input[0]=='3')
	{
		do
		{
			//Ask the user to enter the id that he wants to search about
			clearScreen();
			cout<<"Enter the user ID : ";
			getline(cin, id);
			//If the id exists, Print its row data
			//If not print the following message
			if(db.searchById(id)==false)
			{
				cout<<"ID not found\nSearch again [y/n] ? ";
				cin.getline(confirm, 20);
			}
			else
			{
				//If the result is true, Ask the user if he wants to search again
				cout<<"\nSearch again [y/n] ? ";
				cin.getline(confirm, 20);
			}
		}
		while(tolower(confirm[0]=='y'));
	}
	else if(input[0]=='4')
	{
		clearScreen();
		//If the returned value greater than 0, Print the whole db data, if below then the database is empty
		if(db.viewAll()< 0)
		{
			cout<<"Database is empty\n";
		}

		cout<<"Press enter to continue.";
		cin.ignore();
	}
	else if(input[0]=='5')
	{
		//Simply, Clears the database data by calling clear() function
		clearScreen();
		cout << "Are you sure [y/n] ? ";
		cin.getline(confirm, 20);
		if(tolower(confirm[0]=='y')){
			db.clear();
			cout<<"Done\n";
		}
	}
	}
	while(input[0]!='6');
	return 0;
}
