package pratica4.JogoDeBatalha;

import pratica4.JogoDeBatalha.Personagem.SubClasses.Guerreiro;
import pratica4.JogoDeBatalha.Personagem.SubClasses.Mago;
import pratica4.JogoDeBatalha.SistemaDeBatalha.Batalha;

class Main {
    public static void main(String[] args) {
        Guerreiro guerreiro = new Guerreiro("Cleiton", 8, 6, 18);
        Mago mago = new Mago("Mestre", 10, 3, 19);

        // Batalha.tunoDeBatalha(guerreiro, mago);
        // Batalha.tunoDeBatalha(mago, guerreiro);
        Batalha.duelar(guerreiro, mago);
    }
}
