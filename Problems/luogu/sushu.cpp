# include <bits/stdc++.h>
# define MAXN 100000023
using namespace std;

inline char getc() { 
    static char buf[1 << 18], *fs, *ft;
    return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}

inline int gn() { 
    int k = 0, f = 1;
    char c = getc();
    for(; !isdigit(c); c = getc()) if(c == '-') f = -1;
    for(; isdigit(c); c = getc()) k = k * 10 + c - '0';
    return k * f;
}

char ops[1 << 18], *opt = ops, *const opt_end = ops + (1 << 18);

inline void out() { 
    fwrite(ops, 1, opt - ops, stdout);
    opt = ops;
}

inline void out(int x) { 
    static char *p = new char[21]();
    *(++p) = '\n';
    do { 
        *(++p) = x % 10 | 0x30;
        x /= 10;
    } while(x);
    while(*p) { 
        *(opt++) = *(p--);
        if(opt == opt_end) out();
    }
}

int np[MAXN], p[MAXN >> 4], cnt;

inline void shai(int N) { 
    np[1] = 1;
    for(int i = 2; i <= N; i++) { 
        if(!np[i]) { 
            p[++cnt] = i;
        }
        for(int j = 1; j <= cnt && p[j] * i <= N; j++) { 
            np[p[j] * i] = 1;
            if(!(i % p[j])) break;
        }
    }
}

int main() { 
    int n = gn();
    shai(n);
    for(int i = 1; i <= cnt; i++) { 
        out(p[i]);
    }
    out();
}
