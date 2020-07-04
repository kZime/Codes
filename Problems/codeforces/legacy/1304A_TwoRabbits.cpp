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
    int k = 0, f = 1;
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
    freopen("../output.txt", "w", stdout);
#endif
    int t = gn();
    while (t--) {
        int x = gn(), y = gn(), a = gn(), b = gn();
        if (y - x >= a + b and (y - x) % (a + b) == 0) {
            printf("%d\n", (y - x) / (a + b));
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}

