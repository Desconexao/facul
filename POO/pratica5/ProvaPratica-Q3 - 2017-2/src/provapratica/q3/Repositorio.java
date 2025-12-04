/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provapratica.q3;

/**
 *
 * @author felipe
 */
public interface Repositorio {
    public void guarda(Pessoa nova);
    public Pessoa recupera(String cpf);
    public Pessoa primeiro();
    public Pessoa proximo();
}
