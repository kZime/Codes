#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, h2, h5;

void check(int x) { 
    while (x % 2 == 0) { 
        h2++;
        x >>= 1;
    }
    while (x % 5 == 0) { 
        h5++;
        x /= 5;
    }
}

int main() { 
    cin >> n >> k;
    if (k == 10) { 
        for (int i = 2; i <= n; i++)
            check(i);
        cout << min(h2, h5);
    }
}
