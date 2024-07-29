/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

////////////////////////////////////
// Ihr Code hier:



void Tree::destruct(TreeNode* tmp)
{
	if (tmp != nullptr) {
		destruct(tmp->getLeft());
		destruct(tmp->getRight());
		delete tmp;
	}
}

void Tree::addNode(string Name, int Age, double Income, int PostCode)
{
	if (m_anker == nullptr)
	{
		TreeNode* wurzel = new TreeNode(Age + Income + PostCode, getcurrentNodeconicalID(), Name, Age, Income, PostCode);
		m_anker = wurzel;
		setcurrentNodeChronicalID(getcurrentNodeconicalID() + 1);
	}
	else
	{
		TreeNode* eintrag = new TreeNode(Age + Income + PostCode, getcurrentNodeconicalID(), Name, Age, Income, PostCode);
		receintrag(m_anker, eintrag);
		setcurrentNodeChronicalID(getcurrentNodeconicalID() + 1);
	}
}



bool Tree::searchNode(string Name)
{
	bool found = false;
	recsearch(m_anker, Name, found);
	return found;
}


void Tree::printAll()
{
	std::cout << left <<setw(4) << setfill(' ')<<" ID "<< "|" <<setw(18) << setfill(' ') << " Name " << "|" << setw(6)<<setfill(' ') << " Age" << "|" << setw(11) << setfill(' ') << " Income " << "|"<< setw(10) << setfill(' ') <<" PostCode " << "|" << setw(9) << setfill(' ') << " OrderID " << std::endl;
	std::cout << left << setw(4) << setfill('-') << "-" << setw(19) << setfill('-') << "+" << setw(7) << setfill('-') << "+" << setw(12) << setfill('-') << "+" << setw(11) << setfill('-') << "+" << setw(9) << setfill('-') << "+" << std::endl;
	preOrder(m_anker);
}

