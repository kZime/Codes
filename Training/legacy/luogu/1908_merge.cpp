#include <bits/stdc++.h>
using namespace std;

const int maxn = 40003;
int n, a[maxn], t[maxn], ans;

#define mid ((l + r) >> 1)

void merge(int l, int r) { 
  if (l == r) return;
  merge(l, mid);
  merge(mid + 1, r);
  int i = l, j = mid + 1, p = l;
  while (i <= mid and j <= r) { 
    if (a[i] > a[j]) { 
      t[p++] = a[j++];
      ans += mid - i + 1;
    } else t[p++] = a[i++];
  }
  while (i <= mid) t[p++] = a[i++];
  while (j <= r) t[p++] = a[j++];
  for (int i = l; i <= r; i++)
    a[i] = t[i];
}

int main() { 
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  merge(1, n);
  cout << ans << '\n';
}
