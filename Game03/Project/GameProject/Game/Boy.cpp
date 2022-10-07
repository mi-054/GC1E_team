#include "Boy.h"


Boy::Boy(const CVector2D& p):
     Base(eType_Player) {
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = p;
}
void Boy::Update() 
{
}
void Boy::Draw(){
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void Boy::Collision(Base* b)
{
}
