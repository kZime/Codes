#include <bits/stdc++.h>
using namespace std;
const int maxn = 40003;
int n, ans, b[maxn], cnt = 1, bit[maxn], c[maxn];
struct node { 
  int num, val;
  bool operator < (const node a) const { 
    return val > a.val;
  }
  node (int num, int val): num(num), val(val) {}
};
vector<node> a;
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
  cin >> n;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    a.push_back(node(i, x));
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) { 
    add(a[i].num, 1);
    ans += ask(a[i].num - 1);
  }
  cout << ans;
}
