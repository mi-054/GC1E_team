#pragma once
#include"../Base/Base.h"

class Boy :public Base {
private:
	CImage m_img;
public:
	Boy(const CVector2D& p);
	void Update();
	void Draw();
	void Collision(Base* b);
};