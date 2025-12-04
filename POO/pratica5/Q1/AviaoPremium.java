package pratica5.Q1;

public class AviaoPremium extends Aviao {

    private int totalAssentos;
    private int assentosPremium;

    public AviaoPremium(int numeroAviao, Data dataDePartida, int totalAssentos, int assentosPremium) {
        super(numeroAviao, dataDePartida);
        this.totalAssentos = totalAssentos;
        this.assentosPremium = assentosPremium;

        this.poltronas = new boolean[this.totalAssentos];
    }

    public int maxVagas() {
        return this.totalAssentos;
    }

    public int cadeirasPremium() {
        return this.assentosPremium;
    }

    public char tipo(int numeroPoltrona) {
        if (numeroPoltrona < this.assentosPremium)
            return 'P';
        return 'C';
    }

    public int proximoLivre() {
        for (int i = this.assentosPremium; i < this.poltronas.length; i++)
            if (!poltronas[i])
                return i;
        return -1;
    }

    public int proximoPremiumLivre() {
        for (int i = 0; i < this.assentosPremium; i++)
            if (!poltronas[i])
                return i;
        return -1;
    }

}
