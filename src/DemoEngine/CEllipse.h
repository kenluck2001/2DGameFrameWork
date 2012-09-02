// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CELLIPSE_H__
#define __CELLIPSE_H__
////////////////////////////////////////////////////////////////////////////////
#include "CPositional.h"
#include "CTwoDimensional.h"
#include "CFillable.h"
#include "CColored.h"

namespace DemoEngine
{
    class CEllipse : public DemoEngine::CPositional,
		   public DemoEngine::CTwoDimensional,
		   public DemoEngine::CFillable,
		   public DemoEngine::CColored
    {
 
        public:
            CEllipse() {}
            CEllipse( int x_axis, int y_axis, int width, int height ) 
            {
                SetX(x_axis);
                SetY(y_axis);
                SetWidth( width ) ;
                SetHeight( height );
            }
    };
}
#endif

