// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include <algorithm>
#include "CScene.h"


struct UpdateOp
{
		float m_time ;
		UpdateOp (float fSec ) : m_time ( fSec ) { }
		inline void operator()(DemoEngine::IUpdateable * pObj )
		{
			pObj->Update ( m_time ) ;
		}
};

struct RenderOp
{
		DemoEngine::CRenderer & renderer;  
		RenderOp(DemoEngine::CRenderer & m_renderer) : renderer ( m_renderer ) { }
		inline void operator ()( DemoEngine::IRenderable * pObj )
		{
			pObj->Render (renderer ) ;
		}
};

DemoEngine::CScene::CScene(): m_bRunning(true)
{
}

////////////////////////////////////////////////////////////////////////////////
DemoEngine::CScene::~CScene() 
{

}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

void
DemoEngine::CScene::Update(float fSeconds)
{
	UpdateableList & lst = GetUpdateables();
	std::for_each(lst.begin(),lst.end(), UpdateOp(fSeconds));
}

////////////////////////////////////////////////////////////
void
DemoEngine::CScene::PreRender(DemoEngine::CRenderer & renderer)
{
	renderer.ClearScreen();
}
////////////////////////////////////////////////////////////
void
DemoEngine::CScene::Render(DemoEngine::CRenderer & renderer)
{
	RenderableList & lst = GetRenderables();
	std::for_each(lst.begin(),lst.end(),RenderOp(renderer));
}
////////////////////////////////////////////////////////////
void
DemoEngine::CScene::PostRender(DemoEngine::CRenderer & renderer)
{
	renderer.End();
}

////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CScene::OnQuit( SDL_QuitEvent & ev )
{
  SetRunning(false);
}

bool 
DemoEngine::CScene::IsRunning()
{
  return m_bRunning;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CScene::SetRunning( bool flag )
{
  m_bRunning = flag;
}

////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CScene::SetGame( DemoEngine::CGame *pGame )
{
    m_pGame = pGame;
}
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CGame * 
DemoEngine::CScene::GetGame()
{
    return m_pGame;
}
