#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000006];

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void quicksort(int *a, int l, int r) {
  int key = a[(l+r)/2];
  int i = l, j = r;
  while(i <= j) {
    while(a[i] < key) i++;
    while(a[j] > key) j--;
    if(i <= j) {
      if (i < j)
        swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (l < j) quicksort(a, l, j);
  if (i < r) quicksort(a, i, r);
}

int main(){
  freopen ("inp.txt","r", stdin);
  freopen ("out.txt","w",stdout);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  quicksort(a, 0, n-1);
  for(int i = 0; i < n; i++)
    cout<<a[i]<<" ";
}
