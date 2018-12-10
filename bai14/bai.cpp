#include<bits/stdc++.h>

using namespace std;

int n;
int d[1003][1003];

void floyd() {
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
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
      cin>>d[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if (d[i][j] == 0 && i != j) 
        d[i][j] = 1000000009;
  
  floyd();
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout<<d[i][j]<<" ";
    cout<<endl;  
  }
}

