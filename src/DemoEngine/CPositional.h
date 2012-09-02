// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CPositional_h__
#define __CPositional_h__
////////////////////////////////////////////////////////////////////////////////
#include "CVector2.h"
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  class CPositional
  {
  private:
    CVector2i m_pos;
  public:
    CPositional() {}

    CPositional(int x, int y )  { m_pos[0] = x; m_pos[1] = y;}
    CPositional(const CVector2i & v )  { m_pos = v;}

    virtual ~CPositional(){}


    void SetPosition( int x, int y) { m_pos[0] = x; m_pos[1] = y;}
    void SetPosition( const CVector2i & v ) { m_pos = v; }
    CVector2i & GetPosition() { return m_pos; }
    const CVector2i & GetPosition() const { return m_pos; } 

    void SetX(int x ) { m_pos[0] = x; }
    void SetY(int y ) { m_pos[1] = y; }

    int GetX() { return m_pos[0];}
    int GetY() { return m_pos[1];}
  
    void Move( int x, int y ) { m_pos[0] += x; m_pos[1]+=y; }
    void Move( const CVector2i & v ) { m_pos += v; }
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
