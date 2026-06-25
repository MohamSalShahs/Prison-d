#include <stdio.h>
#include <windows.h>

void Game();

int main() {
    system("mode con: cols=60 lines=30 && title Prison'd");
    printf("\033[4;24H\033[33mPri \033[0mson \033[33m'd\033[0m");
    Sleep(1500);
    printf("\033[2J\033[H");
    Game();
}