
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include "tinyxml.h"
#include <queue>
#include <cmath>

using namespace std;


template<class Type>
class GeneralTree {
private:
    TreeNode<Type> *root;
    int height = 0;
    int size;
public:
    GeneralTree() {
        size = 0;
        TreeNode<string> *node = new TreeNode<Type>("General", 1, "Genres");
        insert(node, 0);
        node = new TreeNode<string>("General", 2, "Thriller");
        insert(node, 1);
        node = new TreeNode<string>("General", 6, "Goodnight Mommy");
        insert(node, 2);
        node = new TreeNode<string>("General", 3, "Action");
        insert(node, 1);
        node = new TreeNode<string>("General", 4, "Romance");
        insert(node, 1);
        node = new TreeNode<string>("General", 7, "A Walk to Remember");
        insert(node, 4);
        node = new TreeNode<string>("General", 8, "The Notebook");
        insert(node, 4);
        node = new TreeNode<string>("General", 5, "Anime");
        insert(node, 1);
        node = new TreeNode<string>("General", 9, "Full Metal Alchemist");
        insert(node, 1);
        node = new TreeNode<string>("General", 10, "Pokemon 2000: The Movie");
        insert(node, 5);
//        display(root);
    }

    GeneralTree(string stuff) : size(0), root(NULL), height(0) {
        // parameter is in there so this one isn't called by default until fixed
        buildTree();
    }


    TreeNode<Type> *getRoot() {
        if (root) {
            return root;
        }
        cout << "Root is empty" << endl;
        return NULL;
    }

    int getSize() {
        return size;
    }

