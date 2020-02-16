//kZime
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define wi(x) cerr << #x << ": " << x << '\n';
#else
#define wi(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
template<typename T>
inline T getNum() {
    T k = 0;
    char c = getchar(), f = 1;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}
#define gn() getNum<int>()
#define gl() getNum<ll>()
clock_t opt, edt;
inline void init() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    opt = clock();
#endif
}
inline void tini() {
#ifndef ONLINE_JUDGE
    edt = clock();
    cerr << "\n#cost: " <<  (double)(edt - opt) / CLOCKS_PER_SEC << "s\n";
#endif
}


// sum = odd

int main() {
    init();
///////////////////////////////////////////////////////////////////////////////

    int T = gn();
    map<pair<int, int>, int> vis;
    map<char, pair<int, int>> p = {
            {'U', {0, 1}},
            {'D', {0, -1}},
            {'L', {-1, 0}},
            {'R', {1, 0}}
    };
    char str[(int)2e5 + 3];
    pair<int, int> ans;
    while (T--) {
        int n = gn();
        int tmp = INF;
        cin >> (str + 1);
        vis.clear();
        int x = 0, y = 0;
        vis[{x, y}] = 1;
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            x += p[str[i]].first;
            y += p[str[i]].second;
            if (vis[{x, y}] and (i - vis[{x, y}] + 1 < tmp)) {
                ans = {vis[{x, y}], i};
                tmp = i - vis[{x, y}] + 1;
                flag = false;
            }
            vis[{x, y}] = i + 1;
        }
        if (flag) {
            printf("-1\n");
        } else {
            printf("%d %d\n", ans.first, ans.second);
        }

    }

///////////////////////////////////////////////////////////////////////////////
    tini();
}

