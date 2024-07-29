/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"


// Ihr Code hier:

RingNode::RingNode(int oldAge,string description, string symbolicData){
		this -> oldAge = oldAge;
		this -> description = description;
		this-> symbolicData = symbolicData;
	};

	int RingNode::getOldAge (){return oldAge;}
	void RingNode::setOldAge(int oldAge){this -> oldAge= oldAge;}
	string RingNode::getDescription(){return description;}
	void RingNode::setDescription(string description){ this->description = description;}
	string RingNode::getSymbolicData(){return symbolicData;}
	void RingNode::setSymbolicData(string symbolicData){ this->symbolicData = symbolicData;}
	void RingNode::setNext(RingNode* next){this-> next=next;}
// 
////////////////////////////////////