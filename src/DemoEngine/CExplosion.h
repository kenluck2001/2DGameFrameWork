// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CExplosion_h__
#define __CExplosion_h__
////////////////////////////////////////////////////////////////////////////////
#include <CGameObject.h>
#include <CAnimatedImage.h>
#include <CSoundServer.h>
#include <../Game/fireworks.h>
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
#define ANIM_FRAME_HALF_WIDTH  17
#define ANIM_FRAME_HALF_HEIGHT 25
////////////////////////////////////////////////////////////////////////////////
//extern CSoundServer *g_pSoundServer;
////////////////////////////////////////////////////////////////////////////////
/// Our explosion object. This takes care of blowing up.
//class CFireworks;
class CFireExplosion;
class CExplosion  : public CGameObject
{
private:
  CAnimatedImage m_ExplosionImage;
  CFireExplosion   m_ExplosionPS;
public:
  ////////////////////
  /// Initializes animation and image.
  CExplosion()
  {
    // Load graphics
    m_ExplosionImage.Load("pics/explosion.png");
    // Load animation frames and seqeuence
    m_ExplosionImage.LoadAnimation("explosion.anim");
    // default animation sequence
    m_ExplosionImage.SetAnimation(0);
    // Set frames per second to animation executes fast
    m_ExplosionImage.SetFPS(30);
  }
  ////////////////////
  // Renders our explosion object.
  void Render( CRenderer & r )
  {
    if ( !m_ExplosionImage.IsFinished())
    {
      // draw current explosion animation, and center it around position.
      // Animation frame width is required, and this cannot be retrieved 
      // from image itself, since we only know how large entire image is!
      r.Render( &m_ExplosionImage, 
		GetPosition()[0]-ANIM_FRAME_HALF_WIDTH,
		GetPosition()[1]-ANIM_FRAME_HALF_HEIGHT);
    }
	m_ExplosionPS.Render( r);
  }
  ////////////////////
  /// Updates our animation.
  void Update( float fSeconds )
  {
    // pass passed time to explosion animation
    m_ExplosionImage.Update(fSeconds);
	m_ExplosionPS.Update(fSeconds);
  }
  ////////////////////
  /// Sets explosion image position, ignites animation and plays audio sample.
  void Explode(int x, int y)
  {
    SetPosition(x,y);
    m_ExplosionImage.SetAnimation(0,false);
    m_ExplosionPS.SetPosition(x,y);
    //m_ExplosionImage.DebugPrint();
	m_ExplosionPS.Initialize(50);
  }

 bool IsFinished() { return m_ExplosionImage.IsFinished();}
};
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

