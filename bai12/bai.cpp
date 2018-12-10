#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1000006];

int max(int a, int b) {
  return a > b ? a : b;
}

int maxSubArraySum(int a[], int size) { 
  int max_so_far = INT_MIN, max_ending_here = 0; 
  for (int i = 0; i < size; i++) { 
    max_ending_here = max_ending_here + a[i]; 
    if (max_so_far < max_ending_here) 
      max_so_far = max_ending_here; 

    if (max_ending_here < 0) 
      max_ending_here = 0; 
  } 
  return max_so_far; 
} 

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n;
  for(int i = 0; i < n; i++) cin>>a[i];
  int max_sum = maxSubArraySum(a, n); 
  cout<<max_sum<<endl;
}

