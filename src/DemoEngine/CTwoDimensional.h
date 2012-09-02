// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CTwoDimensional_h__
#define __CTwoDimensional_h__
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{
  class CTwoDimensional
  {
  protected:
    int m_iWidth;
    int m_iHeight;
  public:
    virtual ~CTwoDimensional(){}
    void SetDimensions( int w, int h ) 
    {
      m_iWidth = w;
      m_iHeight = h;
    }
  
    int GetWidth() { return m_iWidth; }
    int GetHeight() { return m_iHeight; }

    void SetWidth( int val ) { m_iWidth = val; }
    void SetHeight( int val ) { m_iHeight = val; }

  };
}
////////////////////////////////////////////////////////////////////////////////
#endif
