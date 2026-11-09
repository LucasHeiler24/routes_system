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

void smallerDistance(float graph[LENGTH_GRAPH][LENGTH_GRAPH]){

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

int main(void)
{
	float graph[LENGTH_GRAPH][LENGTH_GRAPH] = {
		{0, 240, 210, 0, 0},
		{240, 0, 0, 0, 0},
		{210, 0, 0, 190, 160},
		{0, 0, 190, 0, 280},
		{0, 0, 160, 280, 0}
	};
	int option = -1;

	do {
		showMenu(&option);
		switch(option){
			case 1:
				system("clear");
				showMapCampus(graph);
				break;
			case 2:
				system("clear");
				smallerDistance(graph);
				break;
			case 3:
				system("clear");
				break;
			case 4:
				system("clear");
				showConnections(graph);
				break;
			case 5:
				system("clear");
				printf("\tTchau\n");
				break;
			default:
				system("clear");
				printf("\tOpcao errada, tente novamente!\n");
		}
	} while(option != 5);

	return 0;
}
