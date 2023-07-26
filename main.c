//  welcome to
//  main.c
//  cgame
//
//  by Kadeluxe, 16/04/2018
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <time.h>

static struct termios stored;

void init(void);
void clearConsole(void);
void redrawing(int, int, int, int, int);
void reset(void);
int catchCheck();
 
int main() {
    srand(time(NULL));
    
    int point = 0;
    int * pPoint = &point;
    
    int xE = rand() % 6 + 1;
    short * pXE = &xE;
    int yE = rand() % 6 + 1;
    short * pYE = &yE;
    
    short x = 1, y = 1;
    short * pX = &x, * pY = &y;
    
    char ch;
    
    init();
    
    clearConsole();
    

    printf("START | ");
    redrawing(*pX, *pY, *pXE, *pYE, *pPoint);

    
    while ((ch = getc(stdin)) != 'q') {
        switch (ch) {
            case 'w':
                if (*pY != 1) *pY = *pY - 1;
                clearConsole();
                if (catchCheck(*pX, *pY, *pXE, *pYE) == 0) {
                    *pPoint = *pPoint + 1;
                    *pXE = rand() % 6 + 1;
                    *pYE = rand() % 6 + 1;
                }
                printf("\nTOP | ");
                redrawing(*pX, *pY, *pXE, *pYE, *pPoint);
                break;
            case 's':
                if (*pY != 6) *pY = *pY + 1;
                clearConsole();
                if (catchCheck(*pX, *pY, *pXE, *pYE) == 0) {
                    *pPoint = *pPoint + 1;
                    *pXE = rand() % 6 + 1;
                    *pYE = rand() % 6 + 1;
                }
                printf("\nBOTTOM | ");
                redrawing(*pX, *pY, *pXE, *pYE, *pPoint);
                break;
            case 'a':
                if (x != 1) *pX = *pX - 1;
                clearConsole();
                if (catchCheck(*pX, *pY, *pXE, *pYE) == 0) {
                    *pPoint = *pPoint + 1;
                    *pXE = rand() % 6 + 1;
                    *pYE = rand() % 6 + 1;
                }
                printf("\nLEFT | ");
                redrawing(*pX, *pY, *pXE, *pYE, *pPoint);
                break;
            case 'd':
                if (x != 6) *pX = *pX + 1;
                clearConsole();
                if (catchCheck(*pX, *pY, *pXE, *pYE) == 0) {
                    *pPoint = *pPoint + 1;
                    *pXE = rand() % 6 + 1;
                    *pYE = rand() % 6 + 1;
                }
                printf("\nRIGHT | ");
                redrawing(*pX, *pY, *pXE, *pYE, *pPoint);
                break;
            default:
                clearConsole();
                printf("\nERROR\n");
                redrawing(*pX, *pY, *pXE, *pYE, *pPoint);
        }
    }
    reset();
    clearConsole();
    clearConsole();
    return 0;
}
void x2Draw(x2) {
    if (x2 == 1) {
        printf("&#####\n");
    } else if (x2 == 2) {
        printf("#&####\n");
    } else if (x2 == 3) {
        printf("##&###\n");
    } else if (x2 == 4) {
        printf("###&##\n");
    } else if (x2 == 5) {
        printf("####&#\n");
    } else if (x2 == 6) {
        printf("#####&\n");
    }
}
void redrawing(x1, y1, x2, y2, point) {
    
    // info
    if (point == 10 || point == 15 || point == 20 || point == 25) {
        printf("Points: %d🎉\n", point);
    } else {
        printf("Points: %d\n", point);
    }
    printf("Coordinates: x: %d, y: %d \n", x1, y1);
    printf("Coordinates Enemy: x: %d, y: %d \n", x2, y2);
    
    // ^ info
    // y
    if (y1 == 2) {
        if (y2 == 1) {
            x2Draw(x2);
        } else {
            printf("######\n");
        }
    } else if (y1 == 3) {

        if (y2 == 1) {
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 2) {
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 4) {
        if (y2 == 1) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 2) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 3) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 5) {
        if (y2 == 1) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 2) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 3) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 4) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 6) {
        if (y2 == 1) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 2) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 3) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 4) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 5) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    }
    // ^ y
    // x
    if (y1 == y2) {
        if (x1 == 1) {
            if (x2 == 1) {
                printf("0#####\n");
            } else if (x2 == 2) {
                printf("0&####\n");
            } else if (x2 == 3) {
                printf("0#&###\n");
            } else if (x2 == 4) {
                printf("0##&##\n");
            } else if (x2 == 5) {
                printf("0###&#\n");
            } else if (x2 == 6) {
                printf("0####&\n");
            }
        } else if (x1 == 2) {
            if (x2 == 1) {
                printf("&0####\n");
            } else if (x2 == 2) {
                printf("#0####\n");
            } else if (x2 == 3) {
                printf("#0&###\n");
            } else if (x2 == 4) {
                printf("#0#&##\n");
            } else if (x2 == 5) {
                printf("#0##&#\n");
            } else if (x2 == 6) {
                printf("#0###&\n");
            }
        } else if (x1 == 3) {
            if (x2 == 1) {
                printf("&#0###\n");
            } else if (x2 == 2) {
                printf("#&0###\n");
            } else if (x2 == 3) {
                printf("##0###\n");
            } else if (x2 == 4) {
                printf("##0&##\n");
            } else if (x2 == 5) {
                printf("##0#&#\n");
            } else if (x2 == 6) {
                printf("##0##&\n");
            }
        } else if (x1 == 4) {
            if (x2 == 1) {
                printf("&##0##\n");
            } else if (x2 == 2) {
                printf("#&#0##\n");
            } else if (x2 == 3) {
                printf("##&0##\n");
            } else if (x2 == 4) {
                printf("###0##\n");
            } else if (x2 == 5) {
                printf("###0&#\n");
            } else if (x2 == 6) {
                printf("###0#&\n");
            }
        } else if (x1 == 5) {
            if (x2 == 1) {
                printf("&###0#\n");
            } else if (x2 == 2) {
                printf("#&##0#\n");
            } else if (x2 == 3) {
                printf("##&#0#\n");
            } else if (x2 == 4) {
                printf("###&0#\n");
            } else if (x2 == 5) {
                printf("####0#\n");
            } else if (x2 == 6) {
                printf("####0&\n");
            }
        } else if (x1 == 6) {
            if (x2 == 1) {
                printf("&####0\n");
            } else if (x2 == 2) {
                printf("#&###0\n");
            } else if (x2 == 3) {
                printf("##&##0\n");
            } else if (x2 == 4) {
                printf("###&#0\n");
            } else if (x2 == 5) {
                printf("####&0\n");
            } else if (x2 == 6) {
                printf("#####0\n");
            }
        }
    } else {
        if (x1 == 1) {
            printf("0#####\n");
        } else if (x1 == 2) {
            printf("#0####\n");
        } else if (x1 == 3) {
            printf("##0###\n");
        } else if (x1 == 4) {
            printf("###0##\n");
        } else if (x1 == 5) {
            printf("####0#\n");
        } else if (x1 == 6) {
            printf("#####0\n");
        }
    }
    // ^ x
    // y
    if (y1 == 1) {
        if (y2 == 2) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 3) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 4) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 5) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 6) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 2) {
        if (y2 == 3) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
            printf("######\n");
        } else if (y2 == 4) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 5) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 6) {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 3) {
        if (y2 == 4) {
            x2Draw(x2);
            printf("######\n");
            printf("######\n");
        } else if (y2 == 5) {
            printf("######\n");
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 6) {
            printf("######\n");
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 4) {
        if (y2 == 5) {
            x2Draw(x2);
            printf("######\n");
        } else if (y2 == 6) {
            printf("######\n");
            x2Draw(x2);
        } else {
            printf("######\n");
            printf("######\n");
        }
    } else if (y1 == 5) {
        if (y2 == 6) {
            x2Draw(x2);
        } else {
            printf("######\n");
        }
    }
}

int catchCheck(x1, y1, x2, y2) {
    if (x1 == x2 && y1 == y2) {
        printf("CATCH! 😄");
        return 0;
    }
    return 1;
}

void clearConsole() {
    printf("\n\n\n\n\n\n\n\n\n\n");
}

void init() {
    struct termios settings;
 
    tcgetattr(0, &stored);
 
    settings = stored;
 
    settings.c_lflag &= (~ICANON);
    settings.c_lflag &= (~ECHO);
    settings.c_cc[VTIME] = 0;
    settings.c_cc[VMIN] = 1;
 
    tcsetattr(0, TCSANOW, &settings);
}
void reset() {
    tcsetattr(0, TCSANOW, &stored);
}
