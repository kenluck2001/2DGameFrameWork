// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================


#include <SDL/SDL.h>    
#include <SDL/SDL_gfxPrimitives.h>
#include <cmath>
#include <iostream> 
#include <vector>
#include <cassert>
#include <CParticleSystem.h>
#include <CVector2.h>
#include <CTimer.h>
#include <CImageAlpha.h>
using namespace std;
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
const int WINDOW_WIDTH  = 640;
const int WINDOW_HEIGHT = 480;
const int COLOR_DEPTH_IN_BITS = 24;
const int COLORKEY[3] = {0, 67, 171};
////////////////////////////////////////////////////////////////////////////////
class CSimpleParticleSystem : public CParticleSystem
{
protected:
  CVector2f m_vPos;
  CImageAlpha m_Image;
public:
  
  CSimpleParticleSystem( size_t nNumParticles, const CVector2f & vPos) : 
    CParticleSystem(nNumParticles)
  {
    m_fEnergyDecrementPerSec = 0.55;
    m_vPos = vPos;
    m_Image.Load("pics/particle.png");
	m_Image.SetAlpha(254);
  }
  void InitVelocity( CParticle & p) 
  {
    const int MAX = 201;
    p.m_vVelocity[0] = (rand() % MAX) - MAX/2;
    p.m_vVelocity[1] = (rand() % MAX) - MAX/2;
  }
  
  void InitPosition( CParticle & p) 
  {
    p.m_vPosition = m_vPos;
  }

  void InitEnergy ( CParticle & p ) 
  {
    p.m_fEnergy = 1.0;
  }
  void Render( CRenderer & r )
  {
    for( size_t p=0; p< m_nNumParticlesAlive; p++)
    {
      CParticle & par = m_vecParticles[p];
      r.Render( &m_Image, 
		static_cast<int>(par.m_vPosition[0]), 
		static_cast<int>(par.m_vPosition[1]));
    }
  }
};

////////////////////////////////////////////////////////////////////////////////
/// SDL Programming 2010
////////////////////////////////////////////////////////////////////////////////
/// Example of particle system, that allows to modify particle starting 
/// position via inheritance and function overriding.
/// Hit SPACEBAR to start effect. Hold SPACEBAR to see more.
/// \author anssi.grohn@pkamk.fi
////////////////////////////////////////////////////////////////////////////////

