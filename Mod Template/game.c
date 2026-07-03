#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char* map1[] = {
    ".............\n",
	".............\n",
	".............\n",
	".............\n",
	"......OI!....\n",
	".............\n",
	".............\n",
	".........EXIT\n",
	NULL
};
int map1_len = sizeof(map1) / sizeof(map1[0]);

bool is_OI_d = false;
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
    printf("\033[3;21HYou got Consumed by OI!");
    Sleep(2900);
    exit(0);
}

void win() {
    clear();
    printf("You successfully escaped the OI room!");
    Sleep(3000);
    exit(0);
}


void Game() {
    x = 2;
    y = 2;
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
        if (y <= map1_len) {
			clear(); y += 1; gotoXY(x, y); printf("P"); break;
		}
		if (y >= map1_len) {
			clear(); y -= 1; gotoXY(x, y); printf("P"); break;
		}
		if (x <= 0) {
			clear(); x += 1; gotoXY(x, y); printf("P"); break;
		}
		if (x >= 14) {
			clear(); x -= 1; gotoXY(x, y); printf("P"); break;
		}
    }
}