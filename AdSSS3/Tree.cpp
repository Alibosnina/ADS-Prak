/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;
////////////////////////////////////
// Ihr Code hier:
Tree::Tree() {
	m_anker = 0;
	m_CurrentNodeChronologicalID = 0;
}

Tree::~Tree() {
	/////
	//
	//
	/////
}



bool Tree::addNode(string N, int Alt, double in, int PC) {
    TreeNode* nData = new TreeNode(Alt + in + PC, m_CurrentNodeChronologicalID, N, Alt, in, PC);
    if (m_anker == 0) {
        m_anker = nData;
        m_anker->setRed(0); // Root is black
        m_CurrentNodeChronologicalID++;
        return true;
    }
    
    m_CurrentNodeChronologicalID++;
    TreeNode* ptr = m_anker;
    TreeNode* prnt = nullptr;

    while (ptr != nullptr) {
        prnt = ptr;
        if (nData->getNodeOrderID() >= ptr->getNodeOrderID())
            ptr = ptr->getRight();
        else
            ptr = ptr->getLeft();
    }

    nData->setParent(prnt);
    if (nData->getNodeOrderID() < prnt->getNodeOrderID())
        prnt->setLeft(nData);
    else
        prnt->setRight(nData);

    balance(nData); // Ensure the tree is balanced after insertion
    return true;
}



bool Tree::searchNode(string Nm) {
	cout << "+Fundstellen: \n";
	if (searcht(m_anker, Nm))
		return 1;

	else {
		cout << "konnte nicht gefunden.\n";
		return 0;
	}
}
bool Tree::searcht(TreeNode* head, std::string nm) {
	if (head == 0)
		return 0;
	if (head->getName() == nm) {
		head->print();
		return true;
	}
	return searcht(head->getLeft(), nm) | searcht(head->getRight(), nm);
}
void Tree::printAll() {
	cout << left << setw(4) << " ID";
	cout << left << setw(19) << "| Name";
	cout << left << setw(8) << "| Age";
	cout << left << setw(12) << "| Income";
	cout << left << setw(11) << "| PostCode";
	cout << left << setw(7) << "| OrderID";
	cout << left << setw(7) << "| Red\n";


	cout << right << setfill('-');
	cout << setw(5) << "+";
	cout << setw(19) << "+";
	cout << setw(8) << "+";
	cout << setw(12) << "+";
	cout << setw(11) << "+";
	cout << setw(8) << "+";
	cout << setw(7) << "-" << endl;
	preOrder(m_anker);
}

void Tree::preOrder(TreeNode* ptr) {
	if (ptr == 0) {
		cout << "Baum ist Leer." << endl;
		return;
	}
	cout << setfill(' ');
	cout << setw(4) << ptr->getNodeChronologicalID() << "|";
	cout << setw(18) << ptr->getName() << "|";
	cout << setw(7) << ptr->getAge() << "|";
	cout << setw(11) << ptr->getIncome() << "|";
	cout << setw(10) << ptr->getPostCode() << "|";
	cout << setw(8) << ptr->getNodeOrderID() << "|";
	cout << setw(6) << ptr->getRed() << endl;
	if (ptr->getRight() != 0)
		preOrder(ptr->getRight());
	if (ptr->getLeft() != 0)
		preOrder(ptr->getLeft());
}
void Tree::printLvlOrder() {
	cout << left << setw(4) << " ID";
	cout << left << setw(19) << "| Name";
	cout << left << setw(8) << "| Age";
	cout << left << setw(12) << "| Income";
	cout << left << setw(11) << "| PostCode";
	cout << left << setw(7) << "| OrderID";
	cout << left << setw(7) << "| Red\n";


	cout << right << setfill('-');
	cout << setw(5) << "+";
	cout << setw(19) << "+";
	cout << setw(8) << "+";
	cout << setw(12) << "+";
	cout << setw(11) << "+";
	cout << setw(8) << "+";
	cout << setw(7) << "-" << endl;
	levelOrder(m_anker);
}
void Tree::levelOrder(TreeNode* ptr) {
	queue<TreeNode*> q;
	if (ptr == 0) {
		cout << "Baum ist Leer." << endl;
		return;
	}
	q.push(ptr);
	TreeNode* tmp = ptr;
	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			tmp = q.front();
			cout << setfill(' ');
			cout << setw(4) << tmp->getNodeChronologicalID() << "|";
			cout << setw(18) << tmp->getName() << "|";
			cout << setw(7) << tmp->getAge() << "|";
			cout << setw(11) << tmp->getIncome() << "|";
			cout << setw(10) << tmp->getPostCode() << "|";
			cout << setw(8) << tmp->getNodeOrderID() << "|";
			cout << setw(6) << tmp->getRed() << endl;
			if (tmp->getLeft())
				q.push(tmp->getLeft());
			if (tmp->getRight())
				q.push(tmp->getRight());
			
			q.pop();
			count--;
		}
	}
}


