package pratica2.ex1;

public class Pessoa {
    private String nome;
    private Data dataNascimento;
    private double altura;

    Pessoa(String nome, int diaNascimento, int mesNascimento, int anoNascimento, double altura) {
        this.nome = nome;
        this.dataNascimento = new Data(diaNascimento, mesNascimento, anoNascimento);
        this.altura = altura;

    }

    void setNome(String nome) {
        this.nome = nome;
    }

    void setDataNascimento(int diaNascimento, int mesNascimento, int anoNascimento) {
        this.dataNascimento = new Data(diaNascimento, mesNascimento, anoNascimento);
    }

    void setAltura(double altura) {
        this.altura = altura;
    }

    String getNome() {
        return this.nome;
    }

    Data getDataNascimento() {
        return this.dataNascimento;
    }

    double getAltura() {
        return this.altura;
    }

    void imprimirDados() {
        System.out.println("Nome: " + this.nome);
        System.out.println("Data de nascimento: ");
        this.dataNascimento.imprimeData();
        System.out.println("Altura: " + this.altura);
    }

    int calculaIdade(Data dataAtual) {
        int idade = dataAtual.getAno() - this.dataNascimento.getAno();

        if ((dataAtual.getMes() < this.dataNascimento.getMes())
                || ((dataAtual.getMes() == this.dataNascimento.getMes()) &&
                        dataAtual.getDia() < this.dataNascimento.getDia()))
            idade--;

        return idade;
    }
}
