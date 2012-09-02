// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#ifndef __CSoundServer_h__
#define __CSoundServer_h__
////////////////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <map>
#include <string>

using namespace std;
////////////////////////////////////////////////////////////////////////////////
typedef std::map<std::string, Mix_Chunk *> MapNameToSound;
typedef std::map<std::string, Mix_Music *> MapNameToMusic;
////////////////////////////////////////////////////////////////////////////////
namespace DemoEngine 
{

  class CSoundServer
  {
  private:
    MapNameToSound m_mapNameToSound;
    MapNameToMusic m_mapNameToMusic;

  public: 
    virtual ~CSoundServer() { Destroy(); }
    void Init( int freq = MIX_DEFAULT_FREQUENCY, 
	       Uint16 format = MIX_DEFAULT_FORMAT, 
	       int channels = 2, 
	       int chunksize = 1024);

    void Destroy();

    void Load( const std::string & name, const char *szSoundFile );
    void LoadMusic( const std::string & name, const char *szMusicFile );
    void Remove( const std::string & name);
    void RemoveMusic( const std::string & name );

    int  Play( const std::string & name, int channel = -1 );
    int  PlayLooped( const std::string & name, int loops, int channel = -1 );
    int  PlayLoopedTimed( const std::string & name, int loops, 
			  int ms, int channel = -1 );


    int  FadeInLooped( const std::string & name, int loops, int ms, int channel=-1 );
    void FadeOutLooped( int ms, int channel = -1);

    void Halt( int channel = -1);
    void Pause( int channel = -1);
    void Resume( int channel = -1);


    void PlayMusic( const std::string & name );
    void HaltMusic();
    void FadeInMusic(const std::string & name, int ms);
    void FadeOutMusic(int ms);
    void PauseMusic();
    void ResumeMusic();

    bool IsPaused( int channel );
    bool IsPlaying( int channel );
    bool IsFading( int channel );


	static CSoundServer* iInstance;
	static CSoundServer* GetInstance();

    private:
        // private constructor
        CSoundServer();

  };
}
////////////////////////////////////////////////////////////////////////////////
#endif

