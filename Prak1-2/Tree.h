/*************************************************
 * ADS Praktikum 2.2
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
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* m_anker;
    int currentNodeChronologicalID;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree()
    {
        m_anker = nullptr;
    };
    void destruct(TreeNode* tmp);
    ~Tree()
    {
        destruct(m_anker);
    };
    int getcurrentNodeconicalID() { return currentNodeChronologicalID; };
    void setcurrentNodeChronicalID(int zahl) {
        currentNodeChronologicalID = zahl;
    };
    void addNode(string Name, int Age, double Income, int PostCode);
    bool deleteNode(int NoteOrderID);
    bool searchNode(string Name);
    void printAll();
    void receintrag(TreeNode* comp, TreeNode* add);
    void recsearch(TreeNode* comp, std::string Name, bool &found);
    void preOrder(TreeNode* wurzel);
    void reclevelOrder(TreeNode* tmp, std::vector<std::vector<TreeNode*>>& data, int level, int &highestlevel);
    void levelOrder();
    void recursvie_links_finden(int delID, TreeNode*& ptr, TreeNode*& parent);
    void postOrder(TreeNode* wurzel);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
