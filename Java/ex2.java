public class ex2{ //compactação de 3 byts e não de 4
    public static void main(String args[]){
        int[] array=
        {
            244, 232, 241, 123,
            232, 64, 111, 140
        };
        System.out.printf("\nREDUCE\n\n");
        int[] reduce = Reduce(array);
        System.out.printf("\nCOMPACT\n\n");
        int[] compact = Compact(array);
        int[] deescompact = Descompact(array);
    }
    public static int[] Reduce(int[] array){
        for(int i=0; i< array.length;i++){
            array[i] = array[i] & 224;
            System.out.printf("%d\n", array[i]);
        }
        return array;
    }
    public static int[] Compact(int[] array){
        int[] array_compact= new int[array.length/2];
        for(int i=0, j = 0; i<array.length;i+=2, ++j){
           int temp = array[i] | (array[i+1]>>3); 
            System.out.printf("%d\n", temp);
            array_compact[j]= temp;
        }
        return array_compact;}
    public static int[] Descompact(int[] array_compact){
        int[] array_desc = new int[array_compact.length*2] ;
        return array_desc;
    }
}
