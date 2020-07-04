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
    freopen("../output.txt", "w", stdout);
#endif
    int t = gn();
    while (t--) {
        vector <int> a;
        set <int> b;
        int n = gn(), preans = -1;
        for (int i = 0; i < n; i++)
            a.push_back(gn());
        for (int i = 0; i < n; i++) {
            if (i and a[i] != -1 and a[i - 1] != -1) {
                preans = max(preans, abs(a[i] - a[i - 1]));
            }
            if (a[i] == -1) {
                if (i and a[i - 1] != -1) b.insert(a[i - 1]);
                if (i != n - 1 and a[i + 1] != -1) b.insert(a[i + 1]);
            }
        }
        if (!b.size()) {
            printf("0 0\n");
            continue;
        }
        int s = *b.begin();
        int t = *b.rbegin();
        int ans = s + (t - s) / 2;
        printf("%d %d\n", max(max(t - ans, ans - s), preans), ans);
    }
    return 0;
}

