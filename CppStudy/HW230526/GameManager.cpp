
#include <Windows.h>
#include "GameManager.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"
#include "Bullet.h"

void GameManager::GamePlay()
{
    ConsoleScreen TmpScreen;
    Screen = &(TmpScreen);
    Screen->Init('-');

    Player TmpPlayer;
    MainPlayer = &(TmpPlayer);
    MainPlayer->SetPos({ 10, 5 });


    Bullet TmpBullet;
    PlayerBullet = &TmpBullet;



    Wall TmpWalls[10];
    for (int i = 0; i < 10; i++)
    {
        Walls[i] = &(TmpWalls[i]);
        Walls[i]->SetPos({ i+2,3 });
    }

    while (true)
    {
        Screen->Clear();

        //플레이어 스크린에 셋
        Screen->SetPixel(MainPlayer->GetPos(), 'a');

        //벽 스크린에 셋
        for (int i = 0; i < 10; i++)
        {
            if (Walls[i] == nullptr)
            {
                continue;
            }
            Screen->SetPixel(Walls[i]->GetPos(), 'O');
        }

        //총알 스크린에 셋
        if (Screen->IsScreenOut(PlayerBullet->GetPos() + Up))
        {
            PlayerBullet->SetShoot(false);
        }
        if (PlayerBullet->GetShoot() == true)
        {
            PlayerBullet->AddPos(Up);
            Screen->SetPixel(PlayerBullet->GetPos(), '*');
            BulletHit();
        }

        //전체 스크린 출력
        Screen->Print();


        if (0 != _kbhit())
        {
            Input();
            // 1000이면 1초입니다.
        }
        // 1초 동안 정지합니다.
        Sleep(100);
    }
}

bool GameManager::IsPlayerCollision(int4 _Direction)
{
    for (int i = 0; i < 10; i++)
    {
        if (Walls[i] == nullptr)
        {
            continue;
        }
        if (MainPlayer->GetPos()+ _Direction == Walls[i]->GetPos())
        {
            return true;
        }
    }
    return false;
}

void GameManager::BulletHit()
{
    for (int i = 0; i < 10; i++)
    {
        if (Walls[i] == nullptr)
        {
            continue;
        }
        if (PlayerBullet->GetPos() == Walls[i]->GetPos())
        {
            Walls[i] = nullptr;
            PlayerBullet->SetShoot(false);
            return;
        }
    }
}

void GameManager::Input()
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
        //이동
    case 'a':
        MovePos = Left;
        break;
    case 'd':
        MovePos = Right;
        break;
    case 'w':
        MovePos = Up;
        break;
    case 's':
        MovePos = Down;
        break;
    case ' ':
        //총알쏘기
        PlayerBullet->SetPos(MainPlayer->GetPos());
        PlayerBullet->SetShoot(true);
        break;
    default:
        break;
    }

    if (!(MovePos == int4{ 0, 0 }))
    {
        if (false == Screen->IsScreenOut(MainPlayer->GetPos() + MovePos))
        {
            if (false == IsPlayerCollision(MovePos))
            {
                MainPlayer->AddPos(MovePos);
            }
        }
    }


}