void Tree::preOrder(TreeNode* wurzel) {
	if (wurzel == nullptr) return;

	std::cout << right << setw(4) << setfill(' ') << wurzel->getNodeChronologicalID() << "|" << setw(18) << setfill(' ') << wurzel->getName() << "|" << setw(6) << setfill(' ') << wurzel->getAge() << "|" << setw(11) << setfill(' ') << wurzel->getIncome() << "|" << setw(10) << setfill(' ') << wurzel->getPostCode() << "|" << setw(9) << setfill(' ') << wurzel->getNodeOrderID() << std::endl;

	preOrder(wurzel->getLeft());
	preOrder(wurzel->getRight());
}
void Tree::postOrder(TreeNode* wurzel)
{
    if (wurzel == nullptr) return;

    postOrder(wurzel->getLeft());
    postOrder(wurzel->getRight());

    std::cout << right << setw(4) << setfill(' ') << wurzel->getNodeChronologicalID() << "|" << setw(18) << setfill(' ') << wurzel->getName() << "|" << setw(6) << setfill(' ') << wurzel->getAge() << "|" << setw(11) << setfill(' ') << wurzel->getIncome() << "|" << setw(10) << setfill(' ') << wurzel->getPostCode() << "|" << setw(9) << setfill(' ') << wurzel->getNodeOrderID() << std::endl;
}
void Tree::levelOrder()
{
	std::vector<std::vector<TreeNode*>> data;
	int highestlevel = -1;
	
	reclevelOrder(m_anker, data, 0, highestlevel);
	if (highestlevel == -1)
	{
		std::cout << ">> There is no content!\n";
	}
	else
	{
		std::cout << left << setw(4) << setfill(' ') << " ID " << "|" << setw(18) << setfill(' ') << " Name " << "|" << setw(6) << setfill(' ') << " Age" << "|" << setw(11) << setfill(' ') << " Income " << "|" << setw(10) << setfill(' ') << " PostCode " << "|" << setw(10) << setfill(' ') << " OrderID " <<"|" << setw(8) << setfill(' ') << " Level" << std::endl;
		std::cout << left << setw(4) << setfill('-') << "-" << setw(19) << setfill('-') << "+" << setw(7) << setfill('-') << "+" << setw(12) << setfill('-') << "+" << setw(11) << setfill('-') << "+" << setw(11) << setfill('-') << "+" << setw(8) << setfill('-') << "+" << std::endl;

		for (int i = 0; i <= highestlevel; i++)
		{
			for (int x = 0; x < data.at(i).size(); x++)
			{
				std::cout << right << setw(4) << setfill(' ') << data.at(i).at(x)->getNodeChronologicalID() << "|" << setw(18) << setfill(' ') << data.at(i).at(x)->getName() << "|" << setw(6) << setfill(' ') << data.at(i).at(x)->getAge() << "|" << setw(11) << setfill(' ') << data.at(i).at(x)->getIncome() << "|" << setw(10) << setfill(' ') << data.at(i).at(x)->getPostCode() << "|" << setw(9) << setfill(' ') << data.at(i).at(x)->getNodeOrderID() << "|" << setw(8) << setfill(' ') << i+1 << std::endl;
			}

		}
	}
}
void Tree::reclevelOrder(TreeNode* tmp,std::vector<std::vector<TreeNode*>> &data, int level, int &highestlevel)
{
	if (tmp != nullptr)
	{
		if ((highestlevel < level))
		{
			vector<TreeNode*> newlevel;
			data.push_back(newlevel);
			highestlevel++;
		}
		data.at(level).push_back(tmp);
		if (tmp->getLeft())reclevelOrder(tmp->getLeft(), data, level + 1, highestlevel);
		if (tmp->getRight())reclevelOrder(tmp->getRight(), data, level + 1, highestlevel);
	}
}
void Tree::receintrag(TreeNode* comp, TreeNode* add)
{
	if (comp->getNodeOrderID() > add->getNodeOrderID())
	{
		if (comp->getLeft() == nullptr) comp->setLeft(add);
		else receintrag(comp->getLeft(), add);
	}
	else if (comp->getNodeOrderID() == add->getNodeOrderID()) return;
	else
	{
		if (comp->getRight() == nullptr) comp->setRight(add);
		else receintrag(comp->getRight(), add);
	}
}
void Tree::recsearch(TreeNode* comp, std::string Name, bool &found)
{
	if (comp->getName() == Name)
	{
		found = true;
		std::cout << Name;
	}
	if (comp->getRight() != nullptr) recsearch(comp->getRight(), Name, found);
	if (comp->getLeft() != nullptr) recsearch(comp->getLeft(), Name, found);
}
void Tree::recursvie_links_finden(int delID, TreeNode*& ptr, TreeNode*& parent)
{
	if (ptr->getNodeOrderID() == delID)
		return;

	parent = ptr;
	if (ptr->getNodeOrderID() > delID)
	{
		ptr = ptr->getLeft();
		recursvie_links_finden(delID, ptr, parent);
	}
	else
	{
		ptr = ptr->getRight();
		recursvie_links_finden(delID, ptr, parent);
	}
}
bool Tree::deleteNode(int del_PosID)
{
	if (m_anker == nullptr)
	{
		cout << "ERROR: Fehler ist leer" << endl;
		return false;
	}
	else
	{
		
		TreeNode* ptr = m_anker;
		TreeNode* parent_ptr = ptr;
		recursvie_links_finden(del_PosID, ptr, parent_ptr);

	
		bool isRoot = false;


		
		if (ptr == parent_ptr)
			isRoot = true;

		
		if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr)
		{
			if (isRoot)m_anker = nullptr;
			else if (parent_ptr->getLeft() == ptr) parent_ptr->setLeft(nullptr);
			else parent_ptr->setRight(nullptr);

			delete ptr; 
		   
		}
		else if (ptr->getLeft() == nullptr && ptr->getRight() != nullptr)					
		{
			if (isRoot)m_anker = ptr->getRight();
			else if (parent_ptr->getLeft() == ptr) parent_ptr->setLeft(ptr->getRight());
			else parent_ptr->setRight(ptr->getRight());

			delete ptr;
		}
		else if (ptr->getLeft() != nullptr && ptr->getRight() == nullptr)					
		{
			if (isRoot) m_anker = ptr->getLeft();
			else if (parent_ptr->getLeft() == ptr) parent_ptr->setLeft(ptr->getLeft());
			else parent_ptr->setRight(ptr->getLeft());

			delete ptr;

			
		}
		else if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) 
		{
			
			TreeNode* min = ptr->getRight();
			TreeNode* parent_min = min;

			while (min->getLeft() !=nullptr) 
			{
				parent_min = min;
				min = min->getLeft();
			}

			
			if (ptr->getRight() == min)  min->setLeft(ptr->getLeft());
			else
			{
				parent_min->setLeft(min->getRight());

				min->setLeft(ptr->getLeft());
				min->setRight(ptr->getRight());
			}

			if (isRoot)
			{
				m_anker = min;
			}
			else
			{
				if (parent_ptr->getLeft() == ptr)parent_ptr->setLeft(min);
				else parent_ptr->setRight(min);

			}
			delete ptr;
		}
		cout << "ENTRY DELETED" << endl;
	}
	return true;
}
//
////////////////////////////////////
