# include <bits/stdc++.h>
using namespace std;

struct lis { 
    int f[2];
    lis() {;}
} l[100003];

int n, m;

void ins(int a, int b, bool t) { // let  l[b].f[t] = a
    l[a].f[t] = l[b].f[t];
    l[l[b].f[t]].f[!t] = a;
    l[b].f[t] = a;
    l[a].f[!t] = b;
}

void rem(int a) { 
    l[l[a].f[0]].f[1] = l[a].f[1];
    l[l[a].f[1]].f[0] = l[a].f[0];
}

bool inl(int a) { 
    return !((l[l[a].f[0]].f[1] ^ a) || (l[l[a].f[1]].f[0] ^ a));
}

int main() { 
    scanf("%d", &n);
    ins(1, 100002, 1);
    for(int i = 2; i <= n; i++) { 
        int a, b;
        scanf("%d %d", &a, &b);
        ins(i, a, b);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) { 
        int a;
        scanf("%d", &a);
        if(!inl(a)) continue;
        rem(a);
    }
    int now = l[100002].f[1];
    while(now) { 
        printf("%d ", now);
        now = l[now].f[1];
    }
    puts("\n");
}
