#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../tools.h"
#else
#define wi(x) 
#define wit(x) 
#endif
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

inline ll gn() {
    ll k = 0, f = 1ll;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

const int MAXN = 1000;
const int MAXM = 1000;
const int MOD = 23333;


ll f(ll x) {
    return (x * (x + 1)) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    #pragma warning(suppress : 4996)
    freopen("../output.txt", "w", stdout);
#endif
    int t = gn();
    while (t--) {
        ll n = gn(), m = gn();
        ll ans = f(n);
        if (m == 0) {
            printf("0\n");
        }
        else {
            ll s = (n - m) / (m + 1);
            ll q = (n - m) % (m + 1);
            ans -= q * f(s + 1) + (m + 1 - q) * f(s);
            printf("%lld\n", ans);
        }
    }
    return 0;
}

