public class ClassEmpregados {

    String nome;
    String cpf;
    String dataNascimento;
    Integer senha;
    Boolean isadm;

    ClassEmpregados(String nome, String cpf, String dataNascimento, Integer senha, Boolean isadm) { //contrutor, permite bdados diretamente na função; não te,m porefixo de tipo, apenas o mesmo nome da classe
        this.nome = nome; //o nome desse objeto atual é = a o nome parâmetro;
        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.senha = senha;
        this.isadm = isadm;
    }
}