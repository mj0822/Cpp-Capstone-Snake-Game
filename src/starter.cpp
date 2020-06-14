#include <SDL.h>
#include "starter.h"
#include <SDL_ttf.h>

Starter::Starter(){
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);

  if(TTF_Init()==-1) {  //you did not initialize ttf font, this is done in renderer.cpp but u commented it so...
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }
  //Create a window with a title, "Getting Started", in the centre
  //(or undefined x and y positions), with dimensions of 800 px width
  //and 600 px height and force it to be shown on screen
  SDL_Window* window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
  SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);


  //Create a renderer for the window created above, with the first display driver present
  //and with no additional settings
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  //Set the draw color of renderer to green
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    
  TTF_Font* Sans = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 16); 
  
  if (Sans == NULL){  //check if font loaded or not because load nahi hua to error nahi dega
    std::cout<<"not found  "<<TTF_GetError()<<std::endl;
  }

  SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White);

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

  int texW = 0;  //automatically be changed by below func
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);  //find the size required to save display the text
  SDL_Rect dstrect = { 0, 0, texW, texH };  //auto-rectangele to display above text

  //Pause until app is quit

  while (!quit)
  {
    SDL_WaitEvent(&event);  //like cv2.waitkey(0)

    switch (event.type)
    {
        case SDL_QUIT:
            quit = true;
            break;
    }

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
  }
  //everything is a source and should be closed if opened
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surfaceMessage);

  //Destroy the renderer created above
  SDL_DestroyRenderer(renderer);

  //Destroy the window created above
  SDL_DestroyWindow(window);

  //Close all the systems of SDL initialized at the top
  

  TTF_CloseFont(Sans);
  TTF_Quit();

  SDL_Quit();

}
