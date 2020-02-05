#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>
#define file(x) "turnover." #x
using std::min;
const int N = 1e5 + 10;
int n, st[N], nsz, rt, ch[N][2], fa[N], ans;//st[i] i节点的key
inline void lk(int x, int y, int d) {//x是y的ch[d]
	if (x) fa[x] = y;
	if (y) ch[y][d] = x;
}
inline int gd(int o) {return ch[fa[o]][1] == o;}//返回 o是右节点
inline void rot(int o) {//向上转
	int x = fa[o], d = gd(o);
	lk(o, fa[x], gd(x));
	lk(ch[o][d^1], x, d);
	lk(x, o, d^1);
	if (x == rt) rt = o;
}
inline int newnode(int v) {//新建节点
	st[++nsz] = v;
	return nsz;
}
void splay(int o) {
	for (int x; (x = fa[o]); rot(o)) //如果x o 同向，先转比较高的x
		if(fa[x]) rot(gd(o) == gd(x) ? x : o);
}
void insert(int o, int v) {//普通的插入
	for (int p; (p = ch[o][v >= st[o]]); o = p) ;
	lk(newnode(v), o, v >= st[o]);
	splay(nsz);
}
int sp(int o, int t) {//0 是前驱最大 1 是后驱最小
	for (o = ch[o][t], t ^= 1; ch[o][t]; o = ch[o][t]) ;
	return o;
}
int main() {
	freopen(file(in), "r", stdin);
	freopen(file(out), "w", stdout);
	scanf("%d", &n);
	while (n--) {
		int x;
		if (scanf("%d", &x) == EOF) x = 0;
		if (rt) insert(rt, x);
		else rt = newnode(x);
		int a = sp(rt, 0), b = sp(rt, 1), d = INT_MAX;
		if (a) d = min(abs(st[a] - x), d);
		if (b) d = min(abs(st[b] - x), d);
		if (!a && !b) d = x;
		ans += d;
	}	
	printf("%d\n", ans);
}
