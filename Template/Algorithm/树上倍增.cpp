# include <bits/stdc++.h>
# define MAXN 500023
using namespace std;

inline int gn() { 
    int k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

int n, m, s, fa[MAXN], f[MAXN][20], dep[MAXN];

struct edge { 
    int to;
    edge *ne;
    edge() {;}
    edge(int to_, edge *ne_) { 
        to = to_, ne = ne_;
    }
} *head[MAXN];

inline void addedge(int fr, int to) { 
    head[fr] = new edge(to, head[fr]);
    head[to] = new edge(fr, head[to]);
}

void dfs(int u) {
    dep[u] = dep[f[u][0]] + 1;
    for(int i = 1; i <= 19 && f[u][i - 1]; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(edge *e = head[u]; e; e = e->ne) { 
        if(e->to == f[u][0]) continue;
        f[e->to][0] = u;
        dfs(e->to);
    }
}

inline int lca(int x, int y) { 
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) { 
        if(dep[f[x][i]] >= dep[y]) { //f[x][i] 在y下方
            x = f[x][i];
        }
    }
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) { 
        if(f[x][i] ^ f[y][i]) { 
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}

int main() { 
    n = gn(), m = gn(), s = gn();
    for(int i = 1; i < n; i++) { 
        int s = gn(), t = gn();
        addedge(s, t);
    }
    dfs(s);
    for(int i = 1; i <= m; i++) { 
        printf("%d\n", lca(gn(), gn()));
    }
}
