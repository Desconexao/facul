package pratica3.ex2;

public class BlocoDeLembretes {
    private Lembrete[] lembretes;

    public BlocoDeLembretes(int tamanho) {
        lembretes = new Lembrete[tamanho];
    }

    public BlocoDeLembretes() {
        this(5);
    }
}
