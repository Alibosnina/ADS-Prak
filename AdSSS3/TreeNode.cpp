#include "TreeNode.h"
#include <iostream>
#include <string>

 ////////////////////////////////////
 // Ihr Code hier:
 TreeNode::TreeNode() {
	m_NodeChronologicalID = 0;
	m_Age = 0;
	m_PostCode = 0;
	m_Income = 0;
	m_NodeOrderID = 0;
	m_Name = "";
	m_left = 0;
	m_right = 0;
	red = 1;
	parent = 0;
}

TreeNode::TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode) {
	m_NodeChronologicalID = NodeChronologicalID;
	m_Age = Age;
	m_PostCode = PostCode;
	m_Income = Income;
	m_NodeOrderID = NodeOrderID;
	m_Name = Name;
	m_left = 0;
	m_right = 0;
	red = 1;
	parent = 0;
}

    void TreeNode::print() const
{
	std::cout <<  "NodeID: " << m_NodeOrderID
	     <<  ", Name: " << m_Name 
		 <<  ", Alter: "<<m_Age
		 <<  ", Einkommen: " << m_Income
		 <<  ", PLZ: " << m_PostCode
		 <<  ", PosID: " << m_NodeChronologicalID << std::endl;
}

 //
 ////////////////////////////////////
