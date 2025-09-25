package pratica1.ex2;

public class Main {
    public static void main(String[] args) {
        Funcionario funcTeste = new Funcionario();

        funcTeste.nome = "Gabriel";
        funcTeste.departamento = "TI";
        funcTeste.salario = 4500.0;
        funcTeste.dataEntrada = "09/06/2023";
        funcTeste.rg = "rgaleatorio";

        funcTeste.recebeAumento(500.0);
        funcTeste.calculaGanhoAnual();
        funcTeste.mostra();
    }
}
