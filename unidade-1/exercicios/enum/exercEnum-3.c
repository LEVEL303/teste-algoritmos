#include <stdio.h>

typedef enum mes {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Mes;

typedef struct data {
    int dia;
    Mes mes;
    int ano;
}Data;

void lerData(Data * data) {
    printf("Informe o dia:\n");
    scanf("%d", &data->dia);
    printf("Informe o numero do mes (1-12):\n");
    int mes;
    do {
        scanf("%d", &mes);
        if(mes < JANEIRO || mes > DEZEMBRO) {
            printf("Mes invalido! Tente novamente:\n");
        }
    } while(mes < JANEIRO || mes > DEZEMBRO);
    data->mes = mes;
    printf("Informe o ano:\n");
    scanf("%d", &data->ano);
}

void imprimirData(Data * data) {
    printf("%02d/%02d/%d\n", data->dia, data->mes, data->ano);
}

int main() {
    Data data;
    lerData(&data);
    imprimirData(&data);
    return 0;
}
