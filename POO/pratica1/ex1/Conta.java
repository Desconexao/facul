package pratica1.ex1;

import java.util.Scanner;

public class Conta {
    private int numero;
    private String dono;
    private double saldo;
    private double limite;
    private static int numeroDeContas = 0;

    Conta(String dono, double saldo, double limite) {
        this.dono = dono;
        this.saldo = saldo;
        this.limite = limite;
        numeroDeContas++;
        this.numero = numeroDeContas;
    }

    String getDono() {
        return this.dono;

    }

    double getSaldo() {
        return this.saldo;
    }

    // void setDono(String novoDono) {
    // this.dono = novoDono;
    // }
    //
    // void setSaldo(double novoSaldo) {
    // this.saldo = novoSaldo;
    // }
    //
    // void setSaldo(double novoSaldo) {
    // this.saldo = novoSaldo;
    // }
    //
    // void setLimite

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
        System.out.println("##############################################");
        System.out.println("Numero: " + numero);
        System.out.println("Dono: " + dono);
        System.out.println("Saldo: " + saldo);
        System.out.println("Limite: " + limite);
        System.out.println("##############################################");

    }

}
