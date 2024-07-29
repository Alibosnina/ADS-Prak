
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;


void mainscreen_addTreeCSV(Tree*& ref)
{
    char r;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
        "importieren(r / n) ? >";
    cin >> r;
    if (r == 'r')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
            cout << "Fehler beim Lesen!" << endl;
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}
//
///////////////////////////////////////
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
    int ui_delete;
    std::string ui_search;

    while (user_option != 7) {
       
        std::cout << "=======================" << std::endl;
        std::cout << "ADS - ELK - Stack v1.9, by 25th Bam" << std::endl;
        std::cout << "=======================" << std::endl;

        std::cout << "1) Datensatz einfuegen, manuell" << std::endl;
        std::cout << "2) Datensatz einfuegen, CSV Datei" << std::endl;
        std::cout << "3) Datensatz loeschen" << std::endl;
        std::cout << "4) Suchen" << std::endl;
        std::cout << "5) Datenstruktur anzeigen (pre/post/in)" << std::endl;
        std::cout << "6) Level-Order Ausgabe" << std::endl;
        std::cout << "7) Beenden" << std::endl;
        std::cout << "?> ";
        
        std::cin >> user_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (user_option) {
        case 1:
            std::cout << ">>> Bitte geben Sie die Daten ein";

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
            
            break;

        case 2:
            mainscreen_addTreeCSV(csv_user_data);
            
            break;

        case 3:
            std::cout << std::endl << ">>> Bitte geben sie den zu loeschenden Datensatz an" << std::endl;
            std::cout << "OrderID: ";
            std::cin >> ui_delete;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (csv_user_data->deleteNode(ui_delete) == true) std::cout << std::endl << ">>> SUCCESS - Eintrag wurde geloescht " << std::endl;
            else std::cout << "error while löschening\n";
            
            break;

        case 4:
            std::cout << std::endl << ">>> Bitte geben Sie den zu suchenden Datensatz an" << std::endl;
            std::cout << "Name: ";
            std::getline(std::cin, ui_search);
            std::cout << std::endl << ">>> Fundstelle: ";
            csv_user_data->searchNode(ui_search);
            
            break;

        case 5:
            csv_user_data->printAll();
            
            break;

        case 6:
            csv_user_data->levelOrder();
               
                break;
        default:
            std::cout << std::endl << "ATTENTION - This is not a valid option, please try again" << std::endl;
            break;
        }
    }
    return 0;
}