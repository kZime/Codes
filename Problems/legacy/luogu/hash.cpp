# include <bits/stdc++.h>
using namespace std;

unsigned int has(char *c) { 
    unsigned int res = 0;
    unsigned int len = strlen(c + 1);
    for(unsigned int i = 1; i <= len; i++) { 
        res = res * 127 + c[i] - '0';
    }
    return res;
} 

char s[1602];
unsigned int n, h[10102];

int main() { 
    scanf("%d", &n);
    for(unsigned int i = 1; i <= n; i++) { 
        scanf("%s", s + 1);
        h[i] = has(s);
    }
    sort(h + 1, h + n + 1);
    int ans = 1;
    for(unsigned int i = 2; i <= n; i++) { 
        if(h[i] ^ h[i - 1]) ans++;
    }
    printf("%d\n", ans);
}