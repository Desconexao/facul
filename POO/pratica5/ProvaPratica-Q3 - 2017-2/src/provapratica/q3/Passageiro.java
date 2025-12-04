/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provapratica.q3;

/**
 *
 * @author felipe
 */
public class Passageiro implements Pessoa {
    private String cpf;
    private String nome;
    private boolean vip;
    
    public Passageiro(String cpf, String nome, boolean vip) {
        this.cpf = cpf;
        this.nome = nome;
        this.vip = vip;
    }

    @Override
    public String getCPF() {
        return cpf;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public boolean vip() {
        return vip;
    }
    
    public String toString() {
        return "| CPF: " + cpf
               + " | Nome: " + nome
               + "\t| " + (vip?"Assento Premium":"Assento Comum");
    }
    
}
