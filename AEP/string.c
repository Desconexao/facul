#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void q1(){
    char str[100];
    char strIn[100];

    scanf("%[^\n]s", str);

    for(int i = 0; i < strlen(str); i++){
        strIn[i] = str[strlen(str) - i - 1];
    }

    printf("%s", strIn);

}

void q2(){
    char str[100];

    scanf("%[^\n]s", str);

    for(int i = 0; i < strlen(str); i++){
        while(str[i] == ' '){
            for(int j = i; j < strlen(str); j++){
                str[j] = str[j + 1];
            }
        }
        //str[j] = str[i];
    }
    printf("%s", str);
}

void q3(){
    char str[100];
    int contPalavras = 0, temPalavra = 0;

    scanf("%[^\n]s", str);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            /*if(str[i + 1] != ' ' || !(str[strlen(str) - 1] == ' ')){
                contPalavras++;  
            }*/
            while(str[i] == ' '){
                for(int j = i; j < strlen(str); j++){
                    if(str[j] != ' '){
                        i = j;
                        temPalavra = !temPalavra;
                        break;
                    }
                }
                if(temPalavra){
                    contPalavras++;
                    temPalavra = !temPalavra;
                }
                else
                    break;
            }

        }
    }
    printf("%d", contPalavras);
}

void q4(){
    char str[100];
    char a, b;

    printf("char a:");
    scanf("%c", &a);
    printf("char b:");
    scanf(" %c", &b);
    printf("string: ");
    scanf(" %[^\n]s", str);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == a){
            str[i] = b;
        }
    }

    printf("%s", str);
}

int main(){
    //q1();
    //q2();
    //q3();
    //q4();

    return 0;
}