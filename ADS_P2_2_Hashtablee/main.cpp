#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include"hashtable.h"
#include <random>

int main() {
    Catch::Session().run();

     HashTable h1(1000, 0.6, 1);
    srand(time(nullptr));
    for (unsigned int i = 1; i <= 200; i++)
    {
        int random = 1000 + (rand() % (501));
        h1.insert(random);
    }
    cout << "Methode: linear\n"
        << "Size h1: " << h1.getSize()
        << "\nElements: " << h1.getElements()
        << "\nCollisionCount: " << h1.getCollisionCount() << "\n\n";
    HashTable h2(1000, 0.6, 2);
    for (unsigned int i = 1; i <= 200; i++)
    {
        int random = 1000 + (rand() % (501));
        h2.insert(random);
    }
    cout << "Methode: quadratisch\n"
        << "Size h2: " << h2.getSize()
        << "\nElements: " << h2.getElements()
        << "\nCollisionCount: " << h2.getCollisionCount() << "\n\n";

    HashTable h3(1000, 0.6, 3);
    for (unsigned int i = 1; i <= 200; i++)
    {
        int random = 1000 + (rand() % (501));
        h3.insert(random);
    }
    cout << "Methode: doppeltes hashing\n"
        << "Size h3: " << h3.getSize()
        << "\nElements: " << h3.getElements()
        << "\nCollisionCount: " << h3.getCollisionCount() << "\n\n";
        
    system("pause");
    return 0;
}