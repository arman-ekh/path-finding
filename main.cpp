#include <iostream>

#include "raylib.h"
#include "include/Algorithms/Algorithm.h"
#include "include/Algorithms/BFS.h"
#include "include/Algorithms/DFS.h"
#include "include/Algorithms/UCS.h"
#include "include/EDITOR/GraphEditor.h"
#include "include/Graph/Graph.h"
#include "include/Visualization/Graph_Renderer.h"

int main() {

    const int screenWidth = 1280;
    const int screenHeight = 720;

    Graph graph;
    auto *graph_editor = new GraphEditor(graph);
    auto *graph_renderer = new GraphRenderer();

    //
    // graph_editor->create_node(150,100);
    // graph_editor->create_node(100,200);
    // graph_editor->create_node(200,200);
    // graph_editor->create_node(100,300);
    // graph_editor->create_node(200,300);
    // graph_editor->create_node(300,300);
    //
    // Graph_Node* nodeA = graph_editor->get_node_at("A");
    // Graph_Node* nodeB = graph_editor->get_node_at("B");
    // Graph_Node* nodeC = graph_editor->get_node_at("C");
    // Graph_Node* nodeD = graph_editor->get_node_at("D");
    // Graph_Node* nodeE = graph_editor->get_node_at("E");
    // Graph_Node* nodeF = graph_editor->get_node_at("F");
    //
    //
    // graph_editor->create_edge(6,nodeA,nodeB);
    // graph_editor->create_edge(3,nodeA,nodeC);
    // graph_editor->create_edge(3,nodeB,nodeD);
    // graph_editor->create_edge(2 , nodeB , nodeE);
    // graph_editor->create_edge(2 , nodeC , nodeF);

    // graph.set_goal(nodeE);
    // graph.set_start(nodeA);

    Algorithm* algorithm = nullptr;
    algorithm = new BFS();




    InitWindow(screenWidth, screenHeight, "PATH_FINDING");
    SetTargetFPS(60);

    float dt;
    while (!WindowShouldClose()) {
        dt = GetFrameTime();
        BeginDrawing();


        graph_editor->update();
        graph_renderer->draw(graph);



        ClearBackground(WHITE);
        EndDrawing();
    }
    algorithm->initialize(graph);
    if (algorithm != nullptr) {
        std::cout << "goal : "<< graph.get_goal()->get_name() << std::endl;
        std::cout << "start : "<<graph.get_start()->get_name() << std::endl;
        while (!algorithm->is_finished() && !algorithm->is_found() ) {
            algorithm->step();
        }
        graph.reset_nodes();
        std::cout <<"found: " <<algorithm->is_found()<< std::endl;
    }
    //graph_editor->draw();

    return 0;
}