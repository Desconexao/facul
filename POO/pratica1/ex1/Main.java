package pratica1.ex1;

public class Main {
    public static void main(String[] args) {
        Conta contaMaria, contaGabriel;
        contaMaria = new Conta("Maria", 5, 500);
        contaGabriel = new Conta("Gabriel", 50, 1000);

        contaMaria.imprimeDados();
        contaGabriel.imprimeDados();

        System.out.println("Dono: " + contaMaria.getDono());
        System.out.println("Saldo: " + contaMaria.getSaldo());
        contaMaria.saca(500.0);
        contaMaria.transferePara(contaGabriel, 40);
        System.out.println("Saldo Maria: " + contaMaria.getSaldo());
        System.out.println("Saldo Gabriel: " + contaGabriel.getSaldo());
    }
}
