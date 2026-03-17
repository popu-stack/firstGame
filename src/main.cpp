#include "raylib.h"
#include <filesystem>
#include <iostream>


int removeFile(){
    // escape backslashes or use a raw string literal so the path is valid
    std::filesystem::remove(R"(C:\Users\hayde\Documents\Projects\firstgame\myfile.txt)");
    return 0;
}

void CaptureScreen(const char* baseName) {
    const char* appDir = GetApplicationDirectory(); 
    const char* folderPath = TextFormat("%s../screenshots", appDir);

    if (!DirectoryExists(folderPath)) {
        MakeDirectory(folderPath);
        std::cout << "Folder created at: " << folderPath << std::endl;
    }

    const char* fileName = TextFormat("cap_%0.0f_%s", GetTime(), baseName);
    const char* fullPath = TextFormat("%s/%s", folderPath, fileName);

    removeFile();
    Image screenshot = LoadImageFromScreen();
    ExportImage(screenshot, fullPath);
    UnloadImage(screenshot);
    TraceLog(LOG_INFO, "SCREENSHOT SAVED: %s", fullPath);
}

int main() {
    InitWindow(800, 450, "My First C++ Game");
    SetTargetFPS(60);

    Rectangle rec = { 100, 100, 200, 80 };
    const char* displayText = "Lord Morgan, 2024...";
    
    // Style colors
    Color background = { 69, 54, 75, 255 };
    Color recColour = { 84, 68, 43, 255 };
    Color textColour = { 181, 194, 183, 255 };

    while (!WindowShouldClose()) {
        Vector2 mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                // Now saves to ../screenshots/cap_[time]_myshot.png
                CaptureScreen("myshot.png");
            }    
        }

        BeginDrawing();
            ClearBackground(background);
            DrawText(displayText, 40, 200, 20, textColour);
            
            // Button Drawing
            DrawRectangleRec(rec, Fade(recColour, 0.8f));
            DrawText("SAVE SCREEN", rec.x + 35, rec.y + 30, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}