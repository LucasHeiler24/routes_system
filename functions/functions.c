#include <stdio.h>
#include "../headers/functions.h"
#define LENGTH_GRAPH 5

const char names[5][25] = {"Laboratorio", "Bloco B", "Bloco A", "Refeitorio", "Biblioteca"};

void show_menu(int *option){
	printf("\t=============================\n");
	printf("\tSISTEMA DE ROTAS DO CAMPUS\n");
	printf("\t=============================\n");
	printf("\t1 = Exibir mapa do campus\n");
	printf("\t2 = Encontrar menor rota entre dois predios\n");
	printf("\t3 = Verificar conexao entre dois predios\n");
	printf("\t4 = Exibir matriz de alcancabiliade\n");
	printf("\t5 = Sair \n");
	printf("\t=============================\n");
	printf("\tEscolha uma opcao:\n");
	scanf("\t%d", option);
}

void show_map_mampus(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){
	printf("\t=============================\n");
	printf("\tCAMINHOS ENTRE CADA PREDIO\n");
	printf("\t=============================\n");
	printf("\t%s <-------> %s:......%.2f metros\n", names[0], names[1], graph[0][1]);
	printf("\t%s <-------> %s:......%.2f metros\n", names[0], names[2], graph[0][2]);
	printf("\t%s <-------> %s:......%.2f metros\n", names[2], names[3], graph[2][3]);
	printf("\t%s <-------> %s:......%.2f metros\n", names[2], names[4], graph[2][4]);
	printf("\t%s <-------> %s:......%.2f metros\n", names[3], names[4], graph[3][4]);
	printf("\t=============================\n\n");
}

void menu_builds(){
	printf("\t=============================\n");
	printf("\tEDIFICIOS\n");
	printf("\t=============================\n");
	printf("\t0 = Laboratorio\n");
	printf("\t1 = Bloco B\n");
	printf("\t2 = Bloco A\n");
	printf("\t3 = Refeitorio\n");
	printf("\t4 = Biblioteca\n");
	printf("\t=============================\n");
}

void insert_build(char text[], int *build){
	do {
		printf("\t%s\n", text);
		scanf("%d", build);
	} while (*build < 0 || *build > 4);
}

void show_connections(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){
	printf("\t=============================\n");
	printf("\tEXISTE CAMINHO ENTRE CADA PREDIO\n");
	printf("\t=============================\n");
	printf("\t1 = Existe caminho\n");
	printf("\t0 = Nao existe caminho\n");
	printf("\t=============================\n");
	printf("\t\t\t%-20s %-20s %-18s %-18s %s\n", names[0], names[1], names[2], names[3], names[4]);
	
	for(int i=0; i<LENGTH_GRAPH; i++){
		printf("\t%-20s", names[i]);
		for(int j=0; j<LENGTH_GRAPH; j++){
			if(graph[i][j]) printf("%-20c", '1');
			else printf("%-20c", '0');
		}
		
		printf("\n");
	}
	printf("\n");
}

void warshall(float reachability[LENGTH_GRAPH][LENGTH_GRAPH]){
	for(int k=0; k<LENGTH_GRAPH; k++){
		for(int i=0; i<LENGTH_GRAPH; i++){
			for(int j=0; j<LENGTH_GRAPH; j++){
				if(reachability[i][j] > reachability[i][k] + reachability[k][j])
					reachability[i][j] = reachability[i][k] + reachability[k][j];
			}
		}
	}
}

void insert_builds(int *build1, int *build2){
	menu_builds();
	insert_build("Informe o primeiro predio:", build1);
    clear();
	menu_builds();
	insert_build("Informe o segundo predio:", build2);
}

void exist_path(float graph[LENGTH_GRAPH][LENGTH_GRAPH], float reachability[LENGTH_GRAPH][LENGTH_GRAPH], int build1, int build2){
	float distance_build1 = reachability[build1][build2];
	float distance_build2 = reachability[build2][build1];

	if(distance_build1 == distance_build2){
		printf("\tExiste caminho entre %s <----> %s, sendo:.....%.2f metros\n", names[build1], names[build2], distance_build1);
		dijkstra(graph, build1, build2);
		return;
	}
	
	printf("\tNao existe caminho entre %s <----> %s", names[build1], names[build2]);
}

void dijkstra(float graph[LENGTH_GRAPH][LENGTH_GRAPH], int initial, int final){

	if(initial == final){
		printf("\tVoce esta na mesma posicao.\n");
		return;
	}

	int visited[LENGTH_GRAPH] = {0, 0, 0, 0, 0};
	int idxs[LENGTH_GRAPH] = {-1, -1, -1, -1, -1};
	float distances[LENGTH_GRAPH] = {9999999, 9999999, 9999999, 9999999, 9999999};
	float total = 0.0, minor = 9999999;
	int idx = initial;

	visited[initial] = 1;
	distances[initial] = 0;
	idxs[initial] = initial;

	for(int i=0; i<LENGTH_GRAPH; i++){
		
		for(int j=0; j<LENGTH_GRAPH; j++){
			if(
				!visited[j] &&
				graph[idx][j] &&
				distances[j] > graph[idx][j] + total
			) {
				distances[j] = graph[idx][j] + total;
				idxs[j] = idx;
			}
		}
		
		for(int j=0; j<LENGTH_GRAPH; j++){
			if(minor > distances[j] && !visited[j]){
				minor = distances[j];
				idx = j;
			}
		}

		total = minor;
		minor = 9999999;
		visited[idx] = 1;
	}

	total = distances[final];
	idx = final;

	printf("\t==============================\n");
	printf("\tMELHOR CAMINHO DESCOBERTO\n");
	printf("\t==============================\n");
	printf("\tCaminhos:......%s", names[final]);
	for(int i=0; i<LENGTH_GRAPH; i++){
		if(idx != initial) {
			printf(" <- %s", names[idxs[idx]]);
			idx = idxs[idx];
		} 
		else break;
	}
	printf("\n\t------\n");
	printf("\tTotal a ser percorrido:.....%.2f metros\n", total);
	printf("\t------\n\n");
}

void clear(){
    #ifdef _WIN32 
        system("cls");
    #elif __linux 
        system("clear");
    #endif
}