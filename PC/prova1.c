#include <stdio.h>

void calcula(int horas_de_frio[5][5], int horas_de_frio_mes_media[5], float perc_horas_de_frio_mes[5], float *perc_total_horas_de_frio);

int main() {

  int horas_de_frio_mes_media[5] = { 62, 124, 137, 112, 61 }; //de 1954 a 2017
  int horas_de_frio[5][5];
  float perc_horas_de_frio_mes[5];
  int m, s; //(m)ês e (s)emana
  float perc_total_horas_de_frio = 0.0; //percentual do total de horas em relação à media

  for (m = 0; m < 5; m++)
    for (s = 0; s < 5; s++)
      scanf("%d", &horas_de_frio[m][s]);

  calcula(horas_de_frio, horas_de_frio_mes_media, perc_horas_de_frio_mes, &perc_total_horas_de_frio);
  
  printf("Percentual de horas de frio por mes:\n");
  for (m = 0; m < 5; m++)
    printf("%.1f\n", perc_horas_de_frio_mes[m]);

  printf("Percentual do total de horas de frio em relacao a media:\n%.1f", perc_total_horas_de_frio);

  return 0;
}

void calcula(int horas_de_frio[5][5], int horas_de_frio_mes_media[5], float perc_horas_de_frio_mes[5], float *perc_total_horas_de_frio){
  int somaFrioMes;
  int somaFrioMeses = 0, somaFrioMesesMedia = 0;
  for(int m = 0; m < 5; m++){
    somaFrioMes = 0;
    for(int s = 0; s < 5; s++)
      somaFrioMes += horas_de_frio[m][s];
    somaFrioMeses += somaFrioMes;
    somaFrioMesesMedia += horas_de_frio_mes_media[m];
    perc_horas_de_frio_mes[m] = (float) somaFrioMes / horas_de_frio_mes_media[m] * 100;
  }
  *perc_total_horas_de_frio = (float) somaFrioMeses / somaFrioMesesMedia * 100;
}
