
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include<time.h>
#include "commonFunc.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(double x,double y)
    {
        rect_.x = x, rect_.y = y;
    }
    SDL_FRect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}

    virtual bool LoadImg(std::string path, SDL_Renderer*screen);

    void Render(SDL_Renderer*des, const SDL_Rect* clip = NULL);
    void Free();

protected:
    SDL_Texture* p_object_;
    SDL_FRect rect_;
};
#endif // BASE_OBJECT_H_
