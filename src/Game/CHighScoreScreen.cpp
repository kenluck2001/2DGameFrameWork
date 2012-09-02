// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CHighScoreScreen.h"
#include "CHighScoreList.h"
#include "CSpaceAttacker.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
int BlowThingsUp( void *data)
{
  CHighScoreScreen *pScreen = reinterpret_cast<CHighScoreScreen *>(data);
  while( pScreen->IsActive())
  {
    pScreen->MakeExplosion();
    SDL_Delay(500 + (rand() % 1000));
  }
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
void
CHighScoreScreen::MakeExplosion()
{
  m_Explosions.SetPosition( (20+rand()%600), (40+rand()%400));
  m_Explosions.Initialize(1000);
}
////////////////////////////////////////////////////////////////////////////////
bool 
CHighScoreScreen::IsActive()
{
  return m_bActive;
}
////////////////////////////////////////////////////////////////////////////////
CHighScoreScreen::CHighScoreScreen() : m_pThread(NULL)
{
  m_Font.Load("fonts/impact.ttf",24);
  pfontImg = new CImageAlpha();
  normfont.Load("fonts/arial.ttf",18);
  pfontImg = normfont.CreateImageFromTextAL("Space Attackers : alpha build, not for distribution!");
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::OnKeyDown( SDL_KeyboardEvent & event )
{
  GetGame()->SetCurrentScene("splash");
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::OnEnter()
{
  m_HighScores.Load("saves.hs");
  m_bActive = true;
  m_pThread = SDL_CreateThread( BlowThingsUp, this);
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::OnExit()
{
  m_HighScores.clear();
  m_bActive = false;
  SDL_WaitThread(m_pThread, NULL);
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::Update( float fSeconds )
{
  m_Explosions.Update(fSeconds);
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::CHighScoreScreen::PreRender( CRenderer & r)
{
  r.Begin();
  r.ClearScreen();
}
////////////////////////////////////////////////////////////////////////////////
void CHighScoreScreen::CHighScoreScreen::PostRender( CRenderer & r)
{
  
  m_Explosions.Render(r);
  CHighScoreList::iterator it = m_HighScores.begin(); 
  int ypos = 40;
  for( ; it != m_HighScores.end(); it++)
  {
    ostringstream s;
    s << it->score << " " << it->name;
    CImageAlpha *pImage = m_Font.CreateImageFromTextAL(s.str().c_str());
    r.Render(pImage, 200, ypos);
    ypos+=40;
    delete pImage;
  }
  
  r.Render(pfontImg,0,0); // render alpha version warning
  r.End();
}
////////////////////////////////////////////////////////////////////////////////
