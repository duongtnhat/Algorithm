#include<bits/stdc++.h>

using namespace std;

int n, d[8][8];
int X[8] = {1, 1,-1,-1, 2, 2,-2,-2};
int Y[8] = {2,-2, 2,-2, 1,-1, 1,-1};

bool check(int x, int y) {
  if (x < 0 || x >= n) return false;
  if (y < 0 || y >= n) return false;
  return true;
}

void tryDo(int x, int y, int p) { 
  if (p > n*n) {
    d[x][y] = p;
    for(int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout<<d[i][j]<< " ";
      cout<<endl; 
    }
    cout<<endl;
    return;
  }
  if (d[x][y] != 0) return;
  d[x][y] = p;
  for (int i = 0; i < 8; i++) {
    int xx = x + X[i];
    int yy = y + Y[i];
    if (check(x, y))
      tryDo(xx, yy, p+1);
  }
  d[x][y] = 0;
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n;
  tryDo(0, 0, 1);
}

