// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CAnimation.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include <string>
#include <istream>
#include <ostream>
#include <iterator>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
const char *FRAME_TEXT = "frames";
const char *SEQUENCE_TEXT = "sequences";

////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CAnimation::LoadAnimation( const char *szFilename )
{

  	// Implement this.
  	ifstream file(szFilename);
	string frameStr(FRAME_TEXT);
	string sequenceStr(SEQUENCE_TEXT);
	bool bFrames = false, bSequence = false;
  	if ( file )
  	{
		m_Sequences.clear();
		m_Frames.clear();
		string tmp;
		while( !file.eof())
		{
		  	getline( file, tmp );
		  	if ( tmp.empty()) continue;
		  	if ( tmp[0] == '#' ) continue;

		  	//cout << "found line: " << tmp << "\n";
		  	/* Implement loading routine here */  

			if (tmp == frameStr)
			{
				bFrames = true;
				bSequence = false;
				continue;
			}


			if (tmp == sequenceStr)
			{
				bFrames = false;
				bSequence = true;
				continue;
			} 


			if ( bFrames )
			{
			  	// use stream iterators to copy the stream to the vector as whitespace separated strings
				// construct a stream from the string
		  		std::stringstream strstr(tmp);
			  	std::istream_iterator<int> it(strstr);
			  	std::istream_iterator<int> end;
			  	std::vector<int> results(it, end); //get vector of the integers in a line

				//create rectangle object
				SDL_Rect anim;
				anim.x = results[0];
				anim.y = results[1];
				anim.w = results[2];
				anim.h = results[3];

				// store frames into m_Frames
				m_Frames.push_back (anim);

			}
			if ( bSequence )
			{
			  	// use stream iterators to copy the stream to the vector as whitespace separated strings
				// construct a stream from the string
  				std::stringstream strstr(tmp);

			  	std::istream_iterator<int> it(strstr);
			  	std::istream_iterator<int> end;
			  	std::vector<int> results(it, end); //get vector of the integers in a line
				// store sequences into m_Sequences
				 m_Sequences.push_back (results);
			}

		}// while
    
  	}
  	else
  	{
    	ostringstream s;
    	s << "Could not read file '" << szFilename << "'";
    	throw runtime_error(s.str());
  	}


}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CAnimation::DebugPrint()
{
  	for( size_t i=0;i<m_Frames.size();i++)
  	{
    
    	cout  << "Frame " << i << ": {"
	  	<< m_Frames[i].x << "," 
	  	<< m_Frames[i].y << ","
	  	<< m_Frames[i].w << ","
	  	<< m_Frames[i].h << "}" << endl;
  	}

  	for( size_t i=0;i<m_Sequences.size();i++)
  	{
    	cout << "Sequence " << i << ": " ;
    	for( size_t s=0;s<m_Sequences[i].size();s++)
    	{
      		cout << m_Sequences[i][s] << " ";
    	}
    	cout << endl;
  	}

}

////////////////////////////////////////////////////////////////////////////////
bool
DemoEngine::CAnimation::IsFinished()
{
  return (m_iFrame == m_Sequences[m_iSequence].size()-1);
}


