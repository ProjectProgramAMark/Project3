#pragma once
#include "TreeNode.h"

#define PARENT(i)  (i/2)
//#define LEFT(nodeIndex) 2(nodeIndex) //index starts at 1
//#define RIGHT(nodeIndex) 2(nodeIndex)+1

const INITIAL_CAP = 8;


template <class Type> class Heap {
private:
    TreeNode<Type> * node;
    Type ** array;
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

    TreeNode<Type> getMax(){ return array[0]; }
    int getSize(){ return numElements; }
    int getHeight(){ return height; }
    bool empty(){ return numElements == 0; }
    int leaves(){ return 0; }

    void buildTree() {}
    void clear() {}

    void insert(int key, Type & data) {
        if(numElements == capacity - 1){
//            doubleSize(); // create function
        }
        else{
            node = new TreeNode("Heap", key, data);
            numElements++;
            array[numElements] = node;
            Heapify(numElements); //create function
        }
    }

    void Heapify(int nodeIndex){
        while(nodeIndex > 1 && array[PARENT(nodeIndex)]->key < array[nodeIndex]->key) {

            TreeNode * tmp = array[PARENT(nodeIndex)];

            array[PARENT(nodeIndex)] = array[nodeIndex];

            array[nodeIndex] = tmp;

            nodeIndex = PARENT(nodeIndex);
        }
    }
    void delMax() {}
};