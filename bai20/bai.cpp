#include<bits/stdc++.h>

using namespace std;

int n, W, wt[50], val[50];

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int W, int wt[], int val[], int n) { 
  if (n == 0 || W == 0) 
    return 0; 
  if (wt[n-1] > W) 
    return knapSack(W, wt, val, n-1); 
  else 
    return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
                    knapSack(W, wt, val, n-1)); 
} 
  
int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>W;
  for(int i = 0; i < n; i++) cin>>val[i]>>wt[i];
  cout<<knapSack(W, wt, val, n)<<endl;
}

