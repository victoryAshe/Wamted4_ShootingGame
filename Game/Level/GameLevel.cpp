#include "GameLevel.h"
#include "Actor/Player.h"

GameLevel::GameLevel()
{
	// Add Player Actor.
	AddNewActor(new Player());
}

GameLevel::~GameLevel()
{
}
