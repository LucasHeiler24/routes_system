#include <stdio.h>
#include <string.h>
#define LENGTH_GRAPH 5

const char names[5][25] = {"Laboratorio", "Bloco B", "Bloco A", "Refeitorio", "Biblioteca"};

void showMenu(int *option){
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

void showMapCampus(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){
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

void smallerDistance(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){}

void menuBuilds(){
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

void insertBuild(char text[], int *build){
	do {
		printf("\t%s\n", text);
		scanf("%d", build);
	} while (*build < 0 || *build > 4);
}

void showConnections(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){
	printf("\t=============================\n");
	printf("\tEXISTE CAMINHO ENTRE CADA PREDIO\n");
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

void showGraph(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){
	for(int i=0; i<LENGTH_GRAPH; i++){
		for(int j=0; j<LENGTH_GRAPH; j++)
			printf("%.2f ", graph[i][j]);
		printf("\n");
	}
}

void makeReachability(float reachability[LENGTH_GRAPH][LENGTH_GRAPH]){
	for(int k=0; k<LENGTH_GRAPH; k++){
		for(int i=0; i<LENGTH_GRAPH; i++){
			for(int j=0; j<LENGTH_GRAPH; j++){
				if(reachability[i][j] > reachability[i][k] + reachability[k][j])
					reachability[i][j] = reachability[i][k] + reachability[k][j];
			}
		}
	}
}

void existPath(float graph[LENGTH_GRAPH][LENGTH_GRAPH], float reachability[LENGTH_GRAPH][LENGTH_GRAPH]){

	int build1 = -1, build2 = -1;

	menuBuilds();
	insertBuild("Informe o primeiro predio:", &build1);
	system("clear");
	menuBuilds();
	insertBuild("Informe o segundo predio:", &build2);
	
	float distance_build1 = reachability[build1][build2];
	float distance_build2 = reachability[build2][build1];

	if(distance_build1 == distance_build2)
		printf("Existe caminho entre %s <----> %s, sendo:.....%.2f metros", names[build1], names[build2], distance_build1);
	else 
		printf("Nao existe caminho entre %s <----> %s", names[build1], names[build2]);

}

typedef struct {
	float meters;
	int vertex;
} VertexEdge;

void showPath(float graph[LENGTH_GRAPH][LENGTH_GRAPH], int initial, int final){

	if(initial == final){
		printf("\tVoce esta na mesma posicao.");
		return;
	}

	VertexEdge vertex_edge[LENGTH_GRAPH][LENGTH_GRAPH];
}

int main(void)
{
	float graph[LENGTH_GRAPH][LENGTH_GRAPH] = {
		{0, 240, 210, 0, 0},
		{240, 0, 0, 0, 0},
		{210, 0, 0, 190, 160},
		{0, 0, 190, 0, 280},
		{0, 0, 160, 280, 0}
	};
	float reachability[LENGTH_GRAPH][LENGTH_GRAPH] = {
		{0, 240, 210, 9999999, 9999999},
		{240, 0, 9999999, 9999999, 9999999},
		{210, 9999999, 0, 190, 160},
		{9999999, 9999999, 190, 0, 280},
		{9999999, 9999999, 160, 280, 0}
	};
	int option = -1;

	makeReachability(reachability);
	showPath(graph, 2, 0);

	// do {
	// 	showMenu(&option);
	// 	switch(option){
	// 		case 1:
	// 			system("clear");
	// 			showMapCampus(graph);
	// 			break;
	// 		case 2:
	// 			system("clear");
	// 			smallerDistance(graph);
	// 			break;
	// 		case 3:
	// 			system("clear");
	// 			existPath(reachability);
	// 			break;
	// 		case 4:
	// 			system("clear");
	// 			showConnections(graph);
	// 			break;
	// 		case 5:
	// 			system("clear");
	// 			printf("\tTchau\n");
	// 			break;
	// 		default:
	// 			system("clear");
	// 			printf("\tOpcao errada, tente novamente!\n");
	// 	}
	// } while(option != 5);

	return 0;
}
