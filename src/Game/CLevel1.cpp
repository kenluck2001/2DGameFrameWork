// =============================
// SDL Programming
// Name: ODOH KENNETH EMEKA
// Student id: 0902024
// Task 18
// =============================

#include "CLevel1.h"
#include "CSpaceAttacker.h"
#include <CVector2.h>
#include "CPlayer.h"
#include "CEnemy.h"
#include <CCollisionDetector.h>
#include <iostream>
#include <sstream> 
using namespace std;

const int STRINGLEN = 20;
enum BGELEMENT
{
  BG_STARS,
  BG_STARS2,
  BG_STARS3,
  BG_NUM_BACKGROUNDS
};

CLevel1::CLevel1( )
{
    m_bAboutToDie = false; // this is needed to know when to change the scene to exit scene. Once this flag is true, we can enter the exit scene
	pfontImg = new CImageAlpha();
	pFontNumImg = new CImageAlpha();
	step = 6; //scrolling steps
	normfont.Load("fonts/arial.ttf",18);
	numFont.Load("fonts/impact.ttf",25);
	pfontImg = normfont.CreateImageFromTextAL("Space Attackers : alpha build, not for distribution!");
	pFontNumImg = numFont.CreateImageFromTextAL("00000");

	char  imagePath[BG_NUM_BACKGROUNDS][STRINGLEN] ={"pics/stars.png", "pics/stars2.png", "pics/stars3.png" };
	int stepLimit[BG_NUM_BACKGROUNDS]  = {20 ,12 ,2};

	p_CScrollBackground = new CScrollingBackground(BG_NUM_BACKGROUNDS);
	for (int count = 0; count < BG_NUM_BACKGROUNDS; count++)
 	{
  	  	CBackgroundLayer *p_CBackLayer = new CBackgroundLayer();
	  	p_CBackLayer->Load( imagePath[count]) ;
	  	p_CScrollBackground->SetLayer( count, p_CBackLayer );
	  	p_CScrollBackground->GetLayer( count )->step_limit = stepLimit[count];
		//p_CBackLayer object is destroyed when it exits this scope
    }

	SDL_EnableKeyRepeat( SDL_DEFAULT_REPEAT_DELAY,  SDL_DEFAULT_REPEAT_INTERVAL );
	st.m_State = NONE;
	st.b_State = NO;
}

void CLevel1::OnKeyDown( SDL_KeyboardEvent & ev )
{
	switch ( ev.keysym.sym )
	{
		case SDLK_LEFT:
			st.m_State = LEFT;
			st.b_State = PRESSED;		
		  	break;
		case SDLK_RIGHT:
			st.m_State = RIGHT;
			st.b_State = PRESSED;
		  	break;
		case SDLK_UP:
			st.m_State = UP;
			st.b_State = PRESSED;
		  	break;
		case SDLK_DOWN:
			st.m_State = DOWN;
			st.b_State = PRESSED;
		  	break;
		default:
 			st.m_State = NONE;
 			st.b_State = NO;
		  	break;
	}
}

void CLevel1::OnKeyUp( SDL_KeyboardEvent  & ev )
{
	switch ( ev.keysym.sym )
	{
		case SDLK_SPACE: 
			p_Player->Fire();
			break;
		case SDLK_LEFT:
			st.m_State = LEFT;
			st.b_State = RELEASED;
	  		break;
		case SDLK_RIGHT:
			st.m_State == RIGHT;
			st.b_State = RELEASED;
	  		break;
		case SDLK_UP:
			st.m_State = UP;
			st.b_State = RELEASED;
	  		break;
		case SDLK_DOWN:
			st.m_State = DOWN;
			st.b_State = RELEASED;
	  		break;
		default:
 			st.m_State = NONE;
 			st.b_State = NO;
	  		break;
	}
}


