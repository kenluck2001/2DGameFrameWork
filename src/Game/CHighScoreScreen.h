// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CHighScoreScreen_h__
#define __CHighScoreScreen_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <CScene.h>
#include <CVector2.h>
#include <CRectangle.h>
#include "fireworks.h"
#include "CHighScoreList.h"
#include <CFont.h>
#include <CImageAlpha.h>
////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
class CSpaceAttacker;
class CHighScoreScreen : public CScene
{
private:
  CFireExplosion m_Explosions;
  CHighScoreList           m_HighScores;
  CFont                    m_Font, normfont;
  bool                     m_bActive;
  SDL_Thread*              m_pThread;
  CImageAlpha * pfontImg;
public:
  CHighScoreScreen();
  void OnKeyDown( SDL_KeyboardEvent & event );
  void Update( float fSeconds );
  void PreRender( CRenderer & r);
  void PostRender( CRenderer & r);
  void OnEnter();
  void OnExit();
  bool IsActive();
  void MakeExplosion();
};
  ////////////////////////////////////////////////////////////////////////////////


#endif
