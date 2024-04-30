#include<iostream>
#include<queue>
using namespace std;

void printGraph(int **graph, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}
void topoSort(int **graph, int n) {
  int *indegree = new int[n];
  for (int i = 0; i < n; i++) {
    indegree[i] = 0;
    for (int j = 0; j < n; j++) {
      indegree[i] += graph[j][i];
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (int i = 0; i < n; i++) {
      if (graph[node][i] == 1) {
        indegree[i]--;
        if (indegree[i] == 0) {
          q.push(i);
        }
      }
    }
  }
}
int main() {
  int n = 6;
  int **graph = new int*[n];
  for (int i = 0; i < n; i++) {
    graph[i] = new int[n];
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }
  graph[5][2] = 1;
  graph[5][0] = 1;
  graph[4][0] = 1;
  graph[4][1] = 1;
  graph[2][3] = 1;
  graph[3][1] = 1;
  cout << "Graph:" << endl;
  printGraph(graph, n);
  cout << "Topological Sort:" << endl;
  topoSort(graph, n);
  return 0;
}

