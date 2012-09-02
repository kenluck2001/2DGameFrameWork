// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CGame_h__
#define __CGame_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include "CScene.h"
#include "CRenderer.h"
#include "CTimer.h"
#include <map>
#include <string>
////////////////////////////////////////////////////////////////////////////////
typedef std::map<std::string, DemoEngine::CScene *> SceneMap;
namespace DemoEngine
{
    class CGame
    {
        private:

            DemoEngine::CRenderer m_Renderer;
            bool m_bRunning;
            DemoEngine::CTimer	m_Timer;
            SceneMap m_mapScenes;
            DemoEngine::CScene * m_pCurrentScene;
        public:

            CGame();
            virtual ~CGame();

            CRenderer & GetRenderer()  { return m_Renderer; }
            virtual void OnKeyUp( SDL_KeyboardEvent & ev );
            virtual void OnKeyDown( SDL_KeyboardEvent & ev );
            virtual void OnMouseMotion( SDL_MouseMotionEvent & ev );
            virtual void OnMousePress( SDL_MouseButtonEvent & ev );
            virtual void OnMouseRelease( SDL_MouseButtonEvent & ev );
            virtual void OnUserEvent( SDL_UserEvent & ev );
            virtual void OnQuit( SDL_QuitEvent & ev );

            virtual void HandleEvents();
            virtual void Update();
            virtual void Render();

            bool IsRunning();
            void SetRunning( bool flag );
          
            CTimer & GetTimer() { return m_Timer;}
            void AddScene( const std::string & strName, DemoEngine::CScene *pScene);
            DemoEngine::CScene * GetScene(const std::string & strName );

            void RemoveScene( const std::string & strName );
            void SetCurrentScene(const std::string & strName );
            DemoEngine::CScene * GetCurrentScene();
            bool Execute();

            virtual void OnEnter() {}
            virtual void OnExit() {}
            virtual void Load() {}
            virtual void Unload() {}
    };
  ////////////////////////////////////////////////////////////////////////////////
}
#endif

