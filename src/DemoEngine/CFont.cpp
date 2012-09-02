// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CFont.h"
#include <stdexcept>
#include <iostream>

using namespace DemoEngine;

DemoEngine::CFont::CFont() : m_pFont(NULL)
{
    if(!TTF_WasInit() && TTF_Init() == -1)
    {
        throw std::runtime_error( std::string("TTF_Init: ") +  std::string(TTF_GetError()));  
    }
    SDL_Color normColor = {255, 255, 255, 255};
    SetColor(normColor);
}

void 
DemoEngine::CFont::SetColor(SDL_Color & color)
{
    m_Color = color;
}

SDL_Color & 
DemoEngine::CFont::GetColor( )
{
    return m_Color;
}

DemoEngine::CFont::~CFont()
{
    Cleanup();
}

void 
DemoEngine::CFont::Load( const char *szPath, size_t nFontSize )
{
    m_pFont = TTF_OpenFont(szPath, nFontSize);
    if ( !m_pFont ) throw std::runtime_error("Load font error: " + 
						  std::string(TTF_GetError()));
  
}

void 
DemoEngine::CFont::Cleanup()
{
    if ( m_pFont )  TTF_CloseFont(m_pFont);
    m_pFont = NULL;

}

DemoEngine::CImageAlpha * 
DemoEngine::CFont::CreateImageFromTextAL( const char *szText )
{
    CImageAlpha *pImage = new CImageAlpha();
    if (m_pFont != NULL)
    {
        pImage->SetSurface( TTF_RenderText_Blended( m_pFont, szText, GetColor()) );
        pImage->SetAlpha(128);
    }
    if( pImage->GetSurface() == NULL )
    {
        TTF_SetError("Surface is NULL!!!!!!");
    }
    return pImage;
}
////////////////////////////////////////////////////////////////////////////////


DemoEngine::CImage * 
DemoEngine::CFont::CreateImageFromText( const char *szText )
{
    CImage *pImage = new CImage();
    if (m_pFont != NULL)
    {
        pImage->SetSurface( TTF_RenderText_Solid( m_pFont, szText, GetColor()) );
    }
    if( pImage->GetSurface() == NULL )
    {
        TTF_SetError("Surface is NULL!!!!!!");
    }
    return pImage;
}

////////////////////////////////////////////////////////////////////////////////


DemoEngine::CImageColorkey *
DemoEngine::CFont::CreateImageFromTextCK( const char *szText )
{
    CImageColorkey *pImage = new CImageColorkey();
    if (m_pFont != NULL)
    {
        pImage->SetSurface( TTF_RenderText_Solid( m_pFont, szText, GetColor()) );
    }
    if( pImage->GetSurface() == NULL )
    {
        TTF_SetError("Surface is NULL!!!!!!");
    }
    return pImage;
}

////////////////////////////////////////////////////////////////////////////////


