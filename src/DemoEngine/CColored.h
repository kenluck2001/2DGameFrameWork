// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CColored_h__
#define __CColored_h__
#include <SDL/SDL.h>
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  class CColored
  {
  protected:
    SDL_Color m_Color;
    CColored( );
    CColored( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
  public:

    virtual ~CColored();
  
    SDL_Color & GetColor();
    void   SetColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a );
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
