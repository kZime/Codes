# include <bits/stdc++.h>
# define MAXN 100032
using namespace std;

inline int gn() {
	char c = getchar();
	int k = 0, f = 1;
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
	return k * f;
}

int a[MAXN], h[MAXN], dp[MAXN], n, maxa, ans;

struct zkw {
	int M, x[MAXN << 1];
	zkw() {
		M = 1;
		memset(x, 0, sizeof(x));
	}
	void build(int N) {
		for(; M + 1 <= N; M <<= 1);
	}
	void ins(int o, int p) {
		x[o + M] = p;
		for(o = (o + M) >> 1; o; o >>= 1) {
			x[o] = max(x[o << 1 | 1], x[o << 1]);
		}
	}
	int que(int l, int r) {
		int ans = 0;
		for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if(~l & 1) ans = max(ans, x[l + 1]);
			if(r & 1) ans = max(ans, x[r - 1]);
		}
		return ans;
	}
}seg;

pair<int, int> tmp[MAXN];
int cnt;

inline void lsh() { 
    for(int i = 1; i <= n; i++) { 
        tmp[i] = make_pair(a[i], i);
    }
    sort(tmp + 1, tmp + n + 1);
    for(int i = 1; i <= n; i++) { 
        if(i == 1 || tmp[i].first != tmp[i - 1].first) cnt++;
        a[tmp[i].second] = cnt;
    }
}

int main() { 
	n = gn();
	for(int i = 1; i <= n; i++) {
        a[i] = gn();
        maxa = max(a[i], maxa);
	}
    lsh();
	seg.build(cnt);
	for(int i = 1; i <= n; i++) {
		dp[i] = seg.que(1, a[i] - 1) + 1;
        ans = max(dp[i], ans);
        seg.ins(a[i], dp[i]);
	}
    printf("%d\n", ans);
}
