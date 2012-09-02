// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================
#include "CGame.h"
#include <algorithm>
#include <stdexcept>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CGame::CGame() : m_bRunning(true), m_pCurrentScene(NULL)
{

}
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CGame::~CGame() 
{
  if ( m_pCurrentScene )  m_pCurrentScene->OnExit();
  m_pCurrentScene = NULL;
  
  while( !m_mapScenes.empty() )
  {
    delete m_mapScenes.begin()->second;
    m_mapScenes.erase(m_mapScenes.begin());
  }
  
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::HandleEvents()
{
  SDL_Event ev;
  while ( SDL_PollEvent( &ev ))
  {
    switch( ev.type )
    {
    case SDL_QUIT:
      OnQuit( ev.quit );
      break;
    case SDL_KEYDOWN:
      OnKeyDown( ev.key );
      break;
    case SDL_KEYUP:
      OnKeyUp( ev.key );
      break;
    case SDL_MOUSEMOTION:
      OnMouseMotion( ev.motion );
      break;
    case SDL_MOUSEBUTTONUP:
      OnMouseRelease( ev.button );
      break;
    case SDL_MOUSEBUTTONDOWN:
      OnMousePress( ev.button );
      break;
    case SDL_USEREVENT:
      OnUserEvent( ev.user );
      break;
    default:
      break;
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnQuit( SDL_QuitEvent & ev )
{
  SetRunning(false);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnKeyUp( SDL_KeyboardEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnKeyUp(ev);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnKeyDown( SDL_KeyboardEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnKeyDown(ev);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnMouseMotion( SDL_MouseMotionEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnMouseMotion(ev);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnMousePress( SDL_MouseButtonEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnMousePress(ev);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnMouseRelease( SDL_MouseButtonEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnMouseRelease(ev); 
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::OnUserEvent( SDL_UserEvent & ev ) 
{
  if ( m_pCurrentScene ) m_pCurrentScene->OnUserEvent(ev); 
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CGame::IsRunning()
{
  return m_bRunning;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::SetRunning( bool flag )
{
  m_bRunning = flag;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::Update()
{
  m_Timer.Update();
  if ( GetCurrentScene() != NULL ) 
    GetCurrentScene()->Update(m_Timer.GetPassedTime());
  m_Timer.Reset();
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::Render()
{
  if ( GetCurrentScene() != NULL ) 
  {
    GetCurrentScene()->PreRender(GetRenderer());
    GetCurrentScene()->Render(GetRenderer());
    GetCurrentScene()->PostRender(GetRenderer());
  }
}
////////////////////////////////////////////////////////////////////////////////
bool
DemoEngine::CGame::Execute()
{
  if ( IsRunning())
  {
    HandleEvents();
    Update();
    Render();
    return true;
  }
  return false;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::AddScene( const std::string & strName, DemoEngine::CScene *pScene)
{
  SceneMap::iterator it = m_mapScenes.find(strName);
  if ( m_mapScenes.find(strName) == m_mapScenes.end())
  {
    pScene->SetGame(this);
    m_mapScenes.insert( make_pair(strName, pScene));
  } 
  else 
  {
    throw std::runtime_error("Scene '" + strName + "' already exists!");
  }
}
////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CGame::RemoveScene( const std::string & strName )
{
  SceneMap::iterator it = m_mapScenes.find(strName);
  if ( it != m_mapScenes.end() )
  {
    if ( it->second == m_pCurrentScene) m_pCurrentScene = NULL;
    delete it->second;
    m_mapScenes.erase(it);
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CGame::SetCurrentScene(const std::string & strName )
{
  SceneMap::iterator it = m_mapScenes.find(strName);
  if ( it != m_mapScenes.end() )
  {
    if ( m_pCurrentScene )  m_pCurrentScene->OnExit();
    m_pCurrentScene = it->second;
    m_pCurrentScene->OnEnter();
  }
  else 
  {
    if ( m_pCurrentScene )  m_pCurrentScene->OnExit();
    m_pCurrentScene = NULL;
  }
  
}
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CScene * 
DemoEngine::CGame::GetCurrentScene()
{
  return m_pCurrentScene;
}
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CScene * 
DemoEngine::CGame::GetScene(const std::string & strName )
{
  SceneMap::iterator it = m_mapScenes.find(strName);
  if ( it != m_mapScenes.end()) return it->second;
  else return NULL;
}
////////////////////////////////////////////////////////////////////////////////

