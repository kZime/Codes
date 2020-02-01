#include <bits/stdc++.h>
using namespace std;
inline int gn() { 
    int k = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}
int mi[801][801][11], mx[801][801][11], a[801][801], n, m;
int q, sum[801][801], maxa, mina = 0x7fffffff;
char op[5];
void init() { 
    for (int l = 1; l <= n; l++) { 
        for (int k = 1; k <= 10; k++) { 
            for (int i = 1; i <= m; i++) { 
                if (i + (1 << (k - 1)) - 1> m) break;
                mi[l][i][k] = min(mi[l][i][k - 1], mi[l][i + (1 << (k - 1))][k - 1]);
                mx[l][i][k] = max(mx[l][i][k - 1], mx[l][i + (1 << (k - 1))][k - 1]);
            }
        }
    }
}
inline int getmax(int a, int b, int c, int d) { 
    int k = log2(d - b + 1), ans = 0;
    for (int l = a; l <= c; l++) { 
        ans = max(ans, max(mx[l][b][k], mx[l][d - (1 << k) + 1][k]));
        if (ans == maxa) break;
    }
    return ans;
}
inline int getmin(int a, int b, int c, int d) { 
    int k = log2(d - b + 1), ans = 0x7fffffff;
    for (int l = a; l <= c; l++) { 
        ans = min(ans, min(mi[l][b][k], mi[l][d - (1 << k) + 1][k]));
        if (ans == mina) break;
    }
    return ans;
}
int main() { 
    memset(mi, 0x7f, sizeof(mi));
    n = gn(), m = gn();
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            int t = gn();
            *mx[i][j] = *mi[i][j] = t;
            mina = min(mina, t);
            maxa = max(maxa, t);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + t;
        }
    init();
    q = gn();
    while (q--) { 
        scanf("%s", op);
        int a = gn() + 1, b = gn() + 1, c = gn() + 1, d = gn() + 1;
        if (op[1] == 'U') { 
            cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1] << '\n';
        } else if (op[1] == 'A') { 
            cout << getmax(a, b, c, d) << "\n";
        } else { 
            cout << getmin(a, b, c, d) << "\n";
        }
    }
}
