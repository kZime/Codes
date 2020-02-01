#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++)
        cout << a[i];
    cout << '\n';
}