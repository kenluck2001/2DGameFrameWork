// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

////////////////////////////////////////////////////////////////////////////////
#ifndef __CAnimation_h__
#define __CAnimation_h__
////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <list>
#include <SDL/SDL.h>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine {

  class CAnimation
  {
  protected:
    // Frames in an animation
    std::vector< SDL_Rect >	m_Frames; 
    // animation frame sequences
    std::vector< std::vector<int> > m_Sequences;
    // Current sequence
    size_t			m_iSequence;
    // Current frame in current sequence
    size_t			m_iFrame;
    // Is animation looping
    bool				m_bLooping;
    // What is display time for a single frame
    float				m_fFrameTime;
    // Cumulative passed time
    float				m_fCumTime;
  public:
  
    CAnimation() : m_iSequence(0), m_iFrame(0) 
    {
      m_fCumTime = 0.0f;
      SetFPS( 1 );
    }
    virtual ~CAnimation() {};
    // Sets animation time in frames per second
    void  SetFPS( float fFPS ) { SetFrameTime( 1.0/fFPS ); }
    // Sets display time for a single frame in seconds
    void	SetFrameTime( float fTime ) { m_fFrameTime = fTime; }
    // Returns frame time in seconds
    float GetFrameTime() { return m_fFrameTime; }
    // Sets current frame
    virtual void SetFrame( int frame )    { m_iFrame = frame; }

    ////////////////////
    /// Sets current animation to be displayed (sequence array index)
    virtual void SetAnimation( int anim_id, bool bLoop = false )
    { 
      m_iSequence = anim_id; 
      m_iFrame = 0;
      m_bLooping = bLoop; 
    };
    ////////////////////
    /// Takes care of the nasty animation display logic
    virtual void Update( float fPassedTime )
    {
      m_fCumTime += fPassedTime;
      if ( m_fCumTime > m_fFrameTime )
      {
	int frames = static_cast<int>(m_fCumTime / m_fFrameTime);
	m_iFrame += frames;
	size_t seq_size = m_Sequences[m_iSequence].size();
	// If frames tend to jump
	if ( m_iFrame >= seq_size )
	{
	  m_iFrame = m_bLooping ? m_iFrame - seq_size : seq_size - 1;
	}
	m_fCumTime -= m_fFrameTime * frames;
      }
    
      ApplyAnimation();
    }
    virtual void ApplyAnimation() = 0;

    bool HasAnimation() const { return !m_Frames.empty(); }
  
    const SDL_Rect & GetFrameRectangle() { return m_Frames[m_Sequences[m_iSequence][m_iFrame]]; }
  
    // Throws an exception on error.
    void LoadAnimation( const char *szFilename );
  
    void DebugPrint();
    bool IsFinished();
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
// SDL Programming
////////////////////////////////////////////////////////////////////////////////
// Code example.
// Author Anssi Gröhn
////////////////////////////////////////////////////////////////////////////////