/////Praktiku-03

void Tree::printLevelOrder() {
	queue<TreeNode*> q;
	int niv = 0;

	if (m_anker == 0) {
		cout << "Baum ist Leer." << endl;
		return;
	}
	q.push(m_anker);
	TreeNode* Ptr = m_anker;
	while (!q.empty()) {
		int count = q.size();
		cout << "Niveau " << niv << ": ";
		while (count > 0) {
			Ptr = q.front();
			if (Ptr->getLeft()) {
				if (!Ptr->getLeft()->getRed()) {
					q.push(Ptr->getLeft());
					cout << "(";
				}
				else {
					if (Ptr->getLeft()->getLeft()) 
						q.push(Ptr->getLeft()->getLeft());
					
					if (Ptr->getLeft()->getRight()) 
						q.push(Ptr->getLeft()->getRight());
					
					cout << "(" << Ptr->getLeft()->getNodeOrderID() << ", ";
				}
			}
			else {
				cout << "(";
			}

			cout << Ptr->getNodeOrderID();

			if (Ptr->getRight()) {
				if (!Ptr->getRight()->getRed()) {
					q.push(Ptr->getRight());
					cout << ")";
				}
				else {
					if (Ptr->getRight()->getLeft())
						q.push(Ptr->getRight()->getLeft());

					if (Ptr->getRight()->getRight())
						q.push(Ptr->getRight()->getRight());

					cout << ", " << Ptr->getRight()->getNodeOrderID() << ")";
				}
			}else
				cout << ")";
			q.pop();
			count--;
		}
		niv++;
		cout << endl;
	}
}

void Tree::printLevelOrder(int lvl) {
	queue<TreeNode*> q;
	int niv = 0;

	if (m_anker == 0) {
		cout << "Baum ist Leer." << endl;
		return;
	}
	q.push(m_anker);
	TreeNode* Ptr = m_anker;
	while (!q.empty()) {
		int count = q.size();
		if (niv == lvl)
			cout << "Niveau " << niv << ": ";
		while (count > 0) {
			Ptr = q.front();
			if (Ptr->getLeft()) {
				if (!Ptr->getLeft()->getRed()) {
					q.push(Ptr->getLeft());
					if (niv == lvl)
						cout << "(";
				}
				else {
					if (Ptr->getLeft()->getLeft())
						q.push(Ptr->getLeft()->getLeft());

					if (Ptr->getLeft()->getRight())
						q.push(Ptr->getLeft()->getRight());
					if (niv == lvl)
						cout << "(" << Ptr->getLeft()->getNodeOrderID() << ", ";
				}
			}
			else {
				if (niv == lvl)
					cout << "(";
			}
			if (niv == lvl)
				cout << Ptr->getNodeOrderID();
			if (Ptr->getRight()) {
				if (!Ptr->getRight()->getRed()) {
					q.push(Ptr->getRight());
					if (niv == lvl)
						cout << ")";
				}
				else {
					if (Ptr->getRight()->getLeft())
						q.push(Ptr->getRight()->getLeft());

					if (Ptr->getRight()->getRight())
						q.push(Ptr->getRight()->getRight());
					if (niv == lvl)
						cout << ", " << Ptr->getRight()->getNodeOrderID() << ")";
				}
			}
			else
				if (niv == lvl)
					cout << ")";
			q.pop();
			count--;
		}
		niv++;
		cout << endl;
	}
}

