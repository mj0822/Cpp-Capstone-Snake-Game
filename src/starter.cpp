#inlclude<SDL.h>
#include "starter.h"

Starter::Starter(){
    std::cout<<"Startedddddddd"<<std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout<<"initializeddddddd"<<std::endl;
    //Create a window with a title, "Getting Started", in the centre
    //(or undefined x and y positions), with dimensions of 800 px width
    //and 600 px height and force it to be shown on screen
    SDL_Window* window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    std::cout<<"window shown"<<std::endl;

    //Create a renderer for the window created above, with the first display driver present
    //and with no additional settings
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    std::cout<<"after opening"<<std::endl;
    //Set the draw color of renderer to green
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    std::cout<<"color"<<std::endl;
    //Clear the renderer with the draw color
    SDL_RenderClear(renderer);

    //Update the renderer which will show the renderer cleared by the draw color which is green
    SDL_RenderPresent(renderer);

    //Pause for 3 seconds (or 3000 milliseconds)
    SDL_Delay(3000);
    std::cout<<"off"<<std::endl;
    
    //Destroy the renderer created above
    SDL_DestroyRenderer(renderer);

    //Destroy the window created above
    SDL_DestroyWindow(window);

    //Close all the systems of SDL initialized at the top
    SDL_Quit();

}