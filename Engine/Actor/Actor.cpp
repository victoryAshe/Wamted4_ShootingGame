#include "Actor.h"
#include "Util/Util.h"
#include "Render/Renderer.h"

#include <iostream>
#include <Windows.h>

namespace Wanted
{
	Actor::Actor(const char* image, 
		const Vector2& position,
		Color color)
		: position(position), color(color)
	{
		// copy string.
		width = static_cast<int>(strlen(image));
		this->image = new char[width + 1];
		strcpy_s(this->image, width + 1, image);
	}

	Actor::~Actor()
	{
		// Free memory.
		SafeDeleteArray(image);
	}

	void Actor::BeginPlay() 
	{
		// Event 받은 후에는 flag 설정.
		hasBeganPlay = true;
	}

	void Actor:: Tick(float deltaTime)
	{
	}

	void Actor:: Draw()
	{
		// Renderer에 그리기 요청.
		//Renderer::Draw(position, color, image);

		// Renderer에 Data 제출.
		Renderer::Get().Submit(image, position, color, sortingOrder);
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		// Renderer에 빈칸 그리기 요청.
		//Renderer::Draw(position, ' ');
		
		// 변경하려는 위치가 현재 위치와 같으면 건너뜀.
		if(position == newPosition)
		{
			return;
		}

		// 새로운 위치 설정.
		position = newPosition;
	}
}