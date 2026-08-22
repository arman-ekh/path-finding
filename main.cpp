#include <iostream>
#include <queue>
#include <stack>

#include "raylib.h"
#include "include/EDITOR/GraphEditor.h"
#include "include/Graph/Graph.h"
// #include "Header/DoublyLinkedList.h"
// #include "Header/Graph_Node.h"
// #include "Header/Graph.h"


// void bfs(bool* found , std::queue<Graph_Node*> graph_queue , std::string destination_graph_name);
// void dfs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name );
// bool dls(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ,int limit );
// void ids(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name );
// void ucs(DoublyLinkedList<Graph_Node*>& graph_list_ucs,DoublyLinkedList<int>& graph_list_cost,std::string destination_graph_name);

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    Graph graph;
    auto *graph_editor = new GraphEditor(graph);
    graph_editor->create_node(0,0);
    graph_editor->create_node(0,0);
    graph_editor->create_node(0,0);
    graph_editor->create_node(0,0);


    graph_editor->draw();

    return 0;
}
    // Graph_Node* nodeA = new Graph_Node("A",0,0);
    // Graph_Node* nodeB = new Graph_Node("B",0,0);
    // Graph_Node* nodeC = new Graph_Node("C",0,0);
    // Graph_Node* nodeD = new Graph_Node("D",0,0);
    // Graph_Node* nodeE = new Graph_Node("E",0,0);
    // Graph_Node* nodeF = new Graph_Node("F",0,0);
    // Graph_Node* nodeG = new Graph_Node("G",0,0);
    //
    // nodeA->add_child(nodeB);
    // nodeA->add_child(nodeC);
    // nodeB->add_child(nodeD);
    // nodeB->add_child(nodeE);
    // nodeC->add_child(nodeF);
    // nodeC->add_child(nodeG);
    //
    // nodeB->set_cost(10);
    // nodeC->set_cost(3);
    // nodeD->set_cost(2);
    // nodeE->set_cost(4);
    // nodeF->set_cost(2);
    // nodeG->set_cost(1);

    // std::string origin_graph_name = "A";
    // std::string destination_graph_name = "F";
    //
    //
    // std::stack<Graph_Node*> graph_stack;
    // std::stack<int> children_index;
    //
    // graph_stack.push(nodeA);
    // children_index.push(0);
    //
    // dfs(graph_stack, children_index, destination_graph_name);
    //
    //
    // std::queue<Graph_Node*> graph_queue;
    // graph_queue.push(nodeA);
    // bool found = false;
    // bfs(&found, graph_queue, destination_graph_name);
    //
    //
    // std::stack<Graph_Node*> graph_stack_dls;
    // std::stack<int> children_index_dls;
    //
    // graph_stack_dls.push(nodeA);
    // children_index_dls.push(0);
    //
    // int dls_limit = 2;
    // bool found_dls = dls(graph_stack_dls, children_index_dls, destination_graph_name, dls_limit);
    //
    //
    // std::stack<Graph_Node*> graph_stack_ucs;
    // std::stack<int> children_index_ucs;
    //
    // graph_stack_ucs.push(nodeA);
    // children_index_ucs.push(0);
    // ids(graph_stack_ucs, children_index_ucs, destination_graph_name);
    //
    // DoublyLinkedList<Graph_Node*> graph_list_ucs;
    // DoublyLinkedList<int>graph_list_cost;
    //
    // graph_list_ucs.add_node(nodeA);
    // graph_list_cost.add_node(0);
    //
    // ucs(graph_list_ucs, graph_list_cost, destination_graph_name);


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

