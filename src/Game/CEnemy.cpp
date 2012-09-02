// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CEnemy.h"
#include <CRenderer.h>
#include <iostream>
#include <cstdlib>
#include "CSpaceAttacker.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////////
CEnemy::CEnemy( CSpaceAttacker *pGame)
{
  m_AeroPlane.Load("pics/plane_green.bmp");
  m_AeroPlane.SetColorKey(0,67,171);
  m_pGame = pGame;
  GetBoundingRectangle().SetDimensions(m_AeroPlane.GetSurface()->w,
				       m_AeroPlane.GetSurface()->h);
  screenHeight = static_cast <int>(m_pGame->GetRenderer().GetScreen()->h);
}
////////////////////////////////////////////////////////////////////////////////
void
CEnemy::Update( float fSeconds )
{
  Move( 0, 1 );
  if ( GetY() > (screenHeight + 40)) // passed beyond the lower edge of the screen. Add tolerance to accomodate for unforeseen screen coordinates
  {
    Respawn();
  }
  
  GetBoundingRectangle().SetPosition(GetPosition());
}
////////////////////////////////////////////////////////////////////////////////
void 
CEnemy::Render( CRenderer & r )
{
  r.Render( &m_AeroPlane, 
	    GetX() - m_AeroPlane.GetSurface()->w/2,
	    GetY() - m_AeroPlane.GetSurface()->h/2 ); //align the aeroplane exactly in the center of the screen considering the widht and height of the images itself
}
////////////////////////////////////////////////////////////////////////////////
void
CEnemy::Respawn()
{
  SetPosition( CVector2i(rand() % m_pGame->GetRenderer().GetScreen()->w-30, -30) );
}
////////////////////////////////////////////////////////////////////////////////
