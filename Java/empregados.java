import java.util.LinkedList;
import java.util.Scanner;

class Empregado {
    private String nome;
    private String cpf;
    private String dataNascimento;
    private String senha;
    private boolean administrador;

    public Empregado(String nome, String cpf, String dataNascimento, String senha, boolean administrador) {
        this.nome = nome;
        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.senha = senha;
        this.administrador = administrador;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public boolean isAdministrador() {
        return administrador;
    }

    public void setAdministrador(boolean administrador) {
        this.administrador = administrador;
    }
}

class Ponto {
    private String cpf;
    private String data;
    private String horario;

    public Ponto(String cpf, String data, String horario) {
        this.cpf = cpf;
        this.data = data;
        this.horario = horario;
    }

    // Getters e Setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getHorario() {
        return horario;
    }

    public void setHorario(String horario) {
        this.horario = horario;
    }
}

public class SistemaDePonto {
    public static void main(String[] args) {
        LinkedList<Empregado> listaDeEmpregados = new LinkedList<>();
        LinkedList<Ponto> registrosDePonto = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        // Menu principal
        while (true) {
            System.out.println("\n------ BEM VINDO AO SISTEMA DE PONTO ------");
            System.out.println("1 - Fazer login");
            System.out.println("2 - Sair do sistema");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            if (opcao == 1) {
                System.out.print("Digite seu CPF: ");
                String cpf = scanner.nextLine();
                System.out.print("Digite sua senha: ");
                String senha = scanner.nextLine();

                Empregado empregado = buscarEmpregado(listaDeEmpregados, cpf, senha);
                if (empregado != null) {
                    if (empregado.isAdministrador()) {
                        menuAdministrador(listaDeEmpregados, registrosDePonto, scanner);
                    } else {
                        registrarPonto(registrosDePonto, cpf, scanner);
                    }
                } else {
                    System.out.println("CPF ou senha incorretos. Tente novamente.");
                }
            } else if (opcao == 2) {
                System.out.println("Saindo do sistema. Até mais!");
                break;
            } else {
                System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    // Método para buscar um empregado na lista pelo CPF e senha
    private static Empregado buscarEmpregado(LinkedList<Empregado> listaDeEmpregados, String cpf, String senha) {
        for (Empregado empregado : listaDeEmpregados) {
            if (empregado.getCpf().equals(cpf) && empregado.getSenha().equals(senha)) {
                return empregado;
            }
        }
        return null;
    }

    // Menu para o administrador
    private static void menuAdministrador(LinkedList<Empregado> listaDeEmpregados, LinkedList<Ponto> registrosDePonto, Scanner scanner) {
        while (true) {
            System.out.println("\n------ MENU ADMINISTRADOR ------");
            System.out.println("1 - Cadastrar novo empregado");
            System.out.println("2 - Listar empregados");
            System.out.println("3 - Consultar horas trabalhadas por empregado em um mês");
            System.out.println("4 - Voltar ao menu principal");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            if (opcao == 1) {
                cadastrarEmpregado(listaDeEmpregados, scanner);
            } else if (opcao == 2) {
                listarEmpregados(listaDeEmpregados);
            } else if (opcao == 3) {
                consultarHorasTrabalhadas(registrosDePonto, scanner);
            } else if (opcao == 4) {
                break;
            } else {
                System.out.println("Opção inválida. Tente novamente.");
            }
        }
    }

    // Método para cadastrar um novo empregado
    private static void cadastrarEmpregado(LinkedList<Empregado> listaDeEmpregados, Scanner scanner) {
        System.out.print("Nome do empregado: ");
        String nome = scanner.nextLine();
        System.out.print("CPF do empregado: ");
        String cpf = scanner.nextLine();
        System.out.print("Data de nascimento do empregado: ");
        String dataNascimento = scanner.nextLine();
        System.out.print("Senha do empregado: ");
        String senha = scanner.nextLine();
        System.out.print("O empregado é administrador? (S/N): ");
        String admin = scanner.nextLine();
        boolean administrador = admin.equalsIgnoreCase("S");

        Empregado novoEmpregado = new Empregado(nome, cpf, dataNascimento, senha, administrador);
        listaDeEmpregados.add(novoEmpregado);
        System.out.println("Empregado cadastrado com sucesso!");
    }

    // Método para listar os empregados cadastrados
    private static void listarEmpregados(LinkedList<Empregado> listaDeEmpregados) {
        System.out.println("\n------ LISTA DE EMPREGADOS ------");
        for (Empregado empregado : listaDeEmpregados) {
            System.out.println(empregado.getNome() + " - " + empregado.getCpf());
        }
    }

    // Método para registrar o ponto de um empregado
    private static void registrarPonto(LinkedList<Ponto> registrosDePonto, String cpf, Scanner scanner) {
        // Implemente o registro de ponto aqui
