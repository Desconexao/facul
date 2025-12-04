package pratica3.blocodelembretes;

public class BlocoDeLembretes {
    private Lembrete[] lista;
    private int numeroDeLembretes;

    public BlocoDeLembretes() {
        lista = new Lembrete[10];
        numeroDeLembretes = 0;
    }

    public BlocoDeLembretes(int tamanho) {
        lista = new Lembrete[tamanho];
        numeroDeLembretes = 0;
    }

    public void incluirLembrete(Lembrete l) {
        if (numeroDeLembretes < lista.length) {
            lista[numeroDeLembretes++] = l;
        } else {
            Lembrete[] novaLista = new Lembrete[lista.length * 2];
            for (int i = 0; i < numeroDeLembretes; i++)
                novaLista[i] = lista[i];
            novaLista[numeroDeLembretes++] = l;
            lista = novaLista;
        }
    }

    public Lembrete excluirLembrete(int posicao) {
        if (posicao < numeroDeLembretes) {
            Lembrete excluido = lista[posicao];
            for (int i = posicao; i < numeroDeLembretes - 1; i++)
                lista[i] = lista[i + 1];
            numeroDeLembretes--;
            return excluido;
        }
        return null;
    }

    public void listarLembretes() {
        for (int i = 0; i < numeroDeLembretes; i++)
            lista[i].imprimir();
    }

    public int numeroDeLembretes() {
        return numeroDeLembretes;
    }

    public void buscarLembretesPorData(Data data) {
        int i;
        for (i = 0; i < numeroDeLembretes; i++) {
            if (lista[i].dataEhIgual(data))
                lista[i].imprimir();
        }
    }

    public void buscarLembretesPorNome(String substr) {
        int i;
        for (i = 0; i < numeroDeLembretes; i++) {
            if (lista[i].nomeContemSubstring(substr))
                lista[i].imprimir();
        }
    }

}
