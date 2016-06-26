#include <iostream>
#include "CommandProcessor.h"

using namespace std;

Command_States CommandProcessor:: command_state = Initial;
Menu* CommandProcessor::menus[NR_CMD_STATES];

LinkedTree<double> *linkedTree = new LinkedTree<double>();
AVLTree<double> *avlTree = new AVLTree<double>();
Heap<double> *heap = new Heap<double>();

void CommandProcessor::Process_Commands()
{
    cout << "Process commands starting\n";


    Create_Menus();

    while (command_state != Done)
    {
        const string* cmd = menus[command_state]->Get_Command();

        switch (command_state)
        {
            case Initial:   Process_Initial_Cmd(*cmd);
                break;

            case _Tree: ProcessTree(*cmd);
                break;

            case _Heap: ProcessHeap(*cmd);
                break;

            case _AVLTree: ProcessAVLTree(*cmd);
                break;

            case Done:  break;      // Can't happen
        }
    }

    cout << "Command_Processor exiting\n";
    // Process command in Initial command state

}
void CommandProcessor::Process_Initial_Cmd(const string& cmd)
{
    if (cmd == "Tree") {
        command_state = _Tree;
    }else if (cmd == "Heap") {
        command_state = _Heap;
    }else if(cmd == "AVLTree") {
        command_state = _AVLTree;
    } else {
        cout << "Quit command\n";
        command_state = Done;
    }
}

void CommandProcessor::ProcessTree(const string &cmd) {
    if (cmd == "Add Node to Front") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->push_front(value);
        //cyclicLinkedList->printList();
    }else if (cmd == "Add Node to Back") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->push_back(value);
    }else if (cmd == "Delete Node at Front"){
        cyclicLinkedList->pop_front();
    }else if( cmd == "Delete Value") {
        string input;
        double value;
        cout << "Enter value to be deleted: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->erase(value);
    }else if(cmd == "Get Size of List") {
        cyclicLinkedList->getSize();
    }else if(cmd == "Is List Empty") {
        cyclicLinkedList->empty();
    }else if(cmd == "Get Front Node") {
        cyclicLinkedList->front();
    }else if(cmd == "Get Back Node"){
        cyclicLinkedList->back();
    }else if(cmd == "Get Head Pointer ;)"){
        cyclicLinkedList->getHead();
    }else if(cmd == "Get Tail Pointer"){
        cyclicLinkedList->getTail();
    }else if(cmd == "Get Count"){
        string input;
        double value;
        cout << "Insert value to count: ";
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->getCount(value);
    }else if(cmd == "Print List"){
        cyclicLinkedList->printList();
    }else if(cmd == "Delete List"){
        cyclicLinkedList->~CyclicLinkedList();
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}

void CommandProcessor::ProcessHeap(const string &cmd) {
    if (cmd == "Add Node to Front") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        doublyLinkedList->push_front(value);
        doublyLinkedList->printList();
    }else if (cmd == "Add Node to Back") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        doublyLinkedList->push_back(value);
    }else if (cmd == "Delete Node at Front"){
        doublyLinkedList->pop_front();
    }else if( cmd == "Delete Value") {
        string input;
        double value;
        cout << "Enter value to be deleted: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        doublyLinkedList->erase(value);
    }else if(cmd == "Get Size of List") {
        doublyLinkedList->getSize();
    }else if(cmd == "Is List Empty") {
        doublyLinkedList->empty();
    }else if(cmd == "Get Front Node") {
        doublyLinkedList->front();
    }else if(cmd == "Get Back Node"){
        doublyLinkedList->back();
    }else if(cmd == "Get Head Pointer ;)"){
        doublyLinkedList->getHead();
    }else if(cmd == "Get Tail Pointer"){
        doublyLinkedList->getTail();
    }else if(cmd == "Get Count"){
        string input;
        double value;
        cout << "Insert value to count: ";
        getline(cin,input);
        stringstream(input) >> value;
        doublyLinkedList->getCount(value);
    }else if(cmd == "Print List"){
        doublyLinkedList->printList();
    }else if(cmd == "Delete List"){
        doublyLinkedList->~DoublyLinkedList();
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}

