// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CVector2_h__
#define __CVector2_h__
////////////////////////////////////////////////////////////////////////////////
#include <cmath>
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine
{
  template<class TYPE>
  class CVector2
  {
  private:

    TYPE m_values[2];

  public:
 
    CVector2() { }

    CVector2( TYPE x, TYPE y) 
    {
      m_values[0] = x; 
      m_values[1] = y; 
    }

    CVector2( const CVector2 & v )
    {
      m_values[0] = v.m_values[0];
      m_values[1] = v.m_values[1];
    }

    virtual ~CVector2() 
    {
  
    }

    void operator=( const CVector2 & v )
    {
      m_values[0] = v.m_values[0];
      m_values[1] = v.m_values[1];
    }

    CVector2 operator/( TYPE value ) const
    {
      return CVector2( m_values[0]/value, m_values[1]/value);
    }
  
    CVector2 operator-( const CVector2 & v) const
    {
      return CVector2( m_values[0] - v.m_values[0], m_values[1] - v.m_values[1] );
    }

    CVector2 operator+( const CVector2 & v) const
    {
      return CVector2( m_values[0] + v.m_values[0], m_values[1] + v.m_values[1] );
    }
  
    CVector2 operator*( TYPE value ) const
    {
      return CVector2( m_values[0] * value, m_values[1] * value);
    }

    friend CVector2 operator*( TYPE value, const CVector2 & v )
    {
      return CVector2( v.m_values[0] * value, v.m_values[1] * value);
    }

  
    void operator-=( const CVector2 & v) 
    {
      m_values[0] -= v.m_values[0];
      m_values[1] -= v.m_values[1];
    }

    void operator+=( const CVector2 & v) 
    {
      m_values[0] += v.m_values[0];
      m_values[1] += v.m_values[1];
    }
  
    void operator*=( TYPE v ) 
    {
      m_values[0] *= v;
      m_values[1] *= v;
    }

    void operator/=( TYPE v ) 
    {
      m_values[0] /= v;
      m_values[1] /= v;
    }
  
    TYPE & operator[](int index ) 
    {
      return m_values[index];
    }
  
    const TYPE & operator[](int index) const
    {
      return m_values[index];
    }
  
    TYPE & At(int index ) 
    {
      return m_values[index];
    }

    const TYPE & At(int index )  const
    {
      return m_values[index];
    }

    bool operator==( const CVector2 & v ) const
    {
      return ((m_values[0] == v.m_values[0]) &&
	      (m_values[1] == v.m_values[1])) ;
    }

    bool operator!=( const CVector2 & v ) const
    {
      return ( (m_values[0] != v.m_values[0])  ||
	       (m_values[1] != v.m_values[1]) );
    }

    TYPE LengthSqr() const
    {
      return Dot(*this);
    }
  
    TYPE Length() const
    {
      return sqrtf(Dot(*this));
    }

    void Normalize()
    {
      (*this)/=Length();
    }

    CVector2 NormalizeVector()
    {
      return ( (*this)/Length() ) ;
    }
  
    TYPE Dot( const CVector2 & v ) const
    {
      return (m_values[0] * v.m_values[0] + m_values[1] * v.m_values[1]);
    }
  
  };
  // Something to shorten writing...
  typedef CVector2<int> CVector2i;
  typedef CVector2<float> CVector2f;
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
/// SDL programming
/// Vector2 class 
/// \Author AG
////////////////////////////////////////////////////////////////////////////////
