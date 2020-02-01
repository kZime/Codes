#include <bits/stdc++.h>
using namespace std;

const int maxn = 500003;

int bit[maxn], n, m;

inline int lb(int x) {return x & -x;}

inline void add(int x, int k) { 
  for (; x <= n; x += lb(x))
    bit[x] += k;
}

inline int ask(int x) { 
  int ans = 0;
  for (; x; x -= lb(x))
    ans += bit[x];
  return ans;
}

int main() { 
  cin >> n >> m;
  for (int i = 1; i <= n; i++) { 
    int k;
    cin >> k;
    add(i, k);
  }
  for (int i = 1; i <= m; i++) { 
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) { 
      add(l, r);
    } else { 
      cout << ask(r) - ask(l - 1) << '\n';
    }
  }
}
