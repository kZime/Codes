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

int s[100];

int main() {
    int t = gn();
    while (t--) {
        ll n = gn(), m = gn(), ans = 0;
        bool flag = 0;
        memset(s, 0, sizeof(s));
        
        for (int i = 1; i <= m; i++) {
        	s[(int)log2(gn())]++;
        }
        for (int i = 0; (1ll << i) <= n; i++) {
        	if (n & (1ll << i)) {
        		if (!s[i]) {
        			for (int j = i + 1; j <= 62; j++) {
        				if (s[j]) {
        					s[j]--;
        					ans++;
        					s[i] = 2;
        					for (int k = i + 1; k < j; k++) {
        						s[k] = 1;
        						ans++;
							}
							break;
						}
					}
					if (!s[i]) { //no 1 over there
						flag = 1;
						break;
					}
					//got it
				} 
				s[i]--;
				s[i + 1] += s[i] / 2;
				s[i] = 0;
			} else {
				s[i + 1] += s[i] / 2;
				s[i] = 0;
			}
		}
		if (flag) {
			printf("-1\n");
		} else {
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

