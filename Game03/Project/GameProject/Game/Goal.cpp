#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {

	//�摜����
	m_img = COPY_RESOURCE("Goal", CImage);
	// ���S�ʒu�ݒ�
	m_img.SetCenter(32/2,64/2);
	// �����蔻��p�Z�`�ݒ�
	m_rect = CRect(-16, 32, 16, -64);
	m_pos = pos;

	
}

void Goal::Draw() {
	// �ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	// �����蔻���`�̕\��
	DrawRect();
}
