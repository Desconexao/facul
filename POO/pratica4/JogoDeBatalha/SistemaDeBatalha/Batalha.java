package pratica4.JogoDeBatalha.SistemaDeBatalha;

import pratica4.JogoDeBatalha.Personagem.Personagem;

public class Batalha {

    public static void tunoDeBatalha(Personagem atacante, Personagem defensor) {
        System.out.printf("%s está atacano o %s!!\n", atacante.nome, defensor.nome);
        atacante.atacar(defensor);
        defensor.imprimirStatus();

        if (defensor.saude == 0)
            System.out.printf("%s foi derrotado!!\n", defensor.nome);
    }

    public static Personagem duelar(Personagem p1, Personagem p2) {
        while (p1.saude > 0 && p2.saude > 0) {
            tunoDeBatalha(p1, p2);
            if (p2.saude == 0)
                break;
            tunoDeBatalha(p2, p1);
        }

        if (p1.saude > 0) {
            System.out.printf("%s é o vencedor!!", p1.nome);
            return p1;
        }
        System.out.printf("%s é o vencedor!!", p2.nome);
        return p2;

    }
}
