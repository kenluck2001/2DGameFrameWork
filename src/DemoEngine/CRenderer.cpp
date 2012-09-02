// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CRenderer.h"
#include <SDL/SDL_gfxPrimitives.h>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Begin()
{
    // for transparency, you need to clear screen before drawing again...
    SDL_FillRect( m_pScreen, NULL, 0); 
}
/////////////////////////////////////////////////////////////////
void 
CRenderer::End()
{
    SDL_Flip( m_pScreen ); 
}
////////////////////////////////////////////////////////////////////////////////
void
CRenderer::Render( CImage *pImage, int x, int y )
{
    //disable alpha blending and colorkey
    SDL_SetAlpha ( pImage->GetSurface() , 0 , 0 ) ;  //disable alpha blending
    //disable color key
    int COLORKEY[3] = { 0 , 0 , 0 } ; //use an arbitrary color to disable all forms of colorkey
    Uint32 colorkey = SDL_MapRGB( pImage->GetSurface()->format ,COLORKEY[0] ,COLORKEY[1] ,COLORKEY[2] ) ;
    SDL_SetColorKey ( pImage->GetSurface() , SDL_FALSE, colorkey ) ;

    SDL_Rect dst = { x,y, 0,0};
    SDL_BlitSurface( pImage->GetSurface(), pImage->GetBlittedArea(), m_pScreen, &dst );
}
///////////////////////////////////////////////////////////////////////////////
void
CRenderer::Render( CImageColorkey *pImage, int x, int y )
{
    SDL_SetAlpha ( pImage->GetSurface() , 0 , 0 ) ;  //disable alpha blending
    SDL_SetColorKey ( pImage->GetSurface() , SDL_SRCCOLORKEY, pImage->GetColorkey() ) ;

    SDL_Rect dst = { x,y, 0,0};
    SDL_BlitSurface( pImage->GetSurface(), pImage->GetBlittedArea(), m_pScreen, &dst );
}

//////////////////////////////////////////////////////////////////////////////
void
CRenderer::Render( CImageAlpha *pImage, int x, int y )
{
    if (pImage->IsTransparent())
    {
        SDL_Rect dst = { x,y, 0,0};
        SDL_BlitSurface( pImage->GetSurface(), pImage->GetBlittedArea(), m_pScreen, &dst );
    }
}

////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Render( CEllipse *pEllipse)
{
    int x_axis = static_cast<int>(pEllipse->GetX());
    int y_axis = static_cast<int>(pEllipse->GetY());
    int width = static_cast<int>(pEllipse->GetWidth());
    int height = static_cast<int>(pEllipse->GetHeight());
    SDL_Color & color = pEllipse->GetColor();
    if ( pEllipse->IsFilled())
        filledEllipseRGBA( GetScreen(), x_axis, y_axis, width , height, color.r, color.g, color.b, color.unused );
    else
        ellipseRGBA( GetScreen(), x_axis, y_axis, width , height, color.r, color.g, color.b, color.unused );
}
////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Render( CCircle *pCircle)
{
    int x_axis = static_cast<int>(pCircle->GetX());
    int y_axis = static_cast<int>(pCircle->GetY());
    int radius = static_cast<int>(pCircle->GetRadius());
    SDL_Color & color = pCircle->GetColor();
    if ( pCircle->IsFilled())
        filledCircleRGBA( GetScreen(), x_axis, y_axis, radius, color.r, color.g, color.b, color.unused );
    else
        circleRGBA( GetScreen(), x_axis, y_axis, radius, color.r, color.g, color.b, color.unused );
}
////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Render( CRectangle *pRect )
{
    int x1 = static_cast<int>(pRect->GetX());
    int y1 = static_cast<int>(pRect->GetY());
    int x2 = x1 + static_cast<int>(pRect->GetWidth());
    int y2 = y1 + static_cast<int>(pRect->GetHeight());
    SDL_Color & color = pRect->GetColor();
    if ( pRect->IsFilled())
        boxRGBA( GetScreen(), x1, y1, x2, y2, color.r, color.g, color.b, color.unused );
    else
        rectangleRGBA( GetScreen(), x1, y1, x2, y2, color.r, color.g, color.b, color.unused );
}
////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Render( CLineSegment *pLine )
{
    int x1  = static_cast<int>(pLine->GetStart()[0]);
    int y1  = static_cast<int>(pLine->GetStart()[1]);
    int x2 = static_cast<int>(pLine->GetEnd()[0]);
    int y2 = static_cast<int>(pLine->GetEnd()[1]);
    SDL_Color & color = pLine->GetColor();
    lineRGBA( GetScreen(), x1, y1, x2,y2, color.r, color.g, color.b, color.unused);
}
////////////////////////////////////////////////////////////////////////////////
void
CRenderer::OpenWindow(int width, int height, int depth, int flags )
{
    m_pScreen = SDL_SetVideoMode( width, height, depth, flags);

    if( m_pScreen == NULL ) throw std::runtime_error( std::string(SDL_GetError()));
}
////////////////////////////////////////////////////////////////////////////////
void 
CRenderer::Init()
{
    if ( m_bInitialized) return;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    m_bInitialized = true;
}
////////////////////////////////////////////////////////////////////////////////
void
CRenderer::CleanUp()
{
    if ( m_bInitialized )
        SDL_Quit();
    m_bInitialized = false;
}
////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CRenderer::SetClearColor( Uint8 r, Uint8 g, Uint8 b)
{
    m_ClearColor = SDL_MapRGB( m_pScreen->format, r,g,b);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CRenderer::ClearScreen()
{
    SDL_FillRect( m_pScreen, NULL, m_ClearColor);
}
////////////////////////////////////////////////////////////////////////////////
SDL_Surface * 
DemoEngine::CRenderer::GetScreen()
{
    return m_pScreen;
}
////////////////////////////////////////////////////////////////////////////////
