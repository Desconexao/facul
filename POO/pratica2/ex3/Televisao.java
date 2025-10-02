package pratica2.ex3;

public class Televisao {
    private int canal;
    private int volume;

    Televisao(int canal, int volume) {
        this.canal = canal;
        this.volume = volume;
    }

    void controlaVolume(String escolha) {
        if (escolha.toLowerCase().equals("aumentar"))
            this.volume += 1;
        else
            this.volume -= 1;
    }

    void controlaCanal(String escolha) {
        if (escolha.toLowerCase().equals("aumentar"))
            this.canal += 1;
        else
            this.canal -= 1;
    }

    void escolheCanal(int novoCanal) {
        System.out.println("Mudando do canal " + this.canal + " para o canal " + novoCanal);
        this.canal = novoCanal;
    }

    int getVolume() {
        return this.volume;
    }

    int getCanal() {
        return this.canal;
    }

}
