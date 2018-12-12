#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > next[100005];
int result[100005], d[100005], flag[100005], n, m, W, u, v;
priority_queue<pair<int, int> > q;

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
  q.push(make_pair(0, u));
  while(!q.empty()) {
    pair<int, int> u = q.top();
    q.pop();
    if (flag[u.second] || d[u.second] < -u.first)
      continue;
    flag[u.second] = 1;
    W += -u.first;
    for(int i = 0; i < next[u.second].size(); i++) {
      int v = next[u.second][i].first;
      int w = next[u.second][i].second;
      if (d[v] > w + d[u.second]) {
        d[v] = w + d[u.second];
        result[v] = u.second;
        q.push(make_pair(-d[v], v));
      }
    }
  }
  cout<<d[v]<<endl;
  trace(v);
}

