#pragma once
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class Type> class AVLTree {
private:
    TreeNode<Type> *node;
public:

    AVLTree() {
        cout << "Constructor activated" << endl;
    }

    TreeNode<Type> *getRoot() {
        cout << "Get Root implemented" << endl;
        return node;
    }
    int getSize() {
        cout << "Get Size implemented" << endl;
        return 1;
    }
    int getHeight() {
        cout << "Get Height implemented" << endl;
        return 1;
    }
    int getHeight(TreeNode<Type> node) {
        cout << "Get Height of specific node implemented" << endl;
        return 1;

    }
    int getDepth(TreeNode<Type> node) {
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
    int siblings(TreeNode<Type> node) {
        cout << "Get Siblings implemented" << endl;
        return 1;

    }
    TreeNode<Type> *find(int key, Type data) {
        cout << "Find node implemented" << endl;
        return node;

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
    }


    void clear() {
        cout << "Clear implemented" << endl;

    }

    // Can use as many parameters as we need here
    void insert(TreeNode<Type> data) {
        cout << "Insert implemented" << endl;

    }

    void del(TreeNode<Type> data) {
        cout << "Delete implemented" << endl;
    }
};