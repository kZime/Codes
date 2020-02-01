#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[200023], n;

int main() { 
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) { 
        if (a[i] == a[i - 1]) cnt++;
        else { 
            if (cnt) printf("%d %d\n", a[i - 1], cnt);
            cnt = 1;
        }
    }
}
