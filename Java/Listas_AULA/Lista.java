class Lista <T>{  //lista hgenérica que pode pegar qualquer tipo de dado

    private Integer[] lista = new Integer[10]; //tem 10 posições
    private Integer index = 0; //index

    void add(Integer value) {
        if(index == lista.length) { //quando tem mais itens que o vetor pode comportar
            Integer[] copy = new Integer[lista.length *2];  //se a condição for verdadeira faz uma lista nova com o dobro do tamanho
            for(int i = 0; i < lista.length; i++) { //copia os dados de lista para lista nova
                copy[i] = lista[i];
            }
            lista = copy; //torna lista = lista nova
        }

        lista[index] = value; //caso não, ainda há espaço e ele irá adicionar normalmente o item a lista;
        index++;
        get(index);
    }

    Integer get(int indexGet) {  //um get para pegar o index se ele for privado
        if(indexGet >= index) {
            return null;
        }
        return this.lista[index];
    }
}

//array dinâmico --> memória continua
