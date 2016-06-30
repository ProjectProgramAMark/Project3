#pragma once

#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include "tinyxml.h"

using namespace std;

template<class Type>
class GeneralTree {
private:
    TreeNode<Type> *root;
public:
    GeneralTree() {
//        buildTree();
    }


    TreeNode<Type> *getRoot() {
        cout << "Get Root implemented" << endl;
        return root;
    }

    int getSize() {
        cout << "Get Size implemented" << endl;
        return 1;
    }

    int getHeight() {
        cout << "Get Height implemented" << endl;

        return 1;
    }

    int getHeight(TreeNode<Type> *node) {
        cout << "Get Height of specific node implemented" << endl;
        return 1;

    }

    int getDepth(TreeNode<Type> *node) {
        cout << "Get Depth of specific node implemented" << endl;
        return 1;

    }

    bool empty() {
        cout << "Is Empty implemented" << endl;
        return true;
    }

    int leaves() {
        cout << "Get Leaves implemented" << endl;
        return 1;

    }

    int siblings(TreeNode<Type> *node) {
        cout << "Get Siblings implemented" << endl;
        return 1;

    }

    TreeNode<Type> *findCommonAncestor(TreeNode<Type> *node1, TreeNode<Type> *node2) {
        cout << "Find common ancestors implemented" << endl;
        return root;
    }

    TreeNode<Type> *findNode(Type data) {
        cout << "Find node implemented" << endl;
        return root;

    }

    void preorder() {
        cout << "Preorder implemented" << endl;

    }

    void postorder() {
        cout << "Postorder implemented" << endl;

    }

    void levelorder() {
        cout << "Levelorder implemented" << endl;


    }

    void buildTree() {
        cout << "Build Tree implemented" << endl;
        // Loading XML file and getting rootNode
        string filename = "generalTree.xml";
        TiXmlDocument doc(filename);
        bool loadOkay = doc.LoadFile();
        if (!loadOkay) {
            cout << "Could not load file " << filename << endl;
            cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
        }
        TiXmlNode* generalTreeNode = doc.FirstChild("GeneralTree");
        assert(generalTreeNode != 0);

        TiXmlNode* rootNode = generalTreeNode->FirstChild();
        assert(rootNode != 0);

        // Populating the rest of the tree via recursive function
        recFunction(rootNode);
    }

    void recFunction(TiXmlNode *node) {
        if(node->FirstChildElement() != NULL) {
            // Do something
        } else {
            int key = stoi(node->ToElement()->Attribute("key"));
            Type data = node->ToElement()->Attribute("data");
            TreeNode<Type> *treeNode = new TreeNode<Type>("General", key, data);
            return recFunction(node->FirstChild());
        }
        // After recursiveness is finished
        while(node->NextSibling() != NULL) {
            // Converting XML node to TreeNode
            // Making previous and current nodes
            int key = stoi(node->ToElement()->Attribute("key"));
            Type data = node->ToElement()->Attribute("data");
            TreeNode<Type> *prev = new TreeNode<Type>("General", key, data);
            int key2 = stoi(node->NextSibling()->ToElement()->Attribute("key"));
            Type data2 = node->NextSibling()->ToElement()->Attribute("data");
            TreeNode<Type> *cur = new TreeNode<Type>("General", key2, data2);
            // Create linked list of siblings
            prev->setSibling(cur);
        }
    }

    void clear() {
        cout << "Clear implemented" << endl;

    }

    void display() {
        // Breadth First Traversal
    }

    // Can use as many parameters as we need here
    void insert(TreeNode<Type> *data) {
        cout << "Insert implemented" << endl;

    }

    void del(TreeNode<Type> *data) {
        cout << "Delete implemented" << endl;
    }

};