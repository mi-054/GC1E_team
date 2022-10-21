#include "Play.h"
#include "../Game/Game.h"
#include"Teki.h"


Play::Play():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Play", CImage);
}



Play::~Play()
{
	SOUND("BGM_Title")->Stop();
	SOUND("BGM_Game")->Play(true);
	Base::KillAll();
	Base::Add(new Teki());
}

void Play::Update()
{
	
	
	if (PUSH(CInput::eButton1))
		SetKill();
	
}

void Play::Draw()
{
	m_img.Draw();
}
