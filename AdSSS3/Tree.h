/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

class Tree
{

private:
    TreeNode* m_anker;
    int m_CurrentNodeChronologicalID;

public:
    Tree();
    ~Tree();
    bool addNode(string N, int Alt, double in, int PC);
    bool searchNode(string Nm);
    bool searcht(TreeNode* ptr, std::string nm);
    void printAll();
    void preOrder(TreeNode* ptr);
    void printLvlOrder();
    void levelOrder(TreeNode* ptr);


    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben!
    friend TreeNode* get_anker(Tree& TN);
    
    void printLevelOrder();
    void printLevelOrder(int n);
    void balance(TreeNode* p);
    bool split4Node(TreeNode* p);
    int proofRBCriterion(TreeNode* p);
    bool rotateTreeRight(TreeNode* p1, TreeNode* p2);
    bool rotateTreeLeft(TreeNode* p1, TreeNode* p2);
};
