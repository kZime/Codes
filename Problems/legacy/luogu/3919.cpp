# include <bits/stdc++.h>
# define mid ((l + r) >> 1)
# define MAXN 1000005
using namespace std;

inline int gn() {
    int k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

struct node {
    int sum, ls, rs;
    node() {
        ls = rs = sum = 0;
    }
};

vector <node> p(MAXN * 13);

int n, m, root[MAXN], cnt;

int build(int l, int r) {
    int x = ++cnt;
    if(l ^ r) {
        p[x].ls = build(l, mid);
        p[x].rs = build(mid + 1, r);
    } else {
        p[x].sum = gn();
    }
    return x;
}

int search(int x, int l, int r, int k) {
    if(l ^ r) {
        if(k <= mid) return search(p[x].ls, l, mid, k);
        else return search(p[x].rs, mid + 1, r, k);
    } else {
        return p[x].sum;
    }
}

int add(int pre, int l, int r, int k, int t) {
    int x = ++cnt;
    if(l ^ r) {
        if(k <= mid) {
            p[x].rs = p[pre].rs;
            p[x].ls = add(p[pre].ls, l, mid, k, t);
        } else {
            p[x].ls = p[pre].ls;
            p[x].rs = add(p[pre].rs, mid + 1, r, k, t);
        }
    } else {
        p[x].sum = t;
    }
    return x;
}

int main() {
    n = gn(), m = gn();
    root[0] = build(1, n);
    for(int i = 1, op, v1, loc; i <= m; i++) {
        v1 = gn(), op = gn(), loc = gn();
        if(op == 2) {
            printf("%d\n", search(root[v1], 1, n, loc));
            root[i] = root[v1];
        } else {
            root[i] = add(root[v1], 1, n, loc, gn());
        }
    }
}
