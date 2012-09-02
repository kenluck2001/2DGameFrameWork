// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CSpaceAttacker.h"
#include "CSplashScreen.h"
#include "CLevel1.h"
#include <CSoundServer.h>
#include "CGameOverScreen.h"
#include "CHighScoreScreen.h"


const int COLOR_IN_BITS = 32;
const int FLAG = SDL_HWSURFACE;

using namespace DemoEngine;

////////////////////////////////////////////////////////////////////////////////
CSpaceAttacker::CSpaceAttacker()
{
  	// Create two scenes

    AddScene("level1",new CLevel1());
    AddScene("splash", new CSplashScreen());
    AddScene("gameover", new CGameOverScreen());
	AddScene("highscores", new CHighScoreScreen());
    SetCurrentScene("splash"); //set current scene

  	// Init audio 

    g_pSoundServer = CSoundServer::GetInstance();
  	g_pSoundServer->Init();

	g_pSoundServer->LoadMusic("Song_Of_Peace", "sound/cdk_-_song_of_peace.ogg");
	g_pSoundServer->LoadMusic("Astroboy_Sprung-160" , "sound/astroboy_sprung-160.ogg");
	g_pSoundServer->LoadMusic("gameover", "sound/Syenta_-_Cytheres_Reves_(Cytheres_Dreams)_2.wav");
	g_pSoundServer->Load("fire", "sound/machinegun2.wav");

    g_pSoundServer->Load("boom", "sound/bomb-02.wav");

    //init collision detection
    g_pCollisionDetector = CCollisionDetector::GetInstance();

  	// Init video
  	GetRenderer().Init();

    CScene *pSplashScene = GetScene("splash" );
    CSplashScreen  * pSplash = dynamic_cast<CSplashScreen *>( pSplashScene );

	int ScreenHeight = pSplash->GetScreenHeight();
	int ScreenWidth =  pSplash->GetScreenWidth();
  	GetRenderer().OpenWindow( ScreenWidth, ScreenHeight , COLOR_IN_BITS, FLAG);
  	GetRenderer().SetClearColor(0,0,0);

}
////////////////////////////////////////////////////////////////////////////////

