package pratica3.blocodelembretes;

import java.util.Scanner;

public class LembretesApp {
    private BlocoDeLembretes bloco;

    /**
     * Método construtor
     */
    public LembretesApp() {
        bloco = new BlocoDeLembretes(2);
    }

    /**
     * Exercício 10 - Menu principal da aplicação, dando ao usuário a chance de
     * escolher uma das opções.
     * 
     * @return Retorna um inteiro com a opção escolhida pelo usuário.
     */
    private int menu() {
        int opcao = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("###  Lembretes App - A lista contém " + bloco.numeroDeLembretes() + " lembretes ###");
            System.out.println("Escolha uma das seguintes opções:");
            System.out.println("1- Adicionar novo lembrete");
            System.out.println("2- Remover lembrete");
            System.out.println("3- Listar");
            System.out.println("4- Busca por data");
            System.out.println("5- Busca por nome");
            System.out.println("6- Sair");

            opcao = sc.nextInt();
        } while (opcao < 1 && opcao > 6);
        return opcao;
    }

    /**
     * Método auxiliar para ler dados de um lembrete.
     */
    private Lembrete lerDadosDoLembrete() {
        Scanner sc = new Scanner(System.in);
        System.out.println("# Dados do Lembrete #");
        System.out.print("Digite o dia: ");
        byte dia = sc.nextByte();
        System.out.print("Digite o mês: ");
        byte mes = sc.nextByte();
        System.out.print("Digite o ano: ");
        short ano = sc.nextShort();
        sc.nextLine();
        System.out.print("Digite o assunto do lembrete: ");
        String nome = sc.nextLine();
        System.out.print("Digite a descrição do lembrete: ");
        String descricao = sc.nextLine();
        return new Lembrete(nome, descricao, new Data(dia, mes, ano));
    }

    /**
     * Exercício 11 - Método principal com laço para o menu.
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        LembretesApp app = new LembretesApp();
        int opcao;
        Scanner sc = new Scanner(System.in);

        do {
            opcao = app.menu();

            switch (opcao) {
                case 1:
                    app.bloco.incluirLembrete(app.lerDadosDoLembrete());
                    break;
                case 2:
                    System.out.print("Índice do lembrete a ser removido: ");
                    app.bloco.excluirLembrete(sc.nextInt());
                    break;
                case 3:
                    app.bloco.listarLembretes();
                    break;
                case 4:
                    System.out.println("# Buscar por data #");
                    byte d, m;
                    short a;
                    System.out.print("Qual o dia? ");
                    d = sc.nextByte();
                    System.out.print("Qual o mes? ");
                    m = sc.nextByte();
                    System.out.print("Qual o ano? ");
                    a = sc.nextShort();
                    app.bloco.buscarLembretesPorData(new Data(d, m, a));
                    break;
                case 5:
                    System.out.print("Buscar por nome: ");
                    app.bloco.buscarLembretesPorNome(sc.nextLine());
                    break;
            }
        } while (opcao != 6);

        /*
         * BlocoDeLembretes bloco = new BlocoDeLembretes(2);
         * bloco.incluirLembrete(
         * new Lembrete("Aula de POO",
         * "Segundas às 15:10",
         * new Data((byte) 28,(byte) 3, (short) 2022)));
         * bloco.incluirLembrete(
         * new Lembrete("Compras",
         * "Mercado",
         * new Data((byte) 28,(byte) 3, (short) 2022)));
         * bloco.incluirLembrete(new Lembrete("Dentista",
         * "Clinica X",
         * new Data((byte) 30,(byte) 3, (short) 2022)));
         * //Lembrete excluido = bloco.excluirLembrete(2);
         * bloco.listarLembretes();
         * 
         * //System.out.println("--- Lembrete Excluído: ---");
         * //excluido.imprimir();
         * 
         * Data minhaData = new Data((byte) 28,(byte) 3, (short) 2022);
         * System.out.println("--- Lembretes para a data " + minhaData.getData() +
         * " ---");
         * bloco.buscarLembretesPorData(minhaData);
         * 
         * System.out.println("--- Lembretes por nome ---");
         * bloco.buscarLembretesPorNome("Com");
         */
    }

}
