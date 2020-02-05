# include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main() { 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) v.push_back(i);
    cout << *--v.end() << endl;
    cout << v.back() << endl;
}
