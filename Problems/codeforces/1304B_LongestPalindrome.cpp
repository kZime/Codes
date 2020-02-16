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

bool usd[1034];

int main() {
#ifndef ONLINE_JUDGE
    #pragma warning(suppress : 4996)
    freopen("../output.txt", "w", stdout);
#endif
        vector<string> s;
        vector<string> hp;
        int hw = -1;
        string str;
        memset(usd, 0, sizeof(usd));
        s.clear();
        hp.clear();
        int n = gn(), m = gn();
        for (int i = 0; i < n; i++) {
            cin >> str;
            s.push_back(str);
        }
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            for (int j = i + 1; j < n; j++) {
                bool flag = 1;
                for (int k = 0; k < m; k++) {
                    if (s[i][k] != s[j][m - 1 - k]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag and !usd[j]) {
                    usd[i] = 1;
                    usd[j] = 1;
                    hp.push_back(s[i]);
                }
            }
            bool flag = 1;
            for (int k = 0; k < m; k++) {
                if (s[i][k] != s[i][m - 1 - k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                hw = i;
            }
        }
        if (~hw) {
            cout << m * (hp.size() * 2 + 1) << '\n';
            for (int i = 0; i < hp.size(); i++) {
                cout << hp[i];
            }
            cout << s[hw];
            for (int i = hp.size() - 1; i >= 0; i--) {
                for (int k = m - 1; k >= 0; k--)
                    putchar(hp[i][k]);
            }
        }
        else {
            if (hp.size()) {
                cout << m * (hp.size() * 2) << '\n';
                for (int i = 0; i < hp.size(); i++) 
                    cout << hp[i];
                for (int i = hp.size() - 1; i >= 0; i--) 
                    for (int k = m - 1; k >= 0; k--)
                        putchar(hp[i][k]);
            }
            else {
                printf("0\n");
            }
            
        }
    return 0;
}

