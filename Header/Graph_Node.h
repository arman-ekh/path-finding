#ifndef PATH_FINDING_GRAPH_NODE_H
#define PATH_FINDING_GRAPH_NODE_H

#include "DoublyLinkedList.h"

class Graph_Node {
private:
    Graph_Node* father;
    DoublyLinkedList<Graph_Node*>* children;
    std::string name;
    int cost;
    float x,y;

public:
    Graph_Node(std::string name , float x, float y) {
        father = nullptr;
        children = new DoublyLinkedList<Graph_Node*>();
        this->name = name;
        cost = 0;
    }

    void set_father(Graph_Node* f) { father = f; }
    Graph_Node* get_father() const { return father; }


    DoublyLinkedList<Graph_Node*>& get_children()  {
        return *children;
    }

    std::string get_name() const { return name; }

    void add_child(Graph_Node* child) {
        if (child) {
            child->set_father(this);
            children->add_node(child);
        }
    }

    int get_cost() const { return cost; }
    void set_cost(int c) { cost = c; }

    ~Graph_Node() {
        if (!children) {
            return;
        }
        int size = children->get_list_size();
        for (int i = 0; i < size; i++) {
            Node<Graph_Node*>* listNode = children->get_node(i);
            if (listNode) {
                Graph_Node* childPtr = listNode->get_data();
                delete childPtr;
            }
        }
        delete children;
    }
};

#endif