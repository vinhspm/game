
#include "mainObject.h"

MainObject::MainObject()
{
    frame_ = 0;
    x_pos_ = 150;
    y_pos_ = 350;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = WIDTH_MAIN_OBJECT;
    rect_.h = HEIGHT_MAIN_OBJECT;
    input_type_.up_ = 0;


}

MainObject::~MainObject()
{
    ;
}

bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path,screen);

    if (ret == true)
    {
        width_frame_ = rect_.w/2;
        height_frame_ = rect_.h;
    }

    return ret;
}
void MainObject::set_clips()
{
    if(width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = 0;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;
    }
}
void MainObject::Show(SDL_Renderer*des)
{

    LoadImg("img//bird2.png", des);
    if(input_type_.up_ == 1 )
    {
        frame_++;
    }
    else
    {
        frame_ = 0;
    }

    if(frame_ >= 2)
    {
        frame_ = 0;
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip_[frame_];

    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);

}
void MainObject::HandleInputAction(SDL_Event events, SDL_Renderer *screen)
{
    if(events.type == SDL_KEYDOWN)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_SPACE:
            {
                status_ = UPDOWN_UP;
                input_type_.up_ = 1;
                y_pos_ -= 80;

            }
            break;
        default:
            break;

        }
    }
    else if(events.type == SDL_KEYUP)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_SPACE:
            {
                status_ = UPDOWN_UP;
                input_type_.up_ = 0;

            }
            break;
        default:
            break;

        }
    }
    else
    {
        status_ = UPDOWN_DOWN;
        input_type_.up_ = 0;
        y_pos_ += 30;

    }
}


