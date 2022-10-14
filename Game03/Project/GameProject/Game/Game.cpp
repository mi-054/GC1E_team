#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"
#include "Goal.h"
#include"Boy.h"
#include"UI.h"
#include"Hametu.h"

Game::Game():Base(eType_Scene)
{
	
	//Base::Add(new Map());
	
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(1080, 600), false));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 1, 540), true));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 2, 540), true));
	Base::Add(new Enemy(CVector2D(1280 + 256 * 3, 540), true));
	Base::Add(new Goal(CVector2D(2048, 540 - 32)));

	Base::Add(new UI());
	

}

Game::~Game()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}

void Game::Update()
{
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		if(++t4>=180)
		SetKill();
	}

	
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		if (++t4 >= 180)
		SetKill();
	}

	if (++t2==123*60) {
		SetKill();
	}
}

