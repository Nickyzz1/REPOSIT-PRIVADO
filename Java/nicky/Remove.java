public class Remove {
    // Método estático para remover um elemento de um array
    public static Person[] removeElement(Person[] array, int indexToRemove) {
        if (indexToRemove < 0 || indexToRemove >= array.length) {
            // Índice inválido, apenas retornar o array original
            return array;
        }
        
        // Criar um novo array com tamanho reduzido
        Person[] newArray = new Person[array.length - 1];
        
        // Copiar elementos do array original para o novo array, excluindo o elemento a ser removido
        int newIndex = 0;
        for (int i = 0; i < array.length; i++) {
            if (i != indexToRemove) {
                newArray[newIndex] = array[i];
                newIndex++;
            }
        }
        
        return newArray;
    }
}
