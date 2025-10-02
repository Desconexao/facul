
package pratica2.ex3;

public class ControleRemoto {
    private Televisao televisao;

    public ControleRemoto(int canal, int volume) {
        this.televisao = new Televisao(canal, volume);
    }

    void controlaVolume(String escolha) {
        this.televisao.controlaVolume(escolha);
    }

    void controlaCanal(String escolha) {
        this.televisao.controlaCanal(escolha);
    }

    void escolheCanal(int novoCanal) {
        this.televisao.escolheCanal(novoCanal);
    }

    int getVolume() {
        return this.televisao.getVolume();
    }

    int getCanal() {
        return this.televisao.getCanal();
    }
}
