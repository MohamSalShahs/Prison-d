#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char* map1[] = {
    "\033[31m()\033[0m....O..:\n",
    "[]....U..:\n",
    ".........;\n",
    ".........:\n",
    ".........:\n",
	NULL
};
int map1_len = sizeof(map1) / sizeof(map1[0]);

char* map2[] = {
    "....\033[31m____\033[0m........\n",
    "........\033[31m|\033[0m....\033[31m|\033[0m..\n",
    "....\033[31m____|____|\033[0m..\n",
    "...\033[31m|\033[0m....\033[31m|\033[0m.......\n",
    "...\033[31m|\033[0m....\033[31m|____\033[0m...\n",
    "................\n",
    "................\n",
	NULL
};
int map2_len = sizeof(map2) / sizeof(map2[0]);

char* map3[] = {
    "|..G:\033[31m__\033[0m...:R..|\n",
    "|..Y:\033[34mE\033[0m\033[31m \\\033[0m..:N..|\n",
    "|..\033[31mX\033[0m:\033[31m__/\033[0m..:V..|\n",
    "|..\033[31mX\033[0m:.....:\033[31mX\033[0m..|\n",
    "|..T:.....:B..|\n",
    "|..A:.....:\033[31mX\033[0m..|\n",
	NULL
};
int map3_len = sizeof(map3) / sizeof(map3[0]);

char* map4[] = {
    "....................\n",
    "....................\n",
    "....................\n",
    "....................\n",
    ".....__________.....\n",
    "....|...\033[32mEXIT\033[0m...|....\n",
    "....|__________|....\n",
    ".......|....|.......\n",
	NULL
};
int map4_len = sizeof(map4) / sizeof(map4[0]);

char* map5[] = {
    "._._._._._._._._._._._._.\n",
    "|_|_|_|_|_|_|_|_|_|_|_|_|\n",
    "|_|_|_|_|_|_|_|_|_|_|_|_|\n",
    "|_|_|_|_|_|_|_|_|_|_|_|_|\n",
    ".......................__\n",
    "..............%..@..#./DM\n",
    ".............\033[31m)\033[0m.__..'..|PS\n",
    ".............\033[31m\\\033[0m.....O..\\TR\n",
    ".................\033[31m___\033[0m.....\n",
    "................\033[31m/\033[0m.\033[34mE\033[0m.\033[31m\\\033[0m....\n",
    "................\033[31m\\\033[0m...\033[31m/\033[0m....\n",
	NULL
};
int map5_len = sizeof(map5) / sizeof(map5[0]);

char* map6[] = {
    "....................\n",
    "....................\n",
    ".............__.....\n",
    "............|GP|....\n",
    "............|__|....\n",
    "....................\n",
	NULL
};
int map6_len = sizeof(map6) / sizeof(map6[0]);

char* map7[] = {
    " _______________________\n",
    "|_______________________|\n",
    "\033[42;30m  _      -  __           \n",
    "  ___--        _-    --  \033[0m\n",
    "\033[42;37m _______________________ \033[0m\n",
    "|........................\n",
	NULL
};
int map7_len = sizeof(map7) / sizeof(map7[0]);

char* map8[] = {
    "\033[30;30m _______________________\n",
    "|_______________________|\n",
    "  _      -  __           \n",
    "  ___--        _-    --  \n",
    " _______________________ \n",
    "|..........\033[0m-(\033[30;30m.............\033[0m\n",
	NULL
};
int map8_len = sizeof(map8) / sizeof(map8[0]);

char* map9[] = {
    " _______________________\n",
    "|_____________________\033[37m|-|\033[0m\n",
    "\033[42;30m  _      -            \033[37m|-|\033[0m\n",
    "  ___--        _-    -\033[37m|-|\033[0m\n",
    "\033[42;37m ____________________ \033[37m|-|\033[0m\n",
    "|.....................|-|\n",
	NULL
};
int map9_len = sizeof(map9) / sizeof(map9[0]);

