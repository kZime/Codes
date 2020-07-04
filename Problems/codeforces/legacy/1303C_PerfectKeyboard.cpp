#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

inline ll gn() {
    ll k = 0, f = 1ll;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

const int MAXN = 1000;
const int MAXM = 1000;
const int MOD = 23333;

char nx['{'], pr['}'];
bool usd['{'];

int main() {
    int t = gn();
    while (t--) {
        string str;
        memset(nx, 0, sizeof(nx));
        memset(pr, 0, sizeof(nx));
        memset(usd, 0, sizeof(usd));
        cin >> str;
        int n = str.size();
        char now = 0, beg = 0;
        for (auto i : str) {
            if (!now) {
                now = i;
                beg = i;
                usd[i] = 1;
            }
            else {
                if (i == nx[now] or i == pr[now]) {
                    now = i;
                    usd[i] = 1;
                } 
                else if (!nx[now] and !usd[i]) {
                	usd[i] = 1;
                    nx[now] = i;
                    pr[i] = now;
                    now = i;
                }
                else if (!pr[now] and !usd[i]) {
                	usd[i] = 1;
                    pr[now] = i;
                    nx[i] = now;
                    now = i;
                    beg = i;
                }
                else {
                    now = -1;
                    break;
                }
            }
        }
        if (now == -1) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            while (beg) {
                putchar(beg);
                usd[beg] = 1;
                beg = nx[beg];
            }
            for (char c = 'a'; c <= 'z'; c++) {
                if (!usd[c]) putchar(c);
            }
            putchar('\n');
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

