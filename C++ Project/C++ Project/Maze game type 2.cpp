//Jack Stylianou
//N0953814
//C++ Project
//My porject will be a game, a complex game, a thinking game and a game to break reality
//The Maze Game

#include <iostream>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

const int KEY_UP = 1;
const int KEY_DOWN = 2;
const int KEY_LEFT = 3;
const int KEY_RIGHT = 4;
using namespace std;


const char HEIGHT = 24, WIDTH = 24;
unsigned char maze[WIDTH][HEIGHT] =
{

    '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '_', '_', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#',
    '#', '_', '_', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#',
    '#', '_', '_', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#',
    '#', '_', '_', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#',
    '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#',
    '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '_', '_', '#', '#', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '#', '#', '#', '_', '_', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '_', '_', '_', '_', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '_', '_', '#', '#',

};


struct character
{
    int posX;
    int posY;
    char symbol;
    int hp;
}player;

struct enemies
{
    int posX;
    int posY;
    char enemy_symbol;
};

void player_hit()
{
    player.posX = 1;
    player.posY = 1;
    player.hp--;
}

void Clear() 
{
    system("CLS");
}

void InputHandle(int move, int playerX, int playerY)
{
    move = _getch();
    switch (move)
    {
    case KEY_UP:
            if (playerY - 1 >= 0)
            {
                if (maze[playerY - 1][playerX] != '#')
                {
                    playerY--;
                }
            }
        break;


    case KEY_DOWN:
            if (playerY + 1 <= 4)
            {
                if (maze[playerY + 1][playerX] != '#')
                {
                    playerY++;
                }

            }

        break;

    case KEY_RIGHT:
            if (playerX + 1 <= 4)
            {
                if (maze[playerY][playerX + 1] != '#')
                {
                    playerX++;
                }
            }
        break;

        case KEY_LEFT:
            if (playerX - 1 >= 0)
            {
                if (maze[playerY][playerX - 1] != '#')
                {
                    playerX--;
                }
            }
    }
 }

    void Display(int playerX, int playerY)
    {
         for (int i = 0; i < 5; i++)
        {
         for (int j = 0; j < 5; j++)
             {
             if (j == playerX && i == playerY)
             {  
                 cout << "M";
                 continue;
             }
                 cout << maze[i][j] << " ";
             }
                 cout << "\n";
         }
    }

//bool CheckWinCondition(int, int);

bool CheckWinCondition(int playerX, int playerY)                         
{
    if (playerX == 23 && playerY == 20)
    {
        return true;
    }
    return false; 
}

