#include"commonFunc.h"
#include "BaseObject.h"
#include "mainObject.h"

#include "ThreatsObject.h"
#include<ctime>
BaseObject g_background;
SDL_Surface* g_object = NULL;



bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0)
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

    g_window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,
                                SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL)
            success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)==-1)
        return false;

    //doc file am thanh wav
    g_sound_wing = Mix_LoadWAV("sound//sfx_wing.wav");
    g_sound_hit = Mix_LoadWAV("sound//sfx_hit.wav");
    g_sound_point = Mix_LoadWAV("sound//sfx_point.wav");
    g_sound_die = Mix_LoadWAV("sound//sfx_die.wav");

    if(g_sound_wing == NULL || g_sound_hit == NULL || g_sound_point == NULL || g_sound_die == NULL)
    {
        return false;
    }

    return success;


}

bool LoadBackGround()
{
    bool ret = g_background.LoadImg("img//background.png", g_screen);
    if(ret = false)
        return false;
    else return true;
}


void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[])
{
    if(InitData() == false)
        return -1;
    if(LoadBackGround() == false)
        return -1;

    bool is_quit = false;

    MainObject p_player;
    p_player.LoadImg("img//bird2.png",g_screen);


    //make threats

    const double speed = 0.4; // toc do di chuyen cua threat

    ThreatObject* p_threat1 =  new ThreatObject();
    bool ret1 = p_threat1 ->LoadImg("img/threat.png",g_screen);
    if(ret1 == false) return 10;
    p_threat1 ->SetRect(2 * SCREEN_WIDTH / 3 - WIDTH_THREAT /3,-300);
    p_threat1->set_x_val(speed);

    ThreatObject* p_threat2 =  new ThreatObject();
    bool ret2 = p_threat2 ->LoadImg("img/threat2.png",g_screen);
    if(ret2 == false) return 10;
    p_threat2 ->SetRect(2 * SCREEN_WIDTH / 3 - WIDTH_THREAT /3,-300+600+GAP_THREAT);
    p_threat2->set_x_val(speed);

    ThreatObject* p_threat3 =  new ThreatObject();
    bool ret3 = p_threat3 ->LoadImg("img/threat.png",g_screen);
    if(ret3 == false) return 10;
    p_threat3 ->SetRect(SCREEN_WIDTH,-200);
    p_threat3 ->set_x_val(speed);

    ThreatObject* p_threat4 =  new ThreatObject();
    bool ret4 = p_threat4 ->LoadImg("img/threat2.png",g_screen);
    if(ret4 == false) return 10;
    p_threat4 ->SetRect(SCREEN_WIDTH,-200+600+GAP_THREAT);
    p_threat4->set_x_val(speed);

    ThreatObject* p_threat5 =  new ThreatObject();
    bool ret5 = p_threat5 ->LoadImg("img/threat.png",g_screen);
    if(ret5 == false) return 10;
    p_threat5 ->SetRect(4 * SCREEN_WIDTH / 3 + WIDTH_THREAT / 3,-400);
    p_threat5 ->set_x_val(speed);

    ThreatObject* p_threat6 =  new ThreatObject();
    bool ret6 = p_threat6 ->LoadImg("img/threat2.png",g_screen);
    if(ret6 == false) return 10;
    p_threat6 ->SetRect(4 * SCREEN_WIDTH / 3 + WIDTH_THREAT / 3,-400+600+GAP_THREAT);
    p_threat6->set_x_val(speed);


    float accel=0.02;
    int lose = 0;

    while(!is_quit)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if(g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }

            p_player.HandleInputAction(g_event, g_screen, g_sound_wing);
        }
        p_player.changeY(accel);
        p_player.move(lose);

        if (lose == 1)
        {
            Mix_PlayChannel(-1, g_sound_hit, 0);
            SDL_Delay(2000);
            is_quit = true;
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR );
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen,NULL);
        p_player.Show(g_screen);


        //draw threats
        p_threat1->Show_1(g_screen);
        p_threat1->HandleMove1(SCREEN_WIDTH,SCREEN_HEIGHT);
        p_threat2->Show_1(g_screen);
        p_threat2->HandleMove2(SCREEN_WIDTH,SCREEN_HEIGHT);
        p_threat3->Show_1(g_screen);
        p_threat3->HandleMove1(SCREEN_WIDTH,SCREEN_HEIGHT);
        p_threat4->Show_1(g_screen);
        p_threat4->HandleMove2(SCREEN_WIDTH,SCREEN_HEIGHT);
        p_threat5->Show_1(g_screen);
        p_threat5->HandleMove1(SCREEN_WIDTH,SCREEN_HEIGHT);
        p_threat6->Show_1(g_screen);
        p_threat6->HandleMove2(SCREEN_WIDTH,SCREEN_HEIGHT);

        int result[6];
        result[0] = Check_va_cham(p_player.GetRect(), p_threat1->GetRect());
        result[1] = Check_va_cham(p_player.GetRect(), p_threat2->GetRect());
        result[2] = Check_va_cham(p_player.GetRect(), p_threat3->GetRect());
        result[3] = Check_va_cham(p_player.GetRect(), p_threat4->GetRect());
        result[4] = Check_va_cham(p_player.GetRect(), p_threat5->GetRect());
        result[5] = Check_va_cham(p_player.GetRect(), p_threat6->GetRect());
        for(int x = 0; x < 6;x++)
        {
            if(result[x] == 1)
            {

                Mix_PlayChannel(-1, g_sound_hit, 0);
                SDL_Delay(700);
                Mix_PlayChannel(-1, g_sound_die, 0);
                SDL_Delay(2000);
                is_quit = true;
            }
        }
        SDL_RenderPresent(g_screen);

    }

    close();
    return 0;
}








