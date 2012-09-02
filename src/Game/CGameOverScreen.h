// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CGameOverScreen_h__
#define __CGameOverScreen_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <CScene.h>
#include <CImageAlpha.h>
#include <CFont.h>
////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
class CSpaceAttacker;
class CGameOverScreen : public CScene
{
private:
  CImageAlpha	m_GameOver;
  CImageAlpha * pfontImg;
public:

  CGameOverScreen();
  void OnKeyDown( SDL_KeyboardEvent & event );
  void PreRender( CRenderer & r);
  void Render( CRenderer & r);
  void PostRender( CRenderer & r);
  void OnEnter();

};
////////////////////////////////////////////////////////////////////////////////


#endif
