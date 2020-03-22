---
title: "Templates"
date: 2020-03-10T20:46:08+08:00
draft: true
---
# 读入

## fread + register快读

```cpp
inline char getc(){
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}

inline int gn() {
	register int k = 0, f = 1;
	register char c = getc();
	for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
	for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
	return k * f;
}


// 不能在使用标准读入输出了
```

## getchar快读

```cpp
template<typename T>
inline T getNum() {
    T k = 0;
    int c = getchar(), f = 1;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}
#define gn() getNum<int>()
#define gl() getNum<ll>()
```

# 字符串

## kmp

```cpp
inline void get_ne(char *st) {
	int n = strlen(st);
	int i = 0, j = -1;
	ne[0] = -1;
	while(i < n) {
		while(~j && st[i] != st[j]) j = ne[j];
		ne[++i] = ++j;
	}
}

inline int KMP(char *str, char *st) {
	int i = 0, j = 0;
	int res = 0, n = strlen(str), m = strlen(st);
	while(i < n) {
		while(~j && str[i] != st[j]) j = ne[j];
		i++, j++;
		if(j == m) res++;
	}
	return res;
}
```

# 数学

## 卢卡斯
```cpp
ll inv(ll x, ll p)//x关于p的逆元，p为素数
{
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p)//组合数C(n, m) % p
{
    if(m > n)return 0;
    ll up = 1, down = 1;//分子分母;
    for(int i = n - m + 1; i <= n; i++)up = up * i % p;
    for(int i = 1; i <= m; i++)down = down * i % p;
    return up * inv(down, p) % p;
}
ll Lucas(ll n, ll m, ll p)
{
    if(m == 0)return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

```

## 线性筛

```cpp
bool np[MAXN];
vector<int> pri;

void prime() {
    np[1] = true;
    for (int i = 2; i <= n; i++) {
        if (not np[i]) pri.push_back(i);
        for (int j = 0; pri[j] * i <= n and j < pri.size(); j++) {
            np[pri[j] * i] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}
```

## 快速幂

```cpp
ll pow(ll a, ll b, ll m) {
	ll res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
	}
	return res % m;
}
```



## 矩阵快速幂

```cpp
struct matrix {
    ll m[103][103], n;
    matrix(ll n) : n(n) {
        memset(m, 0, sizeof(m));
    }
    void input() {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> m[i][j];
            }
        }
    }
    void output() {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cout << m[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void unit() {
        for (ll i = 1; i <= n; i++)
            m[i][i] = 1;
    }
    matrix operator *(const matrix &a) const {
        matrix *res = new matrix(n);
        res->n = n;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                for (ll k = 1; k <= n; k++) {
                    (res->m[i][j] += m[i][k] * a.m[k][j]) %= MOD;
                }
            }
        }
        return *res;
    }
};

matrix pow(matrix x, ll k) {
    matrix a = *new matrix(x.n);
    a.unit();
    for (; k; k >>= 1) {
        if (k & 1) a = x * a;
        x = x * x;
    }
    return a;
}
```



# 图论

## 堆优化DIJKSTRA 

```cpp
struct edge { 
    int to, w;
    edge *ne;
    edge (int to, int w, edge *ne) : to(to), w(w), ne(ne) {}
} *head[maxn];

void addedge(int fr, int to, int w) { 
    head[fr] = new edge(to, w, head[fr]);
}

struct status { 
    int x, w;
    status(int x, int w) : x(x), w(w) {}
    bool operator < (const status &b) const { 
        return w > b.w;
    }
};

priority_queue<status> q;

int dis[MAXN];

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) 
        dis[i] = INF;
    dis[s] = 0;
    q.push(status(s, 0));
    while (not q.empty()) { 
        int u = q.top().x, d = q.top().w;
        q.pop();
        if (d > dis[u]) continue;
        for (edge *e = head[u]; e; e = e->ne) { 
            int v = e->to, w = e->w;
            if (dis[u] + w < dis[v]) { 
                dis[v] = dis[u] + w;
                q.push(status(v, dis[v]));
            }
        }
    }
}
```

## 倍增LCA

```cpp
void dfs(int u) {
    dep[u] = dep[f[u][0]] + 1;
    for(int i = 1; i <= 19 && f[u][i - 1]; i++) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(edge *e = head[u]; e; e = e->ne) { 
        if(e->to == f[u][0]) continue;
        f[e->to][0] = u;
        dfs(e->to);
    }
}

inline int lca(int x, int y) { 
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--) { 
        if(dep[f[x][i]] >= dep[y]) { //f[x][i] 在y下方
            x = f[x][i];
        }
    }
    if(x == y) return x;
    for(int i = 19; i >= 0; i--) { 
        if(f[x][i] ^ f[y][i]) { 
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}
```



## 克鲁斯卡尔

```cpp
struct edge { 
  int fr, to, w;
  bool operator<(const edge a) const { 
    return w < a.w;
  }
} e[MAXM];

int f[MAXN];

int gf(int x) { 
  if (f[x] == x) return x;
  return f[x] = gf( f[ f[ f[x] ] ] );
}

void merge(int a, int b) { 
  f[gf(b)] = gf(a);
} 

bool lt(int a, int b) { 
  return gf(a) == gf(b);
}

int kruskal() {
    sort(e + 1, e + 1 + m);
  	int res = 0;
  	for (int i = 1; i <= n; i++) f[i] = i;
  	for (int i = 1; i <= m; i++) { 
    	edge *d = e + i;
    	if (!lt(d->fr, d->to)) { 
      		merge(d->fr, d->to);
      		res += d->w;
    	}
  	}
    return res;
}
```



