#ifndef PATH_FINDING_GRAPH_H
#define PATH_FINDING_GRAPH_H

#include "DoublyLinkedList.h"
#include "Graph_Node.h"


class Graph {
    private:
        DoublyLinkedList<Graph_Node*> graph;
        int node_counter = 0;
    public:
        Graph_Node* add_node(float x, float y) {
            std::string name =std::string(1, 'A' + node_counter);
            Graph_Node* node = new Graph_Node(name, x, y);
            graph.add_node(node);
            node_counter++;

            return node;
        }
        DoublyLinkedList<Graph_Node*> get_graph() {
            return graph;
        }
        Graph_Node* get_node(std::string name) {
            for (int i = 0; i < graph.get_list_size(); i++) {
                if (graph.get_node(i)->get_data()->get_name() == name) {
                    return graph.get_node(i)->get_data();
                }
            }
            return nullptr;
        }
        void delete_node(Graph_Node* node) {
            node_counter--;
            Graph_Node* father = node->get_father();
            if (father != nullptr) {
                DoublyLinkedList<Graph_Node*> children = father->get_children();
                for (int i =0 ; i < children.get_list_size() ; i++) {
                    if (children.get_node(i)->get_data() == node) {
                        children.remove_node(i);
                    }
                }
            }
            for (int i = 0; i < node->get_children().get_list_size() ; i++) {
                Graph_Node* child = node->get_children().get_node(i)->get_data();
                if (child != nullptr) {
                    child->set_father(nullptr);
                }
            }
        }
};
#endif //PATH_FINDING_GRAPH_H