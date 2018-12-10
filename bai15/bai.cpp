#include<bits/stdc++.h>

using namespace std;

int n;
int c[20], x[20], d[20];
int xep[8];

bool check(int pos, int i) {
  if (d[i]) return false;
  if (c[pos+i]) return false;
  if (x[pos-i+7]) return false;
  return true;
}

void tryDo(int pos) { 
  if (pos >= 8) {
    for(int i = 0; i < 8; i++) {
      cout << xep[i] << " ";
    }
    cout<<endl;
  } else {
    for(int i = 0; i < 8; i++)
     if (check(pos, i)) {
       d[i] = 1;
       c[pos+i] = 1;
       x[pos-i+7] = 1;
       xep[pos] = i;
       tryDo(pos+1);
       d[i] = 0;
       c[pos+i] = 0;
       x[pos-i+7] = 0;
     }
  }
}

int main() {
  freopen ("out.txt", "w", stdout);
  tryDo(0);
}

