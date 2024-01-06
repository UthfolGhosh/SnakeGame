#include <bits/stdc++.h>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH=600;
const int SCREEN_HEIGHT =900;

SDL_Window* window=NULL;
SDL_Renderer* snakeRender=NULL;
SDL_Surface* screensurface =NULL;
SDL_Surface* loadsurface(std::string path);
SDL_Rect fruitposition;
SDL_Rect snakeposition;
SDL_Rect tailposition;

int xtail[1000],ytail[1000];
int ntail;

void snaketail()
{
    int xprev = xtail[0];
    int yprev = ytail[0];

    int xprev2,yprev2;

    xtail[0]=snakeposition.x;
    ytail[0]=snakeposition.y;

    for(int i=1; i<ntail; i++)
    {
        xprev2 = xtail[i];
        yprev2= ytail[i];

         xtail[i]=xprev;
         ytail[i]=yprev;

        xprev = xprev2;
        yprev = yprev2;

        SDL_Rect fillRect = {xprev,yprev,20,20};
        SDL_SetRenderDrawColor(snakeRender,255,145,164,0xFF);
        SDL_RenderFillRect(snakeRender,&fillRect);
    }
}

bool checkcollision()
{
    int leftA,leftB;
    int rightA,rightB;
    int topA,topB;
    int bottomA,bottomB;

    leftA=snakeposition.x;
    rightA=snakeposition.x+10;
    topA=snakeposition.y;
    bottomA=snakeposition.y+10;

    leftB=fruitposition.x;
    rightB=fruitposition.x+10;
    topB=fruitposition.y;
    bottomB=fruitposition.y+10;

    if(bottomA<=topB)
    {
        return true;
    }

    if(topA>=bottomB)
    {
        return true;
    }
    
    if(rightA<=leftB)
    {
        return true;
    }
    if(rightB<=leftA)
    {
        return true;
    }

     return false;
}

void  game_structure()
{

}


#ifdef _WIN32
int SDL_main(int argc, char* argv[])
#else
int main(int argc, char* argv[])
#endif
 {
    int dir = 0;
    if(!game_screen())
    {
        printf("Failed to initialize!\n");
    }
    else{
        bool quit = false;
        SDL_Event e;

        game_structure();

        while(!quit)
        {
            while(SDL_PollEvent(&e)!=0)
            {
                if(e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else
                {
                    switch(e.type)
                    {
                        case SDL_KRYDOWN:
                         
                         switch(e.key.keysym.sym)
                         {
                            case SDLK_LEFT:
                              dir = 1;
                              break;
                            case SDLK_RIGHT:
                              dir=2;;
                              break;
                            case SDLK_UP:
                              dir = 3;;
                              break;
                            case SDLK_DOWN:
                              dir = 4;;
                              break;
                            default:
                              break;
                         }
                         break;

                         default:
                           break;
                    }
                }
            }
            gamelogic(dir);
        }
    }
    close();
    return 0;
}

