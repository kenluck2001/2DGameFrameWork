// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CSoundServer.h"
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

// implement missing stubs
////////////////////////////////////////////////////////////////////////////////
DemoEngine::CSoundServer* DemoEngine::CSoundServer::iInstance = NULL;

DemoEngine::CSoundServer::CSoundServer()
{
}

DemoEngine::CSoundServer* DemoEngine::CSoundServer::GetInstance()
{
    if ( iInstance == NULL ) {
    iInstance = new DemoEngine::CSoundServer();
    }

    return iInstance;
}



void
DemoEngine::CSoundServer::Init( int freq, Uint16 format, int channels, int chunksize)
{
	if ( SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 )
	{
    	std::cerr << "Init failed:" << SDL_GetError() << std::endl;
    	exit(0);
  	}


  	int iDesiredFlags  = MIX_INIT_OGG;
  	int iInitedFlags   = Mix_Init(iDesiredFlags);

  	if( (iDesiredFlags & iInitedFlags) != iDesiredFlags) 
  	{
    	cerr << "Mix_Init: Failed to init required ogg and mp3 support!\n";
    	cerr << "Mix_Init: " << Mix_GetError() << "\n";
    	exit(0);
  	}

	if ( Mix_OpenAudio( freq, format, channels, chunksize ) )
  	{
    	cerr << "Unable to open audio: " << Mix_GetError() << endl;
  	}
}

