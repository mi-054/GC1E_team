#pragma once
#include "../Base/Base.h"

class RBoy :public Base {
private:
	enum {
		eState_Idle,
	};
	int m_state;
	int m_cnt;

	CImage m_img;
	bool m_flip;
	bool m_is_ground;
	int m_damage_no;
	int m_hp;

	void StateIdle();

public:
	RBoy::RBoy(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};