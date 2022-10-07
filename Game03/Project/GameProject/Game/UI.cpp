#include "UI.h"
#include"Hametu.h"
#include"Goal.h"

UI::UI():Base(eType_UI)
{
	m_img.Load("Image/UI.png");
	time = 120*60;
}

void UI::Draw()
{
	time -= 1;
	
	int t = time / 60;
	if (time == 60 * 60) {
		Base::Add(new Hametu());
	}
	for (int i = 0; i < 8; i++, t /=10) {
		int s = t%10;
		m_img.SetRect(16 * s, 16, 16 * s+16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16*i , 0);
		m_img.Draw();
	}
	
	
	Base* Goal = Base::FindObject(eType_Goal);
	Base* player = Base::FindObject(eType_Player);

	if (player == nullptr) {
		Base* player = Base::FindObject(eType_Player);
		// プレイヤーがいなければ
			// ゲームオーバーの表示
		m_img.SetRect(0, 96, 0 + 160, 96 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(570, 340);
		m_img.Draw();
	}
	else if (Goal == nullptr) {
		// ゴールがなければ
			// ゲームクリアの表示
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(570, 340);
		m_img.Draw();
	}
	else if (time == 0) {
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(570, 340);
		m_img.Draw();



	}
}
