// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CHighScoreList.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
const size_t MAX_NUM_SCORES = 10;
////////////////////////////////////////////////////////////////////////////////
void
CHighScoreList::Load( const std::string & file )
{
  size_t count = 0;
  clear();
  ifstream f(file.c_str());
  if ( ! f.is_open() ) 
    throw runtime_error("Cannot open highscorefile for reading");

  while( f.good() && (count++ < MAX_NUM_SCORES) )
  {
    string tmp;
    getline(f,tmp);
    istringstream s(tmp);

    CHighScoreItem item;
    s >> item.score;
    s >> item.name;
    insert(item);
  }

  f.close();
}
////////////////////////////////////////////////////////////////////////////////
void
CHighScoreList::Save( const std::string & file )
{
  size_t count = 0;


  ofstream f(file.c_str());

  if ( ! f.is_open() ) 
    throw runtime_error("Cannot open highscorefile for saving");

  CHighScoreList::iterator it = begin();
  while ( it != end() && (count++ < MAX_NUM_SCORES) )
  {
    f << it->score << " " << it->name << "\n";
    it++;
  }
  f.flush();
  f.close();
}
////////////////////////////////////////////////////////////////////////////////
void
CHighScoreList::AddEntry( int score, const std::string & name)
{
  CHighScoreItem item;
  item.score = score;
  item.name = name;
  insert(item);
}
////////////////////////////////////////////////////////////////////////////////
