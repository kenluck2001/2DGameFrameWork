// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CCollisionDetector.h"
////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////

DemoEngine::CCollisionDetector* DemoEngine::CCollisionDetector::iInstance = NULL;

DemoEngine::CCollisionDetector::CCollisionDetector()
{
}

DemoEngine::CCollisionDetector* DemoEngine::CCollisionDetector::GetInstance()
{
    if ( iInstance == NULL ) {
    iInstance = new DemoEngine::CCollisionDetector();
    }

    return iInstance;
}


Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}
////////////////////////////////////////////////////////////////////////////////
inline bool IsTransparent( SDL_Surface *pS, int x, int y )
{
  

  Uint32 pix = getpixel( pS, x,y);
  if ( (pS->flags & SDL_SRCCOLORKEY) && 
       (pix == pS->format->colorkey) ) 
  {
    return true;
  }
  else if ( (pS->flags & SDL_SRCALPHA) &&
	    ( (pix & pS->format->Amask) == 0) )
  {
    return true;
  }
  
  return false;
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CCollisionDetector::Collides(  CImage & imgA,  CVector2i & posA,  CImage & imgB,  CVector2i & posB ) 
{
    int cx, cy, cw, ch;
    int ax = posA[0], ay = posA[1], bx = posB[0], by = posB[1];
    SDL_Surface *pA = imgA.GetSurface();
    SDL_Surface *pB = imgB.GetSurface();   

    if ( ax < bx )
    {
      cx = bx;
      cw = ax + pA->w - bx;   
    }
    else
    {
      cx = ax;
      cw = (bx + pB->w) - ax;
    }
    
    if ( ay < by )
    {
      cy = by;
      ch = ay + pA->h - by;
    }
    else
    {
      cy = ay;
      ch = by + pB->h - ay;      
    }

    SDL_LockSurface( pA );
    SDL_LockSurface( pB );

    for( int y = cy; y < cy+ch ; y++)
    {
      for( int x = cx; x < cx+ cw ; x++)
      {
        // If either of the pixels is transparent, then there is no collision
        if ( IsTransparent( pA, x-ax, y-ay) ) continue;
        if ( IsTransparent( pB, x-bx, y-by) ) continue;

        SDL_UnlockSurface( pA );
        SDL_UnlockSurface( pB );
        return true;
      }
    }
    SDL_UnlockSurface( pA );
    SDL_UnlockSurface( pB );
    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CCollisionDetector::Collides(  CCircle & c1,  CCircle & c2 ) 
{
    CVector2i diff = c1.GetPosition() - c2.GetPosition();
    return  ( diff.Length() < (c1.GetRadius() + c2.GetRadius()));
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CCollisionDetector::Collides(  CRectangle & r1,  CRectangle & r2 ) 
{
    int r1_top = r1.GetY() - (0.5 * r1.GetHeight()) ;
    int r2_top = r2.GetY() - (0.5 * r1.GetHeight());

    int r1_bottom = r1_top + r1.GetHeight();
    int r2_bottom = r2_top + r2.GetHeight();

    int r1_left = r1.GetX() - (0.5 * r1.GetWidth());
    int r2_left = r2.GetX() - (0.5 * r2.GetWidth());

    int r1_right = r1_left + r1.GetWidth();
    int r2_right = r2_left + r2.GetWidth();

    if ( r1_bottom < r2_top ) return false;
    if ( r1_top > r2_bottom ) return false;
    if ( r1_left > r2_right ) return false;
    if ( r1_right < r2_left ) return false;

    return true;

}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CCollisionDetector::Collides(  CCircle & c,  CVector2i & pos ) 
{
    CVector2i diff = c.GetPosition() - pos;
    return  ( diff.Length() < c.GetRadius());
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CCollisionDetector::Collides(  CRectangle & r,  CVector2i & pos ) 
{
    int r1_top = r.GetY() - (0.5 * r.GetHeight()) ;
    int r1_bottom = r1_top + r.GetHeight();
    int r1_left = r.GetX() - (0.5 * r.GetWidth());
    int r1_right = r1_left + r.GetWidth();
    //if point is inside the rectangle
    if ( (r1_bottom >= pos[1]) && (r1_top <= pos[1]) && (r1_left <= pos[0]) && (r1_right >= pos[0])) return true;
    //If we get this far,collision does not occur.
    return false;
}
////////////////////////////////////////////////////////////////////////////////

