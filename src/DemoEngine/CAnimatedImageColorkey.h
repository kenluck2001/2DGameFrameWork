// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CImageColorkey_h__
#define __CImageColorkey_h__
////////////////////////////////////////////////////////////////////////////////
#include "CImageColorkey.h"
#include "CAnimation.h"
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  	class CAnimatedImageColorkey : public CAnimation , public CImage
  	{
  		public:
			virtual void ApplyAnimation()
			{
				if ( HasAnimation())
				{
					SetBlittedArea(GetFrameRectangle());
				}
			}
  	};
}
////////////////////////////////////////////////////////////////////////////////
#endif
