#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;

struct edge { 
  int to, w;
  edge *ne;
  edge(int to, int w, edge *ne) : to(to), w(w), ne(ne) {}
} *head[maxn];

void addedge (int fr, int to, int w) { 
  head[fr] = new edge(to, w, head[fr]);
}

int n, m, s, dis[maxn];

queue<int> q;
bitset<maxn> inq;

int main() { 
  cin >> n >> m >> s;
  fill(dis + 1, dis + 1 + n, 2147483647);
  for (int i = 1; i <= m; i++) { 
    int f, t, w;
    cin >> f >> t >> w;
    addedge(f, t, w);
  }
  q.push(s);
  dis[s] = 0;
  while (!q.empty()) { 
    int x = q.front();
    inq[x] = 0;
    q.pop();
    for (edge *e = head[x]; e; e = e->ne) { 
      if (dis[e->to] > dis[x] + e->w) { 
        dis[e->to] = dis[x] + e->w;
        if (inq[e->to]) continue;
        q.push(e->to);
        inq[e->to] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) { 
    cout << dis[i] << ' ';
  }
}
