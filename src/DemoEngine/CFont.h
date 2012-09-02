// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CFONT_H__
#define __CFONT_H__

#include <SDL/SDL_ttf.h>
#include "CImageAlpha.h"
#include "CImage.h"
#include "CImageColorkey.h"

namespace DemoEngine
{
    class CFont
    {
        protected:
            TTF_Font *m_pFont;
            SDL_Color m_Color;

        public:
            CFont();
            virtual ~CFont();
            void Load( const char *szPath, size_t nFontSize );
            void Cleanup();
            CImageAlpha * CreateImageFromTextAL( const char *szText );
            CImage * CreateImageFromText( const char *szText );
            CImageColorkey * CreateImageFromTextCK( const char *szText );
            void SetColor (SDL_Color & color);
            SDL_Color & GetColor ();
    }; // CFont
} // DemoEngine

#endif

