#include "Player.h"
#include "Core/Input.h"
#include "Engine/Engine.h"

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

	// 좌우 방향키 입력처리.
	if (Input::Get().GetKey(VK_LEFT))
	{
		MoveLeft();
	}

	if (Input::Get().GetKey(VK_RIGHT))
	{
		MoveRight();
	}
}


void Player::MoveLeft()
{
	Vector2 position = GetPosition();
	position.x -= 1;

	// 좌표 검사.
	if(position.x < 0)
	{
		position.x = 0;
	}
}


void Player::MoveRight()
{
	Vector2 position = GetPosition();
	position.x += 1;

	if (position.x + width > Engine::Get().GetWidth())
	{
		position.x -=1;
	}
}
