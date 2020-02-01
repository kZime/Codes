#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e4 + 3;

struct edge { 
  int fr, to;
  edge() { 
    to = 0, fr = 0;
  }
} e[maxn << 2];

int val[maxn], n, m;
vector<int> to1[maxn], to2[maxn];
int dfn[maxn], low[maxn], col[maxn], sum[maxn], stk[maxn], top;
int cnt, color_cnt, ans;
bool ins[maxn];

void tarjan(int x) { 
  dfn[x] = low[x] = ++cnt;
  stk[++top] = x;
  ins[x] = 1;
  for (int i = 0; i < to1[x].size(); i++) { 
    int y = to1[x][i];
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (ins[y]) {
      low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) { 
    ++color_cnt;
    ins[x] = 0;
    while (stk[top + 1] != x) { 
      col[stk[top]] = color_cnt;
      sum[color_cnt] += val[stk[top]];
      ans = max(ans, sum[color_cnt]);
      ins[stk[top]] = 0;
      top--;
    }
  }
}

int dis[maxn];
bool inq[maxn];

void bfs(int x) { 
  memset(dis, 0, sizeof(dis));
  memset(inq, 0, sizeof(inq));
  dis[x] = sum[x];
  queue<int> q;
  inq[x] = 1;
  q.push(x);
  while (!q.empty()) { 
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = 0; i < to2[x].size(); i++) { 
      int v = to2[x][i];
      if (dis[v] < dis[x] + sum[v]) { 
        dis[v] = dis[x] + sum[v];
        if (inq[v]) continue;
        inq[v] = 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= color_cnt; i++)
    ans = max(ans, dis[i]);
}

int main() { 
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  for (int i = 1; i <= m; i++) { 
    cin >> e[i].fr >> e[i].to;
    to1[e[i].fr].push_back(e[i].to);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);
  for (int i = 1; i <= m; i++) 
    if (col[e[i].fr] != col[e[i].to]) 
      to2[col[e[i].fr]].push_back(col[e[i].to]);
  for (int i = 1; i <= color_cnt; i++) 
    bfs(i);
  printf("%d\n", ans);
}
