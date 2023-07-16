#include "raylib.h"
#include <string.h>
#define LARGURA 600
#define ALTURA 600
#define ALTURA_QUADRADO 20
#define LARGURA_QUADRADO 20
#define VELOCIDADE 5

int main(void){

    int x = 300, y = 300;
    int flag = 0;

    //--------------------------------------------------------------------------------------
    //Inicializa¸c~oes
    InitWindow(LARGURA, ALTURA, "Quadrado");//Inicializa janela, com certo tamanho e t´ıtulo
    SetTargetFPS(60);// Ajusta a execu¸c~ao do jogo para 60 frames por segundo
    //--------------------------------------------------------------------------------------
    //La¸co principal do jogo
    while (!WindowShouldClose() && flag == 0) // Detect window close button or ESC key
    {
    // Trata entrada do usu´ario e atualiza estado do jogo
    //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_D)) x += VELOCIDADE;
        if (IsKeyDown(KEY_A)) x -= VELOCIDADE;
        if (IsKeyDown(KEY_W)) y -= VELOCIDADE;
        if (IsKeyDown(KEY_S)) y += VELOCIDADE;

        if ((x >= LARGURA || x <= 0 - LARGURA_QUADRADO ) || (y >= ALTURA || y <= 0 - ALTURA_QUADRADO)){
            flag = 1;
        }


        //----------------------------------------------------------------------------------
        // Atualiza a representa¸c~ao visual a partir do estado do jogo
        //----------------------------------------------------------------------------------
        BeginDrawing();//Inicia o ambiente de desenho na tela
        ClearBackground(RAYWHITE);//Limpa a tela e define cor de fundo
        DrawRectangle(x, y, LARGURA_QUADRADO, ALTURA_QUADRADO, GREEN);//Desenha um texto, com posi¸c~ao, tamanho e cor
        EndDrawing();//Finaliza o ambiente de desenho na tela
        //----------------------------------------------------------------------------------
        }
        CloseWindow();// Fecha a janela e o contexto OpenGL

    return 0;
}