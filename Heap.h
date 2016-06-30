#pragma once
#include "TreeNode.h"

#define PARENT(i)  (i/2)

#define LEFT(i)  (2*i) //index starts at 1

#define RIGHT(i)  (2*i)+1

const int INITIAL_CAP = 8;


template <class Type> class Heap {
private:
    TreeNode<Type> * node;
    TreeNode<Type> ** array;
    int numElements;
    int capacity;
    int height;

public:
    Heap(){
        array = new TreeNode<Type>*[INITIAL_CAP];
        numElements = 0;
        capacity = INITIAL_CAP;
        for(int i=0; i < capacity; i++){
            array[i] = new TreeNode<Type>("Heap", 0, "");
        }
    }

    ~Heap(){
        delete [] array;
    }

    TreeNode<Type>* getMax(){ return array[1]; }
    int getSize(){ return numElements; }
    int getHeight(){ return height; }
    bool empty(){ return numElements == 0; }
    int leaves(){ return 0; }

    void buildTree() {}
    void clear() {}

    void doubleSize() {
        capacity = capacity*2;
        TreeNode<Type> **tmp = new TreeNode<Type>*[capacity];
        for(int i=0; i < capacity; i++){
            tmp[i] = new TreeNode<Type>("Heap", 0, "");
        }
        for(int i = 0; i < numElements; i++){
            tmp[i] = array[i];
        }
        *array = *tmp;
        delete [] tmp;
    }

    void insert(int key, Type & data) {
        if(numElements == capacity - 1){
            doubleSize(); // create function
        }
        node = new TreeNode<Type>("Heap", key, data);
        numElements++;
        array[numElements] = node;
        Heapify(numElements); //create function
    }

    void Heapify(int nodeIndex){
        while(nodeIndex > 1 && array[PARENT(nodeIndex)]->getKey() < array[nodeIndex]->getKey()) {

            TreeNode<Type> * tmp = array[PARENT(nodeIndex)];
            array[PARENT(nodeIndex)] = array[nodeIndex];
            array[nodeIndex] = tmp;

            if(nodeIndex > 2 && array[LEFT(nodeIndex)]->getKey() > array[RIGHT(nodeIndex)]->getKey()) {
                TreeNode<Type> * tmp = array[LEFT(nodeIndex)];
            }

            nodeIndex = PARENT(nodeIndex);
        }
    }
    void delMax() {

    }
    void Display() {
        for(int i = 1; i <= numElements; i++){
            cout << "Key: " << array[i]->getKey() << " Value: " << array[i]->getValue() << endl;
        }
    }
};