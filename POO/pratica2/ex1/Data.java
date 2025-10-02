package pratica2.ex1;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    void imprimeData() {
        System.out.println("\tDia: " + this.dia);
        System.out.println("\tMes: " + this.mes);
        System.out.println("\tAno: " + this.ano);
    }

    int getDia() {
        return this.dia;
    }

    int getMes() {
        return this.mes;
    }

    int getAno() {
        return this.ano;
    }
}
