#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > next[100005];
int result[100005], flag[100005], n, m, W;

void trace(int u) {
  if (u != 0) trace(result[u]);
  cout<<u<<" "; 
}

void DQ(int u) {
  flag[u] = 1;
  int min = 1000000009, p = 0;
  for(int i = 0; i < next[u].size(); i++) {
    if (flag[next[u][i].first] == 0) {
      if (min > next[u][i].second) {
        min = next[u][i].second;
        p = next[u][i].first;
      }
    }
  }
  if (min < 1000000009) {
    result[p] = u;
    W += min;
    DQ(p);
  } else {
    cout<<W<<endl;
    trace(u);
  }
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>m;
  while(m--) {
    int u, v, w;
    cin>>u>>v>>w;
    next[u].push_back(make_pair(v, w));
    next[v].push_back(make_pair(u, w));
  }
  DQ(0);
}

