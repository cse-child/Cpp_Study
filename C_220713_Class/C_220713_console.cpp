#include "Framework.h"
// 주석 색깔입니다.
int main()
{
    enum GameState
    {
        MENU, PLAY, END
    }gameState = MENU;

    GameManager* gm = new GameManager();
    
    do {
        switch (gameState)
        {
        case MENU:
            gm->SelectMenu();
            gameState = PLAY;
            break;
        case PLAY:
            gm->GamePlay();
            gameState = MENU;
            break;
        }
    } while (!gm->IsGameOver());

    cout << "Game Over!" << endl;

    return 0;
}

