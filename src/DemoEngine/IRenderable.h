// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __IRENDERABLE_H__
#define __IRENDERABLE_H__
#include "CRenderer.h"

////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{

    class IRenderable
    {
		public:
			virtual ~IRenderable(){}
			virtual void Render (CRenderer & renderer) = 0; // pure virtual function
	};
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

