/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>
using namespace std;

class RingNode{
	
private:
	//
	int oldAge;
	string description;
	string symbolicData;
	RingNode* next;
	//	
public:
	//
	RingNode();
	RingNode(int oldAge,string description, string symbolicData);

	int getOldAge ();
	void setOldAge(int oldAge);
	string getDescription();
	void setDescription(string description);
	string getSymbolicData();
	void setSymbolicData(string symbolicData);
	RingNode*getNext() {return next;}
	void setNext(RingNode* next);
	//
};
