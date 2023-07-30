/*******************************************************************************************
*
*   Snowfall - Jeffrey Kedda
*   
*   snowfall simulation using sine function for wind and oscillation. Applied terminal velocity and fall phyiscs based on random size of snowflake
*
********************************************************************************************/

#include "Snowflakes.h"

int main(void)
{
   
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Snowfall - Jeffrey Kedda");   
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);
    SetTargetFPS(60);
    Snowflakes snowflakes = Snowflakes();
    Random::Init();

    while (!WindowShouldClose())       
    {

        BeginDrawing();

        ClearBackground(BLACK);
        snowflakes.draw_update();

        EndDrawing();

        snowflakes.removeSnowflake();
       
    }

   
    CloseWindow();        

    return 0;
}