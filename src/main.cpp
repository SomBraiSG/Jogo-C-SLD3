

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

// Your First C++ Program

#include <iostream>

#include "GM_render.h"

// Define MAX and MIN macros
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char **argv)
{
    std::cout << "Hello World!";
    printf("Uhull rodando S2L2\n");
    // Unused argc, argv

    GM_render ren;

    // Declare rect of square
    SDL_Rect squareRect;

    // Square dimensions: Half of the min(SCREEN_WIDTH, SCREEN_HEIGHT)
    squareRect.w = MIN(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;
    squareRect.h = MIN(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;

    // Square position: In the middle of the screen
    squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

    // Event loop
    while (ren.is_game_running())
    {
        ren.draw();

        // Set renderer color red to draw the square
        SDL_SetRenderDrawColor(ren.renderer, 0xFF, 0x00, 0x00, 0xFF);

        // Draw filled square
        SDL_RenderFillRect(ren.renderer, &squareRect);

        ren.draw_end();
    }

    return 0;
}
