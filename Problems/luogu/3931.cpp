#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 1e5 + 3;

struct edge { 
    int to, w;
    edge *ne;
    edge(int tt, int ww, edge * nn) { 
        to = tt, w = ww, ne = nn;
    }
} *head[maxn];

void addedge(int fr, int to, int w) { 
    head[fr] = new edge(to, w, head[fr]);
    head[to] = new edge(fr, w, head[to]);
}

int dp[maxn], n, S;

void dfs(int x, int fa) { 
    bool hasSon = 0;
    for (edge *e = head[x]; e; e = e->ne) { 
        if (e->to == fa) continue; 
        hasSon = 1;
        dfs(e->to, x);
        dp[x] += min(e->w, dp[e->to]);
    }
    if (!hasSon) { 
        dp[x] = INT_MAX;
    }
}

int main() { 
    cin >> n >> S;
    for (int i = 1, f, t, w; i < n; i++) { 
        cin >> f >> t >> w;
        addedge(f, t, w);
    }
    dfs(S, 0);
    cout << dp[S] << '\n';
}
