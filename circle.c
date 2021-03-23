#include "raylib.h"
#include <math.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    const float radius = 100.0;
    float theta = 0.0;
    float theta2 = 4.0;

    InitWindow(screenWidth, screenHeight, "FourierTransform");




    SetTargetFPS(60);          
    while (!WindowShouldClose())        
    {

        BeginDrawing();
                ClearBackground(RAYWHITE);
    
                theta += 0.05;
                theta2 += 0.05;
                
        
                DrawCircleV((Vector2){radius * cosf(theta) + screenWidth/2, radius * sinf(theta) + screenHeight/2}, 6.0,  BLACK);
                DrawCircleLines(screenWidth/2, screenHeight/2, radius, RED);
                DrawLineV((Vector2){screenWidth/2,screenHeight/2}, (Vector2){radius * cosf(theta) + screenWidth/2, radius * sinf(theta) + screenHeight/2}, GREEN);
            
            
               
                DrawLineV((Vector2){radius * cosf(theta) + screenWidth/2, radius * sinf(theta) + screenHeight/2}, (Vector2){(radius * cosf(theta) + screenWidth/2) + 50*cosf(theta2), (radius * sinf(theta) + screenHeight/2) + 50*sinf(theta2)}, RED);
            


        EndDrawing();
    }

    CloseWindow();  

    return 0;
}

















