
#include <stdio.h>

typedef struct{
    int horas;
    int minutos;
    int segundos;

}Horario;

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {

    char descricao[100];
    Data data;
    Horario horario;

}Compromisso;

int main() 
{
    Compromisso compromisso1;

    compromisso1.horario.horas = 10;
    compromisso1.horario.minutos = 20;
    compromisso1.horario.segundos = 5;
    compromisso1.data.dia = 27;
    compromisso1.data.mes = 10;
    compromisso1.data.mes = 2;

    printf("%s", compromisso1);

}
