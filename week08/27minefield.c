#include <stdio.h>
#include "matrix.c"

#define MAX_BOMBS 30

#define TOP_LEFT [i-1][j-1]
#define TOP [i-1][j]
#define TOP_RIGTH [i-1][j+1]
#define LEFT [i][j-1]
#define CENTER [i][j]
#define RIGHT [i][j+1]
#define BOTTOM_LEFT [i+1][j-1]
#define BOTTOM [i+1][j]
#define BOTTOM_RIGHT [i+1][j+1]

void populateBoard(int m[ROWS][COLUMNS]){
    int i, j;
    int bombs = MAX_BOMBS;
    srand(time(NULL)+(time_t)m);
    while(bombs){
        i = rand() % ROWS;
        j = rand() % COLUMNS;
        m[i][j] = 1;
        bombs--;
    }
}

void printBoard(char m[ROWS][COLUMNS]){
    int i, j;
    printf("        ");
    for(j = 0; j < COLUMNS; j++){
        printf("%02d  ", j+1);
    }
    printf("\n\n");
    for(i = 0; i < ROWS; i++){
        printf("%02d   ", i+1);
        
        for(j = 0; j < COLUMNS; j++){
            printf("%4c", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void showNeareast(int board[ROWS][COLUMNS], char visible_board[ROWS][COLUMNS], int y, int x){
    int count = 0;
    char n_nearest[2];
    int i, j;

    if(board[y][x]){
        visible_board[y][x] = 'B';
    } else{
        for(i = y-1; i < y+2; i++){
            for(j = x-1; j < x + 2; j++){
                if(i > 0 && i < ROWS && j > 0 && j < COLUMNS){
                    if(board[i][j]){
                        count ++;
                    }
                }
            }
        }
        sprintf(n_nearest, "%d", count);
        visible_board[y][x] = n_nearest[0];
    }

    printBoard(visible_board);
    

}

void updateGame(int board[ROWS][COLUMNS]){
    int buffer = -1;
    int i, j;
    int play = 1;
    int count_avaible_cells = 0;
    char visible_board[ROWS][COLUMNS] = {0};
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            visible_board[i][j] = '#';
        }
    }
    while(play){
        while(buffer < 1 || buffer > ROWS){
            printf("Enter the row to play: ");
            scanf("%d", &buffer);
            if(buffer < 1 || buffer > ROWS){
                printf("Enter a value between(including) 1 and %d!\n", ROWS);
            }        
        }
        i = buffer - 1;
        buffer = -1;

        while(buffer < 1 || buffer > COLUMNS){
            printf("Enter the column to play: ");
            scanf("%d", &buffer);
            if(buffer < 1 || buffer > COLUMNS){
                printf("Enter a value between(including) 1 and %d!\n", COLUMNS);
            }
        }
        j = buffer-1;
        buffer = -1;
        

        showNeareast(board, visible_board, i, j);

        if(board[i][j]){
            puts("Game Over!");
            play = 0;
        } else{
            for(i = 0; i < ROWS; i ++){
                for(j = 0; j < COLUMNS; j++){
                    if(!board[i][j]){
                        count_avaible_cells++;
                    }
                }
            }
            if(!count_avaible_cells){
                puts("Congratulations! You Won!");
            } else{
                puts("Not a bomb, proceed!");
            }
        }
    }
}

int main(){
    int board[ROWS][COLUMNS] = {0};
    populateBoard(board);

    printMatrix(board);
    updateGame(board);

    return 0;
}