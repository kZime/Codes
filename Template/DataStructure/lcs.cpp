# include <bits/stdc++.h>
# define MAXN 1000
using namespace std;

char a[MAXN], b[MAXN];
int f[MAXN][MAXN], la, lb;

int main() {
    while(scanf("%s%s", a + 1, b + 1) != EOF) {
        la = strlen(a + 1);
        lb = strlen(b + 1);
        for(int i = 1; i <= la; i++) { 
            for(int j = 1; j <= lb; j++) { 
                if(a[i] == b[j]) { 
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else { 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        printf("%d\n", f[la][lb]);
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
}
