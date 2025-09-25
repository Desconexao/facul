package pratica1.ex2;

public class Funcionario {
    String nome;
    String departamento;
    double salario;
    String dataEntrada;
    String rg;

    public void recebeAumento(double aumento) {
        System.out.println("Aumento de " + aumento + " para " + this.nome);
        this.salario += aumento;
        System.out.println("Novo salario: " + this.salario);
    }

    public void calculaGanhoAnual() {
        System.out.println("Salario anual: " + this.salario * 12);
    }

    public void mostra() {
        System.out.println("Nome: " + nome);
        System.out.println("Departamento: " + departamento);
        System.out.println("Salario: " + salario);
        System.out.println("Data entrada: " + dataEntrada);
        System.out.println("RG: " + rg);
    }
}
