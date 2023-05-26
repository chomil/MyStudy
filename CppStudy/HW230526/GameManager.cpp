
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

        //�÷��̾� ��ũ���� ��
        Screen->SetPixel(MainPlayer->GetPos(), 'a');

        //�� ��ũ���� ��
        for (int i = 0; i < 10; i++)
        {
            if (Walls[i] == nullptr)
            {
                continue;
            }
            Screen->SetPixel(Walls[i]->GetPos(), 'O');
        }

        //�Ѿ� ��ũ���� ��
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

        //��ü ��ũ�� ���
        Screen->Print();


        if (0 != _kbhit())
        {
            Input();
            // 1000�̸� 1���Դϴ�.
        }
        // 1�� ���� �����մϴ�.
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
        //�̵�
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
        //�Ѿ˽��
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
