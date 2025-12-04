package pratica4.JogoDeBatalha.Personagem.SubClasses;

import pratica4.JogoDeBatalha.Personagem.Personagem;

public class Guerreiro extends Personagem {
    public Guerreiro(String nome, int ataque, int defesa, int saude) {
        super(nome, ataque, defesa, saude);
    }

    public void atacar(Personagem inimigo) {
        int ataqueMod = this.ataque + 2; // Guerreiro: +2
        if (ataqueMod <= inimigo.defesa)
            return;
        int dano = ataqueMod - inimigo.defesa;
        if (inimigo.saude - dano < 0) {
            inimigo.saude = 0;
            return;
        }

        inimigo.saude -= dano;
    }
}
