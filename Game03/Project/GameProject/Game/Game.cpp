#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"
#include "Goal.h"
#include"Boy.h"
#include"UI.h"
#include"Hametu.h"
#include"GameData.h"
#include"RBoy.h"
#include"../Title/GameOver.h"
#include"../Title/Gameclear.h"

Game::Game():Base(eType_Scene)
{
	
	//Base::Add(new Map());
	
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(1080, 600), false));
	Base::Add(new Boy(CVector2D(900 + 400 * 1, 540), false));
	Base::Add(new Boy(CVector2D(900 + 400 * 2, 540), false));
	Base::Add(new Boy(CVector2D(900 + 400 * 3, 540), false));
	Base::Add(new RBoy(CVector2D(1000 + 400 * 1, 540), false));
	Base::Add(new RBoy(CVector2D(1000 + 400 * 2, 540), false));
	Base::Add(new RBoy(CVector2D(1000 + 400 * 3, 540), false));

	Base::Add(new Goal(CVector2D(2048, 540 - 32)));
	Base::Add(new UI());
	

}

Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	//ゴールが無ければゲームシーン終了
	if (!Base::FindObject(eType_Goal)) {

		//Base::Add(new GameClear);
		//return 
	}

	
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//Base::Add(new GameOver);
	}

	if (++t2==122*60) {
		//Base::Add(new GameOver);
	}
}

