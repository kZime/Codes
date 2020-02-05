#include <bits/stdc++.h>
using namespace std;

int l, r, cnt[10];

void check(int k) { 
  while(k) { 
    cnt[k % 10]++;
    k /= 10;
  }
}

int main() { 
  //freopen("twoj.in", "r", stdin);
  //freopen("twoj.out", "w", stdout);
  cin >> l >> r;
  for (int i = l; i <= r; i++) { 
    check(i);
  }
  cout << cnt[2];
}
