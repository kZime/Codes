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
    int n = gn();
    vector<int> v, a[33];
    for (int i = 0; i < n; i++) {
        int tmp = gn();
        v.push_back(tmp);
        for (int j = 0; tmp; j++) {
            if (tmp & 1) a[j].push_back(i);
            tmp >>= 1;
        }
    }
    int fidd = -1;
    for (int j = 32; j >= 0; j--) {
        if (a[j].size() == 1) {
            fidd = j;
            break;
        }
    }
    if (fidd == -1) {
        for (auto i : v) {
            printf("%d ", i);
        }
        putchar('\n');
    }
    else {
        fidd = a[fidd][0];
        int ans = v[fidd];
        printf("%d ", ans);
        for (auto i : v) {
            if (i == v[fidd]) continue;
            printf("%d ", i);
        }
        putchar('\n');
    }
    return 0;
}


