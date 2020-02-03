// kZime
//

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
        int n = gn();
        vector<int>v;
        for (int i = 1; i <= n; i++)
            v.push_back(gn());
        int k = 0;
        bool flag = 1;
        for (auto i : v) {
            if (flag and i < min(k, n - 1 - k)) {
                flag = 0;
                break;
            }
            k++;
        }
        if (flag) {
            if ((n & 1) == 0 and v[n / 2] == v[n / 2 - 1] and v[n / 2] == n / 2 - 1) {
                printf("NO\n");
            }
            else printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}

 
