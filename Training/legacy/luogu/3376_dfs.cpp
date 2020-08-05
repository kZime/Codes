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

int n, m, s, t, dis[maxn];

bool bfs() { 
  memset(dis, -1, sizeof(dis));
  queue<int> q;
  q.push(s);
  dis[s] = 1;
  while (!q.empty()) { 
    int x = q.front();
    q.pop();
    for (int i = head[x]; ~i; i = e[i].ne) { 
      int y = e[i].to;
      if (!e[i].w or ~dis[y]) continue;
      dis[y] = dis[x] + 1;
      q.push(y);
    }
  }
  return (~dis[t]);
}

int dfs(int x, int val) { 
  int rec = 0;
  if (x == t) return val;
  for (int i = head[x]; ~i; i = e[i].ne) { 
    int y = e[i].to;
    if (dis[y] == dis[x] + 1 and e[i].w and (rec = dfs(y, min(val, e[i].w)))) { 
      e[i].w -= rec;
      e[i ^ 1].w += rec;
      return rec;
    }
  }
  return 0;
}

int max_flow() { 
  int ans = 0, u;
  while (bfs()) 
    while ((u = dfs(s, 0x7fffffff))) 
      ans += u;
  return ans;
}

int main() { 
  fread(buf, 1, (int)5e7, stdin);
  memset(head, -1, sizeof(head));
  n = gn(), m = gn(), s = gn(), t = gn();
  for (int i = 1; i <= m; i++) { 
    int a = gn(), b = gn(), c = gn();
    addedge(a, b, c);
  }
  printf("%d\n", max_flow());
}
