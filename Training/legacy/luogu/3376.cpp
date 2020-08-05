#include <bits/stdc++.h>
using namespace std;

char buf[(int)3e7], *fs = buf;

inline int gn() { 
  int k = 0;
  char c = *fs++;
  for (; !isdigit(c); c = *fs++);
  for (; isdigit(c); c = *fs++) k = k * 10 + c - '0';
  return k;
}

const int maxn = 100003;

struct edge { 
  int to, fr, w, ne;
  edge () { 
    to = fr = w = 0;
    ne = 0;
  }
  edge (int a, int b, int c, int nn) { 
    to = a, fr = b, w = c, ne = nn;
  }
}; 
edge e[maxn << 3];
int head[maxn << 1];
int cnt;

void addedge(int fr, int to, int w) { 
  e[cnt] = edge(to, fr, w, head[fr]), head[fr] = cnt++;
  e[cnt] = edge(fr, to, 0, head[to]), head[to] = cnt++;
}

int n, m, s, t, pre[maxn];
bool vis[maxn];

bool bfs() { 
  memset(vis, 0, sizeof(vis));
  memset(pre, -1, sizeof(pre));
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) { 
    int x = q.front();
    q.pop();
    for (int i = head[x]; ~i; i = e[i].ne) { 
      int y = e[i].to;
      if (not e[i].w or vis[y]) continue;
      vis[y] = 1;
      q.push(y);
      pre[y] = i;
    }
  }
  return (~pre[t]);
}

int get_flow() { 
  int now = pre[t];
  int minflow = 0x7fffffff;
  while (~now) { 
    minflow = min(minflow, e[now].w);
    now = pre[e[now].fr];
  }
  now = pre[t];
  while (~now) { 
    e[now].w -= minflow;
    e[now ^ 1].w += minflow;
    now = pre[e[now].fr];
  }
  return minflow;
}

int main() { 
  fread(buf, 1, (int)5e7, stdin);
  memset(head, -1, sizeof(head));
  n = gn(), m = gn(), s = gn(), t = gn();
  for (int i = 1; i <= m; i++) { 
    int a = gn(), b = gn(), c = gn();
    addedge(a, b, c);
  }
  int ans = 0;
  while (bfs()) { 
    ans += get_flow();
  }
  printf("%d\n", ans);
}
