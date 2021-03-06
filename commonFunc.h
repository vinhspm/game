#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<string>
#include <SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;


//sound
static Mix_Chunk* g_sound_wing;
static Mix_Chunk* g_sound_point;
static Mix_Chunk* g_sound_hit;
static Mix_Chunk* g_sound_die;
static Mix_Chunk* g_sound_over;



//screen
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;



const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;
const int RENDER_DRAW_COLOR = 255 ;
int  Check_va_cham(const SDL_FRect& objectA, const SDL_FRect& objectB);
int Check_point(const SDL_FRect& objectC, const SDL_FRect& objectD);

#endif // COMMON_FUNCTION_H_
