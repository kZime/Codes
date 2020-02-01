#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = (int)1e5 + 3;

char buf[(int)5e7], *fs = buf;

inline int gn() { 
    char c = *fs++;
    int k = 0;
    for (; !isdigit(c); c = *fs++);
    for (; isdigit(c); c = *fs++) k = k * 10 + c - '0';
    return k;
}

struct edge {
    int to;
    edge *ne;
    edge(int tt, edge *nn) {
        ne = nn, to = tt;
    }
} *head[maxn];

void addedge(int fr, int to) {
    head[fr] = new edge(to, head[fr]);
}

int n, m, x[maxn], y[maxn], val[maxn], sum[maxn], dfn[maxn], low[maxn];
int ins[maxn], stk[maxn], top, cnt, col_cnt, col[maxn];

void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    stk[top++] = x;
    ins[x] = 1;
    for (edge *e = head[x]; e; e = e->ne) {
        int y = e->to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x]) {
        col[x] = ++col_cnt;
        while (stk[top] != x) {
            col[stk[--top]] = col_cnt;
            sum[col_cnt] += val[stk[top]];
            ins[stk[top]] = 0;
        }
    }
}

int ans, dis[maxn];
bool inq[maxn];
queue<int> q;

void spfa(int x) { 
    memset(inq, 0, sizeof(inq));
    memset(dis, 0, sizeof(dis));
    q.push(x);
    inq[x] = 1;
    dis[x] = sum[x];
    while (!q.empty()) { 
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (edge *e = head[u]; e; e = e->ne) { 
            int v = e->to;
            if (dis[u] + sum[v] > dis[v]) { 
                dis[v] = dis[u] + sum[v];
                if (!inq[v]) { 
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    for (int i = n + 1; i <= col_cnt; i++)
        ans = max(ans, dis[i]);
}

int main() {
    fread(buf, 1, (int)5e7, stdin);
    n = gn(), m = gn();
    col_cnt = n;
    for (int i = 1; i <= n; i++) {
        val[i] = gn();
    }
    for (int i = 1; i <= m; i++) {
        x[i] = gn(), y[i] = gn();
        addedge(x[i], y[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++){ 
        if (col[x[i]] != col[y[i]]) { 
            addedge(col[x[i]], col[y[i]]);
        }
    }
    for (int i = n + 1; i <= col_cnt; i++) 
        spfa(i);
    cout << ans;
}
/*
6 8
1 1 1 1 1 1
1 3
1 2
3 4
2 4
4 1
3 5
4 5
5 6
*/
