#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;

struct edge { 
  int to, w, ne;
  edge () { 
    to = w = ne = 0;
  }
  edge (int a, int b, int c) { 
    to = a, w = b, ne = c;
  }
} e[maxn << 3];

int cnt, head[maxn];

void addedge(int a, int b, int c) { 
  e[cnt] = edge(b, c, head[a]), head[a] = cnt++;
}

int n, m, s, t;

int dis[maxn];

bool bfs() { 
  memset(dis, -1, sizeof(dis));
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (!q.empty()) { 
    int x = q.front();
    q.pop();
    for (int i = head[x]; ~i; i = e[i].ne) { 
      int y = e[i].to;
      if (dis[y] == -1 and e[i].w != 0) { 
        dis[y] = dis[x] + 1;
        q.push(y);
      }
    }
  }
  return (~dis[t]);
}

int dfs(int x, int val) {
  int rec;
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
    while((u = dfs(s, 0x7fffffff)))
      ans += u;
  return ans;
}

int main() { 
  memset(head, -1, sizeof(head));
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) { 
    int a, b, c;
    cin >> a >> b >> c;
    addedge(a, b, c);
    addedge(b, a, 0);
  }
  printf("%d\n", max_flow());
}
