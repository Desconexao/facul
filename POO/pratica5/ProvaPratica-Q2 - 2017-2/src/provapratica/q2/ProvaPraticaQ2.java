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
public class ProvaPraticaQ2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Aviao aviao = new Aviao(4188, new Data(26,2,2018));
        
        // -- Verifica situação inicial ----------------------------------------
        if (Verifica.situacao01(aviao))
            System.out.println("A instância do Aviao foi criada de forma apropriada.");
        else
            System.out.println("Erro: a instância não foi inicializada de forma correta.");
        
        // -- Verifica situação intermediaria ----------------------------------
        if (Verifica.situacao02(aviao)) {
            System.out.println("--------------------------------------------------");
            System.out.println("Número do Vôo: " + aviao.getNumeroDoVoo());
            System.out.println("Data do Vôo: " + aviao.getData());
            System.out.println("Número de Assentos Livres: " + aviao.vagas());
            System.out.println("--------------------------------------------------");
            System.out.println("Parabéns, as operações funcionaram como esperado!");
        } else
            System.out.println("Erro: existem problemas na implementação das operações.");

    
        // -- Verifica situação Vôo Premium ------------------------------------
        AviaoPremium aviaoPremium = new AviaoPremium(6155, new Data(26,2,2018), 350, 50);
        if (Verifica.situacao03(aviaoPremium)) {
            System.out.println("--------------------------------------------------");
            System.out.println("Número do Vôo: " + aviaoPremium.getNumeroDoVoo());
            System.out.println("Data do Vôo: " + aviaoPremium.getData());
            System.out.println("Número de Assentos Livres: " + aviaoPremium.vagas());
            System.out.println("--------------------------------------------------");
            System.out.println("Parabéns, as operações funcionaram como esperado!");
        } else
            System.out.println("Erro: existem problemas na implementação das operações.");
    }
}