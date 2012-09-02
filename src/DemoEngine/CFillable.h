// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CFillable_h__
#define __CFillable_h__
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  class CFillable
  {
  protected:
    bool m_bFilled;
  public:
  CFillable();
    virtual ~CFillable();
    bool IsFilled();
    void SetFilled( bool flag );
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
