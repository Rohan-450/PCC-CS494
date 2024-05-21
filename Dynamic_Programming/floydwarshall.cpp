#include<iostream>
#include<stdlib.h>
using namespace std;
//graph{k}[i][j]=min(graph{i-1}[i][j],graph{k-1}[i][k]+graph{k-1}[k][j])

void froydWarshall(int V, int **graph, int **dist, int **path) {
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      dist[i][j] = graph[i][j];
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
            dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j], path[i][j] = k;
      }
    }
  }
}

void printDistArr(int V, int **dist) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INT_MAX)
        cout << "INF\t";
      else
        cout << dist[i][j] << "\t";
    }
    cout << endl;
  }
}

void printPath(int u, int v, int **path) {
  if (path[u][v] == 0)
    cout << u << " -> " << v << " ";
  else {
    printPath(u, path[u][v], path);
    cout << " -> " << v << " ";
  }
}

void printDist(int V, int u, int v, int **dist, int **path) {
  if (dist[u][v] == INT_MAX)
    cout << "No path from " << u << " to " << v << endl;
  else {
    printPath(u, v, path);
    cout << "\t";
    cout << "Cost: " << dist[u][v] << endl;
  }
}

int main(){
	int n,graph[10][10],i,j;
	FILE *fp;
	fp = fopen("floyd.txt","r");
	if(fp==NULL){
		printf("Error");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	fclose(fp);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d   ",graph[i][j]);
		}
		printf("\n");
	}
	floydWarshall(graph,n);
	printResult(graph,n);
	
	
	
	return 0;
}