#pragma once
#include <string>
#include <sstream>
#include "Menu.h"
#include "GeneralTree.h"
#include "Heap.h"
#include "AVLTree.h"

enum Command_States { Initial, _Tree, _Heap, _AVLTree, Done };
using namespace std;

class CommandProcessor
{
public:
    static void Process_Commands();

private:
    static const int NR_CMD_STATES = (int)Done + 1;
    static Command_States command_state;
    static Menu* menus[NR_CMD_STATES];

    static void Create_Menus();
    static void Process_Initial_Cmd(const string& cmd);
    static void ProcessTree(const string& cmd);
    static void ProcessHeap(const string& cmd);
    static void ProcessAVLTree(const string& cmd);


    CommandProcessor(void) {};
};
