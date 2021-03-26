#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 6000
#define RADIUS 100

int QUEUE[MAX],front=-1,rear=-1;

/** function        :   insert_in_Q(),
    to push an item into queue.
**/
void remove_from_Q(int queue[]);
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
       // printf("\nQUEUE is full.\n");
       
        return;
    }
    else
    {
        rear++;
        queue[rear]=ele;
    }
    //printf("\nItem inserted..");
}

/** function    :   display_Q(),
    to display queue elements
**/

void display_Q(int queue[])
{       int i;
    if(rear==-1) { 
    //printf("\nQUEUE is Empty.");
    return; }
    for(i=front;i<=rear;i++)
    { printf("%d,",queue[i]); }

}

/** function    :   remove_from_Q(),
    to remove (pop) an item from queue.
**/
void remove_from_Q(int queue[])
{
    int ele;
    if(front==-1)
    {
        //printf("QUEUE is Empty.");
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
   // printf("\nItem removed : %d.",ele);
}




float function(float *x, float radius){
    return radius * sin(*x);
}





int main(void)
{
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    float x = -120.0f;
   
 
    

    InitWindow(screenWidth, screenHeight, "Damped Motion");

   // float y;
    //float *yPtr = &y;
    
    //char yDisplay[30];
    //char xDisplay[30];
    
    //int queueLen = 0;
    

    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            
            x+= 0.01;
            
            
                DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, BLACK);
                DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, BLACK);
                
                DrawCircleLines(screenWidth/2, screenHeight/2, 100, RED);
                DrawLine(screenWidth/2, screenHeight/2, RADIUS*cosf(x) + screenWidth/2, RADIUS*sin(x) + screenHeight/2, BLUE);
                DrawCircle(RADIUS*cosf(x) + screenWidth/2, RADIUS*sin(x) + screenHeight/2, 3, BLACK);
          
               // DrawLine(100*cosf(x*.1) + screenWidth/2, 100*sinf(x*.1) + screenHeight/2, x + screenWidth/2, 100*sinf(x * .1) + screenHeight/2, GREEN);
                
                //*yPtr = ;
                
                insert_in_Q(QUEUE, function(&x, RADIUS));// queueLen++;
           
                float x_new = 0.0;
                    for(int i=rear;i>=front;i--)
                    {
                        x_new += 0.1;
                    //printf("%d,",QUEUE[i]);
                    DrawCircle(screenWidth/2 + x_new + 200, QUEUE[i] + screenHeight/2, 2, BLUE);
                    }
                    
                    
                
            
            //sprintf(yDisplay, "%f", -y);
            //sprintf(xDisplay, "%f", x);
            
            
            
            //DrawText("Displacment(y): ", 10, 10, 20, BLACK);
           // DrawText(yDisplay, 170, 10, 20, BLACK);
            
         ///   DrawText("Time(x): ", 10, 50, 20, BLACK);
         //   DrawText(xDisplay, 100, 50, 20, BLACK);
            
            
          //  DrawText("Down key to reset time", 10, screenHeight - 30, 20, BLACK);
          //  DrawText("Up key to update values", 10, screenHeight - 60, 20, BLACK);
            
        EndDrawing();
    }
    CloseWindow();       

    return 0;
}



