#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

#define CELL_SIZE 10

int main(char* args) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Sand Sim!");

    int rows = screenHeight / CELL_SIZE;
    int cols = screenWidth / CELL_SIZE;

    int* grid = (int*) calloc(rows * cols, sizeof(int));

    for (int i = 0; i < rows * cols; i++) {
        //grid[i] = i % 2;
    }

    grid[2200] = 1;

    SetTargetFPS(60);
    //Main Loop
    while (!WindowShouldClose()) {
        //Handle mouse input
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            int col = mousePosition.x / CELL_SIZE;
            int row = mousePosition.y / CELL_SIZE;
            
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                grid[row * cols + col] = 1;  // Set the cell to 1
            }
        }

        //GAME LOGIC
        //----- GAME LOGIC
        int* next_grid = (int*) calloc(rows * cols, sizeof(int));

        for (int i = 0; i < rows * cols; i++) {
            if(grid[i] == 1) {
                int below_square = grid[i+cols];
                //BROKE IT
                //int below_R = grid[i+cols + 1];
                //int below_L = grid[i+cols - 1];
                if (i + cols < rows * cols && grid[i+cols] == 0) {
                    next_grid[i+cols] = 1;
                    //printf("Moving %d to %d \n", i, i +cols);
                // } else if (below_L == 0) {
                //    next_grid[i+cols - 1] = 1;
                // } else if (below_R == 0) {
                //    next_grid[i+cols + 1] = 1;
                } else  {
                    next_grid[i] = 1;
                }
            }
        }
        //Move next_grid into grid
        memcpy(grid, next_grid, rows* cols * sizeof(int));
        free(next_grid);
        
        //----- DRAWING
        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < rows * cols; i++) {
                int row = i / cols;
                int col = i % cols;

                int x = col * CELL_SIZE;
                int y = row * CELL_SIZE;

                Color cellColor = grid[i] == 1 ? DARKGRAY: LIGHTGRAY;

                DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, cellColor);
                
            }   
            
        EndDrawing();
    }
    CloseWindow();

    free(grid);
    return 0;
}

