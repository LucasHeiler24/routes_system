#include<stdio.h>

typedef struct
{
    char *name;
} No;

typedef struct
{
    No *no1;
    No *no2;
    int weight;
} Aresta;

typedef struct graph
{
    int length;
    Aresta **list
} Graph;

void init(){

    No *noBlocoA = malloc(sizeof(No*));
    No *noBlocoB = malloc(sizeof(No*));
    No *noLaboratorio = malloc(sizeof(No*));
    No *noBiblioteca = malloc(sizeof(No*));
    No *noRefeitorio = malloc(sizeof(No*));

    noBlocoA->name = "BLOCO A";
    noBlocoB->name = "BLOCO B";
    noLaboratorio->name = "LABORATORIO";
    noBiblioteca->name = "BIBLIOTECA";
    noRefeitorio->name = "REFEITORIO";

    Aresta *arestaBlocoALaboratorio = malloc(sizeof(Aresta*));
    Aresta *arestaBlocoABiblioteca = malloc(sizeof(Aresta*));
    Aresta *arestaBlocoARefeitorio = malloc(sizeof(Aresta*));
    Aresta *arestaRefeitorioBiblioteca = malloc(sizeof(Aresta*));
    Aresta *arestaLaboratorioBlocoB = malloc(sizeof(Aresta*));

    arestaBlocoALaboratorio->no1 = noBlocoA;
    arestaBlocoALaboratorio->no2 = noLaboratorio;
    arestaBlocoALaboratorio->weight = 210;

    arestaBlocoABiblioteca->no1 = noBlocoA;
    arestaBlocoABiblioteca->no2 = noBiblioteca;
    arestaBlocoABiblioteca->weight = 160;

    arestaBlocoARefeitorio->no1 = noBlocoA;
    arestaBlocoARefeitorio->no2 = noRefeitorio;
    arestaBlocoARefeitorio->weight = 190;

    arestaRefeitorioBiblioteca->no1 = noRefeitorio;
    arestaRefeitorioBiblioteca->no2 = noBiblioteca;
    arestaRefeitorioBiblioteca->weight = 280;

    arestaLaboratorioBlocoB->no1 = noLaboratorio;
    arestaLaboratorioBlocoB->no2 = noBlocoB;
    arestaLaboratorioBlocoB->weight = 280;
}

int main(void) {

    return 0;
}