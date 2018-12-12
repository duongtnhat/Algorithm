#include<bits/stdc++.h>

using namespace std;

vector<int> next[100005];
int result[100005], n, m;

void coloring() {
  int result[n], u, v;
  result[0]  = 0;
  for (int u = 1; u < n; u++) 
    result[u] = -1;
  bool available[n]; 
  for (int cr = 0; cr < n; cr++) 
    available[cr] = false; 
    
  for (int u = 1; u < n; u++) { 
    for (int i = 0; i < next[u].size(); i++)
      if (result[next[u][i]] != -1) 
        available[result[next[u][i]]] = true; 
    int cr; 
    for (cr = 0; cr < n; cr++) 
      if (!available[cr]) 
        break; 
    result[u] = cr; 
    for (int i = 0; i < next[u].size(); i++)
      if (result[next[u][i]] != -1) 
        available[result[next[u][i]]] = false; 
  } 
  for (int u = 0; u < n; u++) 
    cout<<u<<" "<<result[u]<<endl; 
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>m;
  while(m--) {
    int u, v;
    cin>>u>>v;
    next[u].push_back(v);
    next[v].push_back(u);
  }
  coloring();
}