char* map10[] = {
    "...........\033[31m|\033[0m.C.\033[31m|\033[0m......\n",
    ".......\033[31m_\033[0m....\033[31m\\_/\033[0m.......\n",
    "......\033[31m/\033[0m.\033[31m\\\033[0m.............\n",
    ".....\033[31m|\033[0m.C.\033[31m|\033[0m............\n",
	NULL
};
int map10_len = sizeof(map10) / sizeof(map10[0]);

char* map11[] = {
    ".........._______________________...\n",
    ".........|..Herrmingrein.Street..|..\n",
    ".........|_______________________|..\n",
    ".....................|..............\n",
    ".....................|..............\n",
	NULL
};
int map11_len = sizeof(map11) / sizeof(map11[0]);

char* map12[] = {
    "...................\n",
    "-------------------\n",
    "           ______  \n",
    "         _/__|___|= \n",
    "          ()   ()   \n",
	NULL
};
int map12_len = sizeof(map12) / sizeof(map12[0]);

bool picklock_aq = false;
bool is_outside_cell = false;
bool holding_crowbar = false;
bool holding_flashlight = false;
int x = 3;
int y = 2;

void gotoXY(int x, int y) {
	printf("\033[%d;%dH", y, x);
}
void drawMap(char* map[]) {
	int i = 0;
	while (map[i] != NULL) {
		printf("%s", map[i]);
		i++;
	}
}
void clear() {
	printf("\033[2J\033[H");
}

void lose() {
	clear();
    printf("\033[3;21HYou Lose!");
    Sleep(2900);
    exit(0);
}

void win() {
    clear();
    printf("You successfully escaped the prison!");
    Sleep(3000);
    exit(0);
}

void goToMap12() {
    x = 2;
    y = 2;
    while (1) {
        clear();
        drawMap(map12);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 6: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 9) {
            win();
        }
    }
}

void goToMap11() {
    x = 2;
    y = 2;
    while (1) {
        clear();
        drawMap(map11);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 6: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 37) {
            goToMap12();
        }
    }
}

void goToMap10() {
    x = 2;
    y = 2;
    while (1) {
        clear();
        drawMap(map10);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 5: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 8 && y == 2) lose();
        if (x == 7 && y == 3) lose();
        if (x == 9 && y == 3) lose();
        if (x == 6 && y == 4) lose();
        if (x == 10 && y == 4) lose();
        if (x == 12 && y == 1) lose();
        if (x == 13 && y == 2) lose();
        if (x == 14 && y == 2) lose();
        if (x == 15 && y == 2) lose();
        if (x == 16 && y == 1) lose();
        if (x == 23) {
            goToMap11();
        }
    }
}

void goToMap9() {
    holding_flashlight = false;
    x = 2;
    y = 6;
    while (1) {
        clear();
        drawMap(map9);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 12: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 5: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 7: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 24 && y == 6) {
            goToMap10();
        }
    }
}

void goToMap8_flashlight() {
    x = 13;
    y = 6;
    while (1) {
        clear();
        drawMap(map8);
        printf("\033[%d;%dHP\033[47;30m..\033[0m", y, x);
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 12: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 5: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 7: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 25 && y == 6) {
            goToMap9();
        }
    }
}

void goToMap8() {
    x = 2;
    y = 6;
    while (1) {
        clear();
        drawMap(map8);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 5: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 7: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 12 && y == 6 && holding_flashlight == false) {
            holding_flashlight = true;
            clear();
            printf("Grabbed a flashlight");
            Sleep(2000);
        }
        if (holding_flashlight == true) {
            goToMap8_flashlight();
        }
    }
}

void goToMap7() {
    holding_crowbar = false;
    x = 2;
    y = 6;
    while (1) {
        clear();
        drawMap(map7);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 5: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 7: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 25) {
            goToMap8();
        }
    }
}

