// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CAnimatedImage_h__
#define __CAnimatedImage_h__
////////////////////////////////////////////////////////////////////////////////
#include "CImage.h"
#include "CAnimation.h"
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  	class CAnimatedImage : public CAnimation , public CImage
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
