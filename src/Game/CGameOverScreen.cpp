// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CGameOverScreen.h"
#include "CSpaceAttacker.h"

////////////////////////////////////////////////////////////////////////////////
CGameOverScreen::CGameOverScreen()
{

  m_GameOver.Load("pics/death.png");
  m_GameOver.SetAlpha(128);
  pfontImg = new CImageAlpha ();
  CFont f;
  f.Load("fonts/arial.ttf",18);
  pfontImg = f.CreateImageFromTextAL("Space Attackers : alpha build, not for distribution!");
  
}
////////////////////////////////////////////////////////////////////////////////
void CGameOverScreen::OnKeyDown( SDL_KeyboardEvent & event )
{
  if ( event.keysym.sym == SDLK_SPACE )
  {
    dynamic_cast<CSpaceAttacker *>(GetGame())->SetCurrentScene("splash");
  }
}
////////////////////////////////////////////////////////////////////////////////
void CGameOverScreen::OnEnter()
{
  dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->PlayMusic("gameover");
}
////////////////////////////////////////////////////////////////////////////////
void CGameOverScreen::PreRender( CRenderer & r)
{
  r.Begin();
  r.ClearScreen();

}

////////////////////////////////////////////////////////////////////////////////
void CGameOverScreen::Render( CRenderer & r)
{
  r.Render( &m_GameOver, 0,0);
}
////////////////////////////////////////////////////////////////////////////////
void CGameOverScreen::PostRender( CRenderer & r )
{
	r.Render( pfontImg, 0, 0);
	r.End();
}
////////////////////////////////////////////////////////////////////////////////
