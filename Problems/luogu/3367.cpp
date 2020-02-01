#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 3;

int f[maxn];

int gf(int x) { 
  if (x == f[x]) return x;
  else return f[x] = gf(f[f[f[x]]]);
}

void merge(int x, int y) { 
  f[gf(y)] = gf(x);
}

int main() { 
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    f[i] = i;
  while (m--) { 
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) { 
      merge(l, r);
    } else { 
      cout << ((gf(l) == gf(r)) ? "Y\n" : "N\n");
    }
  }
}
