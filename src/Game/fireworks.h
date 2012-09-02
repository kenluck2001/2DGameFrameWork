// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __FIREWORKS_H__
#define __FIREWORKS_H__



#include <CGame.h>
#include <CVector2.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <CParticleSystem.h>
/* rand example */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CImageAlpha.h>
#include <CGame.h>

#define MIN_VALUE 0.00001
#define MAX_VALUE 0.99999

class CSpaceAttacker;
////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
///////////////////////////////////////////////////////////////////


int MasterOfExplosionsPix( void *data );
int MasterOfExplosionsLine( void *data ) ;
int MasterOfExplosionsSmoke( void *data );

int MasterOfCExplosionsPix( void *data );
int MasterOfCExplosionsLine( void *data ) ;
int MasterOfCExplosionsSmoke( void *data );

////////////////////////////////////////////////////////////////////////////////
/// Our fireworks particle system.
class CFireworks : public CParticleSystem
{
protected:
  CVector2f m_vPos;
  CVector2f  m_vAcceleration;  // Acceleration vector, change of speed AND direction.
  CVector2f vGravity;
  // Get a random float between a, b inclusive
  float GetRandomFloat(const float a, const float b)
  {
    const float r = ((float)rand())/RAND_MAX;   // 0...1
    return (a > b) ? a + (fabs(b - a) * r) : a - (fabs(a - b) * r);
  }

public:

  CFireworks( size_t nNumParticles = 500 ) : CParticleSystem(nNumParticles)
  {
    
  }
  
  void SetPosition( const CVector2f & vPos )
  {
    m_vPos = vPos;
  }

  CVector2f  GetPosition( )
  {
    return m_vPos;
  }
  void SetPosition( float x, float y )
  {
    m_vPos[0] = x;
    m_vPos[1] = y;
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

  void SetAcceleration( CVector2f vGravity )
  {
	m_vAcceleration = vGravity;
  }

  const CVector2f & GetAcceleration() const
  {
    return m_vAcceleration;
  }
  
  CVector2f & GetAcceleration()
  {
    return m_vAcceleration;
  }

};

////////////////////////////////////////////////////////////////////////////////
/// Create new forms of fireWork.
class CRandomColoredFireworks : public CFireworks
{
	public:
  		CRandomColoredFireworks()
  		{
			vGravity[0] = 0, vGravity[1] = 98.1; //initialize gravity value using a scale of 10. Gravity acts in one direction so the X-axis is kept at 0.
			SetAcceleration( vGravity );
  		}

  		void Render( CRenderer & renderer )
  		{
    		for( size_t p=0; p< m_nNumParticlesAlive; p++)
    		{
	  			srand ( time(NULL) );
			  	CParticle & par = m_vecParticles[p];
			  	pixelRGBA(renderer.GetScreen(), 
				static_cast<int>(par.m_vPosition[0]), 
				static_cast<int>(par.m_vPosition[1]), 
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				static_cast<int>(255*(par.m_fEnergy)) );
    		}
   		} 


    	virtual void UpdateVelocity( CParticle &p, float fSeconds ) 
    	{
			// compute change in speed (acceleration)
			CVector2f m_vAcceleration = GetAcceleration();
			p.m_vVelocity[0] += m_vAcceleration[0] * fSeconds;
			p.m_vVelocity[1] += m_vAcceleration[1] * fSeconds;
		
			// change position according to current velocity
			p.m_vPosition[0] += p.m_vVelocity[0] * fSeconds; 
			p.m_vPosition[1] += p.m_vVelocity[1] * fSeconds; 
		}

};

////////////////////////////////////////////////////////////////////////////////
/// Create new forms of fireWork.
class CLineColoredFireworks : public CFireworks
{
	public:
  		CLineColoredFireworks()
  		{
			vGravity[0] = 0, vGravity[1] = 98.1; //initialize gravity value using a scale of 10. Gravity acts in one direction so the X-axis is kept at 0.
			SetAcceleration( vGravity );
  		}

  		void Render( CRenderer & renderer )
  		{
			int pixelOffset; 
    		for( size_t p=0; p< m_nNumParticlesAlive; p++)
    		{
	  			srand ( time(NULL) );
			  	CParticle & par = m_vecParticles[p];
 				CVector2f unitVector = par.m_vPosition.NormalizeVector(); //unit vector
				CVector2f pixelOffset =(-1) * unitVector * GetRandomFloat(MIN_VALUE, MAX_VALUE) * 10; // get random number from (0 to 10) and multiply with unit vector. The floats will be casted to ints automatically. -1 helps to change the direction of the velocity vector
			  	lineRGBA(renderer.GetScreen(), 
				static_cast<int>(par.m_vPosition[0]), 
				static_cast<int>(par.m_vPosition[1]), 
				static_cast<int>(par.m_vPosition[0] + pixelOffset[0]), 
				static_cast<int>(par.m_vPosition[1] + pixelOffset[1]),
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				(GetRandomFloat(MIN_VALUE, MAX_VALUE) * 255),
				static_cast<int>(255*(par.m_fEnergy)) );
    		}
   		} 


