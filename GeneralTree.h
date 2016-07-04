#pragma once

#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include "tinyxml.h"
#include <queue>
#include <cmath>

using namespace std;

const int CAP = 10;

template<class Type>
class GeneralTree {
private:
    TreeNode<Type> *root;
    TreeNode<Type> ***array;
    int height;
    int size;
    int parentSize = 0;
    int childSize = 0;
public:
    GeneralTree()
            : root(nullptr), height(0), size(0) {
        array = new TreeNode<Type> **[CAP];
        for (int i = 0; i < CAP; i++) {
            array[i] = new TreeNode<Type> *[CAP];
        }
        for (int i = 0; i < CAP; i++) {
            for (int j = 0; j < CAP; j++) {
                array[i][j] = new TreeNode<Type>("General", " ");
            }
        }
    }


    TreeNode<Type> *getRoot() {
        cout << "Get Root implemented" << endl;
        return root;
    }

    int getSize() {
        cout << "Get Size implemented" << endl;
        return size;
    }

    int getHeight() {
        double height = (log(size) / log(2));
        return (int) height;
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
        return size == 0;
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

    void preorder(TreeNode<Type> *node) {
        // Visiting the node
        cout << "Key: " << node->getKey() << "Value: "<< node->getValue() << endl;
        // Traversing down children via left
        if(node->getChildren() != nullptr) {
            preorder(node->getChildren());
        }
//         Traversing left children's siblings, A.K.A traversing right
        if(node->getSibling() != nullptr) {
            preorder(node->getSibling());
        }
    }

    void postorder(TreeNode<Type> *node) {
        // Traversing down children via left
        if(node->getChildren() != nullptr) {
            preorder(node->getChildren());
        }
        // Traversing left children's siblings, A.K.A traversing right
        if(node->getSibling() != nullptr) {
            preorder(node->getSibling());
        }
        // Visiting the node
        cout << "Key: " << node->getKey() << "Value: "<< node->getValue() << endl;
    }

    void levelorder(TreeNode<Type> *root) {
        cout << "Levelorder implemented" << endl;
        queue<TreeNode<Type>> *queue = new ::queue<TreeNode<Type>>();
        unsigned long count = 0;
        int level = 0;
        TreeNode<Type> *node = new TreeNode<Type>("General");
        queue->push(*root);
        count++;
        while(!(queue->empty())) {
            *node = queue->front();
            queue->pop();
            cout << node->getValue() << " ";
            TreeNode<Type> *tempNode = node->getChildren();
            if(tempNode) {
                while(tempNode->getSibling() != nullptr) {
                    queue->push(*tempNode);
                    tempNode = tempNode->getSibling();
                }
            }
            if(--count == 0) {
                count = queue->size();
                level++;
            }
        }
        height = level;
    }

    void buildTree() {
        ifstream file;
        int key1, key2, key3;
        string value, input;
        file.open("/home/randomguy/ClionProjects/Project3/GenTree.txt");
        if (file.is_open()) {
            cout << "File Opened." << endl;
        }
        else {
            cerr << "File could not be opened." << endl;
        }

        while (file) {
            file >> key1;
            getline(file, input, '.');
            file >> key2;
            getline(file, input, '.');
            file >> key3;
            getline(file, input, '\n');
            value = input;
            if (file.eof()) { break; }
            cout << key1 << key2 << key3 << value << endl;
            this->insert(key1, key2, key3, value);
        }
        file.close();
//        cout << "Build Tree implemented" << endl;
        // Loading XML file and getting rootNode
//        string filename = "generalTree.xml";
//        TiXmlDocument doc(filename);
//        bool loadOkay = doc.LoadFile();
//        if (!loadOkay) {
//            cout << "Could not load file " << filename << endl;
//            cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
//        }
//        TiXmlNode* generalTreeNode = doc.FirstChild("GeneralTree");
//        assert(generalTreeNode != 0);
//
//        TiXmlNode* rootNode = generalTreeNode->FirstChild();
//        assert(rootNode != 0);
//        int key = stoi(rootNode->ToElement()->Attribute("key"));
//        Type data = rootNode->ToElement()->GetText();
//        root = new TreeNode<Type>("General", key, data);
//        // Populating the rest of the tree via recursive function
//        recFunction(rootNode);
    }

//    void recFunction(TiXmlNode *node) {
//        if(node->FirstChildElement() == NULL) {
//            cout << "First child element is null" << endl;
//            // Do something
//        } else {
//            int key = stoi(node->ToElement()->Attribute("key"));
//            Type data = node->ToElement()->GetText();
//            TreeNode<Type> *treeNode = new TreeNode<Type>("General", key, data);
//            cout << "Right BEFORE recursive activates" << endl;
//            return recFunction(node->FirstChild());
//        }
//        cout << "After recursiveness done" << endl;
//        // After recursiveness is finished
//        while(node->NextSibling() != NULL) {
//            // Converting XML node to TreeNode
//            // Making previous and current nodes
//            cout << "DOING NODE TO ELEMENT" << endl;
//            cout << node->ToText()->Value() << endl;
//            cout << node->ToElement()->Attribute("key") << endl;
//            cout << "DONE WITH NODE TO ELEMENT" << endl;
//            int key = stoi(node->ToElement()->Attribute("key"));
//            cout << "Key 1 is: " << key << endl;
//            Type data = node->ToElement()->GetText();
//            cout << "Data 1 is: " << data << endl;
//            TreeNode<Type> *prev = new TreeNode<Type>("General", key, data);
//            int key2 = stoi(node->NextSibling()->ToElement()->Attribute("key"));
//            Type data2 = node->ToElement()->GetText();
//            TreeNode<Type> *cur = new TreeNode<Type>("General", key2, data2);
//            // Create linked list of siblings
//            prev->setSibling(cur);
//            node = node->NextSibling();
//        }
//        cout << "End of while loop reached" << endl;
//    }

    void clear() {
        cout << "Clear implemented" << endl;

    }

    void display() {
        // Breadth First Traversal
        cout << root->getValue() << endl;
        for (int i = 1; i <= parentSize; i++) {
            cout << array[i][0]->getValue() << " ";
        }
        cout << endl;
        for (int i = 1; i <= parentSize; i++) {
            for (int j = 1; j <= childSize; j++) {
                cout << array[i][j]->getValue() << " ";
            }
        }

    }

    // Can use as many parameters as we need here
    void insert(int head, int parent, int child, Type data) {
        TreeNode<Type> *node = new TreeNode<Type>("General", data);
        TreeNode<Type> *ptr = root;
        if (head == 0 && parent == 0 && child == 0) { //Checks if root
            cout << "Creating root." << endl;
            root = node;
            size++;
        }
        else {
            if (child == 0) {
                array[parent][child] = node; //Sets parent node
                size++;
                parentSize++;
            }
            else {
                array[parent][child] = node;
                size++;
                if (child > childSize) {
                    childSize = child;
                }

            }
        }
    }

    void del(TreeNode<Type> *data) {
        cout << "Delete implemented" << endl;
    }

};