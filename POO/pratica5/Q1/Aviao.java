package pratica5.Q1;

public class Aviao {
    private int numeroAviao;
    private Data dataDePartida;
    protected boolean[] poltronas;

    public Aviao(int numeroAviao, Data dataDePartida) {
        this.numeroAviao = numeroAviao;
        this.dataDePartida = dataDePartida;
        this.poltronas = new boolean[300];
        for (int i = 0; i < this.poltronas.length; i++) {
            poltronas[i] = false;
        }
    }

    public int proximoLivre() {
        for (int i = 0; i < this.poltronas.length; i++) {
            if (poltronas[i] == false)
                return i;

        }
        return -1;
    }

    public boolean verifica(int nAssento) {
        return this.poltronas[nAssento];
    }

    public boolean ocupa(int nAssento) {
        if (!verifica(nAssento)) {
            this.poltronas[nAssento] = true;
            return true;
        }
        return false;
    }

    public int vagas() {
        int numeroDeVagas = 0;
        for (int i = 0; i < this.poltronas.length; i++) {
            if (!this.poltronas[i])
                numeroDeVagas++;
        }
        return numeroDeVagas;

    }

    public int getNumero() {
        return this.numeroAviao;
    }

    public Data getData() {
        return this.dataDePartida;
    }

}
