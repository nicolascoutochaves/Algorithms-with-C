/* Gerador de mapas 2 X 2 que se baseia no algoritmo da caminhada do bebado (Drunkard's Walk Algorithms).
Esse algoritmo pega um ponto aleatorio ou nao do mapa e comeca a gerar caminhos com direcoes, sentidos e quantidades de passos aleatorios, Sem exluir as paredes que compoem as 4 bordas do mapa ou criar caminhos desconectados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//////////////////////////////////////////////////////
//              Geracao do mapa:

//Dimensoes logicas do mapa (referente a matriz do mapa, nao ao mapa desenhado pela raylib)
#define MAP_WIDTH 30  //Largura do mapa
#define MAP_HEIGHT 15  //Altura do mapa
#define MAP_DEPTH 15 //Profundidade do mapa
#define WALLS 2 //Espessura das paredes
#define MAX_TUNNELS 200 //Quantidate de tuneis que vai gerar
#define PADDING 2 //Define o espacamento entra os tuneis(0 e o espacamento padrao 1x1):
#define MAX_STEPS 100 //Quantidade maxima de passos que o algorimo pode percorrer ate a proxima randomizacao de direcoes e sentidos


//Funcao booleana que verifica se o tunel deve se mover em determinada direcao para evitar que as paredes sejam removidas ou ocorra problemas de acesso de posicoes inexistentes na matriz:
int canGenerate(int x, int y, int z, int sx, int sy, int sz, int width, int height, int depth) {
    int generate = 1;
    if( (x == (width-WALLS-1) && sx == 1) || (x == WALLS && sx == -1))
        generate = 0;
    if( (y == (height-WALLS-1) && sy == 1) || (y == WALLS && sy == -1))
        generate = 0;
    if( (z == (depth-WALLS-1) && sz == 1) || (z == WALLS && sz == -1))
        generate = 0;
    return generate;
}

void generateMap(int m[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH])
{
    int x, y, z, j, i, k; //Variaveis de controle da matriz
    int s = 0, sx = 0, sy = 0, sz = 0; //Variaveis que definem a direcao e os sentidos
    int s_ant = s; //Sentido anterior(s indica se esta movendo no eixo x ou no eixo y)
    int tunnels = 0, steps = 0, count_padding = PADDING; // Variaveis de controle dos loops

    srand(time(NULL)); //Gera a seed da funcao rand() usando o tempo do sistema

    y = 1 + (rand() % MAP_HEIGHT-WALLS-1);
    x = 1 + (rand() % MAP_WIDTH-WALLS-1);
    z = 1 + (rand() % MAP_DEPTH-WALLS-1);

    m[y][x][z] = 1;

     //laco principal da geracao dos tuneis
    while(tunnels < MAX_TUNNELS) {

        //Aqui a direcao (x ou y) nunca sera 0 ou igual a anterior, assim o tunel sempre escolhe uma nova direcao, enriquecendo o mapa.
        while(s == s_ant) {
            s = (rand() % 3) - 1;
        }
        //quando s == 1, assume a direcao x.
        if(s == 1) {
            //Define o sentido do movimento no eixo x: este laco faz com que sempre seja adotado um sentido
            while(sx == 0)
                sx = (rand() % 3) - 1;

        } else if(s == -1){
            //Define o sentido do movimento no eixo y: sempre adota um sentido como no laco anterior.
            while(sy == 0)
                sy = (rand() % 3) - 1;

        } else{
            //Define o sentido do movimento no eixo z: sempre adota um sentido como no laco anterior.
            while(sz == 0)
                sz = (rand() % 3) - 1;
        }
        //Define a quantidade de passos que deve dar no sentido e direcao atuais:
            while(steps == 0)
                steps = (rand() % (MAX_STEPS));

        //laco que insere os tuneis na matriz enquanto a quantidade de passos sorteada e maior que 0
        while(steps > 0 && canGenerate(x, y, z, sx, sy, sz, MAP_WIDTH, MAP_HEIGHT, MAP_DEPTH)) {

            y += sy; //acrescenta o sentido de y em i
            x += sx; //acrescenta o sentido de x em j
            z += sz; 
                //Note que cada iteracao do laco principal o sentido sera ou y ou x, nunca os dois ao mesmo tempo, evitando caminhos diagonais

            i = y; //i e uma variavel de controle do espacamento dos tuneis no sentido vertical
            j = x; //j e uma variavel de controle do espacamento dos tuneis no sentido horizontal
            k = z; //k e uma variavel de controle do espacamento dos tuneis no sentido transversal

            m[y][x][z] = 1; //define a posicao do tunel

            //laco que usa os valores de k e l para acrescentar um espacamento no tunel (PADDING)
            while(count_padding > 0) {
                //Condicionais que verificam onde inserior os espacos extras, para evitar que seja inserido um espaco em locais proibidos:
                if (s == -1){
                    if(i + count_padding < (MAP_HEIGHT - WALLS-1)) {
                        i += count_padding;
                        m[i][x][z] = 1;
                        i -= count_padding;
                    }
                    else if (i - count_padding > WALLS) {
                        i -= count_padding;
                        m[i][x][z] = 1;
                        i += count_padding;
                    }
                }
                else if (s == 1){
                    if(j + count_padding < (MAP_WIDTH - WALLS-1)) {
                        j += count_padding;
                        m[y][j][z] = 1;
                        j -= count_padding;
                    }

                    else if (j - count_padding >= WALLS) {
                        j -= count_padding;
                        m[y][j][z] = 1;
                        j += count_padding;
                    }
                }

                else{
                    if(k + count_padding < (MAP_DEPTH - WALLS-1)) {
                        k += count_padding;
                        m[y][x][k] = 1;
                        k -= count_padding;
                    }

                    else if (k - count_padding >= WALLS) {
                        k -= count_padding;
                        m[y][x][k] = 1;
                        k += count_padding;
                    }
                }

                //aqui a variavel count_padding vai decrementando para que na proxima iteracao o padding seja adicionado numa posicao a mais ou a menos, dependendo da condicional
                count_padding--;

            }
            count_padding = PADDING; //Reatribui a variavel count_padding ao valor do padding.
            steps--; //decrementa a quantidade de passos para realizar uma nova operacao
        }
        s_ant = s; //define o sentido anterior

        //Reseta as variaveis de controle para que um outro loop possa ser realizado:
        steps = 0;
        s = 0;
        sx = 0;
        sy = 0;
        sz = 0;

        tunnels++;
    }

}
 
void printMap(int m[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH]){
    int i, j, k = 0;
    //Imprime a matriz, substituindo os valores '1' para espacos em branco e '0' para '#'
    char c = '\0';
    while(c != 'n' && k < MAP_DEPTH){
        for (i = 0; i < MAP_HEIGHT; i++) {
            for (j = 0; j < MAP_WIDTH; j++) {
                
                if(m[i][j][k])
                    printf(" ");
                else
                    printf("#");
            }
            printf("\n");
        }
        getc(stdin);
        k++;
    }

}
/* 
int main(){
    int map[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH] = {0};
    generateMap(map);
    printMap(map);
} */
