
// kZime
//
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "tools.h"
#else
#define wi(x) 
#define wit(x) 
#endif;

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

int main() {
    int t = gn();
    while (t--) {
        int n = gn();
        string s;
        cin >> s;
        int sum = 0, odd = 0; // the number of odd.
        for (auto i : s) {
            sum += i - '0',
            odd += (i - '0') & 1;
        }
        while (!s.empty() and !(s.back() & 1)) {
            sum -= s.back() - '0',
            odd -= s.back() - '0' & 1,
            s.pop_back();
        }
        string ans;
        if (s.empty() or (odd == 1)) ans = "-1";
        else if (sum % 2 == 0) ans = s;
        else { // del odd * 1
            bool flag = 1;
            for (auto i : s) {
                if (flag and (i - '0') & 1) {
                    flag = 0;
                    continue;
                }
                ans += i;
            }
        }
        if (ans.size() == 0) ans = "-1";
        int p = 0;
        while (ans[p] == '0') p++;
        ans = ans.substr(p);
        cout << ans << '\n';
    }
    return 0;
}
