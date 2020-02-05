# include <bits/stdc++.h>
# define ull unsigned long long
using namespace std;

inline ull pow(ull a, ull b) { //return a ^ b
    ull ans = 1;
    for(; b; b >>= 1) { 
        if(b & 1) ans *= a;
        a *= a;
    }
    return ans;
}

inline ull mul(ull a, ull b) { //return a * b
    ull ans = 0;
    for(; b; b >>= 1) { 
        if(b & 1) ans += a;
        a <<= 1;
    }
    return ans;
}

int main() { 
    ull a, b;
    cin >> a >> b;
    cout << mul(a, b) << endl;
    cout << pow(a, b) << endl;
}
