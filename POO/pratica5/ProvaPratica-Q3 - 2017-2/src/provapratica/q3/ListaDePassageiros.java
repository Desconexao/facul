/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provapratica.q3;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author felipe
 */
public class ListaDePassageiros implements Repositorio {
    private List<Pessoa> lista;
    private int indice;
    
    public ListaDePassageiros() {
        lista = new ArrayList<Pessoa>();
        indice = 0;
    }

    @Override
    public void guarda(Pessoa nova) {
        lista.add(nova);
    }

    @Override
    public Pessoa recupera(String cpf) {
        for (Pessoa p : lista) {
            if (p.getCPF().equals(cpf))
                return p;
        }
        return null;
    }

    @Override
    public Pessoa primeiro() {
        indice = 0;
        return lista.get(indice);
    }

    @Override
    public Pessoa proximo() {
        if (indice < lista.size())
            indice++;
        if (indice < lista.size())
            return lista.get(indice);
        else
            return null;
    }
    
    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (Pessoa p : lista) {
            str.append(p);
            str.append("\n");
        }
        return str.toString();
    }
    
    public void inicializaRepositorio1() {
        lista.add(new Passageiro("12345678910", "Ronaldo", true));
        lista.add(new Passageiro("00011122233", "Renato", false));
        lista.add(new Passageiro("44455566677", "Romario", false));
        lista.add(new Passageiro("77788899900", "Neymar", false));
        lista.add(new Passageiro("98765432101", "Douglas", true));
        lista.add(new Passageiro("66617166600", "Robinho", true));

    }

    public void inicializaRepositorio2() {
        lista.add(new Passageiro("12345678910", "Ronaldo", true));
        lista.add(new Passageiro("00011122233", "Renato", false));
        lista.add(new Passageiro("44455566677", "Romario", false));
        lista.add(new Passageiro("11111111122", "Kaka", false));
        lista.add(new Passageiro("33333333344", "Luan", true));
    }
}
