#include <bits/stdc++.h>
using namespace std;

const int maxn = 500003;

int n, m, s;
int fa[maxn][20], dep[maxn];

inline int gn() {
    char c = getchar();
    int k = 0, f = 1;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

struct edge {
    int to;
    edge *ne;
    edge(int to, edge *ne) : to(to), ne(ne) {}
} *head[maxn];

void addedge(int fr, int to) {
    head[fr] = new edge(to, head[fr]);
}

void dfs(int x) {
    dep[x] = dep[fa[x][0]] + 1;
    for (int i = 1; i <= 19; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        if (!fa[x][i]) break;
    }
    for (edge *e = head[x]; e; e = e->ne) {
        if (dep[e->to]) continue;
        fa[e->to][0] = x;
        dfs(e->to);
    }
}

int lca(int a, int b) {
    if (dep[b] > dep[a]) swap(a, b); // a is deeper
    for (int i = 19; ~i; i--) 
        if (dep[fa[a][i]] >= dep[b]) 
            a = fa[a][i];
    if (a == b)
        return a;
    for (int i = 19; ~i; i--) 
        if (fa[a][i] != fa[b][i]) 
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    n = gn(), m = gn(), s = gn();
    for (int i = 1, a, b; i < n; i++) {
        a = gn(), b = gn();
        addedge(a, b);
        addedge(b, a);
    }
    dfs(s);
    for (int i = 1, a, b; i <= n; i++) {
        a = gn(), b = gn();
        cout << lca(a, b) << '\n';
    }
}
