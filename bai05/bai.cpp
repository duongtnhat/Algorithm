#include<bits/stdc++.h>

using namespace std;

int n, W;
pair<int, int> a[1000006];

bool comp(pair<int, int> a, pair<int, int> b){
  if (a.first == b.first) return a.second < b.second;
  else return a.first > b.first;
}

int knapsack(int n, int capacity, pair<int, int> a[]) {
  int tp = 0;
  int u = capacity;
  sort(a, a+n, comp);
  for (int i = 0; i < n; i++) {
    if (a[i].second > u)
      continue;
    else {
      tp = tp + a[i].first;
      u = u - a[i].second;
    }
   }
  return tp; 
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>W;
  for(int i = 0; i < n; i++)
    cin>>a[i].first>>a[i].second;
  cout<<knapsack(n, W, a)<<endl;  
}

