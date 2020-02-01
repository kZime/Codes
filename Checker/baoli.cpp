#include<bits/stdc++.h>
using namespace std;
inline char getc()
{
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int gn()
{
    register int k = 0, f = 1;
    register char c = getc();
    for (; !isdigit(c); c = getc()) if (c == '-') f = -1;
    for (; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return k * f;
}
const int maxn = 800 + 10;
int s[maxn][maxn], d[maxn][maxn];
int n, m, q;
int sum(int x1, int y1, int x2, int y2)
{
    return d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
}
int main()
{
    n = gn(), m = gn();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j] = gn(), d[i][j] = s[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            d[i][j] += d[i - 1][j] - d[i - 1][j - 1] + d[i][j - 1];
    q = gn();
    for (int i = 1; i <= q; ++i)
    {
        char c = getc();
        for (; !isalpha(c); c = getc());
        c = getc();
        getc();
        int x1 = gn(), y1 = gn(), x2 = gn(), y2 = gn();
        ++x1, ++x2, ++y1, ++y2;
        if (c == 'U') // SUM
        {
            printf("%d\n", sum(x1, y1, x2, y2));
        }
        else if (c == 'A') // MAX
        {
            int ans = 0;
            for (int j = x1; j <= x2; ++j)
                for (int k = y1; k <= y2; ++k)
                    ans = max(ans, s[j][k]);
            printf("%d\n", ans);
        }
        else if (c == 'I') // MIN
        {
            int ans = 1e9 + 233;
            for (int j = x1; j <= x2; ++j)
                for (int k = y1; k <= y2; ++k)
                    ans = min(ans, s[j][k]);
            printf("%d\n", ans);
        }
    }
}
