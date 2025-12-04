package pratica5.Q1;

public class Data {
    public int dia;
    public int mes;
    public int ano;

    public Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    @Override
    public String toString() {
        return dia + "/" + mes + "/" + ano;
    }
}
