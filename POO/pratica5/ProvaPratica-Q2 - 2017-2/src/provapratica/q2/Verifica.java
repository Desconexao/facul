/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provapratica.q2;

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
            System.out.println("Erro: A cadeira de número 300 não pode ser ocupada, pois ela não faz parte dos assentos disponíveis.");
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

    public static boolean situacao03(AviaoPremium aviao) {
        if (aviao.getNumeroDoVoo() != 6155) {
            System.out.println("Erro: O número do vôo está errado.");
            return false;
        } 
        if (!aviao.getData().toString().equals("26/2/2018")) {
            System.out.println("Erro: A data do vôo está errada.");
            return false;
        } 
        if (aviao.vagas() != 350) {
            System.out.println("Erro: O número de vagas livres deve ser 350.");
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
        if (aviao.ocupa(350)) {
            System.out.println("Erro: A cadeira de número 350 não pode ser ocupada, pois ela não faz parte dos assentos disponíveis.");
            return false;
        }
        if (aviao.ocupa(100)) {
            System.out.println("Erro: A cadeira de número 100 já estava ocupada e não deveria ser considerada livre.");
            return false;
        }
        if (aviao.vagas() != 347) {
            System.out.println("Erro: O número de vagas livres deveria ser 347 neste momento.");
            return false;
        } 
        if (!aviao.verifica(100)) {
            System.out.println("Erro: O assento de número 100 deveria estar ocupado.");
            return false;
        }
        if (aviao.tipo(49) != 'P') {
            System.out.println("Erro: O assento de número 49 é Premium.");
            return false;
        }
        if (aviao.tipo(50) != 'C') {
            System.out.println("Erro: O assento de número 50 é comum.");
            return false;
        }
        if (aviao.proximoLivre() != 50 ) {
            System.out.println("Erro: O próximo assento comum livre deveria ser o de número 50.");
            return false;
        }
        if (!aviao.ocupa(aviao.proximoLivre())) {
            System.out.println("Erro: O assento comum de número 50 deveria estar disponível para ocupação.");
            return false;
        }
        if (aviao.proximoLivre() != 51) {
            System.out.println("Erro: O próximo assento comum livre deveria ser o de número 51.");
            return false;
        }
        if (aviao.proximoPremiumLivre() != 2) {
            System.out.println("Erro: O próximo assento Premium livre deveria ser o de número 2.");
            return false;
        }
        if (!aviao.ocupa(aviao.proximoPremiumLivre())) {
            System.out.println("Erro: O assento Premium de número 2 deveria estar disponível para ocupação.");
            return false;
        }
         if (aviao.vagas() != 345) {
            System.out.println("Erro: O número de vagas livres deveria ser 345 neste momento.");
            return false;
        }        
        
        return true;
    }
}
