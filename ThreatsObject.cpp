#include "ThreatsObject.h"
#include<ctime>

int a[30]={-400,-390,-380,-370,-360,-350,-340,-330,-320,-310,-300,-280,-270,-260,-250,-240,-230,-220,-210,-200,-190,-180,-170,-160,-150,-140,-130,-120,-110};
int temp;


ThreatObject::ThreatObject()
{
    rect_.x = SCREEN_WIDTH;
    rect_.y = 0;
    rect_.w = WIDTH_THREAT;
    rect_.h = HEIGHT_THREAT;

    x_val_ = 0;
    y_val_ = 0;
}

ThreatObject::~ThreatObject()
{
    ;
}

void ThreatObject::HandleMove1(const int&x_bordr1, const int& y_bordr1)
{
    rect_.x -= x_val_;
    if(rect_.x < -100)
    {
        rect_.x = SCREEN_WIDTH;

        srand(time(0));

        rect_.y = a[rand() % 29];
        temp = rect_.y;
    }
}

void ThreatObject::HandleMove2(const int&x_bordr2, const int& y_bordr2)
{
    rect_.x -= x_val_;
    if(rect_.x < -100)
    {
        rect_.x = SCREEN_WIDTH;

        rect_.y = temp + 600+GAP_THREAT;
    }
}
void ThreatObject::Show_1(SDL_Renderer*des)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des,p_object_,NULL, &renderquad);
}

void ThreatObject::HandleInputAction(SDL_Event events)
{
 ;
}






