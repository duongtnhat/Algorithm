#include<bits/stdc++.h>

using namespace std;

int n, m;
string a, b;
int d[1003][1003];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>m;
  cin>>a>>b;
  for(int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i-1] == b[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      }
      d[i][j] = max(d[i][j], max(d[i-1][j], d[i][j-1]));    
    }
  cout<<d[n][m];  
}

