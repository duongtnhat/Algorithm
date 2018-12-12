#include<bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > next;
int result[100005], take[100005], n, m, w;

int root(int p) {
  if (take[p] == p) return p;
  else { 
    take[p] = root(take[p]);
    return take[p];
  }
}

void kruskal() {
  for(int i = 0; i < next.size(); ++i) {
    pair<int, pair<int, int> > p = next[i]; 
    int r1 = root(p.second.first);
    int r2 = root(p.second.second);
    if (r1 != r2) {
      w += p.first;
      result[i] = 1;
      take[r1] = r2;
    }
  }
}

int main() {
  freopen ("inp.txt", "r", stdin);
  freopen ("out.txt", "w", stdout);
  cin>>n>>m;
  while(m--) {
    int u, v, w;
    cin>>u>>v>>w;
    next.push_back(make_pair(w, make_pair(u, v)));
  }
  sort(next.begin(), next.end());
  for (int i = 0; i < n; i++) take[i] = i;
  kruskal();
  cout<<w<<endl;
  for(int i = 0; i < next.size(); ++i) {
    pair<int, pair<int, int> > p = next[i];
    if (result[i] == 1) {
      cout<<p.second.first<<" "<<p.second.second<<endl;
    }
  }
}

