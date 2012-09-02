// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CPlayer.h"
#include <CImageAlpha.h>
#include "CSpaceAttacker.h"
////////////////////////////////////////////////////////////////////////////////
CPlayer::CPlayer( CSpaceAttacker *pGame )
{
  takeshot = false;
  m_pGame = pGame;
  m_AeroPlane.Load("pics/plane.bmp");
  m_AeroPlane.SetColorKey(0,67,171);
  GetBoundingRectangle().SetDimensions( m_AeroPlane.GetSurface()->w, m_AeroPlane.GetSurface()->h); // create bounding box

}
////////////////////////////////////////////////////////////////////////////////
void 
CPlayer::Fire()
{
	takeshot = true;
	if (takeshot)
	{
	  m_pGame->GetSoundServer()->Play("fire");
	  // find first bullet outside screen
	  for(int i=0;i<MAX_BULLETS;i++)
	  {
		if( m_Bullets[i].IsAvailable() ) // if found, set to plane coordinates so they will move forth.
		{
		  m_Bullets[i].SetPosition( GetPosition() );
		  break;
		}
	  }
	}
  
}
////////////////////////////////////////////////////////////////////////////////
void
CPlayer::Update( float fSeconds )
{
  takeshot = false;
  GetBoundingRectangle().SetPosition(GetPosition());
}
////////////////////////////////////////////////////////////////////////////////
CProjectile * CPlayer::GetBullets()
{
  return m_Bullets;
}
////////////////////////////////////////////////////////////////////////////////
void 
CPlayer::Render( CRenderer & r )
{
  r.Render( &m_AeroPlane, 
	    GetX() - m_AeroPlane.GetSurface()->w/2,
	    GetY() - m_AeroPlane.GetSurface()->h/2);//align the aeroplane exactly in the center of the screen considering the widht and height of the images itself
}
////////////////////////////////////////////////////////////////////////////////
