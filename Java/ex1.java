// compressor
public class Ex{
    public static void main(String[] args){
        int[] array = new int[] {
            244, 232, 241,123,
            232,064,111,140
        };
        int[] compact = Compact(array);
        // int[] conc = Concatenar(array);
        for(int i =0; i<array.length;i++){
            System.out.printf("\n%d", compact[i]);
        }
    }
    public static int[] Compact(int[] lista){
        int[] list = new int[lista.length/2];
        for(int i=0;i< list.length;i++){
            list[i]= (lista[i*2] & 240) | (lista[i*2+1]>>4);
        }
        return list;
    }


    // public static int[] Concatenar(int[] lista){
    //     for(int i =0; i<lista.length;i+=2){
    //         int prox = lista[i+1]>>4;
    //         int concat = lista[i] | prox;
    //         System.out.printf("\n%i\n", concat );

    //     }
    //     return ;

    // }
}