////////////////////////////////////////////////////////////////////////////////
void DemoEngine::CSoundServer::Destroy()
{

	for( MapNameToSound::iterator iter = m_mapNameToSound.begin(); iter != m_mapNameToSound.end();    ++iter )
	{
		Mix_FreeChunk(iter->second);
		m_mapNameToSound.erase(iter);
	}

	for( MapNameToMusic::iterator iter = m_mapNameToMusic.begin(); iter != m_mapNameToMusic.end();    ++iter )
	{
		Mix_FreeMusic(iter->second);
		m_mapNameToMusic.erase(iter);
	}

	Mix_CloseAudio();
  	Mix_Quit();
	SDL_QuitSubSystem( SDL_INIT_AUDIO ); 
}
////////////////////////////////////////////////////////////////////////////////
void DemoEngine::CSoundServer::Load( const std::string & name, const char *szSoundFile )
{
	Mix_Chunk *pSound =  NULL;
  	pSound = Mix_LoadWAV( szSoundFile);
	pair<MapNameToSound::iterator, bool> ret;

  	if( pSound == NULL) 
  	{
    	cerr << "Could not load sound " << Mix_GetError() << endl;
    	exit(0);
  	}
	else
  	{
		ret = m_mapNameToSound.insert (pair<std::string, Mix_Chunk *>(name, pSound) ); 
		if (ret.second==false)
	  	{
			std::cout << "File "<<name <<" already existed !!!" << std::endl;
	  	}
	}

}
////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CSoundServer::LoadMusic( const std::string & name, const char *szMusicFile )
{
	Mix_Music *pMusic =  NULL;
  	pMusic = Mix_LoadMUS( szMusicFile );
	pair<MapNameToMusic::iterator, bool> ret;

  	if( pMusic == NULL) 
  	{
    	cerr << "Could not load music " << Mix_GetError() << endl;
    	exit(0);
  	}
	else
  	{
		ret = m_mapNameToMusic.insert (pair<std::string, Mix_Music *>(name, pMusic) ); 
		if (ret.second==false)
	  	{
			std::cout << "File "<<name <<" already existed !!!" << std::endl;
	  	}
	}


}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::Remove( const std::string & name)
{
  MapNameToSound::iterator it = m_mapNameToSound.find(name);
  if ( it != m_mapNameToSound.end())
  {
    Mix_FreeChunk(it->second);
    m_mapNameToSound.erase(it);
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::RemoveMusic( const std::string & name )
{
  MapNameToMusic::iterator it = m_mapNameToMusic.find(name);
  if ( it != m_mapNameToMusic.end())
  {
    Mix_FreeMusic(it->second);
    m_mapNameToMusic.erase(it);
  }
}
////////////////////////////////////////////////////////////////////////////////
int  
DemoEngine::CSoundServer::Play( const std::string & name, int channel  )
{
  return PlayLooped( name, 0, channel );
/*
	Mix_Chunk * pSound = m_mapNameToSound[name];

	if (pSound != NULL)
	{
		int chan = Mix_PlayChannel (channel, pSound , 0);
		while ( Mix_Playing(chan) != 0 );
	}
  	return 0;
*/
}
/////////////////////////////////////////////////////////////////
int  
DemoEngine::CSoundServer::PlayLooped( const std::string & name, int loops, int channel )
{
	return PlayLoopedTimed( name, loops, 0, channel );
}
////////////////////////////////////////////////////////////////////////////////
int  
DemoEngine::CSoundServer::PlayLoopedTimed( const std::string & name, int loops,  int ms, int channel )
{
	MapNameToSound::iterator it= m_mapNameToSound.find(name);
  	if ( it != m_mapNameToSound.end())
  	{
    	return Mix_PlayChannelTimed(channel, it->second, loops, ms);
  	}
  	return -1;
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::Halt( int channel )
{
	Mix_HaltChannel(channel);
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::Pause( int channel )
{
	Mix_Pause(channel); 
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::Resume( int channel )
{
	Mix_Resume( channel );
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::PlayMusic( const std::string & name )
{
	Mix_Music *pMusic =  m_mapNameToMusic[name];
	if (pMusic != NULL)
	{
		if ( Mix_PlayMusic( pMusic, -1) == -1 ) 
  		{
    		cerr << "Could not play music " << Mix_GetError() << endl;
  		}
	}
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::HaltMusic()
{
	Mix_HaltMusic();
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::PauseMusic()
{
	Mix_PauseMusic();
}
////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::ResumeMusic()
{
	Mix_ResumeMusic();
}

////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CSoundServer::IsPaused( int channel )
{
	if ( Mix_Paused( channel ))   
		return true;
  	return false;
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CSoundServer::IsPlaying( int channel )
{
	if ( Mix_Playing( channel ) )
		return true;
  	return false;
}
////////////////////////////////////////////////////////////////////////////////
bool 
DemoEngine::CSoundServer::IsFading( int channel )
{
	bool status = false;
	switch(Mix_FadingChannel(channel)) 
	{
		case MIX_NO_FADING:
		    printf("Not fading.\n");
		    break;
		case MIX_FADING_OUT:
		    printf("Fading out.\n");
			status = true;
		    break;
		case MIX_FADING_IN:
		    printf("Fading in.\n");
			status = true;
		    break;
	}
	return status;
}
////////////////////////////////////////////////////////////////////////////////
int
DemoEngine::CSoundServer::FadeInLooped( const std::string & name, int loops, int ms, int channel )
{
  MapNameToSound::iterator it= m_mapNameToSound.find(name);
  if ( it != m_mapNameToSound.end())
  {
	int chan = Mix_FadeInChannel(channel, it->second, loops, ms);
    return chan;
  }
  return -1;
}
////////////////////////////////////////////////////////////////////////////////
void
DemoEngine::CSoundServer::FadeOutLooped( int channel, int ms  )
{
	Mix_FadeOutChannel(channel, ms);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::FadeInMusic(const std::string & name, int ms)
{
  MapNameToMusic::iterator it = m_mapNameToMusic.find(name);
  if ( it != m_mapNameToMusic.end())
  {
    Mix_FadeInMusic(it->second, -1, ms);
  }
}

////////////////////////////////////////////////////////////////////////////////
void 
DemoEngine::CSoundServer::FadeOutMusic(int ms)
{
  Mix_FadeOutMusic(ms);
}
