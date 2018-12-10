#include<bits/stdc++.h>

using namespace std;

int n, u, v;
int graph[102][102], path[102], flag[102];

bool isSafe(int x) { 
  return flag[x] == 0; 
} 

void printSolution(int step) { 
  for (int i = 0; i < step; i++) 
    cout << path[i] << " ";
  cout << v << endl;
} 

bool DFS(int step, int u) { 
  if (u == v) printSolution(step);
  else {
    flag[u] = 1;
    path[step] = u;
    for(int i = 0; i < n; i++) {
      if (graph[u][i] && isSafe(i)) {
        DFS(step+1, i);
      }
    }
    flag[u] = 0;
  }
}
  
int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>u>>v;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin>>graph[i][j];
  DFS(0, u);
}

