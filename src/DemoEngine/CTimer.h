// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CTimer_h__
#define __CTimer_h__
#include <SDL/SDL.h>
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  class CTimer
  {
  private:
    Uint32 m_CurrentTime;
    Uint32 m_PreviousTime;
  public:
    CTimer();
    virtual ~CTimer() {}
    void Update();
    void Reset();
    float GetPassedTime();
    Uint32 GetPassedTimeMS();
  }; // CTimer
} // DemoEngine
////////////////////////////////////////////////////////////////////////////////
#endif
