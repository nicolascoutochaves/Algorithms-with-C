#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ALTURA 600
#define LARGURA 800
#define MAX_INIMIGOS 10
#define LADO 20

typedef struct Personagens{
    int x, y;
    int dx, dy;
} Personagem;


int moveInimigo(Personagem *Inimigo, int largura, int altura)
{
    int mover = 1;
    if(
       (Inimigo->x == largura - LADO && Inimigo->dx == 1) ||
       (Inimigo->x == 0 && Inimigo->dx == -1)) mover = 0;
    else if(
       (Inimigo->y == altura - LADO && Inimigo->dy == -1) ||
       (Inimigo->y == 0 && Inimigo->dy == 1)) mover = 0;

    if (mover == 1){
        Inimigo->x += Inimigo->dx * LADO;
        Inimigo->y -= Inimigo->dy * LADO;
    }
 
    return mover;
}
void redefineDeslocamento(Personagem *Inimigo){
    Inimigo->dx = 0;
    Inimigo->dy = 0;

    while (Inimigo->dx == 0 && Inimigo->dy == 0){
        Inimigo->dx = 1 - (rand() % 3);
        Inimigo->dy = 1 - (rand() % 3);
    }      
    
}


int main(){
    int i;
    Personagem Inimigo[MAX_INIMIGOS];

    InitWindow(LARGURA, ALTURA, "JOGO");
    SetTargetFPS(60);
    int temporizador = 0;
    srand(time(NULL));

    for(i = 0; i < MAX_INIMIGOS; i++) {
        Inimigo[i].x = rand() % (LARGURA / LADO) * LADO;
        Inimigo[i].y = rand() % (ALTURA / LADO) * LADO;
        redefineDeslocamento(&Inimigo[i]);
    }

    while(!WindowShouldClose()){
        for(i = 0; i < MAX_INIMIGOS; i++) {
            DrawRectangle(Inimigo[i].x, Inimigo[i].y, LADO, LADO, ORANGE);
        }

        temporizador++;

        if(temporizador > GetFrameTime()*180){
            for(i = 0; i < MAX_INIMIGOS; i++) {
                if(!moveInimigo(&Inimigo[i], LARGURA, ALTURA))
                    redefineDeslocamento(&Inimigo[i]);
            }
            temporizador = 0;
        }
        
         BeginDrawing();
         ClearBackground(RAYWHITE);
         EndDrawing();
    }
    CloseWindow();

    return 0;
}
