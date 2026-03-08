#include "raylib.h"
#include <iostream>
#define MOUSE_SCALE_MARK_SIZE   12
int main() {
    InitWindow(800, 450, "My First C++ Game");
    SetTargetFPS(60);

    Rectangle rec = { 100, 100, 200, 80 };
    Vector2 mousePosition = { 0 };

    bool mouseScaleReady = false;
    bool mouseScaleMode = false;
    
    const char* displayText = " CHANGE";
    int fontSize = 20;
    int posX = GetScreenWidth()/2 - MeasureText(displayText, fontSize)/2;
    int posY = GetScreenHeight()/2 - (fontSize / 2);
    Color background = Color{ 38, 42, 60, 255};
    Color recColour = Color{ 84, 68, 43, 255};

    while (!WindowShouldClose()) {
        mousePosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePosition, rec))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
            {
                mouseScaleMode = true;
                std::cout << "Mouse Clicked - @" << mousePosition.x << ", " << mousePosition.y << std::endl;
            }    
        }
        else mouseScaleReady = false;

        BeginDrawing();
            ClearBackground(background);
            DrawText(displayText,
            posX, 
            posY,
            fontSize, 
            recColour);
            DrawRectangleRec(rec, Fade(recColour, 0.5f));
        EndDrawing();
    }

    CloseWindow();
    return 0;
}