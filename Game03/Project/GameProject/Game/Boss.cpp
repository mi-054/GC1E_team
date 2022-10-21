#include "Boss.h"
#include "AnimData.h"
#include "Field.h"
#include "Effect.h"
#include "Map.h"
#include "Slash.h"
#include"GameData.h"

void Boss::StateIdle()
{

	const float move_speed = 2;

	bool move_flag = false;

	//const float jump_pow = 12;

	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			//移動量を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = false;
			move_flag = true;
		}
	}
}

Boss::Boss(const CVector2D& p, bool flip) :Base(eType_Boss)
{
	m_img = COPY_RESOURCE("Boss", CImage);

	m_img.ChangeAnimation(0);

	m_is_ground = false;

	m_pos_old = m_pos = p;

	m_img.SetCenter(64, 128);

	m_rect = CRect(-54, -128, 54, 0);

	m_flip = flip;

	m_hp = 250;	// 5回
	m_cnt = 300;
}
void Boss::Update()
{
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	StateIdle();

	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();

}
void Boss::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));

	m_img.SetFlipH(m_flip);

	m_img.SetSize(128, 128);

	m_img.Draw();

	DrawRect();
}

void Boss::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player_Attack:
		// Slash型へキャスト、型変換出来たら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				// 同じ攻撃の連続ダメージ防止
				m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					SetKill();
					GameData::s_score += 200;
				}
			}
		}
		break;

	case eType_Field:

		if (Field* f = dynamic_cast<Field*>(b)) {

			if (m_pos.y > f->GetGroundY()) {

				m_pos.y = f->GetGroundY();

				m_vec.y = 0;

				m_is_ground = true;
			}
		}
		break;
	}
}
