#include <bits/stdc++.h>
using namespace std;

struct pii {
  int a, b;
  pii(int a, int b) : a(a), b(b) {}
  bool operator<(const pii &c) {
    if (c.a ^ a) return a < c.a;
    else return b < c.b;
  }
};

const int maxn = 2e5 + 3;

vector<pii> num;
map<int, int> n2n;
int a[maxn], n, b[maxn];

struct node {
  node *ls, *rs;
  int sum;
  node() {
    ls = rs = NULL;
    sum = 0;
  }
} *root[maxn];

#define mid ((l + r) >> 1)

node *build(int l, int r) {
  node *x = new node();
  if (l ^ r) {
    x->ls = build(l, mid);
    x->rs = build(mid + 1, r);
  }
  return x;
}

node *add(node *pre, int l, int r, int k) {
  node *x = new node();
  if (l == r) {
    x->sum = pre->sum + 1;
  } else {
    if (k <= mid) {
      x->rs = pre->rs;
      x->ls = add(pre->ls, l, mid, k);
    } else {
      x->ls = pre->ls;
      x->rs = add(pre->rs, mid + 1, r, k);
    }
    x->sum = x->ls->sum + x->rs->sum;
  }
  return x;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    num.push_back(pii(a[i], i));
  }
  sort(num.begin(), num.end());
  int cnt = 1;
  for (int i = 0; i < num.size(); i++) {
    if (i and num[i].a != num[i - 1].a) cnt++;
    a[num[i].b] = cnt;
  }
  *root[0] = build(1, cnt);
  for (int i = 1; i <= n; i++) {
    root[i] = add(root[i - 1], 1, cnt, a[i]);
  }
}
