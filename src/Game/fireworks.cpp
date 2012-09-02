// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "fireworks.h"
////////////////////////////////////////////////////////////////////////////////

int MasterOfExplosionsPix( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireworksApp *pApp = reinterpret_cast<CFireworksApp *>(data);

  while (pApp->IsRunning()) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetColorPixFireWorks() ;
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }
    pApp->Release();
    SDL_Delay(rand()%500);
  }
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
int MasterOfExplosionsLine( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireworksApp *pApp = reinterpret_cast<CFireworksApp *>(data);

  while (pApp->IsRunning()) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetColorLineFireWorks();
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }
    pApp->Release();
    SDL_Delay(rand()%500);
  }
  return 0;
}

int MasterOfExplosionsSmoke( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireworksApp *pApp = reinterpret_cast<CFireworksApp *>(data);

  while (pApp->IsRunning()) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetSmokeFireWorks();
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }

    pApp->Release();
    SDL_Delay(rand()%500);
  }
  return 0;
}


int MasterOfCExplosionsPix( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireExplosion *pApp = reinterpret_cast<CFireExplosion *>(data);

  while (true) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetColorCPixFireWorks() ;
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }
    pApp->Release();
    SDL_Delay(rand()%50);
	break;
  }
  return 0;
}
////////////////////////////////////////////////////////////////////////////////
int MasterOfCExplosionsLine( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireExplosion *pApp = reinterpret_cast<CFireExplosion *>(data);

  while (true) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetColorCLineFireWorks();
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }
    pApp->Release();
    SDL_Delay(rand()%50);
	break;
  }
  return 0;
}

int MasterOfCExplosionsSmoke( void *data )
{
  // void pointer needs to be casted to proper type before using it.
  CFireExplosion *pApp = reinterpret_cast<CFireExplosion *>(data);

  while (true) // exit thread when application stops running.
  {
    CFireworks *ps = &pApp->GetSmokeCFireWorks();
    pApp->Lock(); 
    ps->Initialize(100);
    while(ps->IsAlive())
    {
      SDL_Delay(10);
    }

    pApp->Release();
    SDL_Delay(rand()%50);
	break;
  }
  return 0;
}
