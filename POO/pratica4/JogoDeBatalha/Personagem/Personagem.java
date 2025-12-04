package pratica4.JogoDeBatalha.Personagem;

public abstract class Personagem {
    public String nome;
    public int ataque;
    public int defesa;
    public int saude;

    public Personagem(String nome, int ataque, int defesa, int saude) {
        this.nome = nome;
        this.ataque = ataque;
        this.defesa = defesa;
        this.saude = saude;
    }

    public void imprimirStatus() {
        System.out.printf("Informações do %s\n", this.nome);
        System.out.printf("\tNome do Personagem: %s", this.nome);
        System.out.printf("\tAtaque: %d", this.ataque);
        System.out.printf("\tDefesa: %d", this.defesa);
        System.out.printf("\tSaúde: %d\n", this.saude);
    }

    public abstract void atacar(Personagem inimigo);

}
