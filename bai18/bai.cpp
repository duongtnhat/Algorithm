#include<bits/stdc++.h>

using namespace std;

int n, graph[20][20], path[20], flag[20];

void calc() {
  path[n] = path[0];
  for(int i = 1; i <= n; i++)
    if (graph[path[i-1]][path[i]] == 0)
      return;
  for(int i = 0; i <= n; i++)
    cout<<path[i]<<" ";
  cout<<endl;
}

void hamCycle(int pos) {
  if (pos >= n) calc();
  else {
    for(int i = 0; i < n; i++) {
      if (flag[i] == 0) {
        flag[i] = 1;
        path[pos] = i;
        hamCycle(pos+1);
        flag[i] = 0;
      }
    }
  }
}
  
int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin>>graph[i][j];
  flag[0] = 1;    
  hamCycle(1);
}

