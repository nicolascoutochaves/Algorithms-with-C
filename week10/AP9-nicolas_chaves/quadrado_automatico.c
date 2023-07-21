/*
Esse programa movimenta um quadrado usando funcoes ate que o quadrado atinja a borda da tela
*/
#include "raylib.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define LARGURA 800
#define ALTURA 600
#define LADO 20
#define N_ENEMIES 1


void spawn_player(int ax, int ay){
    DrawRectangle(ax, ay, LADO, LADO, GREEN);
}
void inputs(int *dax, int *day){
//Define as direcoes dx e dy:

    if (IsKeyDown(KEY_D))
        *dax = 1;

    if (IsKeyDown(KEY_A))
        *dax = -1;

    if (IsKeyDown(KEY_W))
        *day = 1;

    if (IsKeyDown(KEY_S))
        *day = -1;

}
int deveMover(int ax, int ay, int dax, int day, int larg, int alt){
    int deve_mover = 1;
    if((ax == 0 && dax == -1) || (ax == LARGURA - LADO && dax == 1)) deve_mover = 0;
    else if((ay == 0 && day == 1) || (ay == ALTURA - LADO && day == -1)) deve_mover = 0;
    return deve_mover;
} 
void move(int dx, int dy, int *x, int *y){

    if(dx > 0){
        *x += LADO; //Move para direita
    }
    if(dx < 0){
        *x -= LADO; //Move para esquerda
    }
    if(dy > 0){
        *y -= LADO; //Move para cima
    }
    if(dy < 0){
        *y += LADO; //Move para baixo
    }
}
void spawn_enemie(int bx, int by, int count_enemies){
    while(count_enemies < N_ENEMIES){
        DrawRectangle(bx, by, LADO, LADO, RED);
        count_enemies++;
    }     
}


void move_inimigo(int dbx, int dby, int *bx, int *by){

        if(dbx > 0){
            *bx += LADO; //Move para direita
        }
        else if(dbx < 0){
            *bx -= LADO; //Move para esquerda
        }
        else if(dby > 0){
            *by -= LADO; //Move para cima
        }
        else if(dby < 0){
            *by += LADO; //Move para baiaxo
        }
    
     
   
}

int main(){
    int ax, ay, dax = 0, day = 0; // jogador
    int bx, by, dbx = 0, dby =0; // inimigos
    int d, i; // variavel para sortear a direcao(ax ou ay)
    int flag_colisao = 0;
    int count_enemies = 0;

    InitWindow(LARGURA, ALTURA, "Quadrado");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    srand(time(NULL));
    ax = (rand() % LARGURA / LADO) * LADO; //Pois lado sempre sera divisor da largura ou altura.
    ay = (rand() % ALTURA / LADO) * LADO;
    bx = (rand() % LARGURA / LADO) * LADO;
    by = (rand() % ALTURA / LADO) * LADO;

    while (!WindowShouldClose()){
        d = 1 - (rand() % 3); // d > 0 = ax; d < 0 = ay;
        if(d > 0)
            dbx = 1 - (rand() % 3);
        else if (d < 0)
            dby = 1 - (rand() % 3);
        else{
            dbx = 0;
            dby = 0;
        }

        


        inputs(&dax, &day);
        
        if(deveMover(ax, ay, dax, day, LARGURA, ALTURA))
            move(dax, day, &ax, &ay);

        if(deveMover(bx, by, dbx, dby, LARGURA, ALTURA))
            move_inimigo(dbx, dby, &bx, &by);
        

        //reseta as direcoes para que o movimento nao fique infinito e para que quando o quadrado encoste na parede em dax ele ainda possa se mover em dy e vice versa:
        dax = 0;
        day = 0; 
        dbx = 0;
        dby = 0;
 

        BeginDrawing();
        ClearBackground(RAYWHITE);
        spawn_player(ax, ay);
        spawn_enemie(bx, by, count_enemies);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
