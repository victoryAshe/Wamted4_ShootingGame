#include "GameLevel.h"
#include "Actor/Player.h"
#include "Actor/EnemySpawner.h"

GameLevel::GameLevel()
{
	// Add Player Actor.
	AddNewActor(new Player());

	// Add Enemy Spawner.
	AddNewActor(new EnemySpawner());
}

GameLevel::~GameLevel()
{
}
