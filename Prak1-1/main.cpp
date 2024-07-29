/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> " ;
}

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
    int userinp;
    Ring* v1=new Ring();
    string beschreibung;
    string daten;
    while (true)
    {
        print_menu();
        std::cin >> userinp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (userinp){
        case 1:
          cout<< endl <<" Neues Backup anlegen" << endl;
          cout << "Beschreibung ?> " ; getline(cin, beschreibung);

          cout << "Daten ?> " ; getline(cin, daten);

          v1 -> addNewNode(beschreibung,daten);
          cout << endl << ">> Backup wurde erfolgreich angelegt" << endl;
          break;

        case 2:
          cout << "Nach welchen Daten soll gesucht werden? ?> ";
          getline(cin, beschreibung);
          v1 -> search(daten);
          break;
        case 3:
          v1-> print();
          break;
        default :
         cout << "Not definied" << endl;
         break;
    }

system("CLS");}
	//
	///////////////////////////////////////
	
	return result;
}