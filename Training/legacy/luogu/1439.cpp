#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int mp[maxn], a[maxn], b[maxn], f[maxn], n;

int ub(int l, int r, int k, int mid = 233) {
  while (l < r) { 
    mid = (l + r) >> 1;
    if (k >= f[mid]) l = mid + 1;
    else r = mid;
  }
  return l;
}

int main() { 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) { 
    cin >> b[i];
    b[i] = mp[b[i]];
  }
  int ans = 1, cur = 0;
  f[1] = b[1];
  for (int i = 2; i <= n; i++) { 
    if (b[i] > f[ans]) cur = ++ans;
    else cur = ub(1, ans, b[i]);
    f[cur] = b[i];
  }
  cout << ans << ' ';
}

/*
 * 5
 * 3 2 1 4 5
 * 1 2 3 4 5
 *
 * 1 2 3 4 5
 * 3 2 1 4 5
 *
 *
 */
