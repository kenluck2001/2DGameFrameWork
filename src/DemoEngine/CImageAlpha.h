// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================


#ifndef __CIMAGEALPHA_H__ 
#define __CIMAGEALPHA_H__ 
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include "CImage.h"
#define NO_OF_BITS_PER_PIXEL 32
//////////////////////////
namespace DemoEngine
{
    class CImageAlpha : public CImage
    {
        private:
            Uint8 m_Alpha;
        public:
            void SetAlpha(Uint8 i_Alpha);
            Uint8 GetAlpha();
            bool IsTransparent();
            void Load( const char *szFileName );
    };
}

#endif



