// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================


#include "CImageAlpha.h"
#include <stdexcept>
#include <SDL/SDL_image.h>
#include <iostream>


void DemoEngine::CImageAlpha::SetAlpha(Uint8 i_Alpha)
{
    m_Alpha = i_Alpha;
	SDL_SetAlpha( m_pSurface, SDL_SRCALPHA, m_Alpha);
}

Uint8 DemoEngine::CImageAlpha::GetAlpha()
{
    return m_Alpha;
}

bool  DemoEngine::CImageAlpha::IsTransparent()
{
    return (m_Alpha > 0 && m_Alpha < 255) ? true : false ;
}


void DemoEngine::CImageAlpha::Load( const char *szFileName )
{
    m_pSurface = IMG_Load(szFileName);
    if ( m_pSurface == NULL ) 
    {
        throw std::runtime_error( "Cannot load image:" + std::string(szFileName)) ;
    } else
	{
					
		if (m_pSurface->format->BitsPerPixel == NO_OF_BITS_PER_PIXEL)
		{
		    SetAlpha(m_pSurface->format->alpha); // set alpha value
		}
		SetSurface( m_pSurface);
	}
}

