public class ClassEmpregados {
    private String nome;
    private String cpf;
    private String dataNascimento;
    private Integer senha;
    private Boolean isadm;

    public ClassEmpregados(String nome, String cpf, String dataNascimento, Integer senha, Boolean isadm) { 
                                                                                                
        this.nome = nome; // o nome desse objeto atual é = a o nome parâmetro;
        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.senha = senha;
        this.isadm = isadm;
    }

    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public Integer getSenha() {
        return senha;
    }

    public Boolean getIsadm() {
        return isadm;
    }
}
