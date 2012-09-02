// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CCIRCLE_H__
#define __CCIRCLE_H__

#include "CFillable.h"
#include "CColored.h"
#include "CPositional.h"


namespace DemoEngine
{
    class CCircle : public DemoEngine::CFillable, public DemoEngine::CColored, public DemoEngine::CPositional 
    {
        protected:
            int iRadius;
        public:
            CCircle() {}
            CCircle(int x_coord, int y_coord, int rad ) 
            {
                SetRadius(rad);
                SetX(x_coord);
                SetY(y_coord); 
            }
            void SetRadius( int r) { iRadius = r ;}
            int GetRadius() { return iRadius;}
            
    };
}

#endif
