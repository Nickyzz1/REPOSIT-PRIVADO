package oldPonto;

public class Empregado {
    // Definindo todas os atributos da classe como privados, pois se tratam de informações pessoais dos usuários
    private String nomeUsuario;
    private String cpfUsuario;
    private String nascimentoUsuario;
    private String senhaUsuario;
    // private String adminUsuario;

    // Criando o método para pegar os dados do usuário e poder manipular eles
    void novoEmpregado(String nome, String cpf, String nascimento, String senha, String admin){
        nomeUsuario = nome;
        cpfUsuario = cpf;
        nascimentoUsuario = nascimento;
        senhaUsuario = senha;
        // adminUsuario = admin;
    }

    // get e set nome
    String getNome(){
        return nomeUsuario;
    }
    void setNome(String nome){
        nomeUsuario = nome;
    }

    // get e set cpf
    String getCpf(){
        return cpfUsuario;
    }
    void setCpf(String cpf){
        cpfUsuario = cpf;
    }

    // get e set nascimento
    String getNascimento(){
        return nascimentoUsuario;
    }
    void setNascimento(String nascimento){
        nascimentoUsuario = nascimento;
    }

    // get e set senha
    String getSenha(){
        return senhaUsuario;
    }
    void setSenha(String senha){
        senhaUsuario = senha;
    }

    // // get e set admin
    // String admin(){
    //     return adminUsuario;
    // }
    // void setAdmin(String admin){
    //     adminUsuario = admin;
    // }

    private String cpfCadastrado;
    private String senhaCadastrado;
    void usuarioCadastrado(String cpf, String senha){
        cpfCadastrado = cpf;
        senhaCadastrado = senha;
        boolean isAdmin = false;

        if(cpfCadastrado == "13175436960" & senhaCadastrado == "sasa123"){
            isAdmin = true;
        }
    }


}
