#ifndef PATH_FINDING_UI_H
#define PATH_FINDING_UI_H
#include <iostream>
#include <ostream>
#include <raylib.h>
#include <string>
#include "..\EDITOR/GraphEditor.h"
#include "..\EDITOR/AlgorithmController.h"

class Button {

private:
    Rectangle rectangle;
    std::string text;


public:
    Button(Rectangle rectangle, std::string text) {
        this->rectangle = rectangle;
        this->text = text;
    };
    void draw() {

        DrawRectangleRec(rectangle, GRAY);

        int text_width = MeasureText(text.c_str(), 20);

        DrawText(
            text.c_str(),
            rectangle.x + (rectangle.width - text_width) / 2,
            rectangle.y + (rectangle.height - 20) / 2,
            20,
            WHITE
        );
    };
    bool is_clicked() {
        if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            return false;
        }
        if (is_hovering()) {
            return true;
        }else {
            return false;
        }
    };

    bool is_hovering() {
        return CheckCollisionPointRec(
            GetMousePosition(),
            rectangle
        );
    }
};

class UI {
    private:
        int screenWidth, screenHeight;
        GraphEditor* graphEditor;
        AlgorithmController* algorithmController;

        Button* select_button;
        Button* add_edge;
        Button* delete_node;
        Button* add_node;
        Button* set_goal;
        std::string description;
        std::string selected_tool;

    Button* bfs_button;
    Button* dfs_button;
    Button* dls_button;
    Button* ids_button;
    Button* ucs_button;
    Button* greedy_search;
    Button* a_star_button;

    public:
        void draw();
        void initialize(int screenWidth , int screenHeight , GraphEditor* graphEditor , AlgorithmController* algorithmController);
        void update();

};
#endif 