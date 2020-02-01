#include <bits/stdc++.h>
using namespace std;

bool vis[26];
string a, b, c;
map<char, char> sec;
int n, cnt;

int main() {
    cin >> a >> b >> c;
    n = a.size();
    for (int i = 0; i < n; i++) {
        if (sec.find(a[i]) == sec.end() and not vis[b[i] - 'A']) {
            sec[a[i]] = b[i];
            vis[b[i] - 'A'] = true;
            cnt++;
        }
        else if (sec[a[i]] != b[i]) {
            printf("Failed\n");
            return 0;
        }
    }
    if (cnt != 26) {
        printf("Failed\n");
        return 0;
    }
    n = c.size();
    for (int i = 0; i < n; i++) {
        cout << sec[c[i]];
    }
    cout << '\n';
}