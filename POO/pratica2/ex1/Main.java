package pratica2.ex1;

public class Main {
    public static void main(String[] args) {
        Pessoa teste = new Pessoa("nomealeatorio", 8, 10, 1994, 1.76);
        teste.imprimirDados();

        Data dataHoje = new Data(1, 12, 2019);
        System.out.println(teste.getNome() + " tem " + teste.calculaIdade(dataHoje) + " anos");
    }
}
