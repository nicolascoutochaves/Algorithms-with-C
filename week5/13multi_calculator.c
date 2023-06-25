#include <stdio.h>
int main(){

    int n1, n2;
    float res;
    int op; char prtop; //operation
    int flag = 0; 

    printf("Calculator v2.0\n");

    do{        
        printf("1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n5) Exit\nEnter the operation: ");
        scanf("%d", &op);
        

        switch (op){

            case 1:
                printf("Insert n1 and n2: ");
                scanf("%d%d", &n1, &n2);
                res = n1 + n2;
                prtop = '+';
                break;
            case 2:
                printf("Insert n1 and n2: ");
                scanf("%d%d", &n1, &n2);
                res = n1 - n2;
                prtop = '-';
                break;
            case 3:
                printf("Insert n1 and n2: ");
                scanf("%d%d", &n1, &n2);
                res = n1 * n2;
                prtop = '*';
                break;
            case 4:
                printf("Insert n1 and n2: ");
                scanf("%d%d", &n1, &n2);
                if (n2 > 0){
                    res = n1 / n2;
                    prtop = '/';
                } else {
                    printf("Cannot divide by 0!\n");
                    flag = 1;
                }
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("Error! Enter a valid operation!\n");
                flag = 1;
                break;
        }

        if (flag == 0){
            printf("\n%d %c %d = %.2f\n\n", n1, prtop, n2, res);
        }
    } while(op != 5 && flag == 0);

    printf("Exited sucessfully\n");

    return 0;
}