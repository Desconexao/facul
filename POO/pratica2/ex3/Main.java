package pratica2.ex3;

public class Main {
    public static void main(String[] args) {
        ControleRemoto controle = new ControleRemoto(5, 10);

        System.out.println("Canal: " + controle.getCanal());
        System.out.println("Volume: " + controle.getVolume());

        controle.controlaCanal("aumeNtar");
        controle.controlaVolume("DiMinuir");

        System.out.println("Canal: " + controle.getCanal());
        System.out.println("Volume: " + controle.getVolume());

        controle.escolheCanal(10);
        System.out.println("Canal: " + controle.getCanal());

    }
}
