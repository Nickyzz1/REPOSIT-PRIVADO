import java.util.Arrays;
import java.util.Scanner;

class Solution {

    int sum = 0;
    public int[] twoSum(int[] nums, int target) {
        int i = 0;
        while(i < nums.length){
            for(int j = 0; j < nums.length; j++)
            {
                sum = nums[i] + nums[j];
                if(sum == target)
                {
                    int[] cordinates = {i,j};
                    return cordinates;
                }
                sum = 0;
            }
        }
        return null;
    }

    public static void main(String[] args)
    {
        int[] numeros = new int[255];

        Scanner scan = new Scanner(System.in);
        System.out.printf("enter how many numbers you wanna add:");
        int num = scan.nextInt();
        
        for(int i = 0; i < num; i++)
        {
            System.out.printf("\nenter a number %d\n--:", i);
            numeros[i] = {scan.nextInt()};
        }

        System.out.printf("\nenter your target:\n--");
        int target = scan.nextInt();
        
        Solution ob = new Solution();
        if(ob.twoSum(numeros, target) == null)
        System.out.println( "Não há nenhum número que dá essa soma");
        else{
            System.out.println("as coordenadas sao " + Arrays.toString(ob.twoSum(numeros, target)));
        }

    }
}
