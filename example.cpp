/*
 * Usage example for SDatabase class
 *
 *  Created On : Sep 20, 2016
 *      Author : Mohamed El Sayed
 *      email : engmohamedelsayed007@gmail.com
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
	char input[1];
	char confirm[1];
	SDatabase db;
	db.createDB("db.txt");
	db.enable_duplication=true;
	string id, name, address;
	do{
	clearScreen();
	cout<<"1-Add\n2-Delete By ID\n3-Search By ID\n4-View All\n5-Clear Database\n6-Exit\n";
	cout<<"\nYour Choice >> ";
	cin.getline(input, 20);

	if(input[0]=='1')
	{
		do{
			clearScreen();
			cout<<"Enter the user ID : ";
			getline(cin, id);
			db.id=id;
			cout<<"Enter the user Name : ";
			getline(cin, name);
			db.name = name;
			cout<<"Enter the user address : ";
			getline(cin, address);
			db.address = address;
			if(db.addNew()==true)
			{
				cout<<"Done\n";
			}
			else{
			cout<<"\nAn error occurred\nPress any key to continue\n";
			cin.ignore();
			}
			cout<<"Add more [y/n] ? ";
			cin.getline(confirm, 20);
		}
		while(tolower(confirm[0])=='y');
	}
	else if(input[0]=='2')
	{
	do{
		clearScreen();
		cout<<"Enter the user ID : ";
		getline(cin, id);
		if(db.deleteById(id)==true)
			{
				cout<<endl<<"Done\nDelete more [y/n] ? ";
				cin.getline(confirm, 20);
			}
		else
			cout<<"An error occurred\n";

		cin.ignore();
	  }
	  while(tolower(confirm[0])=='y');
	}
	else if(input[0]=='3')
	{
		do
		{
			clearScreen();
			cout<<"Enter the user ID : ";
			getline(cin, id);
			if(db.searchById(id)==false)
				cout<<"ID not found\n";
			else
			{
				cout<<"\nSearch again [y/n] ? ";
				cin.getline(confirm, 20);
			}
			cin.ignore();
		}
		while(tolower(confirm[0]=='y'));
	}
	else if(input[0]=='4')
	{
		clearScreen();
		if(db.viewAll()< 0)
		{
			cout<<"Database is empty\n";
		}
		cout<<"Press enter to continue.";
		cin.ignore();
	}
	else if(input[0]=='5')
	{
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