//     return 0;
// }
//
// void bfs(bool* found , std::queue<Graph_Node*> graph_queue , std::string destination_graph_name) {
//     while (!*found && !graph_queue.empty()) {
//         Graph_Node* current = graph_queue.front();
//         std::cout <<"checking : " <<current->get_name() << " " ;
//         if (current->get_name() == destination_graph_name) {
//             *found = true;
//             std::cout << std::endl;
//         }
//
//         int child_count = current->get_children().get_list_size();
//         if (child_count <= 0 ) {
//             graph_queue.pop();
//         }else {
//             graph_queue.pop();
//             std::cout << "adding: ";
//             for (int i = 0; i < child_count; i++) {
//                 Graph_Node* child = current->get_children().get_node(i)->get_data();
//                 graph_queue.push(child);
//                 std::cout <<child->get_name() << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
// }
//
// void dfs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ) {
//     std::cout << "checking :  " ;
//     while (!graph_stack.empty()) {
//
//         Graph_Node* node = graph_stack.top();
//         int index = children_index.top();
//
//         int child_count = node->get_children().get_list_size();
//
//         std::cout << node->get_name() << " ";
//
//         if (node->get_name() == destination_graph_name) {
//             std::cout << std::endl;
//             break;
//         }
//
//         if (index >= child_count) {
//             graph_stack.pop();
//             children_index.pop();
//
//             if (!children_index.empty()) {
//                 children_index.top()++;
//             }
//
//             continue;
//         }
//
//         Graph_Node* child =
//             node->get_children().get_node(index)->get_data();
//
//         graph_stack.push(child);
//         children_index.push(0);
//     }
//
// }
//
// bool dls(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ,int limit ) {
//     std::cout << "current: " ;
//     int depth = 0;
//     while (!graph_stack.empty()) {
//         depth = graph_stack.size();
//
//         Graph_Node* node = graph_stack.top();
//         int index = children_index.top();
//
//         int child_count = node->get_children().get_list_size();
//
//         std::cout << node->get_name() << " ";
//
//
//         if (node->get_name() == destination_graph_name && depth <= limit) {
//             std::cout << std::endl;
//             return true;
//         }
//
//         if (index >= child_count || depth >= limit) {
//             graph_stack.pop();
//             children_index.pop();
//
//             if (!children_index.empty()) {
//                 children_index.top()++;
//             }
//
//             continue;
//         }
//
//         Graph_Node* child =
//             node->get_children().get_node(index)->get_data();
//
//         graph_stack.push(child);
//         children_index.push(0);
//     }
//     return false;
// }
//
// void ids(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ) {
//     bool found = false;
//     int depth = 0;
//
//     while (!found) {
//         std::cout << std::endl << "depth: " << depth << std::endl;
//         found =  dls(graph_stack, children_index, destination_graph_name, depth);
//         depth++;
//     }
// }
//
// void ucs(DoublyLinkedList<Graph_Node*>& graph_list_ucs,DoublyLinkedList<int>& graph_list_cost,std::string destination_graph_name) {
//
//     bool found = false;
//
//     while (!found) {
//         int min_cost = INT_MAX;
//         int father_index = -1;
//
//         for (int i = 0; i < graph_list_cost.get_list_size(); i++) {
//             Graph_Node* min_check = graph_list_ucs.get_node(i)->get_data();
//
//             std::cout << "checking: " << min_check->get_name() << std::endl;
//
//             if (min_check->get_name() == destination_graph_name) {
//                 found = true;
//                 break;
//             }
//
//             if (min_check->get_cost() < min_cost) {
//                 min_cost = min_check->get_cost();
//                 father_index = i;
//             }
//         }
//
//         if (found)
//             break;
//
//         Graph_Node* father =
//             graph_list_ucs.get_node(father_index)->get_data();
//
//         graph_list_ucs.remove_node(father_index);
//         graph_list_cost.remove_node(father_index);
//
//         std::cout << "adding : ";
//
//         for (int j = 0; j < father->get_children().get_list_size(); j++) {
//             Graph_Node* child =
//                 father->get_children().get_node(j)->get_data();
//
//             child->set_cost(father->get_cost() + child->get_cost());
//
//             graph_list_ucs.add_node(child);
//             graph_list_cost.add_node(child->get_cost());
//
//             std::cout << child->get_name() << " ";
//         }
//
//         std::cout << std::endl;
//     }
// }