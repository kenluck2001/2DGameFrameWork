// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CAnimatedImageAlpha_h__
#define __CAnimatedImageAlpha_h__
////////////////////////////////////////////////////////////////////////////////
#include "CImageAlpha.h"
#include "CAnimation.h"
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  	class CAnimatedImageAlpha : public CAnimation , public CImage
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
