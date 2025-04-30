/*************************************************
* ADS Praktikum 3
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

void mainscreen_addTreeCSV(Tree*& ref)
{
	char j;
	cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
		"importieren(j / n) ? >";
	cin >> j;
	if (j == 'j')
	{
		ifstream csvread;
		csvread.open("ExportZielanalyse.csv", ios::in);
		if (!csvread.is_open())
		{
			cout << "Fehler beim Lesen!" << endl;
			return;
		}
		else
		{
			string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				if (name == "" || age == "" || income == "" || postcode == "") {
					continue;
				}
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
	}
}


int main()
{

    int result = Catch::Session().run();

    ///////////////////////////////////////

    //user csv tree/data storage
    Tree* csv_user_data = new Tree();

    //user programm control
    int user_option = 0;

    //variables
    std::string ui_name;
    int ui_alter;
    double ui_einkommen;
    int ui_plz;
    std::string ui_search;
    int Niv;

    while (user_option != 6) {
       
        std::cout << "=======================" << std::endl;
        std::cout << "ADS-Rot-Schwarz-Baum Praktikum" << std::endl;
        std::cout << "=======================" << std::endl;
        std::cout << "1) Datensatz einfuegen, manuell" << std::endl;
        std::cout << "2) Datensatz einfuegen, CSV Datei" << std::endl;
        std::cout << "3) Suchen" << std::endl;
        std::cout << "4) Ausgabe in Levelorder" << std::endl;
        std::cout << "5) Ausgabe in Levelorder (mit Niveauauswahl)" << std::endl;
        std::cout << "6) Beenden" << std::endl;
        std::cout << "?> ";
        
        std::cin >> user_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (user_option) {
        case 1:
            {std::cout << ">>> Bitte geben Sie die Daten ein";

            std::cout << std::endl << "Name: ";
            std::getline(std::cin, ui_name);

            std::cout << "Alter: ";
            std::cin >> ui_alter;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            std::cout << "Einkommen: ";
            std::cin >> ui_einkommen;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            std::cout << "PLZ: ";
            std::cin >> ui_plz;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            csv_user_data->addNode(ui_name, ui_alter, ui_einkommen, ui_plz);
            std::cout << std::endl << ">>> SUCCESS - Ihre Daten wurden eingefuegt" << std::endl;
            system("PAUSE");
            break;}

        case 2:
            {mainscreen_addTreeCSV(csv_user_data);
            system("PAUSE");
            break;}
            
        case 3:
            {std::cout << std::endl << ">>> Bitte geben Sie den zu suchenden Datensatz an" << std::endl;
            std::cout << "Name: ";
            std::getline(std::cin, ui_search);
            std::cout << std::endl << ">>> Fundstelle: ";
            csv_user_data->searchNode(ui_search);
            system("PAUSE");
            break;}

        case 4:
            //csv_user_data->printLevelOrder();
            {
            cout << "Ausgabe in Levelorder als binärer Suchbaum :\n\n";
            csv_user_data->printLvlOrder();
            cout << "Ausgabe in Level order als 234-Baum:\n";
            csv_user_data->printLevelOrder();
                system("PAUSE");
                break;}
        case 5:
            //csv_user_data->printLevelOrder();
           { 
            cin.ignore();
            cout << "+ Bitte geben Sie das auszudrückende Niveau an" << endl;
            cout << " Nieau ?>";
            cin >> Niv;
            csv_user_data->printLevelOrder(Niv);
            system("PAUSE");
            break;
            }
        default:
            std::cout << std::endl << "ATTENTION - This is not a valid option, please try again" << std::endl;
            break;
        }
    }
    return 0;
}
