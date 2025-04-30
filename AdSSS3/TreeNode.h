/*************************************************
* ADS Praktikum 3
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    std::string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode;
    bool red;
    TreeNode* m_left;
    TreeNode* m_right;
    TreeNode* parent;

    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode();
    TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode);
    
    void print() const;	

    int getNodeOrderID() { return m_NodeOrderID; }
    void setNodeOrderID(int val) { this->m_NodeOrderID = val; }

    int getNodeChronologicalID() {return m_NodeChronologicalID;}
    void setNodeChronologicalID(int val) { this->m_NodeChronologicalID = val; }

    std::string getName() { return m_Name; }
    void setName(std::string val) { this->m_Name = val; }

    int getAge() { return m_Age; }
    void setAge(int val) { this->m_Age = val; }

    double getIncome() { return m_Income; }
    void setIncome(double val) { this->m_Income = val; }

    int getPostCode() { return m_PostCode; }
    void setPostCode(double val) { this->m_PostCode = val; }

    TreeNode* getLeft() { return m_left; }
    void setLeft(TreeNode* val) { this->m_left = val; }

    TreeNode* getRight() { return m_right; }
    void setRight(TreeNode* val) { this->m_right = val; }

    TreeNode* getParent() { return parent; }
    void setParent(TreeNode* parent) { this->parent = parent; }


    bool getRed() {return red;}
    void setRed(bool r){red = r;}
    //
    ////////////////////////////////////
};
