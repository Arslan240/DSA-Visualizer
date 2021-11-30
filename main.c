/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 550;

    InitWindow(screenWidth, screenHeight, "Visualization");

    Camera camera = { 0 };
    // camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    camera.position = (Vector3){5.0f,5.0f,5.0f};
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    
    SetCameraMode(camera, CAMERA_ORBITAL);

    Vector3 cubePosition = { 3 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            // BeginMode3D(camera);

                // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                // DrawGrid(10, 1.0f);

            // EndMode3D();
            int x = 30;
            int width = 80;
            int height = 30;
            int space_btw_2_nodes = 10;
            int increment = width + space_btw_2_nodes;
            int posY_rectantgle = 80;
            int total_nodes = 5;
            
            for (size_t i = 0; i < total_nodes; i++)
            {
                DrawRectangle(x,posY_rectantgle,width,height,WHITE);

                // Logic to draw line, the condition checks if it is last node or note.
                if(i != total_nodes - 1){ //TODO make it dynamic
                    int start_positionX = x+width;
                    int end_positionX = x+increment;
                    int start_posY = posY_rectantgle + (height/2);
                    int end_posY = posY_rectantgle + (height/2);
                    DrawLine(start_positionX,start_posY,end_positionX,end_posY,GREEN);
                }

                // // Logic to draw line with rectangle, because we can't change thickness of line drawn with drawline() method.

                // if(i != total_nodes - 1){
                //     int start_positionX = x+width;
                //     int end_positionX = x+increment;
                //     int rect_line_width = end_positionX - start_positionX; //this will calculate the width of the line btw two rectangles.
                //     int rect_line_height = height / 4; //the height of line drawn will be one fourth of the original rectangle. 
                //     int start_posY = posY_rectantgle + (height/2);
                //     int end_posY = posY_rectantgle + (height/2);
                //     // DrawLine(start_positionX,start_posY,end_positionX,end_posY,GREEN);
                    
                // }

                x += increment;
            }
            
            // DrawRectangle(30,80,50,30,WHITE);
            // DrawCircleLines(60,100,30.0f,RED);
            // DrawCircle(6, 6, 50.f, GREEN);


            DrawText("This is a Linked List example", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}