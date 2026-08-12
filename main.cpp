#include <iostream>
#include <stack>

#include "raylib.h"
#include "Header/DoublyLinkedList.h"
#include "Header/Graph_Node.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    Graph_Node* nodeA = new Graph_Node("A");
    Graph_Node* nodeB = new Graph_Node("B");
    Graph_Node* nodeC = new Graph_Node("C");
    Graph_Node* nodeD = new Graph_Node("D");
    Graph_Node* nodeE = new Graph_Node("E");
    Graph_Node* nodeF = new Graph_Node("F");
    Graph_Node* nodeG = new Graph_Node("G");


    DoublyLinkedList<Graph_Node*> graph;
    graph.add_node(nodeA);
    graph.add_node(nodeB);
    graph.add_node(nodeC);
    graph.add_node(nodeD);
    graph.add_node(nodeE);
    graph.add_node(nodeF);
    graph.add_node(nodeG);


    nodeA->add_child(nodeB);
    nodeA->add_child(nodeC);
    nodeB->add_child(nodeD);
    nodeB->add_child(nodeE);
    nodeC->add_child(nodeF);
    nodeC->add_child(nodeG);

    std::string orign_graph_name = "A";
    std::string destination_graph_name = "F";


    std::stack<Graph_Node*> graph_stack;
    std::stack<int> children_index;

    graph_stack.push(nodeA);
    children_index.push(0);

    while (!graph_stack.empty()) {

        Graph_Node* node = graph_stack.top();
        int index = children_index.top();

        int child_count = node->get_children().get_list_size();

        std::cout << "current: " << node->get_name() << std::endl;

        if (node->get_name() == destination_graph_name) {
            break;
        }

        if (index >= child_count) {
            graph_stack.pop();
            children_index.pop();

            if (!children_index.empty()) {
                children_index.top()++;
            }

            continue;
        }

        Graph_Node* child =
            node->get_children().get_node(index)->get_data();

        graph_stack.push(child);
        children_index.push(0);
    }
    // InitWindow(screenWidth, screenHeight, "PATH_FINDING");
    // SetTargetFPS(60);
    //
    // float dt;
    //
    //
    //
    // while (!WindowShouldClose()) {
    //     dt = GetFrameTime();
    //     BeginDrawing();
    //
    //
    //
    //
    //
    //     ClearBackground(WHITE);
    //     EndDrawing();
    // }

    return 0;
}


