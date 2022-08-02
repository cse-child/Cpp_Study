#include "Framework.h"

int main()
{
	enum GameState
	{
		MENU,
		PLAY
	}gameState = MENU;

	GameManager* gameManager = new GameManager();

	while(true)
	{
		switch (gameState)
		{
		case MENU:
			gameManager->SelectMenu();
			gameState = PLAY;
			break;
		case PLAY:
			gameManager->GamePlay();
			gameState = MENU;
			break;
		}
	}
}
