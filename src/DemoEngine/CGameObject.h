// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CGameObject_h__
#define __CGameObject_h__
////////////////////////////////////////////////////////////////////////////////
#include "IRenderable.h"
#include "IUpdateable.h"
#include "CPositional.h"
#include "CRectangle.h"
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  class CGameObject : public DemoEngine::CPositional,
		      public DemoEngine::IUpdateable,
		      public DemoEngine::IRenderable
  {
  private:
    DemoEngine::CRectangle m_BoundingRectangle;
  public:
    // Gets bounding rectangle.
    DemoEngine::CRectangle & GetBoundingRectangle() 
    { 
      return m_BoundingRectangle; 
    }
    // Sets bounding rectangle.
    void SetBoundingRectangle( DemoEngine::CRectangle & rect) 
    {
      m_BoundingRectangle = rect; 
    }
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

