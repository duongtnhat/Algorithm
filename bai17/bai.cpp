#include<bits/stdc++.h>

using namespace std;

int n, W, wt[50], val[50], dd[50], res = 0;

int max(int a, int b) { return (a > b)? a : b; } 

void calc() {
  int cval = 0, cwt = 0; 
  for(int i = 0; i < n; i++) {
    cval += val[i] * dd[i];
    cwt += wt[i] * dd[i];
  }
  if (cwt <= W)
    res = max(res, cval);
}

void knapSack(int u) { 
  if (u >= n) {
    calc();
    return;
  }
  dd[u] = 1; 
  knapSack(u+1);
  dd[u] = 0;
  knapSack(u+1);
} 
  
int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>W;
  for(int i = 0; i < n; i++) cin>>val[i]>>wt[i];
  knapSack(0);
  cout<<res<<endl;
}

