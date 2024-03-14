#include <stdio.h>
#include <windows.h>


    void start(){
        int fla =1;
        int e;
        while(fla==1){
            printf("Deseja escolher algum produto? 1-sim, 0-não: ");
            scanf("%i",&start);
            if (start==1){
                while(fla=1){
                    printf("CHOSE OPTIONS:\n\n 1- PANIFICADORA\n 2-LIMPEZA\n 3-ALIMENTAÇÃO\n 5-BEBIDAS\n");
                    if (e==1){ 
                        panificadora();       
                    }
                    else if(e==2){
                        

                    }
            else{
                break;
            }
        }
        
    }



    }
    int panificadora(){
        int item;
        float valor[5];
            printf("Okay, set one products you want:\n\n 1-PÃO: $1,40\n 2-SALGADO: $3,50\n 3-PÃO DE QUEIJO: $1,20\n 4-ASSADO: $ 4,00\n9-ir para PAGAMENTO\n0-SAIR\n");
            scanf("%i", &item);
            if(item==1){
                valor[0] = 1.40;
            }

            else if(item==2){
                lista[0][0] = "PÃO";
                valor[0] = 1.40;
                lista[0][1] =valor[0];
                valor[0] = 3.50;
            }
            else if(item==3){
                valor[0] = 1.20;
            }
            else if(item==2){
                valor[0] = 4.00;
            }
            else if(item==9){
                pagamento();
            }
            else if(item==0){
                valor[0] = 3.50;
            }
            return valor;
    }


    int pagamento(float valor){
        printf("Vamos prosseguir para o pagamento!\n Sua lista de compras foi: ");

    }


int main(){
    int e;
    int start;
    int fla=1;
    int cont;
    int pan;

    float pao = 1.40;
    float salgado = 3.50;
    float paoq = 1.2;
    float assado = 4;



    

    }

}
   
    
    return 0;
}
