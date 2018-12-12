#include<bits/stdc++.h>

using namespace std;

int n, W, d[100005], t[100005], p = 0;
pair<int, int> a[100005];
  
void QHD() {
  for(int i = 1; i <= W; i++) {
    d[i] = -1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = W-a[i].second; j >= 0; j--) {
      if (d[j] >= 0) {
        if (d[j+a[i].second] < d[j] + a[i].first) {
          d[j+a[i].second] = d[j] + a[i].first;
          t[j+a[i].second] = i;
          if (d[j+a[i].second] > d[p]) {
            p = j+a[i].second;
          }
        }
      }
    }
  }
}  

void traceBack(int pos) {
  if (pos > 0) {
    traceBack(pos - a[t[pos]].second);
    cout<<t[pos]+1<<" ";
  }
}

void KQ() {
  cout<<d[p]<<endl;
  traceBack(p);
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>W;
  for(int i = 0; i < n; i++){
    cin>>a[i].first>>a[i].second;
  }
  QHD();
  KQ();
}