void CLevel1::OnEnter()
{
	m_Score = 0;
    m_bAboutToDie = false;
	p_Player = new CPlayer ( dynamic_cast<CSpaceAttacker *>(GetGame()) ) ;
    // Position plane in the middle of the screen
    int midwidth = dynamic_cast<CSpaceAttacker *>(GetGame())->GetRenderer().GetScreen()->w/2;
    int midheight = dynamic_cast<CSpaceAttacker *>(GetGame())->GetRenderer().GetScreen()->h/2;
    p_Player->SetPosition( midwidth, midheight);

    dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->PlayMusic("Astroboy_Sprung-160");

    m_pEnemy = new CEnemy(dynamic_cast<CSpaceAttacker*>(GetGame()));
    m_pEnemy->SetPosition(CVector2i( rand()% (GetGame()->GetRenderer().GetScreen()->w/2-30), -30));
  
    GetUpdateables().push_back(p_Player);
    GetRenderables().push_back(p_Player);
    GetUpdateables().push_back(m_pEnemy);
    GetRenderables().push_back(m_pEnemy);

    // make bullets rendered and updated
    for(int i=0;i<MAX_BULLETS;i++)
    {
        //align projectile along the player centre of gravity
        GetUpdateables().push_back(&p_Player->GetBullets()[i]);
        GetRenderables().push_back(&p_Player->GetBullets()[i]);
    }
    // Render and update explosions, too
    GetUpdateables().push_back(&m_Explosion);
    GetRenderables().push_back(&m_Explosion);
}
////////////////////////////////////////////////////////////////////////////////
void
CLevel1::OnExit()
{
    GetUpdateables().clear();
    GetRenderables().clear();
    delete p_Player;
    delete m_pEnemy;
	//delete pfontImg;
	//delete pFontNumImg;
}

void CLevel1::PreRender( CRenderer & renderer )
{
	renderer.ClearScreen();
	renderer.Begin();
	p_CScrollBackground->Render( renderer ); 
}

void CLevel1::Update( float fSeconds  )
{
	CScene::Update(fSeconds);
	int x = 0,y = 0;

	if (st.b_State == PRESSED)
	{
		if (st.m_State == LEFT)	{ --x; }
		if (st.m_State == RIGHT) { ++x; }
		if (st.m_State == UP) {	--y; }
		if (st.m_State == DOWN) { ++y; }
	}
    p_CScrollBackground->Move(VERTICAL,-step *2);


    if ( !m_bAboutToDie )
    {  
        p_Player->Move( (x * 6), (y * 6) ); //scale the coordinates to increase the speed of reaction
        // Perform collision detection with enemy-to-bullets
        for( int i=0;i<MAX_BULLETS;i++)
        {
            if ( dynamic_cast<CSpaceAttacker *>(GetGame())->GetCollisionDetector()->Collides( p_Player->GetBullets()[i].GetBoundingRectangle(), m_pEnemy->GetBoundingRectangle()))
            {
                CVector2i getEnemyPos = m_pEnemy->GetPosition();
                p_Player->GetBullets()[i].SetPosition( getEnemyPos ); //force the bullet to stay on the enemy 
	            p_Player->GetBullets()[i].SetPosition(0,-40); // move the bullet off-screen after hitting your target
	            
	            dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->Play("boom"); 
	            m_Explosion.Explode( m_pEnemy->GetX(),     m_pEnemy->GetY() );
	            m_pEnemy->Respawn();
				m_Score++; //increment score after collision
				//force the ponter to NULL as it could be tricky deleting a pointer and still trying to access it
				pFontNumImg = NULL ; //make the pointer null so it can be reassigned
				ostringstream s;
				s.width(5);
				s.fill('0');
				s << m_Score;
  				const std::string& tmp = s.str();
  				const char* textstr = tmp.c_str();

				pFontNumImg = numFont.CreateImageFromTextAL( textstr );
				
            }
        }
        ////////////////////
        // Check if enemy plane hits player
        if ( dynamic_cast<CSpaceAttacker *>(GetGame())->GetCollisionDetector()->Collides( p_Player->GetBoundingRectangle(), m_pEnemy->GetBoundingRectangle()))
        {
            dynamic_cast<CSpaceAttacker *>(GetGame())->GetSoundServer()->Play("boom"); 
            m_Explosion.Explode( p_Player->GetX(), p_Player->GetY() );

            p_Player->SetPosition(-40,-20); // off-screen
            m_pEnemy->SetPosition(-530,-20); // off-screen (also prevent colliding again)

            m_bAboutToDie = true;
        }
    } 
    else  // After final explosion has stopped
    {

        if ( m_Explosion.IsFinished())
        {
            GetGame()->SetCurrentScene("gameover");
        }

    }
}

////////////////////
/// Overwrite PostRender, draw guide text before flipping buffers.
void CLevel1::PostRender( CRenderer & renderer )
{
    int width = dynamic_cast<CSpaceAttacker *>(GetGame())->GetRenderer().GetScreen()->w;
	renderer.Render( pfontImg, 0, 0);
	renderer.Render( pFontNumImg , (width - pFontNumImg->GetSurface()->w), 0);
	renderer.End();
}

