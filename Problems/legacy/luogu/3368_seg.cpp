#include <bits/stdc++.h>
using namespace std;
#define mid ((l + r) >> 1)
#define lson x->ls, l, mid
#define rson x->rs, mid + 1, r

char buf[(int) 2e8], *fs = buf;

inline int gn() {
    int k = 0, f = 1;
    char c = *fs++;
    for (; !isdigit(c); c = *fs++) if (c == '-') f = -1;
    for (; isdigit(c); c = *fs++) k = k * 10 + c - '0';
    return k * f;
}

int n, m, op;

struct node {
    int sm, lz;
    node *ls, *rs;
    node () {
        sm = lz = 0;
        ls = rs = NULL;
    }
    void pu() {
        sm = 0;
        if (ls) sm += ls->sm;
        if (rs) sm += rs->sm;
    }
    void pd(int l, int r) {
        if (ls) {
            ls->lz += lz;
            ls->sm += (mid - l + 1) * lz;
        }
        if (rs) {
            rs->lz += lz;
            rs->sm += (r - mid) * lz;
        }
        lz = 0;
    }
} *root;

node *build(int l, int r) {
    node *x = new node ();
    if (l == r) {
        x->sm = gn();
        return x;
    }
    x->ls = build(l, mid);
    x->rs = build(mid + 1, r);
    x->pu();
    return x;
}

void add(node *x, int l, int r, int s, int t, int k) {
    if (x->lz) x->pd(l, r);
    if (l == s and r == t) {
        x->lz += k;
        x->sm += (r - l + 1) * k;
        return;
    } else {
        if (t <= mid) add(lson, s, t, k);
        else if (s > mid) add(rson, s, t, k);
        else add(lson, s, mid, k), add(rson, mid + 1, t, k);
    }
    x->pu();
}

int query(node *x, int l, int r, int k) {
    if (x->lz) x->pd(l, r);
    if (l == r) return x->sm;
    else if (k <= mid) return query(lson, k);
    else return query(rson, k);
}

int main() {
    fread(buf, 1, (int) 3e7, stdin);
    n = gn(), m = gn();
    root = build(1, n);
    int x, y, k;
    while (m--) {
        op = gn();
        if (op & 1) {
            x = gn(), y = gn(), k = gn();
            add(root, 1, n, x, y, k);
        } else {
            x = gn();
            cout << query(root, 1, n, x) << '\n';
        }
    }
}
