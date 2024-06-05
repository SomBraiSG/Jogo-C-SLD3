#include <SDL2/SDL.h>


class GM_render
{
private: 
bool is_running = true;

public:
    GM_render();
    ~GM_render();
    void draw_end();
    void draw();
    SDL_Window *window;
    SDL_Renderer * renderer;
    bool is_game_running();

protected:
};