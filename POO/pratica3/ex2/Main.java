package pratica3.ex2;

public class Main {
    public static void main(String[] args) {
        Lembrete l1 = new Lembrete("POO", "Aula de POO", new Data(14, 10, 2025));
        l1.imprimir();

        BlocoDeLembretes blocoL1 = new BlocoDeLembretes(10);

    }
}
