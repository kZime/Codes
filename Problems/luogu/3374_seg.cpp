#include <bits/stdc++.h>
using namespace std;

struct node { 
  int sum;
  node *ls, *rs;
  node () { 
    sum = 0;
    ls = rs = NULL;
  }
} *root;

#define mid ((l + r) >> 1)

node *build(int l, int r) { 
  node *x = new node();
  if (l == r) { 
    cin >> x->sum;
    return x;
  }
  x->ls = build(l, mid);
  x->rs = build(mid + 1, r);
  x->sum = x->ls->sum + x->rs->sum;
  return x;
}

void add(node *x, int l, int r, int p, int k) { 
  x->sum += k;
  if (l == r) return;
  if (p <= mid) add(x->ls, l, mid, p, k);
  else add(x->rs, mid + 1, r, p, k);
}

int ask(node *x, int l, int r, int s, int t) { 
  if (l == s and r == t) return x->sum;
  else if (t <= mid) return ask(x->ls, l, mid, s, t);
  else if (s > mid) return ask(x->rs, mid + 1, r, s, t);
  else return ask(x->ls, l, mid, s, mid) + ask(x->rs, mid + 1, r, mid + 1, t);
}

int n, m;

int main() { 
  scanf("%d%d", &n, &m);
  root = build(1, n);
  while (m--) { 
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) { 
      add(root, 1, n, l, r);
    } else { 
      cout << ask(root, 1, n, l, r) << '\n';
    }
  }
}
