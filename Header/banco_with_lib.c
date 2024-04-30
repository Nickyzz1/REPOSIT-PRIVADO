#include "Banco.h"
#include <stdio.h>


int main(){
    printf("---------------------------------------------\n");
    printf("--------------------BANCO--------------------\n");
    printf("---------------------------------------------\n");
    int fla =1;
    float saldo = 0;
    float emp;
    int count_d;
    int count_e;
    char name[10];

    printf("Enter your name: ");
    scanf("%s", &name);

    while(fla == 1)
    {
        float op;
        float deposit =0;
        float valor=0;
        printf("\nWelcome to Banco! Choose a option:\n0-EXIT\n1-CHEACK ACCOUNT BALANCE\n2-CHEACK ACOUNT\n3-DEPOSIT\n4-WITHDRAW(saque)\n5-LOAN(emp)\n6-EXTRAT\n");
        scanf("%f", &op);
        //sair

        if(op==0){
            fla=0;
        }
        //saldo
        else if(op==1){
            printf("That's you account ballance: %f\n", saldo );
        }
        //cheack account
        else if(op==2){
            printf("Account of: %s\n", name);
        }
        //deposit
        else if(op==3){
            printf("Enter you deposit: ");
            scanf("%f", &deposit);
            printf("Right! Now you ballance account is: %.2f\n", Deposit(valor, deposit));
            saldo = Deposit(deposit,saldo);
            count_d += 1;
        }
        //saque
        else if(op==4){
            printf("Enter your withdraw: ");
            scanf("%f", &valor);
            if(valor <= saldo){
                saldo = Saque(valor,saldo);
            }else if(valor>saldo){
                printf("You can't withdraw more then you have!");
            }
            else{
                printf("Something are wrong...");
            }
        }
        //loan
        else if(op==5){
            printf("Enter the how many you want loan: ");
            scanf("%f", &emp);
            if(saldo*4>saldo){
                printf("This amount is not available for your bank loan!");
            }
            else{
                printf("The amount: %f was loan succesfully\n",Emp(emp));
                emp = Emp(emp);
                count_e+=1;
        }
        }
        //extrat
        else if(op==6){
            printf("Datas:\n");
            printf("---------------------------");
            printf("Your balance: %f\n", saldo);
            printf("Your Loans: %f\n", emp);
            printf("How many deposits: %i\n", count_d);
            printf("How many loans: %i\n", count_e);

        }

        }
        return 0;

}
        
