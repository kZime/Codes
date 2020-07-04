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
    while (T--) {
        int n = gn(), sum = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(gn()), sum += v.back();
        if (sum & 1) {
            printf("YES\n");
        } else {
            int ocnt = 0, ecnt = 0;
            for (auto i : v) {
                if (i & 1) ocnt++;
                else ecnt++;
            }
            if (ocnt and ecnt) {
                printf("YES\n");
            }
            else printf("NO\n");
        }

    }

///////////////////////////////////////////////////////////////////////////////
    tini();
}