bool Tree::split4Node(TreeNode* p) {
	

	if (p->getRed()) {                    //wenn Knoten rot ist
		return 0;
	}
	if (p->getLeft() != 0 && p->getRight() != 0) {          //rechter und linker knoten existieren

		if (p->getLeft()->getRed() && p->getRight()->getRed()) {           //beide sind rot

			if (m_anker != p) {
				p->setRed(1);
			}
			p->getLeft()->setRed(0);      //Knoten schwarz setzten
			p->getRight()->setRed(0);       //Knoten schwarz setzten
			return 1;

		}

	}
	return 0;
}

void Tree::balance(TreeNode* n) {
    while (n != m_anker && n->getParent()->getRed() == 1) {
        TreeNode* parent = n->getParent();
        TreeNode* grandParent = parent->getParent();

        if (parent == grandParent->getLeft()) {
            TreeNode* uncle = grandParent->getRight();
            if (uncle != nullptr && uncle->getRed() == 1) {
                grandParent->setRed(1);
                parent->setRed(0);
                uncle->setRed(0);
                n = grandParent;
            } else {
                if (n == parent->getRight()) {
                    rotateTreeLeft(parent, n);
                    n = parent;
                    parent = n->getParent();
                }
                rotateTreeRight(grandParent, parent);
                parent->setRed(0);
                grandParent->setRed(1);
                n = parent;
            }
        } else {
            TreeNode* uncle = grandParent->getLeft();
            if (uncle != nullptr && uncle->getRed() == 1) {
                grandParent->setRed(1);
                parent->setRed(0);
                uncle->setRed(0);
                n = grandParent;
            } else {
                if (n == parent->getLeft()) {
                    rotateTreeRight(parent, n);
                    n = parent;
                    parent = n->getParent();
                }
                rotateTreeLeft(grandParent, parent);
                parent->setRed(0);
                grandParent->setRed(1);
                n = parent;
            }
        }
    }
    m_anker->setRed(0);
}


int Tree::proofRBCriterion(TreeNode* p) {
    if (p == nullptr) {
        return 1;  // Null nodes are black
    }

    int leftHeight = proofRBCriterion(p->getLeft());
    int rightHeight = proofRBCriterion(p->getRight());

    if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight) {
        return -1;  // Invalid tree if left and right heights are not equal
    }

    if (p->getRed() == 1) {
        if ((p->getLeft() && p->getLeft()->getRed() == 1) ||
            (p->getRight() && p->getRight()->getRed() == 1)) {
            return -1;
        }
        return leftHeight;  
    } else {
        return leftHeight + 1;  // Black node, increment the black height
    }
}



bool Tree::rotateTreeRight(TreeNode* p1, TreeNode* p2) {
    if (p1 == m_anker){
        m_anker = p2;
        p2->setParent(nullptr);
    }
    else {
        TreeNode* prnt = p1->getParent();
        if (prnt->getNodeOrderID() > p2->getNodeOrderID()) {
            prnt->setLeft(p2);
        } else {
            prnt->setRight(p2);
        }
        p2->setParent(prnt);
    }
    p1->setLeft(p2->getRight());
    if (p1->getLeft() != nullptr)
        p1->getLeft()->setParent(p1);
    p2->setRight(p1);
    p1->setParent(p2);
    return true;
}

bool Tree::rotateTreeLeft(TreeNode* p1, TreeNode* p2) {
    if (p1 == m_anker) {
        m_anker = p2;
        p2->setParent(nullptr);
    }
    else {
        TreeNode* prnt = p1->getParent();
        if (prnt->getNodeOrderID() > p2->getNodeOrderID()) {
            prnt->setLeft(p2);
        } else {
            prnt->setRight(p2);
        }
        p2->setParent(prnt);
    }
    p1->setRight(p2->getLeft());
    if (p1->getRight() != nullptr)
        p1->getRight()->setParent(p1);
    p2->setLeft(p1);
    p1->setParent(p2);
    return true;
}


//
////////////////////////////////////