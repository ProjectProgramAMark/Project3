#pragma once
#include "TreeNode.h"

const INITIAL_CAP = 8;

template <class Type> class Heap {
private:
    TreeNode<Type> node;
    TreeNode<Type> root;
    Type * array;
    int numElements;
    int capacity;
    int height;

public:
    Heap(){
        array = new Type[INITIAL_CAP];
        numElements = 0;
        capacity = INITIAL_CAP;
    }

    ~Heap(){
        delete [] array;
    }

    TreeNode<Type> getMax(){ return root; }
    int getSize(){ return numElements; }
    int getHeight(){ return height; }
    bool empty(){ return numElements == 0; }
    int leaves(){ return 0; }

    void buildTree() {}
    void clear() {}

    void insert(int key, Type & data) {
        if(numElements == capacity - 1){
            doubleSize();
        }
    }
    void delMax() {}
};