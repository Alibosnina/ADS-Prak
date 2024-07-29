/*************************************************
 * ADS Praktikum 2.2
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
    int NodeOrderID;
    int NodeChronologicalID;
    std::string Name;
    int Age;
    double Income;
    int PostCode;
    TreeNode* left;
    TreeNode* right;

    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode);
        int getNodeOrderID();
        int getNodeChronologicalID();
        std::string getName();
        int getAge();
        double getIncome();
        int getPostCode();
        TreeNode* getLeft() { return left; }
        TreeNode* getRight() { return right; }
        void setNodeOrderID(int val);
        void setNodeChronologicalID(int val);
        void setName(std::string val);
        void setAge(int val);
        void setIncome(double val);
        void setPostCode(double val);
        void setLeft(TreeNode* val);
        void setRight(TreeNode* val);
    //
    ////////////////////////////////////
};
