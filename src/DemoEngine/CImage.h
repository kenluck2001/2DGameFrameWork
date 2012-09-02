// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================


#ifndef __CIMAGE_H__
#define __CIMAGE_H__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
    class CImage 
    {
        protected:
            SDL_Surface *m_pSurface;
			SDL_Surface *m_pSurfaceOrig;
			SDL_Rect     m_Area;

        public:
            CImage();
            virtual ~CImage();
            void Load( const char *szFileName );
            void SetSurface( SDL_Surface *pSurface );
            SDL_Surface * GetSurface();
            void Release();
            void CreateEmpty(size_t nWidth, size_t nHeight, size_t nDepth);

			void SetOriginalSurface( SDL_Surface *pSurface ); 
    		void SetBlittedArea( int x, int y, int width, int height );
    		void SetBlittedArea( const SDL_Rect & rect );
    		SDL_Rect * GetBlittedArea();

    		void ReleaseOrig();
    		virtual void ScaleUniform( float factor, bool smooth  );
    		virtual void ScaleXY( float factorX, float factorY, bool smooth );
    		virtual void Rotate( float degrees, bool smooth);

    };
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

