#include "Play.h"
#include "../Game/Game.h"


Play::Play():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Play", CImage);
}



Play::~Play()
{
	Base::KillAll();
	Base::Add(new Game());
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
