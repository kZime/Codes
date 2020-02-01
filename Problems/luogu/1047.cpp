# include <bits/stdc++.h>
using namespace std;

int tree[10010], n, m, k;

int main() { 
    cin >> n >> m;
    for(int i = 1; i <= m; i++) { 
        int l, r;
        cin >> l >> r;
        if(l) tree[l - 1]--;
        else k = -1;
        tree[r]++;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) { 
        if(!k) ans++;
        k += tree[i];
    }
    printf("%d\n", ans);
}
