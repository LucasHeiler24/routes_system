#include <stdio.h>
#include "./functions/functions.c"
#define LENGTH_GRAPH 5

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
	int build1 = -1, build2 = -1;

	warshall(reachability);

	do {
		show_menu(&option);
		switch(option){
			case 1:
				clear();
				show_map_mampus(graph);
				break;
			case 2:
				clear();
				insert_builds(&build1, &build2);
				dijkstra(graph, build1, build2);
				break;
			case 3:
				clear();
				insert_builds(&build1, &build2);
				exist_path(graph, reachability, build1, build2);
				break;
			case 4:
				clear();
				show_connections(graph);
				break;
			case 5:
				clear();
				printf("\tTchau\n");
				break;
			default:
				clear();
				printf("\tOpcao errada, tente novamente!\n");
		}
	} while(option != 5);

	return 0;
}
