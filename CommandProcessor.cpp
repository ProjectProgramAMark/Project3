#include <iostream>
#include "CommandProcessor.h"

using namespace std;

Command_States CommandProcessor:: command_state = Initial;
Menu* CommandProcessor::menus[NR_CMD_STATES];

GeneralTree<string> *generalTree = new GeneralTree<string>();
AVLTree<double> *avlTree = new AVLTree<double>();
Heap<string> *heap = new Heap<string>();

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

void CommandProcessor::ProcessHeap(const string &cmd) {
    if (cmd == "Max") {
        heap->getMax();
    }else if (cmd == "Size") {
        heap->getHeight();
    }else if (cmd == "Empty"){
        heap->empty();
    }else if( cmd == "Leaves") {
        heap->leaves();
    }else if(cmd == "Build Tree") {
        heap->buildTree();
    }else if(cmd == "Clear") {
        heap->clear();
    }else if(cmd == "Insert") {
        int key;
        string value;
        cout << "Enter key: " ;
        cin >> key;
        getchar();
        cout << "Enter value: ";
        getline(cin, value);
        heap->insert(key, value);
    }else if(cmd == "Delete Max"){
        heap->delMax();
    }else if(cmd == "Display"){
    }else if(cmd == "Exit"){
        exit(0);
    }else{
        cout << "Error" << endl;
    }
}

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
    menu->Add_Command("Max");
    menu->Add_Command("Size");
    menu->Add_Command("Height");
    menu->Add_Command("Empty");
    menu->Add_Command("Leaves");
    menu->Add_Command("Build Tree");
    menu->Add_Command("Clear");
    menu->Add_Command("Insert");
    menu->Add_Command("Delete Max");
    menu->Add_Command("Display");
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
