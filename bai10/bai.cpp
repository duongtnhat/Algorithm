#include<bits/stdc++.h>

using namespace std;

int n, m, s[100005];
pair<int, int> a[100005];

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>a[i].second>>a[i].first;
  }
  sort(a, a+n);
  int now = -1, count = 0;
  for (int i = 0; i < n; i++) { 
    if (a[i].second > now) {
      count++, s[i] = 1, now = a[i].first;
    }
  }
  cout<<count<<endl;
  for(int i = 0; i < n; i++) {
    if (s[i] == 1) {
      cout<<a[i].second<<" "<<a[i].first<<endl;
    }
  }
}

