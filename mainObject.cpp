#include "commonFunc.h"
#include "mainObject.h"
#include "loadBird.h"



MainObject::MainObject()
{
    x_pos_ = 150;
    y_pos_ = 350;

    rect_.x = 0;
    rect_.y = 0;
    rect_.w = WIDTH_MAIN_OBJECT;
    rect_.h = HEIGHT_MAIN_OBJECT;


}


MainObject::~MainObject()
{
    ;
}

int MainObject::getmPosX()
{
	return mPosX;
}
int MainObject::getmPosY()
{
	return mPosY;
}

//con chim rơi tự do
void MainObject::changeY(float accel)
{
	mVelY += accel;
}


bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path,screen);

    if (ret == true)

    return ret;
}

//quản lý sự kiện nhập vào từ bàn phím
void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer *screen)
{

    if(events.type == SDL_KEYDOWN && events.key.repeat == 0)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_SPACE: mVelY = -1.7;
        break;

        default:
            break;
        }
    }
}


//quản lý chuyển động của con chim
void MainObject::move(int &loseFlag)
{
    mPosY += mVelY;

    if (mPosY < 0)
	{
		mPosY = 0;
	}

    if( mPosY +HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT )
    {
        mPosY = SCREEN_HEIGHT - HEIGHT_MAIN_OBJECT ;
		loseFlag = 1;
    }
}
void MainObject::Show(SDL_Renderer*des)
{
    LoadImg("img//bird2.png", des);

    rect_.x = mPosX;
    rect_.y = mPosY;
    rect_.w = 64;
    rect_.h = 64;
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};



    //render bird với góc thay đổi
    SDL_RenderCopyEx(des,p_object_, NULL, &renderquad, mVelY* 15 -10, nullptr, SDL_FLIP_NONE);


}

