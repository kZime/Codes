# include <bits/stdc++.h>
using namespace std;
int f;
inline int gr(int l = 0, int r = f) {
	int k = 0;
    int len = r - l + 1;
    k = rand() % len + l;
	return k;
}

int n, m, q;
string op[3] = {"SUM", "MAX", "MIN"};

int main() {
	srand((long long) new char);
    n = 800, m = 800;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) { 
            cout << gr(1, 3000) << ' ';
        }
        cout << '\n';
    }
    q = gr(5, f);
    cout << q << '\n';
    while (q--) { 
        cout << op[gr(1, 2)] << ' ';
        int a = gr(0, n - 1), b = gr(0, m - 1);
        int c = gr(a, n - 1), d = gr(b, m - 1);
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
}
