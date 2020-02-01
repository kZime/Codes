# include <bits/stdc++.h>
# define MAXN 100000023
using namespace std;

inline int gn() {
    int k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

bool np[MAXN];
int p[MAXN / 10], cnt;

inline void shai(int N) {
    np[1] = 1;
    for(register  int i = 2; i <= N; i++) {
        if(!np[i]) {
            p[++cnt] = i;
        }
        for(register int j = 1; j <= cnt && p[j] * i <= N; j++) {
            np[p[j] * i] = 1;
            if(!(i % p[j])) break;
        }
    }
}

int main() {
    int n = gn();
//    int n = 100000000;
    shai(n);
    cout << cnt << endl;
}