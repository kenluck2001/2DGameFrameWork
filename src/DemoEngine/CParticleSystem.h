// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CParticleSystem_h__
#define __CParticleSystem_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>    
#include <SDL/SDL_gfxPrimitives.h>
#include <cmath>
#include <iostream> 
#include <vector>
#include <cassert>
#include <CVector2.h>
#include <IUpdateable.h>
#include <IRenderable.h>
#include <CRenderer.h>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
namespace DemoEngine 
{
  ////////////////////////////////////////////////////////////////////////////////
  // Our happy particle object.
  class CParticle
  {
  public:
    CVector2f	m_vPosition;      // current position of game object.
    CVector2f	m_vVelocity;      // speed vector
    float	m_fEnergy;        // particle energy
  };
  ////////////////////////////////////////////////////////////////////////////////
  /// Our happy particle system base class.
  class CParticleSystem : public IUpdateable, public IRenderable
  {
  protected:
    std::vector<CParticle>	m_vecParticles;
    float			m_fEnergyDecrementPerSec;
    size_t			m_nNumParticlesAlive;
    size_t			m_nMaxParticles;
  public:
    ////////////////////
    CParticleSystem( size_t nMaxParticles ) 
    {
      m_nMaxParticles = nMaxParticles;
      CParticle tmp;
      m_vecParticles.assign(m_nMaxParticles, tmp);
      m_nNumParticlesAlive = 0;
      m_fEnergyDecrementPerSec = 0.7f;
    }
    ////////////////////
    virtual ~CParticleSystem(){ m_vecParticles.clear();}
    ////////////////////
    void Initialize(size_t nNumParticles )
    {
      if ( nNumParticles+m_nNumParticlesAlive >= m_nMaxParticles )
      {
	nNumParticles = m_nMaxParticles-m_nNumParticlesAlive;
      }
    
      size_t new_particle_count = (nNumParticles+m_nNumParticlesAlive);
      for( size_t p=m_nNumParticlesAlive; p< new_particle_count; p++)
      {
	InitVelocity(m_vecParticles[p]);
	InitPosition(m_vecParticles[p]);
	InitEnergy(m_vecParticles[p]);
      }
      m_nNumParticlesAlive = new_particle_count;
    }
    ////////////////////  
    bool IsAlive() const 
    {
      return (m_nNumParticlesAlive > 0);
    }
    ////////////////////
    void Update( float fSeconds )
    {
      for( size_t i=m_nNumParticlesAlive; i>0; i--)
      {
	CParticle & p = m_vecParticles[i-1];

	if ( p.m_fEnergy > 0.0f )
	{
	  UpdateVelocity(p, fSeconds );
	  UpdatePosition( p, fSeconds);
	  UpdateEnergy(p,fSeconds);
	}
	else
	{
	  // swap positions of last alive and current dead particle
	  std::swap( m_vecParticles[i-1], m_vecParticles[m_nNumParticlesAlive-1]);
	  m_nNumParticlesAlive--;
	}
      }
    }
    ////////////////////
    void Render( CRenderer & renderer )
    {
      for( size_t p=0; p< m_nNumParticlesAlive; p++)
      {
	CParticle & par = m_vecParticles[p];
	// This Render function call bypasses renderer entirely, and uses
	// SDL_gfx API directly.
	pixelRGBA(renderer.GetScreen(), 
		  static_cast<int>(par.m_vPosition[0]), 
		  static_cast<int>(par.m_vPosition[1]), 
		  255, 
		  static_cast<int>(255*par.m_fEnergy),
		  0,
		  static_cast<int>(255*(par.m_fEnergy)) );
      }
    }
    ////////////////////
    // Initializes particle velocity on birth.
    virtual void InitVelocity( CParticle & p) = 0;

    ////////////////////
    // Initializes particle position on birth.
    virtual void InitPosition( CParticle & p) = 0;

    ////////////////////
    // Initializes particle energy on birth.
    virtual void InitEnergy( CParticle & p ) = 0;

    virtual void UpdateEnergy( CParticle &p, float fSeconds )
    {
      p.m_fEnergy   -= GetEnergyDecrementPerSec() * fSeconds;
    }
  
    virtual void UpdatePosition( CParticle &p, float fSeconds )
    {
      p.m_vPosition += (p.m_vVelocity * fSeconds);
    }
  
    virtual void UpdateVelocity( CParticle &p, float fSeconds ) 
    {
  
    }

    float GetEnergyDecrementPerSec() 
    { 
      return m_fEnergyDecrementPerSec;
    }
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif

