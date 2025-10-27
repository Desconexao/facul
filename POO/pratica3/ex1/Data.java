package pratica3.ex1;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int d, int m, int a) {
        this.dia = d;
        this.mes = m;
        this.ano = a;
    }

    public Data() {
        this(1, 1, 2000);
    }

    void imprimir() {
        System.out.println(dia + "/" + mes + "/" + ano);
    }
}
