/* Gerador de mapas 2 X 2 que se baseia no algoritmo da caminhada do bebado (Drunkard's Walk Algorithms).
Esse algoritmo pega um ponto aleatorio ou nao do mapa e comeca a gerar caminhos com direcoes, sentidos e quantidades de passos aleatorios, Sem exluir as paredes que compoem as 4 bordas do mapa ou criar caminhos desconectados.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//////////////////////////////////////////////////////
//              Geracao do mapa:

//Dimensoes logicas do mapa (referente a matriz do mapa, nao ao mapa desenhado pela raylib)
#define MAP_WIDTH 20  //Largura do mapa
#define MAP_HEIGHT 10  //Altura do mapa
#define MAP_DEPTH 5
#define MAX_TUNNELS 150000//Quantidate de tuneis que vai gerar
#define PADDING 0 //Define o espacamento entra os tuneis(0 e o espacamento padrao 1x1):
#define MAX_STEPS 2


//Funcao booleana que verifica se o tunel deve se mover em determinada direcao para evitar que as paredes sejam removidas ou ocorra problemas de acesso de posicoes inexistentes na matriz:
int canGenerate(int i, int j, int k, int dx, int dy, int dz, int width, int height, int depth) {
    int generate = 1;
    if( (i == (height-3) && dy == 1) || (i == 2 && dy == -1))
        generate = 0;
    if( (j == (width-3) && dx == 1) || (j == 2 && dx == -1))
        generate = 0;
    if( (k == (width-3) && dz == 1) || (k == 2 && dz == -1))
        generate = 0;
    return generate;
}

void generateMap(int m[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH])
{
    int i, j, k, l, m, n; //Variaveis de controle da matriz
    int s = 0, dx = 0, dy = 0, dz = 0; //Variaveis que definem a direcao e os sentidos
    int s_ant = s; //Sentido anterior(s indica se esta movendo no eixo x ou no eixo y)
    int tunnels = 0, steps = 0, count_padding = PADDING; // Variaveis de controle dos loops

    srand(time(NULL)); //Gera a seed da funcao rand() usando o tempo do sistema
/* 
  Define a posicao i e j da matriz para que o tunel sempre comece a partir da posicao m[1][MAP_WIDTH - 2], que e a posicao do portal.
    Dessa forma garantimos que sempre havera um caminho livre ate o portal.
    Para iniciar em uma posicao aleatoria, utilize o trecho comentado abaixo: */

    i = 1 + (rand() % MAP_HEIGHT-3);
    j = 1 + (rand() % MAP_WIDTH-3);
    k = 1 + (rand() % MAP_DEPTH-3);
    m[i][j][k] = 1;

     //laco principal da geracao dos tuneis
    while(tunnels < MAX_TUNNELS) {

        //Aqui a direcao (x ou y) nunca sera 0 ou igual a anterior, assim o tunel sempre escolhe uma nova direcao, enriquecendo o mapa.
        while(s == s_ant) {
            s = (rand() % 3) - 1;
        }
        //quando s == 1, assume a direcao x.
        if(s == 1) {
            //Define o sentido do movimento no eixo x: este laco faz com que sempre seja adotado um sentido
            while(dx == 0)
                dx = (rand() % 3) - 1;
        } else if(s == -1){
            //Define o sentido do movimento no eixo y: sempre adota um sentido como no laco anterior.
            while(dy == 0)
                dy = (rand() % 3) - 1;
        } else{
            //Define o sentido do movimento no eixo z: sempre adota um sentido como no laco anterior.
            while(dz == 0)
                dz = (rand() % 3) - 1;
        }
        //Define a quantidade de passos que deve dar no sentido e direcao atuais:
            while(steps == 0)
                steps = (rand() % (MAX_STEPS));

        //laco que insere os tuneis na matriz enquanto a quantidade de passos sorteada e maior que 0
        while(steps > 0 && canGenerate(i,j,dx,dy,dz, MAP_WIDTH, MAP_HEIGHT, MAP_DEPTH)) {

            i += dy; //acrescenta o sentido de y em i
            j += dx; //acrescenta o sentido de x em j
                //Note que cada iteracao do laco principal o sentido sera ou y ou x, nunca os dois ao mesmo tempo, evitando caminhos diagonais

            k = i; //k e uma variavel de controle do espacamento dos tuneis no sentido vertical
            l = j; //l e uma variavel de controle do espacamento dos tuneis no sentido horizontal

            m[i][j] = 1; //define a posicao do tunel

            //laco que usa os valores de k e l para acrescentar um espacamento no tunel (PADDING)
            while(count_padding > 0) {
                //Condicionais que verificam onde inserior os espacos extras, para evitar que seja inserido um espaco em locais proibidos:
                if (s == 1){
                    if(k + count_padding < (MAP_HEIGHT - 3)) {
                        k += count_padding;
                        m[k][j] = 1;
                        k -= count_padding;
                    }

                    else if (k - count_padding > 1) {
                        k -= count_padding;
                        m[k][j] = 1;
                        k += count_padding;
                    }
                }
                else{
                    if(l + count_padding < (MAP_WIDTH - 3)) {
                        l += count_padding;
                        m[i][l] = 1;
                        l -= count_padding;
                    }

                    else if (l - count_padding > 1) {
                        l -= count_padding;
                        m[i][l] = 1;
                        l += count_padding;
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
        dx = 0;
        dy = 0;

        tunnels++;
    }


}
 
void printMap(int m[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH]){
    int i, j, k;
    //Imprime a matriz, substituindo os valores '1' para espacos em branco e '0' para '#'
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            for(k = 0; k < MAP_DEPTH; k++){
                
            }
            
            if(m[i][j][k])
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }

}

int main(){
    int map[MAP_HEIGHT][MAP_WIDTH][MAP_DEPTH] = {0};
    //generateMap(map);
    printMap(map);
}
