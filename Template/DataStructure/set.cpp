# include <bits/stdc++.h>
using namespace std;

set <int> s;

int main() { 
    int n;
    cin >> n;
    for(int i = 1; i <= n << 1; i += 2) s.insert(i);
    while(1) { 
        int a;
        cin >> a;
        cout << *--s.lower_bound(a) << endl;
    }
}
