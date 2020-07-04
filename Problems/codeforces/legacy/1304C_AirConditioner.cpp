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

const int MAXN = 1000;
const int MAXM = 1000;
const int MOD = 23333;

int main() {
#ifndef ONLINE_JUDGE
    #pragma warning(suppress : 4996)
    freopen("../input.txt", "r", stdin);
    #pragma warning(suppress : 4996)
    freopen("../output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q--) {
        ll n, m, now;
        cin >> n >> m;
        ll l = m, r = m, t, tl, tr;
        now = 0;
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            cin >> t >> tl >> tr;
            r += t - now;
            l -= t - now;
            if (r > tr) r = tr;
            if (l < tl) l = tl;
            if (r < l) 
                flag = 0;
            now = t;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}

