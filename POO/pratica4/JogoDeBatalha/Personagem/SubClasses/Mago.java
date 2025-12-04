package pratica4.JogoDeBatalha.Personagem.SubClasses;

import pratica4.JogoDeBatalha.Personagem.Personagem;

public class Mago extends Personagem {
    public Mago(String nome, int ataque, int defesa, int saude) {
        super(nome, ataque, defesa, saude);
    }

    public void atacar(Personagem inimigo) {
        int reducaoDefesa = inimigo.defesa / 2; // Considera apenas metade da defesa do inimigo no ataque
        if (this.ataque <= reducaoDefesa)
            return;
        int dano = this.ataque - reducaoDefesa;
        if (inimigo.saude - dano < 0) {
            inimigo.saude = 0;
            return;
        }

        inimigo.saude -= dano;
    }

}
