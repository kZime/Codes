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
 

struct node { 
    int k, s, c;
    node *ch[2], *fa;
    node() {;}
    node(int a, int b, int y) { 
        k = a, s = b, c = y;
    }
    inline void rs() { 
        s = ch[0]->s + ch[1]->s + c;
    }
}nil(0, 0, 0), *NIL = &nil;

struct Splay { 
    node *root;
    int ncnt;
    inline void init() { 
        ncnt = 0;
        root = NIL;
    }
    inline void rot(node *x, bool d) { //1 -> ZIG
        node *y = x->fa;
        node *k = x->ch[d];
        if(y->fa != NIL) y->fa->ch[y == y->fa->ch[1]] = x;
        x->fa = y->fa;
        x->ch[d] = y;
        y->fa = x;
        y->ch[!d] = k;
        if(k != NIL) k->fa = y;
        y->rs();
        x->rs();
    }
    inline void splay(node *x, node *target) { //rot x to target->ch[]
        node *y;
        while(x->fa != target) { 
            y = x->fa;
            bool a = (x == y->ch[0]);
            if(y->fa != target) { 
                bool b = (y == y->fa->ch[0]);
                rot(y, b);
            }
            rot(x, a);
        }
        if(target == NIL) root = x;
    }
    inline void ins(int key) { 
        if(root == NIL) { 
            ncnt = 0;
            root = new node(key, 1, 1);
            root->ch[0] = root->ch[1] = root->fa = NIL;
            return;
        }
        node *x = root, *y;
        while(true) { 
            x->s++;
            if(key == x->k) { 
                x->c++;
                x->rs();
                y = x;
                break;
            } else { //keep finding...
                bool d = key > x->k;
                if(x->ch[d] != NIL) x = x->ch[d];
                else { 
                    y = x->ch[d] = new node(key, 1, 1);
                    y->ch[0] = y->ch[1] = NIL;
                    y->fa = x;
                    break;
                }
            }
        }
        splay(y, NIL);
    }
    inline node* search(int key) { 
        if(root == NIL) return NIL;
        node *x = root, *y = NIL;
        while(true) { 
            if(key == x->k) { 
                y = x;
                break;
            } else { 
                bool d = key > x->k;
                if(x->ch[d] != NIL) x = x->ch[d];
                else break;
            }
        }
        splay(x, NIL);
        return y;
    }
    inline node* getm(node *x, bool d) { //d = 1 -> get_max
        node *y = x->fa;
        while(x->ch[d] != NIL) x = x->ch[d];
        splay(x, y);
        return x;
    }
    inline void del(int key) { 
        if(root == NIL) return;
        node *x = search(key), *y;
        if(x == NIL) return ;
        else if(x->c > 1) { 
            x->c--;
            x->rs();
        } else if(x->ch[0] == NIL && x->ch[1] == NIL) { //empty tree
            init();
        } else if(x->ch[0] == NIL || x->ch[1] == NIL) { 
            bool d = (x->ch[0] == NIL);
            root = x->ch[d];
            x->ch[d]->fa = NIL;
        } else { 
            y = getm(x->ch[1], 0);
            y->fa = NIL;
            y->ch[0] = x->ch[0];
            y->ch[0]->fa = y;
            y->rs();
            root = y;
        }
    }
    inline int rank(int key) {
        node *x = root;
        if(x == NIL) return 1;
        int ans = 0;
        while(true) { 
            if(key == x->k) { 
                ans += x->ch[0]->s + 1;
                return ans;
            }
            else if(key < x->k) { 
                if(x->ch[0] == NIL) { 
                    return ans + 1; // rank of x
                }
                x = x->ch[0];
            }else { 
                ans += x->ch[0]->s + 1;
                if(x->ch[1] == NIL) { 
                    return ans + 1;
                }
                x = x->ch[1];
            }
        }
    }
    inline node *kth(int k) { 
        if(root == NIL || k > root->s || !k) return NIL;
        node *x = root;
        while(true) { 
            if(x->ch[0]->s + 1 <= k && k <= x->ch[0]->s + x->c) break;//k -> x
            else if(k <= x->ch[0]->s) x = x->ch[0];
            else { 
                k -= x->ch[0]->s + x->c;
                x = x->ch[1];
            }
        }
        splay(x, NIL);
        return x;
    }
    inline node *prec(int key) { 
        int k = rank(key) - 1;
        return kth(k);
    }
    inline node *succ(int key) { 
        int k = rank(key) + (search(key) != NIL);
        return kth(k);
    }
}sp;

int n;

int main() { 
# ifndef LOCAL 
    freopen("phs.in", "r", stdin);
    freopen("phs.out", "w", stdout);
# else 
    freopen("in", "r", stdin);
# endif
    n = gn();
    sp.init();
    for(int i = 1; i <= n; i++) {
		switch(gn()) {
			case 1: sp.ins(gn());break;
			case 2: sp.del(gn());break;
			case 3: printf("%d\n", sp.rank(gn()));break;
			case 4: printf("%d\n", sp.kth(gn())->k);break;
			case 5: printf("%d\n", sp.prec(gn())->k);break;
			case 6: printf("%d\n", sp.succ(gn())->k);break;
		}
	}
    return 0;
}
