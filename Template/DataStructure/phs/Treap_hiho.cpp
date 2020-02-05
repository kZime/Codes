# include <bits/stdc++.h>
# define INF 0x7fffffff
using namespace std;

#define getc() getchar()

inline int gn() { 
    register int k = 0, f = 1;
    register char c = getc();
    for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
    for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return k * f;
}

struct node { //大根♂堆
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

int prec(node *x, int p) { 
    int ans = -INF;
    if(p > x->k) { 
        if(x->ch[1]) ans = prec(x->ch[1], p);
        return max(ans, x->k);
    } else if(x->ch[0]) ans = prec(x->ch[0], p);
    return ans;
}

int n;

int main() { 
# ifdef LOCAL
    freopen("in", "r", stdin);
# endif
    printf("FAQ!!!\n");
    n = gn();
    node *root = new node(INF);
    root->r = INF;
    insert(root, INF);
    for(int i = 1; i <= n; i++) {
        char op[3];
        scanf("%s", op);
		switch(op[0]) {
			case 'I': insert(root, gn());break;
			case 'Q': printf("%d\n", prec(root, gn() + 1));break;
		}
	}
    return 0;
}
