#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER
#define LENGTH_GRAPH 5

void show_menu(int *option);
void show_map_mampus(float graph[LENGTH_GRAPH][LENGTH_GRAPH]);
void menu_builds();
void insert_build(char text[], int *build);
void show_connections(float graph[LENGTH_GRAPH][LENGTH_GRAPH]);
void warshall(float reachability[LENGTH_GRAPH][LENGTH_GRAPH]);
void insert_builds(int *build1, int *build2);
void exist_path(float graph[LENGTH_GRAPH][LENGTH_GRAPH], float reachability[LENGTH_GRAPH][LENGTH_GRAPH], int build1, int build2);
void dijkstra(float graph[LENGTH_GRAPH][LENGTH_GRAPH], int initial, int final);
void clear();

#endif