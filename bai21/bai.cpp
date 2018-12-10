#include<bits/stdc++.h>

using namespace std;

int n, graph[20][20], path[20];

bool isSafe(int v, int pos) { 
  if (graph[path[pos-1]][v] == 0) 
    return false; 
  for (int i = 0; i < pos; i++) 
    if (path[i] == v) 
      return false;   
  return true; 
} 

bool hamCycleUtil(int pos) 
{ 
  if (pos == n) { 
    if (graph[path[pos-1]][path[0]] == 1) 
      return true; 
    else
      return false; 
  } 
  for (int v = 1; v < n; v++) { 
    if (isSafe(v, pos)) { 
      path[pos] = v; 
      if (hamCycleUtil(pos+1)) 
        return true; 
      path[pos] = -1; 
    } 
  } 
  return false; 
} 

void printSolution() { 
  for (int i = 0; i < n; i++) 
    cout << path[i] << " ";
  cout << path[0] << endl;
} 

bool hamCycle() 
{  
  for (int i = 0; i < n; i++) 
    path[i] = -1; 
  path[0] = 0; 
  if (!hamCycleUtil(1)) { 
    cout<<-1; 
    return false; 
  } 
  printSolution(); 
  return true; 
} 
  
int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin>>graph[i][j];
  hamCycle();
}

