#pragma once

#include "TreeNode.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class Type>
class GeneralTree {
private:
    TreeNode<Type> *root;
public:
    GeneralTree() {
        buildTree();
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

    void inorder() {
        cout << "Inorder implemented" << endl;

    }


    void buildTree() {
        cout << "Build Tree implemented" << endl;
        string line;
        ifstream treeFile("generalTree.txt");
        if (treeFile.is_open()) {
            while (getline(treeFile, line)) {
                unsigned long pos = line.find(' ');
                string data = line.substr(0, pos);
//                cout << "Data is: " << data << endl;
                string str = line.substr(pos + 1);
//                cout << "Str is: " << str << endl;
                pos = str.find_last_of('.');
                string str2 = str.substr(pos + 1);
//                cout << "Str2 is: " << str2 << endl;
                string::size_type sz;
                int node_pos = stoi(str2, &sz);
//                cout << "Node_pos is: " << node_pos << endl;
                string parent = str.substr(0, pos);
//                cout << "Parent is: " << parent << endl;
                //TreeNode<Type> *ptr = findNode(str);
                //insert(data, ptr, node_pos);
            }
            treeFile.close();
        }
        else cout << "Unable to open file";
    }

    void clear() {
        cout << "Clear implemented" << endl;

    }

    // Can use as many parameters as we need here
    void insert(TreeNode<Type> *data) {
        cout << "Insert implemented" << endl;

    }

    void del(TreeNode<Type> *data) {
        cout << "Delete implemented" << endl;
    }

};