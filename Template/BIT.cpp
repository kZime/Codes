# include <bits/stdc++.h>
using namespace std;

inline int gn() { 
    int k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

int a[100], n, m;

inline int lb(int x) {return x & -x;}

inline void add(int x, int y) { 
    for(; x <= n; x += lb(x))
        a[x] += y;
}

inline int query(int x) { 
    int ans = 0;
    for(; x; x -= lb(x)) 
        ans += a[x];
    return ans;
}

int main() { 
    n = gn();
    for(int i = 1; i <= n; i++) add(i, gn());
    int l = gn(), r = gn();
    printf("%d\n", query(r) - query(l - 1));
}