    virtual void UpdateVelocity( CParticle &p, float fSeconds ) 
    {
		// compute change in speed (acceleration)
		CVector2f m_vAcceleration = GetAcceleration();
    	p.m_vVelocity[0] += m_vAcceleration[0] * fSeconds;
    	p.m_vVelocity[1] += m_vAcceleration[1] * fSeconds;
    
    	// change position according to current velocity
    	p.m_vPosition[0] += p.m_vVelocity[0] * fSeconds; 
    	p.m_vPosition[1] += p.m_vVelocity[1] * fSeconds; 
    }

};

class CSimpleQuasiSmoke : public CFireworks
{
	private:
  		CImageAlpha m_Image;
	public:
  
  		CSimpleQuasiSmoke( ) 
  		{
			vGravity[0] = 0, vGravity[1] = 98.1; //initialize gravity value using a scale of 10. Gravity acts in one direction so the X-axis is kept at 0.
			SetAcceleration( vGravity );
    		m_Image.Load("pics/smoke.png");
			m_Image.SetAlpha( 254 );
  		}

  		void InitVelocity( CParticle & p) 
  		{
    		const int MAX = 20;
    		p.m_vVelocity[0] = (rand() % MAX) - MAX/2;
    		p.m_vVelocity[1] = (rand() % MAX) - MAX/2;
  		}
  

  		void Render( CRenderer & r )
  		{
    		for( size_t p=0; p< m_nNumParticlesAlive; p++)
    		{
      			CParticle & par = m_vecParticles[p];
      			r.Render( &m_Image, static_cast<int>(par.m_vPosition[0]), static_cast<int>(par.m_vPosition[1]));
    		}
  		}

		virtual void UpdateVelocity( CParticle &p, float fSeconds ) 
		{
			// compute change in speed (acceleration)
			// randomize particle to look a bit like brownian motion
			CVector2f m_vAcceleration = GetAcceleration();
			p.m_vVelocity[0] += m_vAcceleration[0] * fSeconds * GetRandomFloat(MIN_VALUE, MAX_VALUE);
			p.m_vVelocity[1] += m_vAcceleration[1] * fSeconds * GetRandomFloat(MIN_VALUE, MAX_VALUE);
		
			// change position according to current velocity
			p.m_vPosition[0] += p.m_vVelocity[0] * fSeconds * GetRandomFloat(MIN_VALUE, MAX_VALUE); 
			p.m_vPosition[1] += p.m_vVelocity[1] * fSeconds * GetRandomFloat(MIN_VALUE, MAX_VALUE); 
		}

};



/// Class for easily adding a mutex to another class.
class CMutexProtected
{
	private:
  		SDL_mutex *m_pMutex;
	public:

	CMutexProtected()
	{
		m_pMutex = SDL_CreateMutex();
	}

	virtual ~CMutexProtected()
	{
		SDL_DestroyMutex(m_pMutex);
	}

	void Lock()
	{
	  	SDL_LockMutex(m_pMutex);
	}

	void Release()
	{
		SDL_UnlockMutex(m_pMutex);
	}
};


////////////////////////////////////////////////////////////////////////////////

class CFireworksApp : public CGame, public CMutexProtected
{
	private:
  		CRandomColoredFireworks  m_RandCol;
		CLineColoredFireworks  m_LineCol;
  		CSimpleQuasiSmoke m_Smoke;
  		CScene  *m_pScene;
  		bool m_buttonPressed;
		SDL_Thread * m_pExplosionThreads[3];   // threads are stored here.

