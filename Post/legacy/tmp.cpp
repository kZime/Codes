vector<int> g[N];

void addEdge(int x, int y) {
	g[x].push_back(y);
	g[y].push_back(x);
}

int fa[N][20], dep[N];

fa[x][i + 1] = fa[fa[x][i]][i];

void dfs(int x) {
	for (int i = 0; fa[x][i]; ++i) fa[x][i + 1] = fa[fa[x][i]][i];
	for (int to : g[x]) {
		if (fa[x][0] == to) continue ;
		dep[to] = dep[x] + 1;
		fa[to][0] = x;
		dfs(to);
	}
}

dfs(1);

int lca(int x, int y) {
	if (dep[x] != dep[y]) {
		if (dep[x] < dep[y]) swap(x, y);
		for (int t = dep[x] - dep[y], i = 16; ~i; --i) 
			if (t & (1 << i)) 
				x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 16; ~i; --i) 
		if (fa[x][i] != fa[y][i]) 
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}


void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			// Do sth
		}
	}
}

int ex_gcd(int a, int b, int &x, int &y) { 
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}
const int mod = 1e9 + 7;

int inv(int x) {
	int a, b;
	ex_gcd(x, mod, a, b);
	return ((a % mod) + mod) % mod;
}

int qpow(int x, int n) { 
	int ans = 1;
	for ( ; n; n /= 2, x = (ll) x * x % mod) {
		if (n & 1) ans = (ll) ans * x % mod;
	}
	return ans;
}

qpow(x, mod - 2);

int fac[N], inv[N];

void prepare(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) 
		fac[i] = (ll) fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	for (int i = n; i >= 1; --i) 
		inv[i - 1] = (ll) inv[i] * i % mod;
	
	// inv[x] = 1 / (x!)
	// (ll) fac[x - 1] * inv[x] % mod;
}

inline int nCr(int n, int m) {
	return n < m ? 0 : (ll) fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void prepare(int n) {
	inv[1] = 1;
	for (int i = 2; i <= n; ++i)
		inv[i] = (ll) inv[mod % i] * (mod - mod / i) % mod;
}

int inver(int x) {
	if (x == 1) return 1;
	return (ll) inver(mod % x) * (mod - mod / x) % mod;
}
