#include <bits/stdc++.h>
using namespace std;

struct edge { 
  int fr, to, w;
  bool operator<(const edge a) const { 
    return w < a.w;
  }
} e[200003];

int f[5003];

int gf(int x) { 
  if (f[x] == x) return x;
  else return f[x] = gf(f[f[f[x]]]);
}

void merge(int a, int b) { 
  f[gf(b)] = gf(a);
} 
bool lt(int a, int b) { 
  return gf(a) == gf(b);
}

int n, m;

int main() { 
  cin >> n >> m;
  for (int i = 1; i <= m; i++) { 
    cin >> e[i].fr >> e[i].to >> e[i].w;
  }
  sort(e + 1, e + 1 + m);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    f[i] = i;
  for (int i = 1; i <= m; i++) { 
    edge *d = e + i;
    if (!lt(d->fr, d->to)) { 
      merge(d->fr, d->to);
      ans += d->w;
    }
  }
  int ss = f[1];
  for (int i = 2; i <= n; i++) { 
    if (f[i] != ss) { 
      return printf("orz\n"), 0;
    }
  }
  cout << ans << '\n';
}
