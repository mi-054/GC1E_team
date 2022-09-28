#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {

	//画像複製
	m_img = COPY_RESOURCE("Goal", CImage);
	// 中心位置設定
	m_img.SetCenter(32/2,64/2);
	// 当たり判定用短形設定
	m_rect = CRect(-16, 32, 16, -64);
	m_pos = pos;

	
}

void Goal::Draw() {
	// 位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	// 当たり判定矩形の表示
	DrawRect();
}
