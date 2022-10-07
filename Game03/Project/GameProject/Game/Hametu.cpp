#include "Hametu.h"
#include"UI.h"

Hametu::Hametu() :Base(eType_Hametu)
{
	m_img.Load("Image/Hametu.png");
}
void Hametu::Update()
{
	if (++m_cnt >= 180) {
		//‘Ò‹@ŠÔ3•b`‚T•b
		SetKill();
	}
}
void Hametu::Draw()
{
	m_img.Draw();
	m_img.SetPos(400, 0);
}



