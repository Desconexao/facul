package pratica3.ex2;

public class Lembrete {
    private String nome;
    private String descricao;
    private Data data;

    public Lembrete(String nome, String descricao, Data data) {
        this.nome = nome;
        this.descricao = descricao;
        this.data = data;
    }

    public Lembrete(String nome, String descricao) {
        this(nome, descricao, new Data());
    }

    public void imprimir() {
        System.out.println("########################################");
        System.out.println("Nome do Lembrete: " + nome);
        System.out.print("Data: ");
        data.imprimir();
        System.out.println("Descrição: " + descricao);

        System.out.println("########################################");

    }
}
