#include <iostream>
//#include "CommandProcessor.h"
#include "Heap.h"
using namespace std;

int main() {
//    CommandProcessor::Process_Commands();
    Heap<string> *heap = new Heap<string>;
    int key = 76;
    string value = "banana";
    heap->insert(key, value);
    key = 24;
    value = "bank";
    heap->insert(key, value);
    key = 35;
    value = "bones";
    heap->insert(key, value);
    key = 57;
    value = "banshee";
    heap->insert(key, value);
    key = 212;
    value = "brisk";
    heap->insert(key, value);
    key = 33;
    value = "brain";
    heap->insert(key, value);
    key = 111;
    value = "brawn";
    heap->insert(key, value);
    key = 48;
    value = "bloat";
    heap->insert(key, value);
    key = 53;
    value = "bounce";
    heap->insert(key, value);
    key = 231;
    value = "brazen";
    heap->insert(key, value);
    key = 338;
    value = "bleet";
    heap->insert(key, value);
    key = 444;
    value = "blatant";
    heap->insert(key, value);
    key = 148;
    value = "blush";
    heap->insert(key, value);
    key = 238;
    value = "blind";
    heap->insert(key, value);
    key = 438;
    value = "biscuit";
    heap->insert(key, value);
    key = 482;
    value = "bunny";
    heap->insert(key, value);
    heap->Display();
    cout << "Size: " << heap->getSize() << endl;
    cout << "Max: " << "Key[" << heap->getMax()->getKey() << "]" << " Value[" << heap->getMax()->getValue() << "]" << endl;
//    cout << "Hello, World!" << endl;
    return 0;
}