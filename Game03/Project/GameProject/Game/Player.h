#pragma once
#include "../Base/Base.h"

class Player :public Base {
private:
	// 状態
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	// 状態変数
	int m_state;

	CImage m_img;
	// 左右反転フラグ
	bool m_flip;
	// 着地フラグ
	bool m_is_ground;
	
	int m_cnt;
	// 攻撃番号
	int m_attack_no;
	// ダメージ番号
	int m_damage_no;
	// ヒットポイント
	int m_hp;

	// 各状態での挙動
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();

public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};