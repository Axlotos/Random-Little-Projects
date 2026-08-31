#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Window dimensions
    int winWidth = 200;
    int winHeight = 48;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create Window and Renderer
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer("uhh title for hyprland to not use ;)", winWidth, winHeight, 0, &window, &renderer);

    // Main Loop
    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) { running = false; }
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_N || event.key.key == SDLK_ESCAPE) { running = false; }
                if (event.key.key == SDLK_Y || event.key.key == SDLK_RETURN) { system("command -v hyprshutdown >/dev/null 2>&1 && hyprshutdown || hyprctl dispatch 'hl.dsp.exit()'"); }
            }
        }

        // Drawing
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Black background
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer, 8, 8, "Are you sure you would");
        SDL_RenderDebugText(renderer, 8, 16, "like to close Hyprland?");

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderDebugText(renderer, 88, 32, "Y/n");  

        SDL_RenderPresent(renderer);
    }

    // DESTROYING!!!!!!
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}