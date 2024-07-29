/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>
using namespace std;

// Ihr Code hier:
void Ring::addNewNode(string description, string symbolicData){
    if(m_anker == nullptr)
    {
        m_anker= new RingNode(0,description,symbolicData);
        m_anker -> setNext(m_anker);
        m_countNodes++;
    }
    else if (m_anker -> getNext() == m_anker)
    {
        RingNode* tmp= new RingNode(0, description, symbolicData);
        m_anker -> setNext(tmp);
        tmp-> setNext(m_anker);
        m_countNodes++;
        m_anker = tmp;
        ageplus(m_anker);
    }
    else if (m_countNodes == 6)
    {
        RingNode *ptr = m_anker;
        RingNode *neuer_eintrag = new RingNode(0,description,symbolicData); 

        ageplus(m_anker);

        ptr->setOldAge(ptr->getOldAge() + 1);
        while (ptr->getOldAge() != 6)
        {
            ptr = ptr->getNext();
        }
        
        neuer_eintrag->setNext(ptr->getNext());
        m_anker->setNext(neuer_eintrag);
        ptr->setNext(nullptr);
        m_anker = neuer_eintrag;

       //Wir löschen den ältesten Knoten, um Speicherlecks zu vermeiden
        delete ptr;             
        ptr = nullptr;
    }
    else 
    {
        RingNode* newN = new RingNode (0, description, symbolicData);
        RingNode* newnext = m_anker -> getNext();
        m_anker-> setNext(newN);
        newN -> setNext(newnext);
        m_anker = newN;
        newN = nullptr;
        delete newN;
        newnext = nullptr;
        delete newnext;
        ageplus(m_anker);
        m_countNodes++;
    }
    } 

    bool Ring:: search(string name)
    {
        bool f = false;
        if (m_anker == nullptr)
        {
            cout << ">> Datensatz konnte nicht gefunden werden.\n";
            return false;
        }
        /*else if (m_anker -> getSymbolicData() == name){
            cout << ">> Gefunden in Backup: Alter " << m_anker -> getOldAge() << " , Beschreibung: " 
            << m_anker -> getDescription() << ", Daten: " << m_anker-> getSymbolicData() << endl;
            f=true;
        }*/
        else
        {
            RingNode* tmp= m_anker;
            for(int i=0 ; i< m_countNodes; i++ )
            {
                if (tmp -> getSymbolicData() == name)
                {
                    cout << "Gefunden in Backup: Alter" << tmp-> getOldAge() 
                    <<", Beschreibung: " << tmp-> getDescription() << ", Daten: " 
                    << tmp ->getSymbolicData()<< endl;
                    f = true;
                    //return true;
                }
                tmp = tmp -> getNext();
            }
        }
        if(!f) cout << ">> Datensatz konnte nicht gefunden werden.\n" ;
        return f;
    }

    void Ring:: print()
    {
        if (m_anker != nullptr)
        {
            RingNode* tmp= m_anker-> getNext();
            for(int i = 0 ; i < m_countNodes; i++ ){
                cout << "Alter: " << tmp->getOldAge() << " , Beschreibung: " << tmp->getDescription()
                << ", Daten : " << tmp-> getSymbolicData() << endl;
                cout << "-----------------------------------\n";
                tmp=tmp->getNext();
            }
        } 
        else
        {
            cout <<">> keine datensätze vorhanden.";
        }
    }

    void Ring::ageplus(RingNode* m_anker)
    {
        RingNode* tmp = m_anker ->getNext();
        while (tmp != m_anker){
            tmp -> setOldAge( tmp->getOldAge() + 1);
            tmp = tmp -> getNext();
        };
        tmp = nullptr;
    }

//
////////////////////////////////////