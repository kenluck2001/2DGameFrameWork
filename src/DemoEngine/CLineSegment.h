// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================
#ifndef __CLINESEGMENT_H__
#define __CLINESEGMENT_H__

#include "CColored.h"
#include "CPositional.h"


namespace DemoEngine
{
    class CLineSegment : public DemoEngine::CColored, public DemoEngine::CPositional 
    {
        protected:
            CVector2i m_vDirection;
        public:
            CLineSegment() {}

            CLineSegment(const CVector2i & pos, const CVector2i & dir) 
            {
                SetPosition( pos);
                SetDirection( dir );
            }

            CVector2i GetStart() { return GetPosition();  }
            CVector2i GetEnd()  { return GetPosition() + GetDirection(); }
          
            CVector2i  GetDirection() { return m_vDirection;}  
            void SetDirection( const CVector2i & vDir ) 
            {
                m_vDirection = vDir;  
            }
            
    };
}

#endif

