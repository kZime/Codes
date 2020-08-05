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
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            if (c[i] != a[i] and c[i] != b[i]) {
                printf("NO\n");
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        }
    }
    return 0;
}

