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
    printf("Informe o numero do mes:\n");
    int mes;
    do {
    scanf("%d")
    } while(mes < 1 && mes > 12);
}

void imprimirData(Data * data) {
    printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
}

int main() {
    Data data;

}