    int getHeight() {
        if (!empty()) {
            int max = 0;
            int h;
            h = getHeight(root->getChildren());
            if (h > max) {
                max = h;
            }
            max++;
            h = getHeight(root->getSibling());
            if (h > max) {
                max = h;
            }
            return max;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    int getHeight(TreeNode<Type> *node) {
        if (!empty()) {
            int max = 0;
            int h;
            h = getHeight(node->getChildren());
            if (h > max) {
                max = h;
            }
            max++;
            h = getHeight(node->getSibling());
            if (h > max) {
                max = h;
            }
            return max;
        }
        cout << "Tree is empty" << endl;
        return 0;
    }

    int getDepth(TreeNode<Type> *node) {
        if (node == root)
            return 0;
        else
            return 1 + getDepth(node->getParent()); // 1 + (depth of parent)
    }

    bool empty() {
        return root == nullptr;
    }

    int leaves(TreeNode<Type> *node) {
        do {
            if (!node) return 0;
            else if (!(node->getChildren())) return 1;
            else {
                return leaves(node->getChildren());
            }
        } while (node->getSibling());
    }

    int siblings(TreeNode<Type> *node) {
        int count = 0;
        while (node->getSibling()) {
            count++;
        }
        return count;

    }

    TreeNode<Type> *findCommonAncestor(TreeNode<Type> *node1, TreeNode<Type> *node2) {
        cout << "Find common ancestors implemented" << endl;
        return root;
    }

    TreeNode<Type> *findNode(int key, TreeNode<Type> *node) {
        if (node->getKey() == key) {
            return node;
        } else {
            if (node->getChildren()) {
                return findNode(key, node->getChildren());
            } else if (node->getSibling()) {
                return findNode(key, node->getSibling());
            } else {
//                cout << "Done traversing" << endl;
            }
        }
//        cout << "Node not found" << endl;
        return NULL;
    }

    TreeNode<Type> *findNode(int key) {
        // Just calls the other findNode function
        // with root as the starting point
        TreeNode<Type> *node = findNode(key, root);
        return node;
    }

    void preorder(TreeNode<Type> *node) {
        // Visiting the node
        cout << "Key: " << node->getKey() << "Value: " << node->getValue() << endl;
        // Traversing down children via left
        if (node->getChildren() != nullptr) {
            preorder(node->getChildren());
        }
        // Traversing left children's siblings, A.K.A traversing right
        if (node->getSibling() != nullptr) {
            preorder(node->getSibling());
        }
    }

    void postorder(TreeNode<Type> *node) {
        // Traversing down children via left
        if (node->getChildren() != nullptr) {
            preorder(node->getChildren());
        }
        // Traversing left children's siblings, A.K.A traversing right
        if (node->getSibling() != nullptr) {
            preorder(node->getSibling());
        }
        // Visiting the node
        cout << "Key: " << node->getKey() << "Value: " << node->getValue() << endl;
    }

    void levelorder(TreeNode<Type> *root) {
        cout << "Levelorder implemented" << endl;
        queue<TreeNode<Type>> *queue = new ::queue<TreeNode<Type>>();
        unsigned long count = 0;
        int level = 0;
        TreeNode<Type> *node = new TreeNode<Type>("General");
        queue->push(*root);
        count++;
        while (!(queue->empty())) {
            *node = queue->front();
            queue->pop();
            cout << node->getValue() << " ";
            TreeNode<Type> *tempNode = node->getChildren();
            if (tempNode) {
                while (tempNode->getSibling() != nullptr) {
                    queue->push(*tempNode);
                    tempNode = tempNode->getSibling();
                }
            }
            if (--count == 0) {
                count = queue->size();
                level++;
            }
        }
        height = level;
    }

    void buildTree() {
        // Loading XML file and getting rootNode
        string filename = "generalTree.xml";
        TiXmlDocument doc(filename);
        bool loadOkay = doc.LoadFile();
        if (!loadOkay) {
            cout << "Could not load file " << filename << endl;
            cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
        }
        TiXmlNode *generalTreeNode = doc.FirstChild("GeneralTree");
        assert(generalTreeNode != 0);

        TiXmlNode *rootNode = generalTreeNode->FirstChild();
        assert(rootNode != 0);
        int key = stoi(rootNode->ToElement()->Attribute("key"));
        Type data = rootNode->ToElement()->GetText();
        root = new TreeNode<Type>("General", key, data);
        // Populating the rest of the tree via recursive function
        recFunction(rootNode);
    }

    void recFunction(TiXmlNode *node) {
        if (node->FirstChildElement() == NULL) {
            cout << "First child element is null" << endl;
            // Do something
        } else {
            int key = stoi(node->ToElement()->Attribute("key"));
            Type data = node->ToElement()->GetText();
            TreeNode<Type> *treeNode = new TreeNode<Type>("General", key, data);
            cout << "Right BEFORE recursive activates" << endl;
            return recFunction(node->FirstChild());
        }
        cout << "After recursiveness done" << endl;
        // After recursiveness is finished
        while (node->NextSibling() != NULL) {
            // Converting XML node to TreeNode
            // Making previous and current nodes
            cout << "DOING NODE TO ELEMENT" << endl;
            cout << node->ToText()->Value() << endl;
            cout << node->ToElement()->Attribute("key") << endl;
            cout << "DONE WITH NODE TO ELEMENT" << endl;
            int key = stoi(node->ToElement()->Attribute("key"));
            cout << "Key 1 is: " << key << endl;
            Type data = node->ToElement()->GetText();
            cout << "Data 1 is: " << data << endl;
            TreeNode<Type> *prev = new TreeNode<Type>("General", key, data);
            int key2 = stoi(node->NextSibling()->ToElement()->Attribute("key"));
            Type data2 = node->ToElement()->GetText();
            TreeNode<Type> *cur = new TreeNode<Type>("General", key2, data2);
            // Create linked list of siblings
            prev->setSibling(cur);
            node = node->NextSibling();
        }
    }

    void clear() {
        TreeNode<Type> *temp;
        TreeNode<Type> *traverse = root->getChildren();
        while (traverse != NULL) {
            temp = traverse;
            traverse = traverse->getChildren();
            delete temp;
        }
    }

    void insert(TreeNode<Type> *data, int parentNodeKey) {
        if (!root) {
            root = data;
            size++;
            return;
        }
        TreeNode<Type> *parentNode = findNode(parentNodeKey, root);
        if (!parentNode) {
//            cout << "Parent node is null, key of parent node could not be found" << endl;
            return;
        }
        if (!parentNode->getChildren()) {
            // Parent node is null, can just set children
            parentNode->setChildren(data);
        } else {
            TreeNode<Type> *temp = parentNode->getChildren();
            while (temp->getSibling()) {
                temp = temp->getSibling();
            }
            temp->setSibling(data);
//            cout << "Find Node implemented" << endl;

        }
    }

    void display(TreeNode<Type> *node) {
        //level order traversal of tree
        queue<TreeNode<Type>, deque<TreeNode<Type>, allocator<TreeNode<Type>>>> *queue =
                new ::queue<TreeNode<Type>, deque<TreeNode<Type>, allocator<TreeNode<Type>>>>();
        queue->push(*node);
        int level = 0;
        while (1) {
            int nodeCount = (int) queue->size();
            if (nodeCount == 0)
                return;
            level++;
            while (nodeCount > 0) {
                TreeNode<Type> temp = queue->front();
                queue->pop();
                cout << temp.getValue() << " ";
                for (int i = 1; i <= temp.getKey(); i++) {
                    if (temp.getChildren() != NULL)
                        queue->push(*temp.getChildren());
                }
                nodeCount--;
            }
            cout << endl;
        }
    }

    void del(TreeNode<Type> *data) {
        TreeNode<Type> *node = findNode(data->getKey(), root);
        if (!node) {
//            cout << "Couldn't find the node" << endl;
            return;
        }
        delete node;
    }
};