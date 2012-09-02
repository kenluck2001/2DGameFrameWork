// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CEnemy_h__
#define __CEnemy_h__
#include <CGameObject.h>
#include <CImageColorkey.h>
////////////////////////////////////////////////////////////////////////////////
using namespace DemoEngine;
class CSpaceAttacker;
////////////////////////////////////////////////////////////////////////////////
class CEnemy : public CGameObject
{
private:
  CImageColorkey m_AeroPlane;
  CSpaceAttacker *m_pGame;
  int screenHeight;
public:
  CEnemy( CSpaceAttacker *pGame);
  void Render( CRenderer & r );
  void Update( float fSeconds );
  void Respawn();
};
////////////////////////////////////////////////////////////////////////////////

#endif
