#include <iostream>
#include "CommandProcessor.h"

using namespace std;

Command_States CommandProcessor:: command_state = Initial;
Menu* CommandProcessor::menus[NR_CMD_STATES];

GeneralTree<string> *generalTree = new GeneralTree<string>();
AVLTree<double> *avlTree = new AVLTree<double>();
//Heap<double> *heap = new Heap<double>();

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

//            case _Heap: ProcessHeap(*cmd);
//                break;

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
//    }else if (cmd == "Heap") {
//        command_state = _Heap;
//    }
    } else if(cmd == "AVLTree") {
        command_state = _AVLTree;
    } else {
        cout << "Quit command\n";
        command_state = Done;
    }
}


void CommandProcessor::ProcessTree(const string &cmd) {
    if (cmd == "Get Root") {
        generalTree->getRoot();
    }else if (cmd == "Get Size") {
        generalTree->getSize();
    }else if (cmd == "Get Height"){
        generalTree->getHeight();
    }else if(cmd == "Get Depth") {
        string input;
//        double value;
        cout << "Which node to calculate depth?" << endl;
        getline(cin,input);
//        stringstream(input) >> value;
        TreeNode<string> *node = new TreeNode<string>("General", input);
        generalTree->getDepth(node);
    }else if(cmd == "Is Empty") {
        generalTree->empty();
    }else if(cmd == "Get Leaves") {
        generalTree->empty();
    }else if(cmd == "Get Siblings") {
        string input;
//        double value;
        cout << "Which node to get siblings for?" << endl;
        getline(cin,input);
//        stringstream(input) >> value;
        TreeNode<string> *node = new TreeNode<string>("General", input);
        generalTree->siblings(node);
    }else if(cmd == "Find Common Ancestor") {
        string input;
//        double value;
        string trash;
        cout << "Please enter node 1 for common ancestor" << endl;
        getline(cin,input);
//        stringstream(input) >> value;
        TreeNode<string> *node1 = new TreeNode<string>("General", input);
        getline(cin, trash);
        cout << "Please enter node 2 for common ancestor" << endl;
        getline(cin,input);
//        stringstream(input) >> value;
        TreeNode<string> * node2 = new TreeNode<string>("General", input);
        generalTree->findCommonAncestor(node1, node2);
    }else if(cmd == "Find Tree Node") {
        string data;
//        string trash;
//        cout << "Key for node" << endl;
        getline(cin, data);
//        getline(cin, trash);
//        cout << "Data for node" << endl;
        getline(cin, data);
//        stringstream(input) >> data;
        generalTree->findNode(data);
    }else if(cmd == "Preorder"){
        generalTree->preorder();
    }else if(cmd == "Postorder"){
        generalTree->postorder();
    }else if(cmd == "Levelorder"){
        generalTree->levelorder();
    }else if(cmd == "Build Tree"){
        generalTree->buildTree();
    }else if(cmd == "Clear"){
        generalTree->clear();
    }else if(cmd == "Insert"){
        string input;
        int key;
        string data;
        string trash;
        cout << "What data do you want to be in the TreeNode?" << endl;
        getline(cin, data);
        getline(cin, trash);
        cout << "What key do you want the TreeNoden to have?" << endl;
        getline(cin, input);
        stringstream(input) >> key;
        TreeNode<string> *node = new TreeNode<string>("General", key, data);
        generalTree->insert(node);
    }else if(cmd == "Delete") {
        string data;
        cout << "What data does the TreeNode you want to delete have?" << endl;
        getline(cin, data);
        TreeNode<string> *node = new TreeNode<string>("General", data);
        generalTree->del(node);
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}

//void CommandProcessor::ProcessHeap(const string &cmd) {
//    cout << "Process heap yo" << endl;
////    if (cmd == "Add Node to Front") {
////        string input;
////        double value;
////        cout << "Enter value of data in node: " << endl;
////        getline(cin,input);
////        stringstream(input) >> value;
////        doublyLinkedList->push_front(value);
////        doublyLinkedList->printList();
////    }else if (cmd == "Add Node to Back") {
////        string input;
////        double value;
////        cout << "Enter value of data in node: " << endl;
////        getline(cin,input);
////        stringstream(input) >> value;
////        doublyLinkedList->push_back(value);
////    }else if (cmd == "Delete Node at Front"){
////        doublyLinkedList->pop_front();
////    }else if( cmd == "Delete Value") {
////        string input;
////        double value;
////        cout << "Enter value to be deleted: " << endl;
////        getline(cin,input);
////        stringstream(input) >> value;
////        doublyLinkedList->erase(value);
////    }else if(cmd == "Get Size of List") {
////        doublyLinkedList->getSize();
////    }else if(cmd == "Is List Empty") {
////        doublyLinkedList->empty();
////    }else if(cmd == "Get Front Node") {
////        doublyLinkedList->front();
////    }else if(cmd == "Get Back Node"){
////        doublyLinkedList->back();
////    }else if(cmd == "Get Head Pointer ;)"){
////        doublyLinkedList->getHead();
////    }else if(cmd == "Get Tail Pointer"){
////        doublyLinkedList->getTail();
////    }else if(cmd == "Get Count"){
////        string input;
////        double value;
////        cout << "Insert value to count: ";
////        getline(cin,input);
////        stringstream(input) >> value;
////        doublyLinkedList->getCount(value);
////    }else if(cmd == "Print List"){
////        doublyLinkedList->printList();
////    }else if(cmd == "Delete List"){
////        doublyLinkedList->~DoublyLinkedList();
////    }else if(cmd == "Exit"){
////        exit(0);
////    }else{
////        cout << "Error" << endl;
////    }
//}

void CommandProcessor::ProcessAVLTree(const string &cmd) {
    if (cmd == "Get Root") {
        avlTree->getRoot();
    }else if (cmd == "Get Size") {
        avlTree->getSize();
    }else if (cmd == "Get Height"){
        avlTree->getHeight();
    }else if(cmd == "Get Depth") {
        string input;
        double value;
        cout << "Which node to calculate depth?" << endl;
        getline(cin,input);
        stringstream(input) >> value;
        TreeNode<double> *node = new TreeNode<double>("AVL", value);
        avlTree->getDepth(node);
    }else if(cmd == "Is Empty") {
        avlTree->empty();
    }else if(cmd == "Get Leaves") {
        avlTree->empty();
    }else if(cmd == "Get Siblings") {
        string input;
        double value;
        cout << "Which node to get siblings for?" << endl;
        getline(cin,input);
        stringstream(input) >> value;
        TreeNode<double> *node = new TreeNode<double>("AVL", value);
        avlTree->siblings(node);
    }else if(cmd == "Preorder"){
        avlTree->preorder();
    }else if(cmd == "Postorder"){
        avlTree->postorder();
    }else if(cmd == "Levelorder"){
        avlTree->levelorder();
    }else if(cmd == "Build Tree"){
        avlTree->buildTree();
    }else if(cmd == "Clear"){
        avlTree->clear();
    }else if(cmd == "Insert"){
        string input;
        double data;
        cout << "What data do you want the TreeNode to have?" << endl;
        getline(cin, input);
        stringstream(input) >> data;
        TreeNode<double> *node = new TreeNode<double>("AVL", data);
        avlTree->insert(node);
    }else if(cmd == "Delete") {
        string input;
        double data;
        cout << "What data does the TreeNode you want to delete have?" << endl;
        getline(cin, input);
        stringstream(input) >> data;
        TreeNode<double> *node = new TreeNode<double>("AVL", data);
        avlTree->del(node);
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
//    menu->Add_Command("Heap");
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
//    menu = new Menu("Enter command number:\n");
//    menu->Add_Command("Add Node to Front");
//    menu->Add_Command("Add Node to Back");
//    menu->Add_Command("Delete Node at Front");
//    menu->Add_Command("Delete Value");
//    menu->Add_Command("Is List Empty");
//    menu->Add_Command("Get Front Node");
//    menu->Add_Command("Get Back Node");
//    menu->Add_Command("Get Head Pointer ;)");
//    menu->Add_Command("Get Tail Pointer");
//    menu->Add_Command("Get Size of List");
//    menu->Add_Command("Get Count");
//    menu->Add_Command("Print List");
//    menu->Add_Command("Delete List");
//    menu->Add_Command("Exit");
//    menus[_Heap] = menu;

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
