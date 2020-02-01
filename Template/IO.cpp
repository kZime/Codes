# include <bits/stdc++.h>
using namespace std;

char buf[1 << 18], *fs, *ft;
char ops[1 << 18], *opt = ops, *const opt_end = ops + (1 << 18);
 
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

inline char gc() { 
    char c = getc();
    for(; !isalpha(c); c = getc());
    return c;
}
 
inline void out() { 
    fwrite(ops, 1, opt - ops, stdout);
    opt = ops;
}
 
inline void out(int x, char c) { 
    bool f = 0;
    if(x < 0) { 
        x = -x;
        f = 1;
    }
    static char *p = new char[21]();
    *(++p) = c;
    do { 
        *(++p) = x % 10 | 0x30;
        x /= 10;
    } while(x);
    if(f) *(++p) = '-';
    while(*p) { 
        *(opt++) = *(p--);
        if(opt == opt_end) out();
    }
}

int main() { 
    
}
