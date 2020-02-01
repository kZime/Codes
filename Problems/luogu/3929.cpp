#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int n, a[maxn], b[maxn];

int check(int a[], bool flag) {
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    int cnt = 0;
    for (int i = 2; i <= n; i++) { 
        if (flag) { 
            if (b[i] > b[i - 1]) 
                cnt++,
                b[i] = -INT_MAX;
        } else { 
            if (b[i] < b[i - 1])
                cnt++,
                b[i] = INT_MAX;
        }
        flag = !flag;
    }
    return cnt <= 1;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        cout << ((check(a, 1) or check(a, 0)) ? "Yes\n" : "No\n"); 
    }
}
