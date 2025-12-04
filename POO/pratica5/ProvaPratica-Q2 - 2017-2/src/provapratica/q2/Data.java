/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provapratica.q2;

/**
 *
 * @author felipe
 */
public class Data {
    public int dia;
    public int mes;
    public int ano;
    
    public Data (int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }
    
    @Override
    public String toString() {
        return dia + "/" + mes + "/" + ano;
    }
}