void goToMap6() {
    x = 10;
    y = 1;
    while (1) {
        clear();
        drawMap(map6);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 21: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 7: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 14 && y == 3 && holding_crowbar == true) goToMap7();
        if (x == 15 && y == 3 && holding_crowbar == true) goToMap7();
        if (x == 13 && y == 4 && holding_crowbar == true) goToMap7();
        if (x == 16 && y == 4 && holding_crowbar == true) goToMap7();
        if (x == 13 && y == 5 && holding_crowbar == true) goToMap7();
        if (x == 14 && y == 5 && holding_crowbar == true) goToMap7();
        if (x == 15 && y == 5 && holding_crowbar == true) goToMap7();
        if (x == 16 && y == 5 && holding_crowbar == true) goToMap7();
		
        if (x == 14 && y == 3 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 15 && y == 3 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 13 && y == 4 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 16 && y == 4 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 13 && y == 5 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 14 && y == 5 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 15 && y == 5 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
        if (x == 16 && y == 5 && holding_crowbar == false) { clear(); printf("You didn't get the crowbar!"); Sleep(2500); lose(); }
    }
}

void goToMap5() {
    x = 1;
    y = 6;
    while (1) {
        clear();
        drawMap(map5);
        gotoXY(x, y); printf("P");
        printf("\033[16;4HX: %d\033[17;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 26: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 4: clear(); y += 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 18 && y == 9) lose();
        if (x == 18 && y == 9) lose();
        if (x == 20 && y == 9) lose();
        if (x == 17 && y == 10) lose();
        if (x == 17 && y == 11) lose();
        if (x == 21 && y == 11) lose();
        if (y == 12) {
            goToMap6();
        }
        if (x == 14 && y == 7 && holding_crowbar == false) {
            holding_crowbar = true;
            clear();
            printf("Grabbed a crowbar");
            Sleep(2500);
        }
    }
}

void goToMap4() {
    x = 10;
    y = 1;
    while (1) {
        clear();
        drawMap(map4);
        gotoXY(x, y); printf("P");
        printf("\033[12;4HX: %d\033[13;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 21: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
        }
        if (y == 8) {
            goToMap5();
        }
    }
}

void goToMap3() {
    x = 8;
    y = 1;
    while (1) {
        clear();
        drawMap(map3);
        gotoXY(x, y); printf("P");
        printf("\033[12;4HX: %d\033[13;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 5: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 11: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 6 && y == 1 || x == 7 && y == 1 && is_outside_cell == true) lose();
        if (x == 8 && y == 2 && is_outside_cell == true) lose();
        if (x == 8 && y == 3 && is_outside_cell == true || x == 7 && y == 3 && is_outside_cell == true || x == 6 && y == 3 && is_outside_cell == true) lose();
        if (y == 6 && is_outside_cell == true) {
            goToMap4();
        }
    }
}

void goToMap2() {
    x = 2;
    y = 3;
    while (1) {
        clear();
        drawMap(map2);
        gotoXY(x, y); printf("P");
        printf("\033[12;4HX: %d\033[13;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 17: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
        }
        if (y == 8) {
            goToMap3();
        }
    }
}

void Game() {
    x = 1;
    y = 3;
    while (1) {
        clear();
        drawMap(map1);
        gotoXY(x, y); printf("P");
        printf("\033[12;4HX: %d\033[13;4HY: %d", x, y);
        
        int input = getch();
        
        switch (input) {
            case 72: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
            case 80: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 75: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
            case 77: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 27: system("mode con: cols=120 lines=30 && title Command Prompt"); exit(0); break;
        }
        switch (x) {
            case 0: clear(); x += 1; gotoXY(x, y); printf("P"); break;
            case 11: clear(); x -= 1; gotoXY(x, y); printf("P"); break;
        }
        switch (y) {
            case 0: clear(); y += 1; gotoXY(x, y); printf("P"); break;
            case 6: clear(); y -= 1; gotoXY(x, y); printf("P"); break;
        }
        if (x == 10 && y == 3 && picklock_aq == false) {
            printf("\033[2J\033[H\033[14;4HThe door is locked. Find something to open the door.");
            Sleep(2500);
        }
        if (x == 7 && y == 1 && picklock_aq == false) {
            picklock_aq = true;
            if (picklock_aq == true) {
                clear();
                printf("\033[14;4HPicklock Aquired!");
                Sleep(1000);
            }
        }
        if (x == 9 && y == 3 && picklock_aq == true && is_outside_cell == false) {
            is_outside_cell = true;
            if (is_outside_cell == true) {
                goToMap2();
            }
        }
    }
}