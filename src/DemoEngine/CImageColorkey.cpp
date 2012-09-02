// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================


#include "CImageColorkey.h"
#include <stdexcept>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>


void DemoEngine::CImageColorkey::SetColorkey(Uint32 color)
{
    m_Colorkey = color;
}

void
DemoEngine::CImageColorkey::SetColorKey( Uint8 r, Uint8 g, Uint8 b)
{
  	m_Colorkey = SDL_MapRGB( GetSurface()->format, r,g,b);
}


Uint32 DemoEngine::CImageColorkey::GetColorkey()
{
    return m_Colorkey;
}



