public class Pessoa {
    private String nome;
    private int age;
    private boolean isExApprentice;

    public Pessoa(String nome, int age, boolean isExApprentice){
        this.nome = nome;
        this.age = age;
        this.isExApprentice = isExApprentice;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }


    public boolean isExApprentice() {
        return isExApprentice;
    }

    public void setExApprentice(boolean isExApprentice) {
        this.isExApprentice = isExApprentice;
    }
}
