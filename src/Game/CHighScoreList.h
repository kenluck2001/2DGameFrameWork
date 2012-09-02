// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CHighScoreList_h__
#define __CHighScoreList_h__
#include <string>
#include <set>
////////////////////////////////////////////////////////////////////////////////
/// High score item.
struct CHighScoreItem
{
  std::string name;
  int         score;

  bool operator<( const CHighScoreItem & s) const
  {
    return ( score > s.score ); // simplest at this point
  }
  
};
////////////////////////////////////////////////////////////////////////////////
/// Entire list.
class CHighScoreList : public std::set<CHighScoreItem>
{
public:
  
  void Load( const std::string & file );
  void Save( const std::string & file );
  void AddEntry( int score, const std::string & name);
};
////////////////////////////////////////////////////////////////////////////////
#endif
