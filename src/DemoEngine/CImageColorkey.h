// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================



#ifndef __CIMAGECOLORKEY_H__
#define __CIMAGECOLORKEY_H__
////////////////////////////////////////////////////////////////////////////////

#include "CImage.h"

namespace DemoEngine
{
    class CImageColorkey : public CImage
    {
        private:
            Uint32 m_Colorkey;


        public:
            void SetColorkey(Uint32 color);
            Uint32 GetColorkey();
			void SetColorKey( Uint8 r, Uint8 g, Uint8 b);
    };
}

#endif
