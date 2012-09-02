// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CLEVEL1_H__
#define __CLEVEL1_H__
////////////////////////////////////////////////////////////////////////////////
#include <CScene.h>
#include <CFont.h>
#include <CScrollingBackground.h>
#include "CEnemy.h"
//#include "fireworks.h"
#include "CExplosion.h"


////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;

class CSpaceAttacker;
class CPlayer;

enum MoveState {NONE, UP, DOWN, LEFT, RIGHT };
enum ButtonState {NO, PRESSED, RELEASED };

struct State
{
	MoveState m_State;
	ButtonState b_State;
};



class CLevel1 : public CScene 
{
	private:
  		CScrollingBackground * p_CScrollBackground;
		CImageAlpha     * pfontImg, * pFontNumImg;
		State st;
		CPlayer * p_Player;
        CEnemy * m_pEnemy;
        CExplosion m_Explosion; 
        bool m_bAboutToDie;
		int m_Score, step;
		CFont normfont , numFont;
  
	public:
	  	CLevel1( );
  		void OnKeyDown( SDL_KeyboardEvent & ev );
	  	void OnKeyUp( SDL_KeyboardEvent  & ev );
  		void PreRender( CRenderer & renderer );
  		void Update(float fSeconds  );
	  	void PostRender( CRenderer & renderer );
        void OnEnter();
        void OnExit();
 
};
////////////////////////////////////////////////////////////////////////////////
#endif
