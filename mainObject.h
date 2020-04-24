#ifndef MAIN_OBJECT_H_

#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"


#define WIDTH_MAIN_OBJECT 200
#define HEIGHT_MAIN_OBJECT 200
class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();

    enum UpDownType
    {
        UPDOWN_UP = 1,
        UPDOWN_DOWN = 0,
    };
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer*screen);
    void set_clips();
    void HandleMove();


private:
    int x_val_;
    int y_val_;



    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[2];
    Input input_type_;

    int frame_;
    int status_;


};

#endif // MAIN_OBJECT_H_
