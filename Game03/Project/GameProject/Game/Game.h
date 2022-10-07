#pragma once

#include "../Base/Base.h"

class Game : public Base {
public:
	int t2 = 0;
	Game();
	~Game();
	void Update();
};