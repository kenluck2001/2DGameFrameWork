// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CImage.h"
#include <stdexcept>
#include <iostream>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CImage::CImage()
{
  	m_pSurfaceOrig = NULL;
  	SetBlittedArea( 0,0,0,0);

    m_pSurface = NULL;
    int initFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    int retFlags = IMG_Init(initFlags);
    if ( retFlags != initFlags )
    {
        std::cerr<<"SDL_image init failed: " << IMG_GetError() <<std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CImage::~CImage()
{
	Release();
	ReleaseOrig();
	IMG_Quit( ) ;
}
////////////////////////////////////////////////////////////////////////////////

void
DemoEngine::CImage::Load( const char *szFileName )
{
	Release();
	ReleaseOrig();

    m_pSurface = IMG_Load(szFileName);
    if ( m_pSurface == NULL ) 
        throw std::runtime_error( "Cannot load image:" + std::string(szFileName) );
    SDL_SetAlpha ( GetSurface() , 0 , 0 ) ;  //disable alpha blending

  	SetBlittedArea(0,0, m_pSurface->w, m_pSurface->h);
  	m_pSurfaceOrig = m_pSurface; //reserve the original surface and make changes to the derived surface

}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CImage::SetSurface( SDL_Surface *pSurface )
{
    m_pSurface = pSurface;
  	if ( m_pSurface )
    	SetBlittedArea( 0,0, m_pSurface->w, m_pSurface->h);
}
////////////////////////////////////////////////////////////////////////////////
SDL_Surface * 
DemoEngine::CImage::GetSurface()
{
    return m_pSurface;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CImage::Release()
{
  	if ( m_pSurface != m_pSurfaceOrig && m_pSurface != NULL ) //perform this check to prevent image degradation as a result of scaling up and down on the same surface reference
  	{
        SDL_FreeSurface(m_pSurface );
    	m_pSurface = NULL;
	}
}
////////////////////////////////////////////////////////////////////////////////

void DemoEngine::CImage::ReleaseOrig()
{
  	if ( m_pSurfaceOrig )
  	{
    	SDL_FreeSurface( m_pSurfaceOrig );
    	m_pSurfaceOrig = NULL;    
  	}
}
////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CImage::ScaleUniform( float factor, bool smooth )
{
  	SDL_Surface *pTmp = NULL;

  	pTmp = zoomSurface( m_pSurfaceOrig, factor, factor, smooth);
  	if ( pTmp )
  	{
    	Release();
    	SetSurface(pTmp);
  	}
}

////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CImage::ScaleXY( float factorX, float factorY, bool smooth )
{
  	SDL_Surface *pTmp = NULL;
  	pTmp = zoomSurface( m_pSurfaceOrig, factorX, factorY, smooth);
  	if ( pTmp )
  	{
    	Release();
    	SetSurface(pTmp);
  	}
}

////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CImage::Rotate( float degrees, bool smooth )
{
  	SDL_Surface *pTmp = NULL;
  	pTmp = rotozoomSurface( m_pSurfaceOrig, degrees, 1.0, smooth );
  	if ( pTmp )
  	{
    	Release();
    	SetSurface(pTmp);
  	}
}

////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CImage::SetBlittedArea( int x, int y, int width, int height )
{
  	m_Area.x = x;
  	m_Area.y = y;
  	m_Area.w = width;
  	m_Area.h = height;
}

////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CImage::SetBlittedArea( const SDL_Rect & rect )
{
  	m_Area = rect;
}

////////////////////////////////////////////////////////////////////////////////
SDL_Rect *
DemoEngine::CImage::GetBlittedArea()
{
  return &m_Area;
}

void 
DemoEngine::CImage::SetOriginalSurface( SDL_Surface *pSurface )
{
  	m_pSurfaceOrig = pSurface;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CImage::CreateEmpty(size_t nWidth, size_t nHeight, size_t nDepth)
{
    Uint32 rmask, gmask, bmask, amask;
  
    // SDL interprets each pixel as a 32-bit number, so our masks must depend
    // on the endianness (byte order) of the machine 

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0;
    #endif
  	Release();
  	ReleaseOrig();

    // Creates new surface with hardware acceleration and alpha channel
    m_pSurface = SDL_CreateRGBSurface( SDL_HWSURFACE, 
				      nWidth, nHeight, nDepth,
				      rmask, gmask, bmask, amask );
  
    if ( m_pSurface == NULL ) 
    {
        std::cerr << "Creating new surface failed:" << SDL_GetError() << std::endl;
        exit(1);
    }
	m_pSurfaceOrig = m_pSurface;
}
////////////////////////////////////////////////////////////////////////////////
