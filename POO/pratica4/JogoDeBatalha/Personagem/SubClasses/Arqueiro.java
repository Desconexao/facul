package pratica4.JogoDeBatalha.Personagem.SubClasses;

import java.util.Random;

import pratica4.JogoDeBatalha.Personagem.Personagem;

public class Arqueiro extends Personagem {
    public Arqueiro(String nome, int ataque, int defesa, int saude) {
        super(nome, ataque, defesa, saude);
    }

    public void atacar(Personagem inimigo) {
        Random random = new Random();
        if (random.nextInt(4) == 0)
            return;
        if (this.ataque <= inimigo.defesa)
            return;
        int dano = this.ataque - inimigo.defesa;
        if (inimigo.saude - dano < 0) {
            inimigo.saude = 0;
            return;
        }

        inimigo.saude -= dano;
    }

}
