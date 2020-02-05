# include <bits/stdc++.h>
# define INF 0x7fffffff
# define MAXN 30023
 
using namespace std;
 
char buf[1<<18],*fs,*ft;
inline char getc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin)),fs==ft)?EOF:*fs++;}
 
inline int gn() {
	int k = 0, f = 1;
	char c = getc();
	for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
	for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
	return k * f;
}
 
inline char haha() {
	char c = getc();
	for(; !isalpha(c); c = getc());
	return c = getc();
}
 
struct edge {
	int to;
	edge *ne;
	inline edge() {
		to = 0, ne = NULL;			
	}
	inline edge(int to_, edge *ne_) {
		to = to_, ne = ne_;
	}
}*head[MAXN];
 
inline void addedge(int fr, int to) {
	edge *e = new edge(to, head[fr]);
	head[fr] = e;
	edge *d = new edge(fr, head[to]);
	head[to] = d;
}
 
int n, a[MAXN], Q;
 
int q[MAXN], fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
 
inline void bfs() {
	int l = 1, r = 1;
	memset(son, -1, sizeof(son));
	q[1] = 1;
	while(l <= r) {
		int u = q[l++];
		siz[u] = 1;
		dep[u] = dep[fa[u]] + 1;
		for(edge *e = head[u]; e; e = e->ne) {
			if(siz[e->to]) continue;
			fa[e->to] = u;
			q[++r] = e->to;
		}
	}
	for(int i = r; i; i--) {
		siz[fa[q[i]]] += siz[q[i]];
		if(siz[q[i]] > siz[son[fa[q[i]]]]) son[fa[q[i]]] = q[i];
	}
}
 
int top[MAXN], dfn[MAXN], adfn[MAXN], id;
 
void dfs(int x, int tp) {
	dfn[x] = ++id;
	adfn[id] = x;
	top[x] = tp;
	if(!~son[x]) return;
	dfs(son[x], tp);
	for(edge *e = head[x]; e; e = e->ne) {
		if(dfn[e->to]) continue;
		dfs(e->to, e->to);
	}
}
 
int mx[MAXN << 2], sum[MAXN << 2], M;
 
inline void pushup(int x) {
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
 
inline void build() {
	memset(mx, 0x80, sizeof(mx));
	for(M = 1; M <= n + 1; M <<= 1);
	for(int i = 1; i <= n; i++) {
		mx[i + M] = sum[i + M] = a[adfn[i]];
	}
	for(int i = M; i >= 1; i--) {
		pushup(i);
	}
}
 
inline void change(int x, int k) {
	mx[x + M] = sum[x + M] = k;
	for(int i = (x + M) >> 1; i; i >>= 1) {
		pushup(i);
	}
}
 
inline int query_max(int l, int r) {
	int ans = -INF;
	for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if(~l & 1) ans = max(ans, mx[l + 1]);
		if(r & 1) ans = max(ans, mx[r - 1]);
	}
	return ans;
}
 
inline int query_sum(int l, int r) {
	int ans = 0;
	for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if(~l & 1) ans += sum[l + 1];
		if(r & 1) ans += sum[r - 1];
	}
	return ans;
}
 
inline int find_max(int u, int v) {
	int tu = top[u], tv = top[v];
	int ans = -INF;
	while(tu ^ tv) {
		if(dep[tu] < dep[tv]) {
			swap(tu, tv);
			swap(u, v);
		}
		ans = max(ans, query_max(dfn[tu], dfn[u]));
		u = fa[tu];
		tu = top[u];
	}
	if(u ^ v) {
		if(dep[u] < dep[v]) swap(u, v);
	}
		ans = max(ans, query_max(dfn[v], dfn[u]));
	return ans;
}
 
inline int find_sum(int u, int v) {
	int tu = top[u], tv = top[v];
	int ans = 0;
	while(tu ^ tv) {
		if(dep[tu] < dep[tv]) {
			swap(tu, tv);
			swap(u, v);
		}
		ans += query_sum(dfn[tu], dfn[u]);
		u = fa[tu];
		tu = top[u];
	}
	if(u ^ v) {
		if(dep[u] < dep[v]) swap(u, v);
	}
	ans += query_sum(dfn[v], dfn[u]);
	return ans;
}
 
int main() { 
#ifndef LOCAL
	freopen("bzoj_1036.in", "r", stdin);
	freopen("bzoj_1036.out", "w", stdout);
#endif
	n = gn();
	for(int i = 1; i < n; i++) addedge(gn(), gn());
	bfs();
	dfs(1, 1);
	for(int i = 1; i <= n; i++) a[i]= gn();
	build();
	Q = gn();
	while(Q--) {
		char op = haha();
		if(op == 'M') {
			int l = gn();
			int r = gn();
			printf("%d\n", find_max(l, r));
		} else if(op == 'S') {
			int l = gn();
			int r = gn();
			printf("%d\n", find_sum(l, r));
		} else if(op == 'H') {
			int x = gn();
			int k = gn();
			change(dfn[x], k);
		}
	}
}