int main()
{

    enemies enemy_horizontal = { 10, 6, 'K' };       //bad guy one 
    enemies enemy_vertical = { 5, 6, 'K' };          //bad guy two
    enemies enemy_jump = { 7, 5, 'K' };              //bad guy three

   // const char HEIGHT = 24, WIDTH = 24;
    bool update = false;
    char move_key = 'd';

    player.posX = 0;                                               // 23x 20y   This is the end point. 
    player.posY = 1;                                               // 0x  1y    This is the xy to where you start
    player.symbol = 'M';    //This is You
    int movement;

    player.hp = 3;  //so the player or You only has three life lines.This will alos show on the screen.            

    // '#' = Walls
    // '_' = Paths


    for (int i = 0; i < 10; i++)
    {
        if (i == 4)
        {
            continue;
        }
        std::cout << "\b\b\b\b\b\b\b\b\b\b ____      ____      __                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_  _|    |_  _|    [  |                                                                                          << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  \ \  /\  / /.---.  | |  .---.   .--.   _ .--..--.  .---.                                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   \ \/  \/ // /__\\ | | / /'`\]/ .'`\ \[ `.-. .-. |/ /__\\                                                           << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b    \  /\  / | \__., | | | \__. | \__. | | | | | | || \__.,                                                            << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b     \/  \/   '.__.'[___]'.___.' '.__.' [___||__||__]'.__.'                                                         << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b           ________  __    ______    ___                 ________                                    << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b          |_   __  |[  | .' ___  | .'   `.              |_   __  |                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   _   _   __ | |_ \_| | |/ .'   \_|/  .-.  \ _ .--..--.    | |_ \_|                                                     << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b[ \ [ \ [  ]|  _| _  | || |       | |   | |[ `.-. .-. |   |  _| _                                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b \ \/\ \/ /_| |__/ | | |\ `.___.'\\  `-'  / | | | | | |  _| |__/ |                                                       << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  \__/\__/|________|[___]`.____ .' `.___.' [___||__||__]|________|                                                         << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b     _                                                                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b    / \                                                                                                                                            << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   / _ \     _ .--.  .---.                                                                                                                    << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  / ___ \   [ `/'`\]/ /__\\                                                                                                            << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b_/ /   \ \_  | |    | \__.,                                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|____| |____|[___]    '.__.'                                                                                                             << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b   ____         ________                                                                                                                                       << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b .' __ \       |_   __  |                                                                                                                                          << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b/ .'  \ | _ .--. | |_ \_|                                                                                                                    << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b| | (_/ |[ `/'`\]|  _| _                                                                                                           << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b\ `.__.'\ | |   _| |__/ |                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b `.___ .'[___] |________|                                                                                                           << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b ____  ____                                                                                                                                                    << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_  _||_  _|                                                                                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  \ \  / / .--.   __   _                                                                                                                   << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   \ \/ // .'`\ \[  | | |                                                                                                           << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   _|  |_| \__. | | \_/ |,                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  |______|'.__.'  '.__.'_/                                                                                                        << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b            ____   _____  _____                                                                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b         .'    '.|_   _||_   _|                                                                                                                                                      << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  _   __ |  .--.  | | |    | |                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b [ \ [  ]| |    | | | '    ' |                                                                                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b   \ '/ / |  `--'  |  \ \__/ /                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b [\_:  /   '.____.'    `.__.'                                                                                                           << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  \__.'                                                                                                                            << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b _______                        __                                                                                                                                                 << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_   __ \                      |  ]                                                                                                                                                                << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |__) |  .---.  ,--.    .--.| |   _   __                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  |  __ /  / /__\\`'_\ : / /'`\' |  [ \ [  ]                                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |  \ \_| \__.,// | |,| \__/  |   \ '/ /                                                                                                                << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|____| |___|'.__.'\'-;__/ '.__.;__][\_:  /                                                                                                            << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b                                    \__.'                                                                                                                            << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b         ______     ____   ______                                                                                                                                                     << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b       / ____ `. .' __ \ |_   _ `.                                                                                                                                                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _ .--. `'  __) |/ .'  \ |  | | `. \ _   __                                                                                                              << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b[ `/'`\]_  |__ '.| | (_/ |  | |  | |[ \ [  ]                                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |   | \____) |\ `.__.'\ _| |_.' / \ '/ /                                                                                                                << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b[___]   \______.' `.___ .'|______.'[\_:  /                                                                                                              << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b                                    \__.'                                                                                                                                 << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b         ______     ____   ______                                                                                                                                                    << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b       / ____ `. .' __ \ |_   _ `.                                                                                                                                                                          << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _ .--. `'  __) |/ .'  \ |  | | `. \ _   __                                                                                                             << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b[ `/'`\]_  |__ '.| | (_/ |  | |  | |[ \ [  ]                                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |   | \____) |\ `.__.'\ _| |_.' / \ '/ /                                                                                                                << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b[___]   \______.' `.___ .'|______.'[\_:  /                                                                                                              << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b                                    \__.'                                                                                                                               << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b  ____    ____                       _______                                                                                                                                                                                     << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b |_   \  /   _|                     |_   __ \                                                                                                                                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  |   \/   |   ,--.   ____  .---.    | |__) |  __   _   _ .--.   _ .--.  .---.  _ .--.                                                                                                          << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |\  /| |  `'_\ : [_   ]/ /__\\   |  __ /  [  | | | [ `.-. | [ `.-. |/ /__\\[ `/'`\]                                                                                                      << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _| |_\/_| |_ // | |, .' /_| \__.,  _| |  \ \_ | \_/ |, | | | |  | | | || \__., | |                                                                                                                 << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_____||_____|\'-;__/[_____]'.__.' |____| |___|'.__.'_/[___||__][___||__]'.__.'[___]                                                                                                               << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b ____    ____   ____          ______    _______             ____  _____           ________                                                                                                                                                                         << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_   \  /   _|.' __ \        / ____ `. |_   __ \           |_   \|_   _|         |_   __  |                                                                                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b |   \/   | / .'  \ | ____  `'  __) |   | |__) |  __   _    |   \ | |   _ .--.    | |_ \_| _ .--.                                                                                      << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |\  /| | | | (_/ |[_   ] _  |__ '.   |  __ /  [  | | |   | |\ \| |  [ `.-. |   |  _| _ [ `/'`\]                                                                                           << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _| |_\/_| |_\ `.__.'\ .' /_| \____) |  _| |  \ \_ | \_/ |, _| |_\   |_  | | | |  _| |__/ | | |                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _____||_____|`.___ .'[_____]\______.' |____| |___|'.__.'_/|_____|\____|[___||__]|________|[___]                                                                                                           << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b _____                          __   _                                                                                                                                                                               << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_   _|                        |  ] (_)                                                                                                                                                                                   << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |       .--.   ,--.    .--.| |  __   _ .--.   .--./)                                                                                     << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b  | |   _ / .'`\ \`'_\ : / /'`\' | [  | [ `.-. | / /'`\;                                                                                          << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b _| |__/ || \__. |// | |,| \__/  |  | |  | | | | \ \._//_                                                                                                  << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|________| '.__.' \'-;__/ '.__.;__][___][___||__].',__`(_)                                                                                                            << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b                                                 ( ( __))                                                                                                         << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b _____       ____      ____         __  _  ____  _____   ______                                                                                                                                                                               " << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_   _|    .'    '.  .' __ \       |  ]| ||_   \|_   _|.' ___  |                                                                                                                                                            " << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |     |  .--.  |/ .'  \ |  .--.| | | |  |   \ | | / .'   \_|                                                                                << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |   _ | |    | || | (_/ |/ /'`\' | | |  | |\ \| | | |   ____                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b_| |__/ ||  `--'  |\ `.__.'\| \__/  | |_| _| |_\   |_\ `.___]  |_  _                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|________| '.____.'  `.___ .' '.__.;__](_)|_____|\____|`._____.'(_)(_)                                                                                            << \n" << std::flush;
        Sleep(100);

        std::cout << "\b\b\b\b\b\b\b\b\b\b _____       ____      ____         __  _  ____  _____   ______                                                                                                                                                                               " << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|_   _|    .'    '.  .' __ \       |  ]| ||_   \|_   _|.' ___  |                                                                                                                                                            " << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |     |  .--.  |/ .'  \ |  .--.| | | |  |   \ | | / .'   \_|                                                                                 << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b | |   _ | |    | || | (_/ |/ /'`\' | | |  | |\ \| | | |   ____                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b_| |__/ ||  `--'  |\ `.__.'\| \__/  | |_| _| |_\   |_\ `.___]  |_  _                                                                                        << \n" << std::flush;
        std::cout << "\b\b\b\b\b\b\b\b\b\b|________| '.____.'  `.___ .' '.__.;__](_)|_____|\____|`._____.'(_)(_)(_)                                                                                         << \n" << std::flush;
        Sleep(200);

        cout << "Hello Maze Runner use [w], [a], [s], [d] to move around so that you can escape this maze. press any [w] or [a] or [s] or [d] and then press [enter] to start playing the MAZE GAME\n"; 
        cout << "presse (e) then return to exit the game\n";

    }

    while (move_key != 'x')
    {

        srand(time(NULL));
        int random_move = rand() % 2 + 1;

        cin >> move_key;
        update = true;

        if (update == true)
        {

            system("CLS");

            maze[enemy_horizontal.posX][enemy_horizontal.posY] = enemy_horizontal.enemy_symbol;
            maze[enemy_vertical.posX][enemy_vertical.posY] = enemy_vertical.enemy_symbol;
            maze[enemy_jump.posX][enemy_jump.posY] = enemy_jump.enemy_symbol;

            maze[player.posX][player.posY] = player.symbol;

            for (int y = 0; y < HEIGHT; y++)
            {
                cout << endl;
                for (int x = 0; x < WIDTH; x++)
                {
                    cout << maze[x][y];
                }
            }
            cout << endl << endl << "    your health Maze Runner. Maze Runner we just got readings on three hostile enemies. stay alert : " << player.hp << endl << "...    ...     ...     ..      ...     ...\n \n"; //this is when the player is hit
            update = false;
        }

        switch (move_key)
        {

        case 'w':
            update = true;
            if (maze[player.posX][player.posY - 1] != '#')
            {
                maze[player.posX][player.posY] = '_';
                player.posY--;

                if (maze[player.posX][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
                {
                    player_hit();
                }


                cout << player.posX << " " << player.posY << endl;
            }
            else
                cout << "  Maze Runner this is communication team 5, you just hit the wall, Over...";   //this is when the player is hit
            break;

        case 's':
            update = true;
            if (maze[player.posX][player.posY + 1] != '#')
            {
                maze[player.posX][player.posY] = '_';
                player.posY++;

                if (maze[player.posX][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
                {
                    player_hit();
                }


                cout << player.posX << " " << player.posY << endl;
            }
            else
                cout << "  Maze Runner this is communication team 5, you just hit the wall, Over...";     //this is when the player is hit
            break;

        case 'a':
            update = true;
            if (maze[player.posX - 1][player.posY] != '#')
            {
                maze[player.posX][player.posY] = '_';
                player.posX--;

                if (maze[player.posX][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
                {
                    player_hit();
                }


                cout << player.posX << " " << player.posY << endl;
            }
            else
                cout << " Maze Runner this is communcation team 5, you just hit the wall, Over...";     //this is when the player is hit

            break;

        case 'd':
            update = true;
            if (maze[player.posX + 1][player.posY] != '#')
            {
                maze[player.posX][player.posY] = '_';
                player.posX++;

                if (maze[player.posX][player.posY] == maze[enemy_horizontal.posX][enemy_horizontal.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_vertical.posX][enemy_vertical.posY] ||
                    maze[player.posX][player.posY] == maze[enemy_jump.posX][enemy_jump.posY])
                {
                    player_hit();
                }

                cout << player.posX << " " << player.posY << endl;
            }
            else
                cout << " Maze Runner this is communication team 5, you just hit the wall, Over..."; //this is when the player is hit
            break;
        }


        if (player.hp == 0)
        {
            move_key = 'x';
            cout << " This is communication team 5, We have lost all communications to Maze Runner, Maze Runner is KIA, Over... \n";
            cout << "  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______          \n";
            cout << " /  _____|    /   \     |   \/   | |   ____|    /  __  \  \   \  /   / |   ____||   _  \               \n";
            cout << " |  |  __     /  ^  \    |  \  /  | |  |__      |  |  |  |  \   \/   /  |  |__   |  |_)  |              \n";
            cout << " |  | |_ |   /  /_\  \   |  |\/|  | |   __|     |  |  |  |   \      /   |   __|  |      /               \n";
            cout << " |  |__| |  /  _____  \  |  |  |  | |  |____    |  `--'  |    \    /    |  |____ |  |\  \----.        \n";
            cout << "  \______| /__/     \__\ |__|  |__| |_______|    \______/      \__/     |_______|| _| `._____|      \n";
        }

        int playerposX = 1;
        int playerposY = 0;
        int movement;

        while (!CheckWinCondition(player.posX, player.posY))
        {
            Display(player.posX, player.posY);
            InputHandle(movement, player.posX, player.posY);
            Clear();
        }

        //23x & 20y This is the end point  // if (player.posY == 17)
        //player.posX, player.posY
        //(CheckWinCondition

        cout << "Maze Runner this is communication team 5, You have escaped, send your location and we'ell get you out of there, Over...\n";
        cout << "   ---------------+---------------                                   \n";
        cout << "            ___ /^^[___                                  \n";
        cout << "            /|^+----+   |#___________//                                     \n";
        cout << "          ( -+ |____|    ______-----+/                                     \n";
        cout << "             ==_________--'                                     \n";
        cout << "               ~_|___|__                       \n";


    }
    return 0;
}
