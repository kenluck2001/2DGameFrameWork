// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CSpaceAttacker_h__
#define __CSpaceAttacker_h__
////////////////////////////////////////////////////////////////////////////////
#include <CGame.h>
#include <CScene.h>
#include <CSoundServer.h>
#include <CFont.h>
#include <CTimer.h>
#include <CCollisionDetector.h>
using namespace DemoEngine;


////////////////////////////////////////////////////////////////////////////////
class CSpaceAttacker : public CGame
{
    private:
        CSoundServer * g_pSoundServer;
        CCollisionDetector * g_pCollisionDetector;
    public:
        ////////////////////
        ///
        CSpaceAttacker();
        ////////////////////
        ///
	
        virtual ~CSpaceAttacker()
        {
            //delete g_pCollisionDetector;
	        //delete g_pSoundServer;
        }

        CSoundServer * GetSoundServer() 
        { 
	        return g_pSoundServer;
        }

        CCollisionDetector * GetCollisionDetector()
        {
            return g_pCollisionDetector;
        }

};
////////////////////////////////////////////////////////////////////////////////
#endif
