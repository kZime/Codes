# include <bits/stdc++.h>
using namespace std;

inline char getc() {
	static char buf[1 << 18], *fs, *ft;
	return (fs == ft && (ft = (fs = buf) + fread(buf, 1 << 18, 1, stdin)), fs == ft) ? EOF : *fs++;
}

# define getc() getchar()

inline int gn() {
	int k = 0, f = 1;
	char c = getc();
	for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
	for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
	return k * f;
}

inline int gcd(int a, int b) { // a > b
    if(a < b) swap(a, b);
    while(a % b) { 
        a = a % b;
        if(a < b) swap(a, b);
    }
    return b;
}

int main() {
# ifndef LOCAL

//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
# endif
//    int n = gn(), m = gn();// n > m;
	int n = 10000, m = 10000;
    if(m > n) swap(m, n);
    int ans = 0;
    
    for(int i = 1; i <= m; i++) {
        ans += i;
        for(int j = i + 1; j <= m; j++) { 
            ans += gcd(i, j) << 1;
        }
    }
    for(int i = m + 1; i <= n; i++) { 
        for(int j = 1; j <= m; j++) { 
            ans += gcd(i, j);
        }
    }
	cout << ans;
	return 0;
}
