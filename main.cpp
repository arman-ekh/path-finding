#include <iostream>
#include <queue>
#include <stack>

#include "raylib.h"
#include "Header/DoublyLinkedList.h"
#include "Header/Graph_Node.h"


void bfs(bool* found , std::queue<Graph_Node*> graph_queue , std::string destination_graph_name);
void dfs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name );
bool dls(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ,int limit );
void ucs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name );

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

    std::string origin_graph_name = "A";
    std::string destination_graph_name = "F";


    std::stack<Graph_Node*> graph_stack;
    std::stack<int> children_index;

    graph_stack.push(nodeA);
    children_index.push(0);

    dfs(graph_stack, children_index, destination_graph_name);


    std::queue<Graph_Node*> graph_queue;
    graph_queue.push(nodeA);
    bool found = false;
    bfs(&found, graph_queue, destination_graph_name);


    std::stack<Graph_Node*> graph_stack_dls;
    std::stack<int> children_index_dls;

    graph_stack_dls.push(nodeA);
    children_index_dls.push(0);

    int dls_limit = 3;
    bool found_dls = dls(graph_stack_dls, children_index_dls, destination_graph_name, dls_limit);


    std::stack<Graph_Node*> graph_stack_ucs;
    std::stack<int> children_index_ucs;

    graph_stack_ucs.push(nodeA);
    children_index_ucs.push(0);
    ucs(graph_stack_ucs, children_index_ucs, destination_graph_name);

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

void bfs(bool* found , std::queue<Graph_Node*> graph_queue , std::string destination_graph_name) {
    while (!*found && !graph_queue.empty()) {
        Graph_Node* current = graph_queue.front();
        std::cout <<"checking : " <<current->get_name() << " " ;
        if (current->get_name() == destination_graph_name) {
            *found = true;
            std::cout << std::endl;
        }

        int child_count = current->get_children().get_list_size();
        if (child_count <= 0 ) {
            graph_queue.pop();
        }else {
            graph_queue.pop();
            std::cout << "adding: ";
            for (int i = 0; i < child_count; i++) {
                Graph_Node* child = current->get_children().get_node(i)->get_data();
                graph_queue.push(child);
                std::cout <<child->get_name() << " ";
            }
            std::cout << std::endl;
        }
    }
}

void dfs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ) {
    std::cout << "checking :  " ;
    while (!graph_stack.empty()) {

        Graph_Node* node = graph_stack.top();
        int index = children_index.top();

        int child_count = node->get_children().get_list_size();

        std::cout << node->get_name() << " ";

        if (node->get_name() == destination_graph_name) {
            std::cout << std::endl;
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

}

bool dls(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ,int limit ) {
    std::cout << "current: " ;
    int depth = 0;
    while (!graph_stack.empty()) {
        depth = graph_stack.size();

        Graph_Node* node = graph_stack.top();
        int index = children_index.top();

        int child_count = node->get_children().get_list_size();

        std::cout << node->get_name() << " ";


        if (node->get_name() == destination_graph_name && depth <= limit) {
            std::cout << std::endl;
            return true;
        }

        if (index >= child_count || depth >= limit) {
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
    return false;
}

void ucs(std::stack<Graph_Node*> graph_stack ,std::stack<int> children_index , std::string destination_graph_name ) {
    bool found = false;
    int depth = 0;

    while (!found) {
        std::cout << std::endl << "depth: " << depth << std::endl;
        found =  dls(graph_stack, children_index, destination_graph_name, depth);
        depth++;
    }
}
