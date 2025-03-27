#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    Data datas[2];
} Datas;

int dataEmDias(Data data){
    int dataEmDias = 0;
    dataEmDias = data.dia + data.mes * 30 + data.ano * 365;
    return dataEmDias;
}

Data diferenca(int data1EmDias, int data2EmDias){
    Data diff;
    if(data1EmDias > data2EmDias)
        diff.dia = data1EmDias - data2EmDias;
    else if(data1EmDias < data2EmDias)
        diff.dia = data2EmDias - data1EmDias;
    else{
        diff.dia = 0;
        diff.mes = 0;
        diff.ano = 0;
        return diff;
    }
    diff.ano = diff.dia / 365;
    diff.dia = diff.dia % 365;
    diff.mes = diff.dia / 30; 
    diff.dia = diff.dia % 30;

    return diff;
}

int validaData(int valor, char dma){
    if(dma == 'D')
        while(valor < 0){
            printf("Dia invalido, digite o dia novamente: ");
            scanf("%d", &valor);
        }

    else if(dma == 'M')
        while(valor < 0 || valor > 12){
            printf("Mes invalido, digite o mes novamente: ");
            scanf("%d", &valor);
        }

    else if(dma == 'A')
        while(valor < 0){
            printf("Ano invalido, digite o ano novamente: ");
            scanf("%d", &valor);
        }
        
    return valor;
}

Data leData(){
    int data1EmDias, data2EmDias;
    Data data, diff;
    Datas datas;
    for(int i = 0; i < 2; i++){
        printf("Digite o dia da data[%d]: ", i);
        scanf("%d", &data.dia);
        if(data.dia < 0)
            data.dia = validaData(data.dia, 'D');
        printf("Digite o mes da data[%d]: ", i);
        scanf("%d", &data.mes);
        if(data.mes < 0 || data.mes > 12)
            data.mes = validaData(data.mes, 'M');
        printf("Digite o ano da data[%d]: ", i);
        scanf("%d", &data.ano);
        if(data.ano < 0)
            data.ano = validaData(data.ano, 'A');
        datas.datas[i] =  data;
    }
    data1EmDias = dataEmDias(datas.datas[0]);
    data2EmDias = dataEmDias(datas.datas[1]);
    diff = diferenca(data1EmDias, data2EmDias);
    return diff;
}

int main(){
    Data diff = leData();

    printf("%d anos | %d meses | %d dias", diff.ano, diff.mes, diff.dia);
}
