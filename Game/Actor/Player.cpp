#include "Player.h"
#include "Actor/PlayerBullet.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Level/Level.h"

Player::Player()
	: super("<=A=>", Vector2::Zero, Color::Green)
{
	// Set position to create.
	int xPosition = (Engine::Get().GetWidth() / 2) - (width / 2);
	int yPosition = Engine::Get().GetHeight() - 2;
	SetPosition(Vector2(xPosition, yPosition));
}

Player::~Player()
{
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 종료 처리.
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		// 게임 종료.
		QuitGame();
	}

	// 좌우 방향키 입력처리.
	if (Input::Get().GetKey(VK_LEFT))
	{
		MoveLeft();
	}

	if (Input::Get().GetKey(VK_RIGHT))
	{
		MoveRight();
	}

	// Space->탄약 발사
	if(Input::Get().GetKeyDown(VK_SPACE))
	{
		Fire();
	}
}


void Player::MoveLeft()
{
	position.x -= 1;

	// 좌표 검사.
	if(position.x < 0)
	{
		position.x = 0;
	}
}


void Player::MoveRight()
{
	position.x += 1;

	if (position.x + width > Engine::Get().GetWidth())
	{
		position.x -=1;
	}
}

void Player::Fire()
{
	// Set new Actor's position.
	Vector2 bulletPosition(
		position.x + (width / 2),
		position.y
	);

	// Create Bullet.
	GetOwner()->AddNewActor(new PlayerBullet(bulletPosition));
}
