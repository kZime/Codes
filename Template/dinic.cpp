# include <bits/stdc++.h>
# define MAXN 123
# define INF 0x7fffffff
using namespace std;

inline char getc() {
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}

inline int gn() {
    int k = 0, f = 1;
    char c = getc();
    for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
    for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return f * k;
}

struct edge {
    int to, w, ne;
    edge() {;}
    edge(int to_, int w_, int ne_) {
        to = to_, ne = ne_, w = w_;
    }
}e[MAXN << 5];

int cnt, head[MAXN << 1], s, t, n, m;

inline void addedge(int fr, int to, int w) {
    e[cnt] = edge(to, w, head[fr]), head[fr] = cnt++;
    e[cnt] = edge(fr, 0, head[to]), head[to] = cnt++;
}

int dis[MAXN << 1];
queue <int> q;

inline bool bfs() {
    memset(dis, -1, sizeof(dis));
    q.push(s);
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i; i = e[i].ne) {
            int v = e[i].to;
            if(!~dis[v] && e[i].w > 0) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }   
    return ~dis[t];
}

int dfs(int u, int val) {
    int rec = 0;
    if(u == t) return val;
    for(int i = head[u]; ~i; i = e[i].ne) {
        int v = e[i].to;
        if(dis[v] == dis[u] + 1 && e[i].w > 0 && (rec = dfs(e[i].to, min(val, e[i].w)))) {
            e[i].w -= rec;
            e[i ^ 1].w += rec;
            return rec;
        }
    }
    return 0;
}

inline int max_flow() {
    int ans = 0, u;
    while(bfs()) {
        while((u = dfs(s, INF))) ans += u;
    }
    return ans;
}

int main() {
    freopen("in", "r", stdin);
    memset(head, -1, sizeof(head));
    n = gn(), m = gn(), s = gn() + n, t = gn();
    for(int i = 1; i <= n; i++) addedge(i, i + n, 1);
    for(int x, y, i = 1; i <= m; i++) {
        x = gn(), y = gn();
        addedge(x + n, y, INF);
        addedge(y + n, x, INF);
    }
    printf("%d\n", max_flow());
}
