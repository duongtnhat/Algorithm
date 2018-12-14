#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > next[100005];
int result[100005], d[100005], flag[100005], n, m, u, v;

void trace(int v) {
  if (v != u) trace(result[v]);
  cout<<v<<" ";
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>m>>u>>v;
  while(m--) {
    int u, v, w;
    cin>>u>>v>>w;
    next[u].push_back(make_pair(v, w));
    next[v].push_back(make_pair(u, w));
  }
  for(int i = 1; i < n; i++) d[i] = 1000000007;
  while(true) {
    int m = -1;
    for(int i = 0; i < n; i++) {
      if (flag[i] == 0) {
        if (m == -1) m = i;
        else if (d[i] < d[m]) m = i;
      }
    }
    if (m == -1) break;
    flag[m] = 1;
    for(int i = 0; i < next[m].size(); i++) {
      int v = next[m][i].first;
      int w = next[m][i].second;
      if (d[v] > w + d[m]) {
        d[v] = w + d[m];
        result[v] = m;
      }
    }
  }
  cout<<d[v]<<endl;
  trace(v);
}

