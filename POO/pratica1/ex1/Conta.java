package pratica1.ex1;

import java.util.Scanner;

public class Conta {
    int numero;
    String dono;
    double saldo;
    double limite;

    void deposita(double quantidade) {
        this.saldo = this.saldo + quantidade;
    }

    boolean saca(double valor) {
        if (this.saldo < valor) {
            if (valor < this.limite) {
                System.out.println("Você pode sacar utilizando seu limite de " + this.limite);
                System.out.println("Deseja sacar? ");
                Scanner sc = new Scanner(System.in);
                String opc = sc.nextLine();
                sc.close();
                if (opc.toLowerCase().equals("sim")) {
                    this.limite -= valor;
                    return true;
                }
            }
            return false;
        } else {
            this.saldo = this.saldo - valor;
            return true;
        }
    }

    String imprimeDono() {
        return this.dono;
    }

    double devolveSaldo() {
        return this.saldo;
    }

    void transferePara(Conta pessoa, double valor) {
        pessoa.saldo += valor;
        this.saldo -= valor;
    }

    void imprimeDados() {
        System.out.println("Numero: " + numero);
        System.out.println("Dono: " + dono);
        System.out.println("Saldo: " + saldo);
        System.out.println("Limite: " + limite);
    }

}
