#pragma once

template<class Type>class TreeNode {
private:
    int key;
    Type value;
    TreeNode *parent;
    TreeNode *children;
    TreeNode *sibling;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(string treeType, int key, Type value) {
        cout << "Constructor activated" << endl;
        if(treeType == "General"){
            this->key = key;
            this->value = value;
            this->children = nullptr;
            this->sibling = nullptr;
        }
        else if(treeType == "Heap"){
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        else if(treeType == "AVL"){
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        else{
            cout << "Node could not be created. Try again." << endl;
        }
    }

    TreeNode(string treeType, int key) {
        cout << "Constructor activated" << endl;
        if(treeType == "General"){
            this->key = key;
            this->value = 0;
            this->children = nullptr;
            this->sibling = nullptr;
        }
        else if(treeType == "Heap"){
            this->key = key;
            this->value = 0;
            this->left = nullptr;
            this->right = nullptr;
        }
        else if(treeType == "AVL"){
            this->key = key;
            this->value = 0;
            this->left = nullptr;
            this->right = nullptr;
        }
        else{
            cout << "Node could not be created. Try again." << endl;
        }
    }

    TreeNode(string treeType, Type value) {
        cout << "Constructor activated" << endl;
        if(treeType == "General"){
            this->key = 0;
            this->value = value;
            this->children = nullptr;
            this->sibling = nullptr;
        }
        else if(treeType == "Heap"){
            this->key = 0;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        else if(treeType == "AVL"){
            this->key = 0;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        else{
            cout << "Node could not be created. Try again." << endl;
        }
    }


    int getKey() const {
        return key;
    }

    void setKey(int key) {
        this->key = key;
    }

    Type getValue() const {
        return value;
    }

    void setValue(Type value) {
        this->value = value;
    }

    TreeNode *getParent() const {
        return parent;
    }

    void setParent(TreeNode *parent) {
        this->parent = parent;
    }

    TreeNode *getChildren() const {
        return children;
    }

    void setChildren(TreeNode *children) {
        this->children = children;
    }

    TreeNode *getSibling() const {
        return sibling;
    }

    void setSibling(TreeNode *sibling) {
        this->sibling = sibling;
    }

    TreeNode *getLeft() const {
        return left;
    }

    TreeNode *getRight() const {
        return right;
    }
};