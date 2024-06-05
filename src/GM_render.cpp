#include "GM_render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

// Define screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

GM_render::GM_render()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initialized!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
        return;
    }

    // Create window
    window = SDL_CreateWindow("Basic C SDL project",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Window could not be created!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Renderer could not be created!\n"
               "SDL_Error: %s\n",
               SDL_GetError());
    }
}

GM_render::~GM_render()
{
    // Destroy renderer
    SDL_DestroyRenderer(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();
}

void GM_render::draw_end()
{
    // Update screen
    SDL_RenderPresent(renderer);
}

void GM_render::draw()
{
    SDL_Event e;

    // Wait indefinitely for the next available event
    SDL_WaitEvent(&e);

    // User requests quit
    if (e.type == SDL_QUIT)
    {
        is_running = false;
    }

    // Initialize renderer color white for the background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Clear screen
    SDL_RenderClear(renderer);
}

bool GM_render::is_game_running()
{
    return is_running;
}
