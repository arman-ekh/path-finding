#include "../../include/Visualization/UI.h"

#include <raylib.h>
#include <string>



void UI::initialize(int screenWidth, int screenHeight , GraphEditor* graphEditor,AlgorithmController* algorithmController) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->graphEditor = graphEditor;
    this->algorithmController = algorithmController;

    float button_width = screenWidth/4 - 40;
    float button_height = 80;
    float button_x = screenWidth - screenWidth/4 + 20;

    this->select_button = new Button(Rectangle(button_x  , 20 , button_width , button_height) , "SELECT_NODE");
    this->add_edge = new Button(Rectangle(button_x , 220 , button_width , button_height) , "ADD_EDGE");
    this->add_node = new Button(Rectangle(button_x , 120 , button_width , button_height) , "ADD_NODE");
    this->delete_node = new Button(Rectangle(button_x , 320 , button_width , button_height),"DELETE_NODE");
    this->set_goal = new Button(Rectangle(button_x , 420 ,button_width , button_height ) , "SET_GOAL");

    this->bfs_button = new Button(Rectangle(button_x, 800, button_width/3-5, 50),"BFS");
    this->dfs_button = new Button(Rectangle(button_x+button_width/3, 800, button_width/3-5, 50),"DFS");
    this->dls_button = new Button(Rectangle(button_x+(2*button_width)/3, 800, button_width/3-5, 50),"DLS");
    this->ids_button = new Button(Rectangle(button_x, 900, button_width/3-5, 50),"IDS");
    this->ucs_button = new Button(Rectangle(button_x+button_width/3, 900, button_width/3-5, 50),"UCS");
}

void UI::draw() {
    DrawRectangle(screenWidth - screenWidth/4 , 0 ,screenWidth/4 , screenHeight , BLACK);
    select_button->draw();
    add_node->draw();
    delete_node->draw();
    set_goal->draw();
    add_edge->draw();

    bfs_button->draw();
    dfs_button->draw();
    dls_button->draw();
    ids_button->draw();
    ucs_button->draw();

    DrawText(
        selected_tool.c_str(),
        screenWidth - screenWidth / 4 + 20,
        520,
        22,
        WHITE
    );

    DrawText(
        description.c_str(),
        screenWidth - screenWidth / 4 + 20,
        560,
        18,
        GRAY
    );
}

void UI::update() {

    if (select_button->is_clicked()) {

        graphEditor->set_mode(EditorMode::SELECT);

        selected_tool = "SELECT NODE";

        description =
            "Click on a node to select it.";
    }

    if (add_node->is_clicked()) {

        graphEditor->set_mode(EditorMode::CREATE_NODE);

        selected_tool = "ADD NODE";

        description =
            "Click anywhere to \ncreate a new node.";
    }

    if (add_edge->is_clicked()) {

        graphEditor->set_mode(EditorMode::CREATE_EDGE);

        selected_tool = "ADD EDGE";

        description =
            "Click a source node, \nthen click another node to\ncreate an edge.";
    }

    if (delete_node->is_clicked()) {

        graphEditor->set_mode(EditorMode::DELETE);

        selected_tool = "DELETE NODE";

        description =
            "Click on a node to delete it.";
    }

    if (set_goal->is_clicked()) {

        graphEditor->set_mode(EditorMode::SET_GOAL);

        selected_tool = "SET GOAL";

        description =
            "Click on a node to\nset it as the goal.";
    }

    if (bfs_button->is_clicked()) {
        algorithmController->set_algorithm(
            AlgorithmType::BFS
        );
    }

    if (dfs_button->is_clicked()) {
        algorithmController->set_algorithm(
            AlgorithmType::DFS
        );
    }

    if (dls_button->is_clicked()) {
        algorithmController->set_algorithm(
            AlgorithmType::DLS
        );
    }

    if (ids_button->is_clicked()) {
        algorithmController->set_algorithm(
            AlgorithmType::IDS
        );
    }

    if (ucs_button->is_clicked()) {
        algorithmController->set_algorithm(
            AlgorithmType::UCS
        );
    }
}

