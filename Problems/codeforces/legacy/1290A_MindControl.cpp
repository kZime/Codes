#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "tools.h"
#else
#define wi(x) 
#define wit(x) 
#endif
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

inline int gn() {
    int k = 0;
    char c = getchar(), f = 1;
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
        int n = gn(), m = gn(), k = gn(), t = min(m - 1, k);
        vector <int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(gn());
        int ans = -INF;
        for (int l = 0, r = n - 1 - t; r < n; l++, r++) {
            int tmp = INF;
            wi(l);
            wi(r);
            for (int ll = l, rr = r - (m - 1 - t); rr <= r; ll++, rr++) {
                wi(ll);
                wi(rr);
                tmp = min(tmp, max(v[ll], v[rr]));
                
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
10 8 3
t = 3; sui = 4
0 6:
1 3
*/

