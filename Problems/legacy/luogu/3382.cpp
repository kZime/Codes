#include <bits/stdc++.h>
using namespace std;

typedef double db;

int n;
db xi[15];

db f(db x) { 
  db ans = xi[0];
  for (int i = 1; i <= n; i++)
    ans = ans * x + xi[i];
  return ans;
}

void ts(db l, db r) { 
  if (l + 0.000001 >= r) { 
    printf("%0.5f\n", r);
    return;
  }
  db t1 = 1.0 * (r - l) / 3.0 + l;
  db t2 = 2.0 * (r - l) / 3.0 + l;
  if (f(t1) > f(t2)) ts(l, t2);
  else ts(t1, r);
}

int main() { 
  db l, r;
  cin >> n >> l >> r;
  for (int i = 0; i <= n; i++)
    cin >> xi[i];
  ts(l, r);
}
