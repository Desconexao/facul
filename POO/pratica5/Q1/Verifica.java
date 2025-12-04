/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica5.Q1;

/**
 *
 * @author felipe
 */
public class Verifica {
    public static boolean situacao01(Aviao aviao) {
        if (aviao.getNumeroDoVoo() != 4188) {
            System.out.println("Erro: O número do vôo está errado.");
            return false;
        }
        if (aviao.proximoLivre() != 0) {
            System.out.println("Erro: A primeira posição livre deveria ser a posição 0.");
            return false;
        }
        if (aviao.vagas() != 300) {
            System.out.println("Erro: O número de vagas livres deve ser 300.");
            return false;
        }
        if (aviao.verifica(100)) {
            System.out.println("Erro: O assento de número 100 deveria estar vazio.");
            return false;
        }
        return true;
    }

    public static boolean situacao02(Aviao aviao) {
        if (aviao.getNumeroDoVoo() != 4188) {
            System.out.println("Erro: O número do vôo está errado.");
            return false;
        }
        if (!aviao.getData().toString().equals("26/2/2018")) {
            System.out.println("Erro: A data do vôo está errada.");
            return false;
        }
        if (aviao.vagas() != 300) {
            System.out.println("Erro: O número de vagas livres deve ser 300.");
            return false;
        }
        int i = 0;
        if (!aviao.ocupa(i)) {
            System.out.println("Erro: A cadeira " + i + " não deveria estar ocupada.");
            return false;
        }
        i = 1;
        if (!aviao.ocupa(i)) {
            System.out.println("Erro: A cadeira " + i + " não deveria estar ocupada.");
            return false;
        }
        i = 100;
        if (!aviao.ocupa(i)) {
            System.out.println("Erro: A cadeira " + i + " não deveria estar ocupada.");
            return false;
        }
        if (aviao.ocupa(300)) {
            System.out.println(
                    "Erro: A cadeira de número 300 não pode ser ocupada, pois ela não faz parte dos assentos disponíveis.");
            return false;
        }
        if (aviao.ocupa(100)) {
            System.out.println("Erro: A cadeira de número 100 já estava ocupada e não deveria ser considerada livre.");
            return false;
        }
        if (aviao.vagas() != 297) {
            System.out.println("Erro: O número de vagas livres deveria ser 297 neste momento.");
            return false;
        }
        if (!aviao.verifica(100)) {
            System.out.println("Erro: O assento de número 100 deveria estar ocupado.");
            return false;
        }
        return true;
    }
}
