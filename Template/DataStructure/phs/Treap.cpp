# include <bits/stdc++.h>
# define INF 0x7fffffff
using namespace std;
 
char buf[1 << 18], *fs, *ft;
 
inline char getc() { 
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
 
inline int gn() { 
    int k = 0, f = 1;
    char c = getc();
    for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
    for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return k * f;
}
 
struct node { //澶ф牴鈾 鍫
    int s, k, r;
    node *ch[2];
    inline node(){;}
    inline node(int key) { 
        k = key;
        s = 1;
        r = rand();
        ch[1] = ch[0] = NULL;
    }
    inline void pu() { 
        s = 1;
        s += ch[1] ? ch[1]->s : 0;
        s += ch[0] ? ch[0]->s : 0;
    }
};
 
void rotate(node *&x, bool d) { 
    node *k = x->ch[d ^ 1];
    x->ch[d ^ 1] = k->ch[d];
    k->ch[d] = x;
    x->pu();
    k->pu();
    x = k;
}
 
void insert(node *&x, int p) { 
    if(!x) x = new node(p);
    else { 
        bool d = p > x->k;
        insert(x->ch[d], p);
        if(x->ch[d]->r > x->r) rotate(x, d ^ 1);
    }
    x->pu();
}
 
void remove(node *&x, int p) { 
    if(x->k == p) { 
        node *tmp = x;
        if(x->ch[1] && x->ch[0]) { 
            bool d = x->ch[1]->r < x->ch[0]->r;
            rotate(x, d);
            remove(x->ch[d], p);
        } else { 
            if(!x->ch[0]) x = x->ch[1];
            else x = x->ch[0];
            delete tmp;
        }
    } else { 
        remove(x->ch[p > x->k], p);
    }
    if(x) x->pu();
}
 
int rank(node *x, int p) { 
    if(!x) return 1;
    else if(p <= x->k) return rank(x->ch[0], p);
    else return rank(x->ch[1], p) + (x->ch[0] ? x->ch[0]->s : 0) + 1;
}
 
int kth(node *x, int p) { 
    if(p <= 0 || !x || p > x->s) return 0;
    int s = x->ch[0] ? x->ch[0]->s : 0;
    if(p == s + 1) return x->k;
    else if(p <= s) return kth(x->ch[0], p);
    else return kth(x->ch[1], p - s - 1);
}
 
int prec(node *x, int p) { 
    int ans = -INF;
    if(p > x->k) { 
        if(x->ch[1]) ans = prec(x->ch[1], p);
        return max(ans, x->k);
    } else if(x->ch[0]) ans = prec(x->ch[0], p);
    return ans;
}
 
int succ(node *x, int p) { 
    int ans = INF;
    if(p < x->k) { 
        if(x->ch[0]) ans = succ(x->ch[0], p);
        return min(ans, x->k);
    } else if(x->ch[1]) ans = succ(x->ch[1], p);
    return ans;
}
 
int n;
 
int main() { 
# ifndef LOCAL 
    freopen("phs.in", "r", stdin);
    freopen("phs.out", "w", stdout);
# else 
    freopen("in", "r", stdin);
# endif
    n = gn();
    node *root = new node(INF);
    root->r = INF;
    insert(root, INF);
    for(int i = 1; i <= n; i++) {
		switch(gn()) {
			case 1: insert(root, gn());break;
			case 2: remove(root, gn());break;
			case 3: printf("%d\n", rank(root, gn()));break;
			case 4: printf("%d\n", kth(root, gn()));break;
			case 5: printf("%d\n", prec(root, gn()));break;
			case 6: printf("%d\n", succ(root, gn()));break;
		}
	}
    return 0;
}
