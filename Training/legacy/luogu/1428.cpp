# include <bits/stdc++.h>
using namespace std;

pair<int, int> a[110]; // <值, 序号>
int v[110], n, bit[110], cnt;

inline int lb(int x) {return x & -x;}

inline void add(int x) { 
    for(; x <= n; x += lb(x)) { 
        bit[x]++;
    }
}

inline int query(int x) { 
    int ans = 0;
    for(; x; x -= lb(x)) { 
        ans += bit[x];
    }
    return ans;
}

inline void lsh() { 
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) { 
        if(i == 1 || a[i].first ^ a[i - 1].first) ++cnt;
        v[a[i].second] = cnt;
    }
}

int main() { 
    scanf("%d", &n);
    for(int x, i = 1; i <= n; i++) { 
        scanf("%d", &x);
        a[i] = make_pair(x, i);
    }
    lsh();
    for(int i = 1; i <= n; i++) { 
        printf("%d ", query(v[i] - 1));
        add(v[i]);
    }
}
