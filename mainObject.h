#ifndef MAIN_OBJECT_H_

#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"


#define WIDTH_MAIN_OBJECT 200
#define HEIGHT_MAIN_OBJECT 70
class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();

    MainObject(SDL_Renderer* renderer);
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    int getmPosX();
    int getmPosY();
    void changeY(float accel);
    void HandleInputAction(SDL_Event events, SDL_Renderer*screen, Mix_Chunk* wing_sound);
    void move(int &loseFlag);

private:
    int x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;


    SDL_Texture *Bird;

    int mPosX=60, mPosY=0;
    float mVelY=0;

};

#endif // MAIN_OBJECT_H_
