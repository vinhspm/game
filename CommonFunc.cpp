#include "commonFunc.h"

int  Check_va_cham(const SDL_FRect& objectA, const SDL_FRect& objectB)
{
    int left_a = objectA.x+10;
    int right_a = objectA.x + objectA.w-10;
    int top_a = objectA.y+10;
    int bottom_a = objectA.y + objectA.h-8;

    int left_b = objectB.x;
    int right_b = objectB.x + objectB.w;
    int top_b = objectB.y;
    int bottom_b = objectB.y + objectB.h;

  // Case 1: size object 1 > size object 2
  if (left_a >= left_b && left_a <= right_b)
  {
    if (top_a >= top_b && top_a <= bottom_b)
    {
      return 1;
    }
  }

  if (left_a >= left_b && left_a <= right_b)
  {
    if (bottom_a >= top_b && bottom_a <= bottom_b)
    {
      return 1;
    }
  }

  if (right_a >= left_b && right_a <= right_b)
  {
    if (top_a >= top_b && top_a <= bottom_b)
    {
      return 1;
    }
  }

  if (right_a >= left_b && right_a <= right_b)
  {
    if (bottom_a >= top_b && bottom_a <= bottom_b)
    {
      return 1;
    }
  }

  // Case 2: size object 1 < size object 2
  if (left_a <= left_b && left_b <= right_a)
  {
    if (top_b >= top_a && top_b <= bottom_a)
    {
      return 1;
    }
  }

  if (left_b >= left_a && left_b <= right_a)
  {
    if (bottom_b >= top_a && bottom_b <= bottom_a)
    {
      return 1;
    }
  }

  if (right_b >= left_a && right_b <= right_a)
  {
    if (top_b >= top_a && top_b <= bottom_a)
    {
      return 1;
    }
  }

  if (right_b >= left_a && right_b <= right_a)
  {
    if (bottom_b >= top_a && bottom_b <= bottom_a)
    {
      return 1;
    }
  }

   // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return 1;
  }

  return 0;

}

int Check_point(const SDL_FRect& objectC, const SDL_FRect& objectD)
{
    int left_c = objectC.x+10;
    int right_c = objectC.x + objectC.w-10;
    int top_c = objectC.y+10;
    int bottom_c = objectC.y + objectC.h-8;

    int left_d = objectD.x;
    int right_d = objectD.x + objectD.w;
    int top_d = objectD.y;
    int bottom_d = objectD.y + objectD.h;

    //objA pass objB
    if(left_c > (left_d+right_d)/2 &&right_c < right_d) return 1;
    return 0;
}

