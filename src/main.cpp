#include "raylib.h"
#include <iostream>

void CaptureScreen(const char* filename) {
    const char* appDir = GetApplicationDirectory(); 
    const char* screenshotFolder = TextFormat("%s../screenshots", appDir);
    if (!DirectoryExists(screenshotFolder)) {
        MakeDirectory(screenshotFolder);
    }
    const char* fullPath = TextFormat("%s/%s", screenshotFolder, filename);
    Image screenshot = LoadImageFromScreen();
    ExportImage(screenshot, fullPath);
    UnloadImage(screenshot);
    TraceLog(LOG_INFO, "Screenshot successfully saved to: %s", fullPath);
}

int main() {
    InitWindow(800, 450, "My First C++ Game");
    SetTargetFPS(60);
    Rectangle rec = { 100, 100, 200, 80 };
    Vector2 mousePosition = { 0 };
    bool mouseScaleMode = false;
    const char* appDir = GetApplicationDirectory();
    const char* displayText = "Lord Morgan, 2024...";
    int fontSize = 20;
    int posX = GetScreenWidth()/2 - MeasureText(displayText, fontSize)/2;
    int posY = GetScreenHeight()/2 - (fontSize / 2);
    
    Color background = Color{ 69, 54, 75, 255};
    Color recColour = Color{ 84, 68, 43, 255};
    Color textColour = { 181, 194, 183, 255 };

    while (!WindowShouldClose()) {
        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                mouseScaleMode = true;
                std::cout << "Mouse Clicked - @" << mousePosition.x << ", " << mousePosition.y << std::endl;
                CaptureScreen("screenshot.png");
            };    
        }
        BeginDrawing();
            ClearBackground(background);
            DrawText(displayText, posX, posY, fontSize, textColour);
            DrawRectangleRec(rec, Fade(recColour, 0.5f));
            DrawText("SAVE SCREEN", rec.x + 10, rec.y + 30, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}