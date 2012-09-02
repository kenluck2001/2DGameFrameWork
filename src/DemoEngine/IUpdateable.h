// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// ============================

#ifndef __IUPDATEABLE_H__
#define __IUPDATEABLE_H__

////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
    class IUpdateable
    {
		public:
			virtual ~IUpdateable(){}
			virtual void Update (float fSecond) = 0; // pure virtual function
	};
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