void CommandProcessor::ProcessAVLTree(const string &cmd) {
    if (cmd == "Add Node to Front") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->push_front(value);
        //cyclicLinkedList->printList();
    }else if (cmd == "Add Node to Back") {
        string input;
        double value;
        cout << "Enter value of data in node: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->push_back(value);
    }else if (cmd == "Delete Node at Front"){
        cyclicLinkedList->pop_front();
    }else if( cmd == "Delete Value") {
        string input;
        double value;
        cout << "Enter value to be deleted: " << endl;
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->erase(value);
    }else if(cmd == "Get Size of List") {
        cyclicLinkedList->getSize();
    }else if(cmd == "Is List Empty") {
        cyclicLinkedList->empty();
    }else if(cmd == "Get Front Node") {
        cyclicLinkedList->front();
    }else if(cmd == "Get Back Node"){
        cyclicLinkedList->back();
    }else if(cmd == "Get Head Pointer ;)"){
        cyclicLinkedList->getHead();
    }else if(cmd == "Get Tail Pointer"){
        cyclicLinkedList->getTail();
    }else if(cmd == "Get Count"){
        string input;
        double value;
        cout << "Insert value to count: ";
        getline(cin,input);
        stringstream(input) >> value;
        cyclicLinkedList->getCount(value);
    }else if(cmd == "Print List"){
        cyclicLinkedList->printList();
    }else if(cmd == "Delete List"){
        cyclicLinkedList->~CyclicLinkedList();
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}


void CommandProcessor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Which linked list do you want to create?");
    menu->Add_Command("Tree");
    menu->Add_Command("Heap");
    menu->Add_Command("AVLTree");

    menus[Initial] = menu;

    //Menu for Tree
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Get Root");
    menu->Add_Command("Get Size");
    menu->Add_Command("Get Height");
    menu->Add_Command("Get Depth");
    menu->Add_Command("Is Empty");
    menu->Add_Command("Get Leaves");
    menu->Add_Command("Get Siblings");
    menu->Add_Command("Find Common Ancestor");
    menu->Add_Command("Find Tree Node");
    menu->Add_Command("Preorder");
    menu->Add_Command("Postorder");
    menu->Add_Command("Levelorder");
    menu->Add_Command("Inorder");
    menu->Add_Command("Build Tree");
    menu->Add_Command("Clear");
    menu->Add_Command("Insert");
    menu->Add_Command("Delete");
    menu->Add_Command("Exit");
    menus[_Tree] = menu;

    //Menu for Heap
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Add Node to Front");
    menu->Add_Command("Add Node to Back");
    menu->Add_Command("Delete Node at Front");
    menu->Add_Command("Delete Value");
    menu->Add_Command("Is List Empty");
    menu->Add_Command("Get Front Node");
    menu->Add_Command("Get Back Node");
    menu->Add_Command("Get Head Pointer ;)");
    menu->Add_Command("Get Tail Pointer");
    menu->Add_Command("Get Size of List");
    menu->Add_Command("Get Count");
    menu->Add_Command("Print List");
    menu->Add_Command("Delete List");
    menu->Add_Command("Exit");
    menus[_Heap] = menu;

    //Menu for AVLTree
    menu = new Menu("Enter command number:\n");
    menu->Add_Command("Get Root");
    menu->Add_Command("Get Size");
    menu->Add_Command("Get Height");
    menu->Add_Command("Get Depth");
    menu->Add_Command("Is Empty");
    menu->Add_Command("Get Leaves");
    menu->Add_Command("Get Siblings");
    menu->Add_Command("Find Tree Node");
    menu->Add_Command("Preorder");
    menu->Add_Command("Postorder");
    menu->Add_Command("Levelorder");
    menu->Add_Command("Inorder");
    menu->Add_Command("Build Tree");
    menu->Add_Command("Clear");
    menu->Add_Command("Insert");
    menu->Add_Command("Delete");
    menu->Add_Command("Exit");
    menus[_AVLTree] = menu;
}
