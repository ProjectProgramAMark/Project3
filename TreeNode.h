#pragma once



template<class Type>class TreeNode {
private:
    int key;
    Type value;
    TreeNode *parent;
    TreeNode *children;

public:

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
};