	public:
  		CFireworksApp()
  		{
    		GetRenderer().Init();
    		GetRenderer().OpenWindow( 640,480,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
    		GetRenderer().SetClearColor(0,0,0);
    		m_pScene = new CScene();
    		m_pScene->GetRenderables().push_back( &m_RandCol );
    		m_pScene->GetRenderables().push_back( &m_LineCol );
    		m_pScene->GetRenderables().push_back( &m_Smoke );

    		m_pScene->GetUpdateables().push_back( &m_RandCol );
    		m_pScene->GetUpdateables().push_back( &m_LineCol );
    		m_pScene->GetUpdateables().push_back( &m_Smoke );
    		AddScene("main", m_pScene);
    		SetCurrentScene("main");

    		m_pExplosionThreads[0] = SDL_CreateThread( MasterOfExplosionsPix, this);
    		m_pExplosionThreads[1] = SDL_CreateThread( MasterOfExplosionsLine, this);
    		m_pExplosionThreads[2] = SDL_CreateThread( MasterOfExplosionsSmoke, this);
			SetPosition( 200, 200 );		
  		}

  		virtual ~CFireworksApp()
  		{
    		// Wait for threads to exit. They should have exited they 
    		// MasterOfExplosion function by now.
    		//SDL_WaitThread( m_pExplosionThreads[0], NULL );
    		//SDL_WaitThread( m_pExplosionThreads[1], NULL );
    		//SDL_WaitThread( m_pExplosionThreads[2], NULL );
  		}

		void SetPosition (float x, float y)
		{
			m_RandCol.SetPosition( x, y);
			m_LineCol.SetPosition( x, y);
			m_Smoke.SetPosition( x, y );
		}

  		void OnKeyDown( SDL_KeyboardEvent & ev )
  		{
    		switch ( ev.keysym.sym )
    		{
				case SDL_QUIT: // when window is closed
					SetRunning( false );
					break;
				case SDLK_q:
					// Kill all threads
					SDL_KillThread( m_pExplosionThreads[0] );
					SDL_KillThread( m_pExplosionThreads[1] );
					SDL_KillThread( m_pExplosionThreads[2] );
					SetRunning( false );
					break;
				default:
			  		break;
    		}

  		}


  		void Render()
  		{
			if ( m_buttonPressed )
			{
				GetRenderer().ClearScreen();
				CGame::Render();
			}
  		}

		// Accessors, so these can be accessed from thread.
		CFireworks & GetColorPixFireWorks()  { return m_RandCol; }
		CFireworks & GetColorLineFireWorks() { return m_LineCol; }
		CFireworks & GetSmokeFireWorks()   { return m_Smoke;  }
};

class CFireExplosion : public CFireworks, public CMutexProtected
{
	private:
  		CRandomColoredFireworks  m_RandCol;
		CLineColoredFireworks  m_LineCol;
  		CSimpleQuasiSmoke m_Smoke;
		SDL_Thread * m_pExplosionThreads[3];   // threads are stored here.

	public:
  		CFireExplosion()
  		{
    		m_pExplosionThreads[0] = SDL_CreateThread( MasterOfCExplosionsPix, this);
    		m_pExplosionThreads[1] = SDL_CreateThread( MasterOfCExplosionsLine, this);
    		m_pExplosionThreads[2] = SDL_CreateThread( MasterOfCExplosionsSmoke, this);
	
  		}

  		virtual ~CFireExplosion()
  		{
			SDL_KillThread( m_pExplosionThreads[0] );
			SDL_KillThread( m_pExplosionThreads[1] );
			SDL_KillThread( m_pExplosionThreads[2] );
  		}

		void SetPosition (int x, int y)
		{
			m_RandCol.SetPosition( x, y);
			m_LineCol.SetPosition( x, y);
			m_Smoke.SetPosition( x, y );
		}

		void Initialize(size_t nNumParticles )
		{
			m_RandCol.Initialize(nNumParticles );
			m_LineCol.Initialize(nNumParticles );
			m_Smoke.Initialize(nNumParticles );
		}

		void Update( float fSeconds )
		{
			m_RandCol.Update( fSeconds );
			m_LineCol.Update( fSeconds );
			m_Smoke.Update( fSeconds );
		}


		void Render( CRenderer & renderer )
		{
			m_RandCol.Render( renderer );
			m_LineCol.Render( renderer );
			m_Smoke.Render( renderer );
	 	}

		////////////////////
		// Initializes particle velocity on birth.
		void InitVelocity( CParticle & p)
		{
			m_RandCol.InitVelocity( p);
			m_LineCol.InitVelocity( p);
			m_Smoke.InitVelocity( p);
		} 

		void InitPosition( CParticle & p)
		{
			m_RandCol.InitPosition( p);
			m_LineCol.InitPosition( p);
			m_Smoke.InitPosition( p);
		}
		void InitEnergy( CParticle & p ) 
		{	
			m_RandCol.InitPosition( p);
			m_LineCol.InitPosition( p);
			m_Smoke.InitPosition( p);
		}


		// Accessors, so these can be accessed from thread.
		CFireworks & GetColorCPixFireWorks()  { return m_RandCol; }
		CFireworks & GetColorCLineFireWorks() { return m_LineCol; }
		CFireworks & GetSmokeCFireWorks()   { return m_Smoke;  }
};



#endif
