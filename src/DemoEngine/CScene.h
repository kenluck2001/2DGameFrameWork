// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CSCENE_H__
#define __CSCENE_H__

#include <SDL/SDL.h>
#include <iostream>
#include <list>

#include "CRenderer.h"
#include "IRenderable.h"
#include "IUpdateable.h"

using namespace std;

typedef std::list<DemoEngine::IRenderable *> RenderableList;
typedef std::list<DemoEngine::IUpdateable *> UpdateableList;




namespace DemoEngine
{
    class CGame; // forward declaration since we only need the game pointer.
    class CScene : public DemoEngine::IUpdateable, public DemoEngine::IRenderable
    {
		private:
			RenderableList m_lstRenderables;
			UpdateableList m_lstUpdateables;
			bool m_bRunning;
            DemoEngine::CGame * m_pGame;

		public:
			CScene();
			virtual ~CScene();

			RenderableList & GetRenderables()
			{
				return m_lstRenderables;
			}
			UpdateableList & GetUpdateables()
			{
				return m_lstUpdateables;
			}

            virtual void OnKeyUp( SDL_KeyboardEvent & ev ) {}
            virtual void OnKeyDown( SDL_KeyboardEvent & ev ) {}
            virtual void OnMouseMotion( SDL_MouseMotionEvent & ev ) {}
            virtual void OnMousePress( SDL_MouseButtonEvent & ev ) {}
            virtual void OnMouseRelease( SDL_MouseButtonEvent & ev ) {}
            virtual void OnUserEvent( SDL_UserEvent & ev ) {}
            virtual void OnQuit( SDL_QuitEvent & ev );

			virtual void Update(float fSecond);

			virtual void PreRender(CRenderer & renderer);
			virtual void Render(CRenderer & renderer);
			virtual void PostRender(CRenderer & renderer);
      
            bool IsRunning();
            void SetRunning( bool flag );
			virtual void OnEnter(){}
			virtual void OnExit(){}
			virtual void Load(){}
    		virtual void Unload(){}

            void SetGame( DemoEngine::CGame *pGame );
            DemoEngine::CGame * GetGame();
	};

}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

 
