package pratica1.exComplementar;

public class Carro {
    String marca;
    String modelo;
    String ano;
    double velocidadeAtual;

    public void acelerar(double incremento) {
        this.velocidadeAtual += incremento;
    }

    public void frear(double decremento) {
        // para evitar velocidades negativas, que seria a marcha ré,
        // já que não foi implementado;
        if ((this.velocidadeAtual - decremento) < 0) {
            this.velocidadeAtual = 0.0;
            return;
        }
        this.velocidadeAtual -= decremento;
    }

    public void mostrarVelocidade() {
        System.out.println("Velocidade Atual: " + velocidadeAtual + " km/h");
    }
}
