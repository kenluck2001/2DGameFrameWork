// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CSplashScreen.h"
#include "CSpaceAttacker.h"
#define STEP 2
#define MENU_TEXT_HEIGHT 30
////////////////////////////////////////////////////////////////////////////////

CSplashScreen::CSplashScreen(  ) 
{
	stat = FADE_IN;
	bmusicFinished = false;
	m_TitleScreen.Load( "pics/title_screen.png");
	m_Menu.Load("pics/menu.png");
	m_MenuBlurred.Load("pics/menu_blur.png");
	pfontInfo = new CImageAlpha ;
	upImg.Load("pics/up.png");
	downImg.Load("pics/down.png");

	m_Menu.SetAlpha( 254 );
	m_MenuBlurred.SetAlpha( 254 );
	upImg.SetAlpha( 254 );
	downImg.SetAlpha( 254 );
	m_iALpha = 0;
	m_TitleScreen.SetAlpha(m_iALpha);
	m_iWidth = m_iHeight = 0;

	pfontImg = new CImageAlpha ();
	CFont f;
	f.Load("fonts/arial.ttf",18);
	pfontImg = f.CreateImageFromTextAL("Space Attackers : alpha build, not for distribution!");
	SDL_Color color = {88, 58, 58, 255};
	f.SetColor (color);
	pfontInfo = f.CreateImageFromTextAL("Press Enter key to make selection. Use Arrow keys to navigate up or down!");
  
}

////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::OnEnter()
{
    stat = FADE_IN;
}
////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::OnExit()
{
  	//dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->HaltMusic();
}

////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::OnKeyDown( SDL_KeyboardEvent & event )
{
	if ( ( m_Selection < NO_OF_MENU_ITEM )&&( m_Selection >=  NEWGAME ))
	{
	  	if ( event.keysym.sym == SDLK_UP )
	  	{
			m_Selection = static_cast<MenuItem>(m_Selection - 1);
	  	}
		else if ( event.keysym.sym == SDLK_DOWN )
	  	{
			m_Selection = static_cast<MenuItem>(m_Selection + 1);
	  	}
		else if ( event.keysym.sym == SDLK_SPACE )
	  	{
			switch ( m_Selection )
			{
				case NEWGAME:
				  stat  = FADE_OUT;
				  break;
				case HIGHSCORE:
				  GetGame()->SetCurrentScene("highscores");
				  break;
				case EXIT:
				  GetGame()->SetRunning(false);
				  break;
			}
	  	}
	}
}
////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::Update( float fSeconds  )
{
	// select proper blitted area
  	m_MenuBlurred.SetBlittedArea( 0, m_Selection * MENU_TEXT_HEIGHT, m_Menu.GetSurface()->w, MENU_TEXT_HEIGHT);
  	if (! bmusicFinished)
    {
        dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->PlayMusic( "Song_Of_Peace" );
        bmusicFinished  = true;
    }


	if (stat == FADE_IN)
	{ 
    	// increase alpha vlue
    	m_iALpha += STEP;
    	if ( m_iALpha <= 255 ) 
		{
    		m_TitleScreen.SetAlpha( m_iALpha );
            dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->FadeInMusic( "Song_Of_Peace", 1500); // fad in 1.5 seconds;
   		}
        else
        {
            m_iALpha = 254;
        }
	}

        //m_iALpha = 254;

	if ( stat == FADE_OUT)
	{
    	m_iALpha -= STEP;
      	if ( m_iALpha >= 0 ) 
		{
      		m_TitleScreen.SetAlpha( m_iALpha );
            dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->FadeOutMusic(1500); // fad in 5 seconds
			if ( m_iALpha == 0 ) 
			{ 
                m_TitleScreen.SetAlpha( m_iALpha );
                dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->RemoveMusic( "Song_Of_Peace"  );
		        dynamic_cast<CSpaceAttacker *>(GetGame())->SetCurrentScene("level1");
			} 
		}
	}


	
}
////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::Render( CRenderer & r)
{
  	r.Render(&m_TitleScreen, 0,0);
  	r.Render( &m_Menu, 20, 100);
  	r.Render( &m_MenuBlurred, 20, (100 + (MENU_TEXT_HEIGHT * m_Selection)) );

}
////////////////////////////////////////////////////////////////////////////////
void CSplashScreen::PostRender( CRenderer & r )
{
	r.Render( pfontImg, 0, 0);
	r.Render( &upImg, 20, 300);
	r.Render( &downImg, 20, 340);
	r.Render( pfontInfo, 20, 380);
	r.End();
}

////////////////////////////////////////////////////////////////////////////////
//screen height
int CSplashScreen::GetScreenHeight()
{
	m_iHeight = m_TitleScreen.GetSurface()->h;
	return m_iHeight;
}

////////////////////////////////////////////////////////////////////////////////
//screen width
int CSplashScreen::GetScreenWidth()
{
	m_iWidth = m_TitleScreen.GetSurface()->w;
	return m_iWidth;
}

