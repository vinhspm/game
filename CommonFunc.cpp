#include "commonFunc.h"

int  Check_va_cham(const SDL_FRect& objectA, const SDL_FRect& objectB)
{
    int left_a = objectA.x;
  int right_a = objectA.x + objectA.w;
  int top_a = objectA.y;
  int bottom_a = objectA.y + objectA.h;

  int left_b = objectB.x;
  int right_b = objectB.x + objectB.w;
  int top_b = objectB.y;
  int bottom_b = objectB.y + objectB.h;

  // Case 1: size object 1 > size object 2
  if (left_a >= left_b && left_a <= right_b)
  {
    if (top_a >= top_b && top_a <= bottom_b)
    {
      return true;
    }
  }

  if (left_a >= left_b && left_a <= right_b)
  {
    if (bottom_a >= top_b && bottom_a <= bottom_b)
    {
      return true;
    }
  }

  if (right_a >= left_b && right_a <= right_b)
  {
    if (top_a >= top_b && top_a <= bottom_b)
    {
      return true;
    }
  }

  if (right_a >= left_b && right_a <= right_b)
  {
    if (bottom_a >= top_b && bottom_a <= bottom_b)
    {
      return true;
    }
  }

  // Case 2: size object 1 < size object 2
  if (left_a <= left_b && left_b <= right_a)
  {
    if (top_b >= top_a && top_b <= bottom_a)
    {
      return true;
    }
  }

  if (left_b >= left_a && left_b <= right_a)
  {
    if (bottom_b >= top_a && bottom_b <= bottom_a)
    {
      return true;
    }
  }

  if (right_b >= left_a && right_b <= right_a)
  {
    if (top_b >= top_a && top_b <= bottom_a)
    {
      return true;
    }
  }

  if (right_b >= left_a && right_b <= right_a)
  {
    if (bottom_b >= top_a && bottom_b <= bottom_a)
    {
      return true;
    }
  }

   // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;

}

