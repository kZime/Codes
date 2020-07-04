#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "tools.h"
#else
#define wi(x) 
#define wit(x) 
#endif
#include <iostream>
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



int main() {
#ifndef ONLINE_JUDGE
    #pragma warning(suppress : 4996)
    freopen("output.txt", "w", stdout);
#endif
    int t = gn();
    while (t--) {
        ll n = gn(), g = gn(), b = gn(), m;
        m = n;
        n = (n+1) / 2;
        ll k = n / g;
        ll p = n % g;
        ll ans;
        if (p != 0) {
            ans = k * (g + b) + p;
        }
        else {
            ans = (k * (g + b) - b);
        }
        if (ans < m) ans = m;
        printf("%lld\n", ans);
    }
    return 0;
}

/*
10 8 3
t = 3; sui = 4
0 6:
1 3
*/

