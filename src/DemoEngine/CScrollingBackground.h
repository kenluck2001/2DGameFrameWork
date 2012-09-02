// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CScrollingBackground_h__
#define __CScrollingBackground_h__
#include <CImageAlpha.h>
#include <CRenderer.h>
#include <vector>
#include <cassert>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  enum OFFSET_DIR
  {
    HORIZONTAL,
    VERTICAL,
	NUM_DIRS
  };
  /** A layer for a single repeatable alpha-blended background image. */
  class CBackgroundLayer 
  {
  public:
    SDL_Rect dest;
    DemoEngine::CImageAlpha *m_pImage;
    int offset[NUM_DIRS];
    int cum_steps[NUM_DIRS];
    int step_limit;
  public:
    CBackgroundLayer()
    {
      dest.x = 0;
      dest.y = 0;
      offset[0] = offset[1] = 0;
      m_pImage = NULL;
      cum_steps[0] = cum_steps[1] = 0;
      step_limit = 1;
    }
    
    virtual ~CBackgroundLayer()
    {
      delete m_pImage;
    }

    void SetImage( DemoEngine::CImageAlpha *pImage ) 
    {
      m_pImage = pImage;
    }

    void Load( const char *szFile )
    {
      m_pImage = new CImageAlpha();
      m_pImage->Load(szFile);
    }
    
    void Render( DemoEngine::CRenderer & renderer  )
    {
   		SDL_Surface * pScreen = renderer.GetScreen() ;
		SDL_Rect tmp = dest;
		tmp.x = dest.x;
		tmp.y = dest.y;

		if ( offset[VERTICAL] > 0 )
		{
		  offset[VERTICAL] -= m_pImage->GetSurface()->h;
		}
		tmp.y += offset[VERTICAL];
		
		while( tmp.y < pScreen->h )
		{
		  if ( offset[HORIZONTAL] > 0 )
		  {
		  	offset[HORIZONTAL] -= m_pImage->GetSurface()->w;
		  }
		  tmp.x += offset[HORIZONTAL];
		  while( tmp.x < pScreen->w )
		  {
			SDL_Rect blit = tmp;
			SDL_BlitSurface( m_pImage->GetSurface(), NULL, pScreen, &blit );
			tmp.x += m_pImage->GetSurface()->w;
		  }
			  
		  tmp.y += m_pImage->GetSurface()->h;
		  tmp.x = dest.x;
		}
    }
  
    void Move( OFFSET_DIR d, int step )
    {
      cum_steps[d] += step;
      if ( cum_steps[d] >= step_limit )
      {
	offset[d] -= cum_steps[d]/step_limit;
	cum_steps[d] -= (cum_steps[d]/step_limit)*step_limit;
      }
      else if ( cum_steps[d] <= -step_limit )
      {
	offset[d] += cum_steps[d]/-step_limit;
	cum_steps[d] -= (cum_steps[d]/-step_limit)*-step_limit;
      }    
      int iImageWidth = m_pImage->GetSurface()->w;
      int iImageHeight = m_pImage->GetSurface()->h;
      int steps_h = offset[HORIZONTAL] / iImageWidth;
      int steps_v = offset[VERTICAL] / iImageHeight;
      
      if ( offset[HORIZONTAL] >= iImageWidth )       offset[HORIZONTAL] += iImageWidth * steps_h;
      else if ( offset[HORIZONTAL] <= -iImageWidth ) offset[HORIZONTAL] -= iImageWidth * steps_h;

      if ( offset[VERTICAL] >= iImageHeight )       offset[VERTICAL] += iImageHeight * steps_v;
      else if ( offset[VERTICAL] <= -iImageHeight ) offset[VERTICAL] -= iImageHeight * steps_v;
    }
  };
  ////////////////////
  /// Actual class from layered, scrolling background.
  class CScrollingBackground 
  {
  protected:
    std::vector<DemoEngine::CBackgroundLayer *> m_vecLayers;
  public:
    CScrollingBackground( size_t nLayers)
    {
      m_vecLayers.reserve(nLayers);
      for( size_t t=0;t<nLayers;t++)
		m_vecLayers.push_back(NULL);
    }
    virtual ~CScrollingBackground()
    {
      while(m_vecLayers.empty())
      {
		delete m_vecLayers.back();
		m_vecLayers.pop_back();
      }
    }
    void SetLayer( size_t nLayerNum, DemoEngine::CBackgroundLayer *pLayer )
    {
      delete m_vecLayers[nLayerNum];
      m_vecLayers[nLayerNum] = pLayer;
    }

    void SetLayer( size_t nLayerNum, const char *szFile )
    {
      delete m_vecLayers[nLayerNum];
      m_vecLayers[nLayerNum] = new DemoEngine::CBackgroundLayer();
      m_vecLayers[nLayerNum]->Load(szFile);
    }

    DemoEngine::CBackgroundLayer * GetLayer( size_t nLayerNum )
    {
      return m_vecLayers[nLayerNum];
    }

    void Move( OFFSET_DIR d, int step )
    {
      for(size_t i=0;i<m_vecLayers.size();i++)
      {
	m_vecLayers[i]->Move(d,step);
      }
    }
    void Render( DemoEngine::CRenderer & renderer )
    {
      for(size_t i=0;i<m_vecLayers.size();i++)
      {
	m_vecLayers[i]->Render(renderer);
      }
    }
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
/// SDL Programming
/// Brush-up: Add support for multi-layered scrolling background.
/// Reference answer
/// Author AG
////////////////////////////////////////////////////////////////////////////////

