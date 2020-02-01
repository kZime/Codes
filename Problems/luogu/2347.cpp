#include <bits/stdc++.h>
using namespace std;

// 1 2 3 5 10 20
int a[6], n[6] = {1, 2, 3, 5, 10, 20}, res;
map<int, bool> ss;

void dfs(int x, int ans) {
    if (x == 6) {
        if (ss.find(ans) == ss.end()) {
            ss[ans] = 1;
            res++;
        }
        return;
    }
    else
        for (int i = 0; i <= a[x]; i++)
            dfs(x + 1, ans + i * n[x]);
}

int main() {
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    ss[0] = 1;
    dfs(0, 0);
    cout << "Total=" << res<< '\n';
    return 0;
}