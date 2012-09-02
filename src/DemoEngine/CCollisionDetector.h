// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 16
// =============================

#ifndef __CCollisionDetector_h__
#define __CCollisionDetector_h__
////////////////////////////////////////////////////////////////////////////////
#include <CImage.h>
#include <CCircle.h>
#include <CRectangle.h>
#include <CVector2.h>
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  /// Class for detecting collision between primitives and images.
  class CCollisionDetector
  {
    private:
        CCollisionDetector();
    public:
	    static CCollisionDetector * iInstance;
	    static CCollisionDetector * GetInstance();
        ////////////////////
        /// Checks whether two images collide. 
        /// \param imgA First image.
        /// \param posA Position of top left coordinate of imgA.
        /// \param imgB Second image.
        /// \param posB Position of top left coordinate of imgB.
        /// \return true if images collide, false otherwise.
        bool Collides(  DemoEngine::CImage &   imgA,  DemoEngine::CVector2i & posA,
			       DemoEngine::CImage &   imgB,  DemoEngine::CVector2i & posB ) ;
        
        ////////////////////
        /// Checks whether two circles collide.
        /// \param c1 First circle.
        /// \param c2 Second circle.
        /// \return true if circles collide, false otherwise.
        bool Collides(  DemoEngine::CCircle &    c1,  DemoEngine::CCircle &    c2 ) ;
        ////////////////////
        /// Checks whether two rectangles collide.
        /// \param r1 First rectangle.
        /// \param r2 Second rectangle.
        /// \return true if rectangles collide, false otherwise.
        bool Collides(  DemoEngine::CRectangle & r1,  DemoEngine::CRectangle & r2 ) ;
        ////////////////////
        /// Checks whether point is inside a circle.
        /// \param c A circle
        /// \param pos Point
        /// \return true if pos is inside circle c, false otherwise.
        bool Collides(  DemoEngine::CCircle &    c,  DemoEngine::CVector2i & pos ) ;
        ////////////////////
        /// Checks whether point is inside a rectangle.
        /// \param r A rectangle
        /// \param pos Point
        /// \return true if pos is inside rectangle r, false otherwise.
        bool Collides(  DemoEngine::CRectangle &  r,  DemoEngine::CVector2i & pos ) ;
  };
}
////////////////////////////////////////////////////////////////////////////////
#endif

