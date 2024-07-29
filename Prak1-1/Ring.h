/*************************************************
* ADS Praktikum 1.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"
using namespace std;

class Ring{
	
	private:
		// Ihr Code hier:	
		int m_countNodes;
		RingNode* m_anker;
		//
		////////////////////////////////////
	public:
		// Ihr Code hier:
		Ring(){m_anker=nullptr; m_countNodes=0;};
		void addNewNode(string description, string symbolicData);
		bool search(string name);
		void print();
		void ageplus(RingNode* m_anker);


		//
		////////////////////////////////////
		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_countNodes(Ring& r);
};
