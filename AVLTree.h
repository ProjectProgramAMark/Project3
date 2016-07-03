#pragma once
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class Type> class AVLTree {
private:
    TreeNode<Type> *root;
    int sz;
public:

    AVLTree(Type value) : sz(0) {
        root = new TreeNode<Type>("AVL", value);
    }

    AVLTree(Type value, int key) : sz(0) {
        root = new TreeNode<Type>("AVL", key, value);
    }

    AVLTree(int key) : sz(0) {
        root = new TreeNode<Type>("AVL", key);
    }

    AVLTree() : sz(0), root(NULL) { };

    TreeNode<Type> *getRoot() {
        if (root) {
            return root;
        }
        cout << "Root is empty" << endl;
        return NULL;
    }

    int getSize() {
        return sz;
    }

    int getHeight() {
        if (!empty()) {
            int left = getHeight(root->getLeft());
            int right = getHeight(root->getRight());
            int height = right;
            if (left > right) {
                height = left;
            }
            return height;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    int getHeight(TreeNode<Type> *node) {
        if (!node) {
            return 0;
        }
        int left = getHeight(node->getLeft());
        int right = getHeight(node->getRight());

        int height = right;
        if (left > right) {
            height = left;
        }
        return height + 1;
    }

    int getDepth(TreeNode<Type> *node) {
        if (!empty()) {
            int depth = 0;
            TreeNode<Type> *temp = root;
            while (temp->getKey() != node->getKey()) {
                if (temp->getKey() > node->getKey()) {
                    temp = temp->getLeft();
                }
                else {
                    temp = temp->getRight();
                }
                depth += 1;
            }
            return depth + 1;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    bool empty() {
        if (!root) {
            return true;
        }
        return false;
    }

    int leaves() {
        if (!empty()) {
            int leave = 0;
            leave = leaves(root, leave);
            return leave;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    int leaves(TreeNode<Type> *node, int leave) {
        if (node && !node->getLeft() && !node->getRight()) {
            leave += 1;
        }
        else if (node) {
            int LLeft = leaves(node->getLeft(), leave);
            int LRight = leaves(node->getRight(), leave);
            leave += LLeft + LRight;
        }
        return leave;
    }

    int siblings(TreeNode<Type> *node) {
        if (node && !empty()) {
            int Left = siblings(node->getLeft());
            int Right = siblings(node->getRight());
            return Right + Left + 1;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    TreeNode<Type> *find(int key, Type data) {
        if (!empty()) {
            TreeNode<Type> *temp = root;
            while (temp->getKey() != key && temp->getValue() != data) {
                if (temp->getValue() > data) {
                    temp = temp->getLeft();
                }
                else {
                    temp = temp->getRight();
                }
            }
            if (temp->getValue() != data) {
                cout << "Couldn't find node" << endl;
                return NULL;
            }
            return temp;
        }
        cout << "Tree is empty" << endl;
        return NULL;
    }

    void preorder() {
        if (!empty()) {
            preorder(root);
        }
        else {
            cout << "Tree is empty" << endl;
        }
    }

    void preorder(TreeNode<Type> *node) {
        if (node) {
            cout << "Key: " << node->getKey() << " Value: " << node->getValue() << endl;
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }

    void postorder() {
        if (!empty()) {
            postorder(root);
        }
        else {
            cout << "Tree is empty" << endl;
        }
    }

    void postorder(TreeNode<Type> *node) {
        if (node) {
            postorder(node->getLeft());
            postorder(node->getRight());
            cout << "Key: " << node->getKey() << " Value: " << node->getValue() << endl;
        }

    }
    void levelorder() {
        if (!empty()) {
            queue<TreeNode<Type> *> *queue = new ::queue<TreeNode<Type> *>();
            queue->push(root);
            TreeNode<Type> *temp = NULL;
            while (!queue->empty()) {
                temp = queue->front();
                queue->pop();
                if (temp->getLeft()) {
                    queue->push(temp->getLeft());
                }
                if (temp->getRight()) {
                    queue->push(temp->getRight());
                }
                cout << "Key: " << temp->getKey() << " Value: " << temp->getValue() << endl;
            }
        }
        else {
            cout << "Tree is empty" << endl;
        }
    }

    void inorder() {
        if (!empty()) {
            inorder(root);
        }
        else {
            cout << "Tree is empty" << endl;
        }
    }

    void inorder(TreeNode<Type> *node) {
        if (node) {
            inorder(node->getLeft());
            cout << "Key: " << node->getKey() << " Value: " << node->getValue() << endl;
            inorder(node->getRight());
        }
    }

    void buildTree() {
        vector<TreeNode<Type> *> *vec = new vector<TreeNode<Type> *>();
        string line;
        ifstream myfile("tree.txt");
        int cnt = 0;
        if (myfile.is_open()) {
            int key;
            Type data;
            while (!myfile.eof()) {
                if (cnt == 0) {
                    if (!getline(myfile, line)) break;
                    parseLine(line, key, data);
                    // cout << data << ", " << key<< endl;
                    if (key == -1) continue;
                    root = new TreeNode<Type>("AVL", data);
                    root->setKey(key);
                    vec->push_back(root);
                    cnt++;
                    sz++;
                }
                else {
                    if (!getline(myfile, line)) break;
                    parseLine(line, key, data);
                    if (key != -1) {
                        TreeNode<Type> *n = new TreeNode<Type>("AVL", data);
                        n->setKey(key);
                        vec->push_back(n);
                        cnt++;
                        sz++;
                    }
                    if (!getline(myfile, line)) break;
                    parseLine(line, key, data);
                    if (key != -1) {
                        TreeNode<Type> *n = new TreeNode<Type>("AVL", data);
                        n->setKey(key);
                        vec->push_back(n);
                        cnt++;
                        sz++;
                    }
                }
            }
            myfile.close();
            buildTree(vec);
        }
        else cout << "Unable to open file" << endl;
    }

    void buildTree(vector<TreeNode<Type> *> *vec) {
        vector<TreeNode<Type> *> *temp = new vector<TreeNode<Type> *>();
        TreeNode<Type> *n = NULL;
        while (!vec->empty()) {
            bool inserted = false;
            n = vec->at(0);
            vec->erase(vec->begin());
            if (temp->empty()) {
                temp->push_back(n);
            }
            else {
                for (int i = 0; i < temp->size(); i++) {
                    if (n->getKey() < temp->at(i)->getKey()) {
                        temp->insert(temp->begin() + i, n);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    temp->push_back(n);
                }
            }
        }
        int mid = (temp->size()) / 2;
        root = temp->at(mid);
        root->setLeft(buildTree(temp, 0, mid - 1, root));
        root->setRight(buildTree(temp, mid + 1, temp->size() - 1, root));
        delete temp;
    }

    TreeNode<Type> *buildTree(vector<TreeNode<Type> *> *t, int begin, int end, TreeNode<Type> *parent) {
        if (end < begin) {
            return NULL;
        }
        int mid = ((end - begin) / 2) + begin;
        t->at(mid)->setParent(parent);
        if (end - begin != 0) {
            t->at(mid)->setLeft(buildTree(t, begin, mid - 1, t->at(mid)));
            t->at(mid)->setRight(buildTree(t, mid + 1, end, t->at(mid)));
        }
        return t->at(mid);
    }

    void parseLine(string line, int &key, Type &data) {
        string::size_type sz;
        int pos = line.find(' ');
        string k = line.substr(0, pos);
        Type temp = line.substr(pos + 1);
        data = temp;
        key = stoi(k, &sz);
    }

    void clear() {
        clear(root);
        root = NULL;
        sz = 0;
    }

    void clear(TreeNode<Type> *d) {
        if (!empty()) {
            if (d->getLeft()) {
                clear(d->getLeft());
            }
            if (d->getRight()) {
                clear(d->getRight());
            }
            delete d;
        }
    }

    // Can use as many parameters as we need here
    void insert(TreeNode<Type> *data) {
        if (!empty()) {
            vector<TreeNode<Type> *> *vec = new vector<TreeNode<Type> *>();
            buildVector(vec, root);
            bool inserted = false;
            for (int i = 0; i < vec->size(); i++) {
                if (data->getKey() <= vec->at(i)->getKey()) {
                    vec->insert(vec->begin() + i, data);
                    sz++;
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                vec->push_back(data);
            }
            int mid = (vec->size()) / 2;
            root = vec->at(mid);
            root->setLeft(buildTree(vec, 0, mid - 1, root));
            root->setRight(buildTree(vec, mid + 1, vec->size() - 1, root));
            delete vec;
        }
        else {
            root = data;
        }
    }

    void buildVector(vector<TreeNode<Type> *> *v, TreeNode<Type> *n) {
        buildVector(v, n->getLeft());
        v->push_back(n);
        buildVector(v, n->getRight());
    }

    void del(TreeNode<Type> *data) {
        if (!empty()) {
            vector<TreeNode<Type> *> *vec = new vector<TreeNode<Type> *>();
            buildVector(vec, root);
            bool found = false;
            for (int i = 0; i < vec->size(); i++) {
                if (vec->at(i) == data) {
                    vec->erase(vec->begin() + i);
                    found = true;
                    sz--;
                    delete data;
                    break;
                }
            }
            if (found) {
                int mid = ((int) vec->size()) / 2;
                root = vec->at(mid);
                root->setLeft(buildTree(vec, 0, mid - 1, root));
                root->setRight(buildTree(vec, mid + 1, (int) vec->size() - 1, root));
                delete vec;
            }
            else {
                cout << "Couldnt find the node" << endl;
            }
        }
        cout << "Tree is empty" << endl;
    }
};