# 数据结构

## 树状数组

```cpp
inline int lb(int x) {return x & -x;}

inline void add(int x, int k) { 
  for (; x <= n; x += lb(x))
    a[x] += k;
}

inline int sum(int x) { 
  int res = 0;
  for (; x; x -= lb(x))
    res += a[x];
  return res;
}
```



## zkw线段树

```cpp
inline void build() {
    for(M = 1; M <= n + 1; M <<= 1);// M可以等于n 所以要M <= n + 1
    for(int i = M + 1; i <= M + n; i++) { // 处理叶子节点
        nd[i] = get_num();
    }
    for(int i = M; i >= 1; i--) { // 处理父节点
        push_up(i);
    }
}

inline void change_one_point(int x , int k) {
    x += M;
	nd[x] += k;
    for(x >>= 1; x; x >>= 1) {
        push_up(x);
    }
}

inline int query(int l, int r) {
    int res = 0;
    for(l = M + l - 1, r = M + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1) { // l = M + l - 1, r = M + r + 1, 意思是将l 和 r 变成开区间，l ^ r ^ 1  -->  not l ^ r == 1  -->  l 和 r不是同一节点的两个子节点
        if(~l & 1) res += nd[l + 1];// l是左子区间                       
        if(r & 1) res += nd[r - 1]; // r是右子区间                       
    }
    return res;
}
```

## 树链剖分
```cpp
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

inline int query(int u, int v) { 
# define tu top[u]
# define tv top[v]
    int res = 0;
    while(tu != tv) { 
        if(dep[tu] < dep[tv]) swap(u, v);
        res = max(res, query(adfn[tu], adfn[u]));
        u = fa[tu];
    }
    if(dep[u] > dep[v]) swap(u, v);
    res = max(res, find(adfn[u] + 1, adfn[v]));
    return res;
}
```

## Splay
```cpp
struct SplayTree {
    struct ST_Node {
        ST_Node *left,*right,*father;
        int value,weight;
    }*root;
    int SC;
    ST_Node SE[MAXN];
    void ZIG(ST_Node *x) {
        ST_Node *y=x->father;
        // x->right
        y->left = x->right;
        if (x->right)
            x->right->father=y;
        // y->father
        x->father = y->father;
        if (y->father) {
            if (y==y->father->left)
                y->father->left = x;
            else
                y->father->right = x;
        }
        // y
        x->right = y;
        y->father = x;
    }
    void ZAG(ST_Node *x) {
        ST_Node *y=x->father;
        // x->left
        y->right = x->left;
        if (x->left)
            x->left->father=y;
        // y->father
        x->father = y->father;
        if (y->father) {
            if (y==y->father->left)
                y->father->left = x;
            else
                y->father->right = x;
        }
        x->left = y;
        y->father = x;
    }
    void Splay(ST_Node *x,ST_Node *y) {
        while (x->father != y) {
            if (x->father->father == y) {
                if (x->father->left == x)
                    ZIG(x);
                else
                    ZAG(x);
            }
            else if (x->father->father->left == x->father) {
                if (x->father->left == x) {
                    ZIG(x->father);
                    ZIG(x);
                }
                else {
                    ZAG(x);
                    ZIG(x);
                }
            }
            else {
                if (x->father->right == x) {
                    ZAG(x->father);
                    ZAG(x);
                }
                else {
                    ZIG(x);
                    ZAG(x);
                }
            }
        }
        if (y==0)
            root=x;
    }
    void insert(int value) {
        ST_Node **p=&root,*y=0;
        while(true) {
            if (!*p) {
                *p=SE+ (++SC);
                (*p)->left = (*p)->right = 0;
                (*p)->value = value;
                (*p)->weight = 1;
                (*p)->father = y;
                Splay(*p,0);
                break;
            }
            y=*p;
            if (value == (*p)->value) {
                (*p)->weight ++;
                Splay(*p,0);
                break;
            }
            else if (value < (*p)->value)
                p=&(*p)->left;
            else
                p=&(*p)->right;
        }
    }
    ST_Node* join(ST_Node *a,ST_Node *b) {    
        if (a) a->father=0;
        if (b) b->father=0;
        if (!b)    return a;
        if (!a) return b;
        ST_Node *c=a;
        for (;c->right;c=c->right);
        Splay(c,0);
        c->right=b;
        b->father=c;
        return c;
    }
    void remove(ST_Node *x) {
        Splay(x,0);
        root=join(x->left,x->right);
    }
    void delmin(int &min,int &cnt) {
        ST_Node *x=root;
        for (;x->left;x=x->left);
        min=x->value; cnt=x->weight;
        remove(x);
    }
}Splay;
```

# 杂项

## 计时

```cpp
clock_t opt, edt;
opt = clock();
edt = clock();
cerr << "\n#cost: " <<  (double)(edt - opt) / CLOCKS_PER_SEC << "s\n";
```

