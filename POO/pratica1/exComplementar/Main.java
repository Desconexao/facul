package pratica1.exComplementar;

public class Main {

    public static void main(String[] args) {
        Carro carro1 = new Carro();

        carro1.marca = "Fiat";
        carro1.modelo = "Pulse Hybrid";
        carro1.ano = "2025";
        carro1.velocidadeAtual = 0.0;

        carro1.mostrarVelocidade();
        carro1.acelerar(25.0);
        carro1.mostrarVelocidade();
        carro1.frear(20);
        carro1.mostrarVelocidade();
        carro1.frear(10);
        carro1.mostrarVelocidade();

    }
}
