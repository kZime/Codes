#include <bits/stdc++.h>
using namespace std;

inline int gn() {
    int k = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

int n;
string s[3];
int mp[27]; // char 2 int
vector<int> sch;

void dfs(int x, int y, int pre) {
    if (!y) {
        return;
    }
    
    for (int i = 1)
}

int main() {
    freopen("in", "r", stdin);
    cin >> n >> s[0] >> s[1] >> s[2];
    for (int i = n - 1; ~i; i--) {
        sch.push_back(a[i] - 'A');
        sch.push_back(b[i] - 'A');
        sch.push_back(c[i] - 'A');
    }
    for (int i = 0; i < sch.size(); i++)
        cout << sch[i] << ' ';
}