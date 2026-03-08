// Ctrl + Shift + B

#include "raylib.h"

int main() {
    
    InitWindow(800, 450, "My First C++ Game");
    SetTargetFPS(60);
    
    const char* displayText = " CHANGE";
    int fontSize = 20;
    int posX = GetScreenWidth()/2 - MeasureText(displayText, fontSize)/2;
    int posY = GetScreenHeight()/2 - (fontSize / 2);
    Color color = BLACK;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(Color{ 255, 20, 30, 255 });
            DrawText(displayText,
            posX, 
            posY,
            fontSize, 
            color);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}