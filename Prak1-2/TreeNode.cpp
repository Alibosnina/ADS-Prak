/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

////////////////////////////////////
// Ihr Code hier:
TreeNode::TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode)
    {
        this->NodeOrderID = NodeOrderID;
        this->NodeChronologicalID = NodeChronologicalID;
        this->Name = Name;
        this->Age = Age;
        this->Income = Income;
        this->PostCode = PostCode;
    }
        int TreeNode::getNodeOrderID() { return NodeOrderID; }
        int TreeNode::getNodeChronologicalID() {return NodeChronologicalID; }
        std::string TreeNode::getName() { return Name; }
        int TreeNode::getAge() { return Age; }
        double TreeNode::getIncome() { return Income; }
        int TreeNode::getPostCode() { return PostCode; }
        void TreeNode::setNodeOrderID(int val) { this->NodeOrderID = val; }
        void TreeNode::setNodeChronologicalID(int val) { this->NodeChronologicalID = val; }
        void TreeNode::setName(std::string val) { this->Name = val; }
        void TreeNode::setAge(int val) { this->Age = val; }
        void TreeNode::setIncome(double val) { this->Income = val; }
        void TreeNode::setPostCode(double val) { this->PostCode = val; }
        void TreeNode::setLeft(TreeNode* val) { this->left = val; }
        void TreeNode::setRight(TreeNode* val) { this->right = val; }
//
////////////////////////////////////
