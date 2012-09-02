// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CPlayer_h__
#define __CPlayer_h__
////////////////////////////////////////////////////////////////////////////////
#include <CGameObject.h>
#include <CImageColorkey.h>
#include <CRenderer.h>
#include <CProjectile.h>
using namespace DemoEngine;
class CSpaceAttacker;
#define MAX_BULLETS 4
////////////////////////////////////////////////////////////////////////////////
class CPlayer : public CGameObject
{
private:
  CImageColorkey m_AeroPlane;
  CSpaceAttacker *m_pGame;
  CProjectile      m_Bullets[MAX_BULLETS]; // limited clip size :)
  bool takeshot;
public:
  CPlayer( CSpaceAttacker *pGame);
  void Fire();
  void Render( CRenderer & r );
  void Update( float fSeconds );
  CProjectile * GetBullets();
};
////////////////////////////////////////////////////////////////////////////////

#endif
