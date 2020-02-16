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
        string str;
        cin >> str;
        int n = str.size();
        int beg = -1, end = n;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                beg = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '1') {
                end = i;
                break;
            }
        }
        if (beg == end or beg == -1) {
            printf("0\n");
        }
        else {
            int ans = 0;
            for (int i = beg; i <= end; i++) {
                if (str[i] == '0') ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

/*
10 8 3
t = 3; sui = 4
0 6:
1 3
*/

