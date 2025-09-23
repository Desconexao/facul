package pratica1.ex1;

public class Main {
    public static void main(String[] args) {
        Conta contaMaria, contaGabriel;
        contaMaria = new Conta();
        contaGabriel = new Conta();

        contaGabriel.saldo = 5.0;
        contaMaria.dono = "Maria";
        contaMaria.saldo = 50.0;
        contaMaria.limite = 1000.0;
        System.out.println("Dono: " + contaMaria.dono);
        System.out.println("Saldo: " + contaMaria.saldo);
        contaMaria.saca(500.0);
        contaMaria.transferePara(contaGabriel, 40);
        System.out.println("Saldo Maria: " + contaMaria.saldo);
        System.out.println("Saldo Gabriel: " + contaGabriel.saldo);
    }
}
