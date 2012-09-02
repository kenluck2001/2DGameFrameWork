// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CSplashScreen_h__
#define __CSplashScreen_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <CScene.h>
#include <CImageAlpha.h>


////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
enum SplashState { FADE_IN, FADE_OUT};
enum MenuItem { NEWGAME, HIGHSCORE, EXIT, NO_OF_MENU_ITEM };
////////////////////////////////////////////////////////////////////////////////
class CSpaceAttacker;

class CSplashScreen : public CScene
{
	private:

  		bool  m_bMusicStart;
  		CImageAlpha  m_TitleScreen;
  		CImageAlpha  m_Menu;
  		CImageAlpha  m_MenuBlurred;
  		int	m_iWidth; 	//screen widthclass
  		int	m_iHeight;	//screen height
		int m_iALpha;
		SplashState stat;
		CImageAlpha     *pfontImg;
		bool bmusicFinished;
  		MenuItem m_Selection;

		CImageAlpha     *pfontInfo;
		CImageAlpha     upImg;
		CImageAlpha     downImg;
	public:
  		CSplashScreen( );

		int GetScreenHeight();
		int GetScreenWidth();
  		void OnKeyDown( SDL_KeyboardEvent & event );
  		void Update( float fSeconds );
  		void Render( CRenderer & r);
	  	void PostRender( CRenderer & r );
        void OnEnter();
        void OnExit();
};
  ////////////////////////////////////////////////////////////////////////////////
#endif

