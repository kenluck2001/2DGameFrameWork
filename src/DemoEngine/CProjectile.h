// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CProjectile_h__
#define __CProjectile_h__
////////////////////////////////////////////////////////////////////////////////
#include <CGameObject.h>
#include <CImageAlpha.h>
#include <CRenderer.h>
using namespace DemoEngine;
////////////////////////////////////////////////////////////////////////////////
class CProjectile : public CGameObject
{
    private:
        CImageAlpha m_Bullet;
    public:
        CProjectile()
        {
            m_Bullet.Load("pics/plasma_up.png");
            m_Bullet.SetAlpha(254);
            SetPosition( CVector2i(0,-m_Bullet.GetSurface()->h/2));
            // set bounding rectangle dimensions for collision
            GetBoundingRectangle().SetDimensions(m_Bullet.GetSurface()->w, m_Bullet.GetSurface()->h);
        }

        void Render( CRenderer & r )
        {
            r.Render(&m_Bullet, GetX() - m_Bullet.GetSurface()->w/2, GetY() - m_Bullet.GetSurface()->h/2 );  
        }

        void Update( float fSeconds )
        {
            if (  GetY() > -m_Bullet.GetSurface()->h/2 )
            {
                Move(0,-20);
            }
            // update bounding rectangle dimensiosn for collision

            GetBoundingRectangle().SetPosition(GetPosition());
        }

        bool IsAvailable()
        {
            return ( GetY() <= -m_Bullet.GetSurface()->h/2); // off screen
        }  
};
////////////////////////////////////////////////////////////////////////////////
#endif

