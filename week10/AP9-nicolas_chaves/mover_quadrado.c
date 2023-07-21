/*
Esse programa movimenta um quadrado usando funcoes ate que o quadrado atinja a borda da tela
*/
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA 800
#define ALTURA 800

#define LADO 20

int deveMover(int x, int y, int dx, int dy, int larg, int alt){

    int deve_mover = 1;
    if((x == 0 && dx == -1) || (x == LARGURA - LADO && dx == 1)) deve_mover = 0;
    else if((y == 0 && dy == 1) || (y == ALTURA - LADO && dy == -1)) deve_mover = 0;
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
int main(void)

{
    int x, y, dx = 0, dy = 0;
    InitWindow(LARGURA, ALTURA, "Quadrado");
    SetTargetFPS(60);
    srand(time(NULL));

    x = (rand() % LARGURA / LADO) * LADO; //Pois lado sempre sera divisor da largura ou altura.
    y = (rand() % ALTURA / LADO) * LADO;

    while (!WindowShouldClose())
    {
        //Define as direcoes dx e dy:
        if (IsKeyDown(KEY_RIGHT))
            dx = 1;

        if (IsKeyDown(KEY_LEFT))
            dx = -1;

        if (IsKeyDown(KEY_UP))
            dy = 1;

        if (IsKeyDown(KEY_DOWN))
            dy = -1;

        if(deveMover(x, y, dx, dy, LARGURA, ALTURA))
            move(dx, dy, &x, &y);


        //reseta as direcoes para que o movimento nao fique infinito e para que quando o quadrado encoste na parede em dx ele ainda possa se mover em dy e vice versa:
        dy = 0;
        dx = 0;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(x, y, LADO, LADO, GREEN);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
