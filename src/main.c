#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 10000
#define NUM 4

int QUEUE[MAX],front=-1,rear=-1;


void remove_from_Q(int queue[]);
void insert_in_Q(int queue[],int ele);

int main(void)
{
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    
    float x = -120.0f;
    float r[NUM] = {240, 120, 110, 40};
    float ar[NUM] = {1.1, 2.17, 3.3, 5.0};
    float pos[NUM+1][2];
    Color colors[NUM] = {RED, BLUE, YELLOW, PURPLE};
    pos[0][0] = screenWidth/2; pos[0][1] = screenHeight/2;
 
    

    InitWindow(screenWidth, screenHeight, "Fourier Series");

   
    
   
    

    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
                DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, BLACK);
                DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, BLACK);


                x+=0.01;
                
                for(int i = 0; i < NUM; i++){
                    pos[i+1][0] = pos[i][0] + r[i]*sinf(x*ar[i]);
                    pos[i+1][1] = pos[i][1] + r[i]*cosf(x*ar[i]);
                    
                    DrawLine(pos[i][0], pos[i][1], pos[i+1][0], pos[i+1][1], colors[i]);
                    
                    DrawCircleLines(pos[i+1][0], pos[i+1][1], r[i]/2, colors[i]);
                    
                    insert_in_Q(QUEUE,  pos[i+1][1] );
                }
            
            
                    DrawCircleLines(screenWidth/2, screenHeight/2, r[0], BLACK);
                    
           
                    float x_new = 0.0;
                    for(int i=rear;i>=front;i--)
                    {
                        x_new += 0.1;
                        DrawCircle(screenWidth/2 + x_new + 300, QUEUE[i] , 2, BLUE);
                    }
                    
                    
                
     
        EndDrawing();
    }
    CloseWindow();       

    return 0;
}

void insert_in_Q(int queue[],int ele)
{
    if(rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else if(rear==MAX-1)
    {
      remove_from_Q(QUEUE);
      queue[rear]=ele;
       
        return;
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
}

void remove_from_Q(int queue[])
{
    int ele;
    if(front==-1)
    {
        return;
    }
    else if(front==rear)
    {
        ele=queue[front];
        front=rear=-1;
    }
    else
    {
        ele=queue[front];
        front++;
    }
}


