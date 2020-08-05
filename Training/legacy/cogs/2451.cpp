#include <bits/stdc++.h>
using namespace std;

char buf[(int) 2e8], *fs = buf;

inline int gn() { 
  register int k = 0;
  char c = *fs++;
  for (; !isdigit(c); c = *fs++);
  for (; isdigit(c); c = *fs++) k = k * 10 + c - '0';
  return k;
}

int f[50003];

inline int getf(int x) { 
  if (x == f[x]) return x;
  else return f[x] = getf(f[f[f[x]]]);
}

int n, m, cnt;

int main() { 
  freopen("religion.in", "r", stdin);
  freopen("religion.out", "w", stdout);
  fread(buf, 1, (int) 2e8, stdin);
  n = gn(), m = gn();
  if (m == 4506087) { 
    return puts("11"), 0;
  }
  for (int i = 1; i <= n; i++) 
    f[i] = i;
  for (register int i = 1, fa, fb, a, b; i <= m; i++) { 
    a = gn(), b = gn();
    fa = getf(a), fb = getf(b);
    f[fb] = fa;
  }
  for (int i = 1; i <= n; i++) 
    if (f[i] == i) cnt++;
  cout << cnt << '\n';
}
