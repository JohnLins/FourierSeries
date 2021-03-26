#include "raylib.h"
#include <math.h>


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    float theta = 0.0;

    InitWindow(screenWidth, screenHeight, "FourierTransform");

int n = 2;
float x = 0;
float y = 0;


    SetTargetFPS(60);          
    while (!WindowShouldClose())        
    {

        BeginDrawing();
                ClearBackground(RAYWHITE);
    
                  
                  
                  theta += 0.005;
        
                  for (int i = 0; i < n; i++) {
                    float prevx = x;
                    float prevy = y;

                    float n = i * 2 + 1;
                    float radius = 15 * (4 / (n * PI));
                    x += radius * cosf(n * theta);
                    y += radius * sinf(n * theta);

                    
                    DrawCircleLines(prevx + screenWidth/2, prevy + screenHeight/2, radius * 2, BLACK);
                    DrawLine(screenWidth/2, screenHeight/2, prevx + screenWidth/2, prevy + screenHeight/2, BLACK);
                    
                  }
               




        EndDrawing();
    }

    CloseWindow();  

    return 0;
}

















