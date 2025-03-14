#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int horas;
    int minutos;
    int segundos;
}Hora;

Hora diferenca(Hora hora1, Hora hora2){
    Hora diff;
    int hora1Total = 0, hora2Total = 0;

    hora1Total = hora1.horas * 3600 + hora1.minutos * 60 + hora1.segundos;
    hora2Total = hora2.horas * 3600 + hora2.minutos * 60 + hora2.segundos;

    if(hora1Total > hora2Total){
        diff.horas = (hora1Total - hora2Total) / 3600;
        diff.minutos = ((hora1Total - hora2Total) % 3600) / 60;
        diff.segundos = ((hora1Total - hora2Total) % 3600) % 60;
    }else{
        diff.horas = (hora2Total - hora1Total) / 3600;
        diff.minutos = ((hora2Total - hora1Total) % 3600) / 60;
        diff.segundos = ((hora2Total - hora1Total) % 3600) % 60;
    }
    
    return diff;
}

int main(){
    Hora hora1;
    Hora hora2;
    Hora diff;

    printf("Digite a hora 1: [Hora, Minuto, Segundo] ");
    scanf("%d %d %d", &hora1.horas, &hora1.minutos, &hora1.segundos);

    printf("Digite a hora 2: [Hora, Minuto, Segundo] ");
    scanf("%d %d %d", &hora2.horas, &hora2.minutos, &hora2.segundos);

    diff = diferenca(hora1, hora2);
    printf("Diferenca: %d:%02d:%02d\n", diff.horas, diff.minutos, diff.segundos);

    return 0;

}