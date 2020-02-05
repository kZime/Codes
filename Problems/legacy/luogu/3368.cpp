#include <bits/stdc++.h>
using namespace std;

const int maxn = 500003;

int a[maxn], c[maxn], n, m;

inline int lb(int x) {return x & -x;}

inline void add(int x, int k) { 
  for (; x <= n; x += lb(x)) 
    c[x] += k;
}

inline int ask(int x) { 
  int ans = 0;
  for (; x; x -= lb(x))
    ans += c[x];
  return ans;
}

int main() { 
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--) { 
    int op;
    cin >> op;
    if (op & 1) { 
      int l, r, x;
      cin >> l >> r >> x;
      add(l, x);
      add(r + 1, -x);
    } else { 
      int k;
      cin >> k;
      cout << a[k] + ask(k) << '\n';
    }
  }
}
