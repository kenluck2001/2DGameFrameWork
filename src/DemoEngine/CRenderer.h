// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CRenderer_H__
#define __CRenderer_H__
////////////////////////////////////////////////////////////////////////////////
#include "CImage.h"
#include "CImageColorkey.h"
#include "CImageAlpha.h"
#include "CEllipse.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CLineSegment.h"
#include <SDL/SDL.h>


namespace DemoEngine
{
    class CImage;
    ////////////////////
    class CRenderer
    {
        private:
            bool m_bInitialized;
            SDL_Surface* m_pScreen;
            Uint32  m_ClearColor;
        public:
            CRenderer() : m_bInitialized(false) {}
            void Init();
            void CleanUp();
            void OpenWindow( int width, int height, int depth, int flags );
            void Render( CImage *pImage, int x, int y );
            void Render( CImageColorkey *pImage, int x, int y );
            void Render( CImageAlpha *pImage, int x, int y );

            void Render( CEllipse *pEllipse );
            void Render( CCircle *pCircle );
            void Render( CRectangle *pRect );
            void Render( CLineSegment *pLine );

            void SetClearColor( Uint8 r, Uint8 g, Uint8 b);
            void ClearScreen();
            SDL_Surface * GetScreen();
            void Begin();
            void End();
    };
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

