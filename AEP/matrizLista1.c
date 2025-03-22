#include <stdio.h>
#include <stdlib.h>

void ex16p2(){
    int  a[4][6], b[4][6], s[4][6], d[4][6];
    
    for(int L = 0; L < 4; L++){
        for(int C = 0; C < 6; C++){
            printf("a[%d][%d] e b[%d][%d] = ", L, C, L, C);
            scanf("%d", &a[L][C]);
            scanf("%d", &b[L][C]);
            s[L][C] = a[L][C] + b[L][C];
            d[L][C] = a[L][C] - b[L][C];
        }
    }

    for(int L = 0; L < 4; L++){
        for(int C = 0; C < 6; C++){
            printf("%d + %d = ", a[L][C], b[L][C]);
            printf("%d \n", s[L][C]);
            printf("%d - %d = ", a[L][C], b[L][C]);
            printf("%d\n", d[L][C]);
        }
    }
}

void ex16p3(){
    int a[4][4];
    int somaX1 = 0, somaX2 = 0, somaX3 = 0, somaX4 = 0;

    for(int L = 0; L < 4; L++){
        for(int C = 0; C < 4; C++){
            printf("a[%d][%d] = ", L, C);
            scanf("%d", &a[L][C]);
            
            if((L == C) && ((L <= 1)  && (C <= 1))){
                somaX1 += a[L][C];
            }
            if((L == C) && ((L >= 2)  && (C >= 2))){
                somaX2 += a[L][C];
            }

        }
    }  

    for(int L = 0; L < 4; L++){
        for(int C = 0; C <= L; C++){
            somaX3 += a[L][C];
        }
    }

    for(int C = 2; C >= 0; C--){
        for(int L = 0; L <= 2; L++){
            somaX4 += a[L][C];
        }
    }
}

void ex16p4(){
    int d[5][5];
    int numero = 321;
    int achou = 0;

    

    for(int L = 0; L < 4; L++){
        for(int C = 0; C < 6; C++)
            scanf("%d", &d[L][C]);  
    }
    printf("Numero: ");
    scanf("%d", &numero);
    for(int L = 0; L < 4; L++){
        for(int C = 0; C < 6; C++){
            if(numero == d[L][C])
                achou = 1;   
        }
    }

    if(achou)
        printf("Existe\n");
    else
        printf("N exste\n");
}

void ex16p5(){
    int g[5][5];
    int sl[5], sc[5];
    int somaColuna = 0, somaLinha = 0;

    for(int L = 0; L < 5; L++){
        for(int C = 0; C < 5; C++){
            scanf("%d", &g[L][C]);
            somaLinha += g[L][C];
            somaColuna += g[C][L];
        }
        sl[L] = somaLinha;
        sc[L] = somaColuna;
    }
    /*
    for(int C = 0; C < 5; C++){
        for(int L = 0; L < 5; L++){
            somaColuna += g[L][C];
        }
        sc[C] = somaColuna;
    }
    
    for(int L = 0; L < 5; L++){
        for(int C = 0; C < 5; C++){
            somaLinha += g[L][C];
            
        }
        sl[L] = somaLinha;
    }*/
}

void ex16p6(){
    float a[12][13];
    float maiorNumero = 0;

    for(int L = 0; L < 12; L++){
        for(int C = 0; C < 13; C++){
            printf("%f %f: ", L, C);
            scanf("%f", &a[L][C]);
            if(a[L][C] > maiorNumero)
                maiorNumero = a[L][C];
        }
    }
    for(int L = 0; L < 12; L++){
        for(int C = 0; C < 13; C++){
            a[L][C] = a[L][C] / maiorNumero;
            printf("%f \n", a[L][C]);
        }
    }
}

void ex16p7(){
    int g[13];
    int m[13][3];
    int pontos = 0;
    int contAcertos = 0, contSimples = 0, contDupla = 0, contTripla = 0;

    for(int i = 0; i < 13; i++){
        scanf("%d", &g[i]);
    }

    for(int L = 0; L < 13; L++){
        for(int C = 0; C < 3; C++){
            scanf("%d", &m[L][C]);
        }
    }

    for(int C = 0; C < 3; C++){
        for(int L = 0; L < 13; L++){
            if(m[L][C] == g[L])
                pontos += 1;
        }
    }
    for(int L = 0; L < 13; L++){
        for(int C = 0; C < 3; C++){
            if(m[L][C] == 1)
                contAcertos += 1;
        }
        switch (contAcertos)
        {
        case 1:
            contSimples += 1;
            break;
        case 2:
            contDupla += 1;
            break;
        case 3:
            contTripla += 1;
            break;
    
        default:
            break;
        }
    }

    printf("Pontos: %d\n", pontos);
    printf("Simples: %d\nDupla: %d\nTripla: %d\n", contSimples, contDupla, contTripla);

}

int main(){
    ex16p7();
}