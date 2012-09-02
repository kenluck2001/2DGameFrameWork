// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CRECTANGLE_H__
#define __CRECTANGLE_H__

#include "CFillable.h"
#include "CColored.h"
#include "CTwoDimensional.h"
#include "CPositional.h"


namespace DemoEngine
{
    class CRectangle : public DemoEngine::CFillable, public DemoEngine::CColored, public DemoEngine::CTwoDimensional, public DemoEngine::CPositional 
    {

        public:
            CRectangle() {}
            CRectangle( int x_axis, int y_axis, int width, int height ) 
            {
                SetX(x_axis);
                SetY(y_axis);
                SetWidth( width ) ;
                SetHeight( height );
            }
    };
}

#endif
