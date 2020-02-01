# include <bits/stdc++.h>
# define MAXN 100023
using namespace std;

inline char getc() { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}

inline int gi() { 
    int k = 0, f = 1;
    char c = getc();
    for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
    for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return k * f;
}

int nsz, root, ch[MAXN][2], sz[MAXN], fa[MAXN], key[MAXN], cnt[MAXN]; 

inline bool ws(int o) { //which son
    return o == ch[fa[o]][1];
}

inline void pu(int o) {sz[o] = cnt[o] + sz[ch[o][0]] + sz[ch[o][1]];}

inline void cg(int o, int x, int d) { //change o to x's son
    if(o) fa[o] = x;
    if(x) ch[x][d] = o;
}

inline void rot(int o) { 
    int x = fa[o], d = ws(o);
    cg(o, fa[x], ws(x));
    cg(ch[o][!d], x, d);
    cg(x, o, !d);
    pu(x);
    pu(o);
    if(x == root) root = o;
}

inline int newnode(int v) { 
    key[++nsz] = v;
    cnt[nsz] = 1;
    pu(nsz);
    return nsz;
}

inline void splay(int o, int t) { 
    while(fa[o] != t) { 
        int x = fa[o];
        if(fa[x] != t) { 
            if(ws(x) == ws(o)) rot(x);
            else rot(o);
        }
        rot(o);
    }
}

inline void insert(int v) { 
    if(!root) { 
        root = newnode(v); 
        return;
    }
    int o = root;
    while(key[o] ^ v) { 
        sz[o]++;
        int d = v > key[o];
        if(!ch[o][d]) cg(ch[o][d] = newnode(v), o, d);
        o = ch[o][d];
    }
    if(o != nsz) cnt[o]++, pu(o);
    splay(o, 0);
}

inline void remove(int v) { 
    int o = root;
    while(key[o] ^ v) { 
        sz[o]--;
        int d = v > key[o];
        o = ch[o][d];
    }
    cnt[o]--;
    pu(o);
    splay(o, 0);
}

int tar;

int rank(int o, int v) { 
    if(v < key[o]) return rank(ch[o][0], v);
    else if(v > key[o]) return sz[ch[o][0]] + cnt[o] + rank(ch[o][1], v);
    else return tar = 0, sz[ch[o][0]] + 1;
}

int kth(int o, int k) { 
    while(k) { 
        if(k <= sz[ch[o][0]]) o = ch[o][0];
        else if((k -= sz[ch[o][0]]) <= cnt[o]) return key[tar = o];
        else k -= cnt[o];
    }
    return key[tar = o];
}

inline int sp(int v, int t) {
  insert(v);
  remove(v);
  rank(root, v);
  splay(tar, 0);
  int o = ch[root][t], r;
  t ^= 1;
  while (o) {
    if (cnt[o]) {
      r = key[o];
      if (sz[ch[o][t]]) o = ch[o][t];
      else break;
    }
    else o = sz[ch[o][t]] ? ch[o][t] : ch[o][t^1];
  }
  return r;
}

void dfs(int o) { 
    if(!o) return;
    printf("key: %d siz:%d son: %d %d fa: %d\n", key[o], sz[o], key[ch[o][0]], key[ch[o][1]], key[fa[o]]);
    dfs(ch[o][0]);
    dfs(ch[o][1]);
}

int main() { 
# ifndef LOCAL
    freopen("phs.in", "r", stdin);
    freopen("phs.out", "w", stdout);
# endif
    int n = gi();
    while (n--) {
        int op = gi(), x = gi();
        if (op == 1) insert(x);
        else if (op == 2) remove(x);
        else if (op == 3) printf("%d\n", rank(root, x)), splay(tar, 0);
        else if (op == 4) printf("%d\n", kth(root, x)), splay(tar, 0);
        else if (op == 5) printf("%d\n", sp(x, 0));
        else if (op == 6) printf("%d\n", sp(x, 1));
        //printf("op: %d x: %d\n", op, x);
        //dfs(root);
    }
}
