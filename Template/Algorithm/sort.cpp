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
 
inline void out() { 
    fwrite(ops, 1, opt - ops, stdout);
    opt = ops;
}
 
inline void out(int x) { 
    static char *p = new char[21]();
    *(++p) = ' ';
    do { 
        *(++p) = x % 10 | 0x30;
        x /= 10;
    } while(x);
    while(*p) { 
        *(opt++) = *(p--);
        if(opt == opt_end) out();
    }
}

inline void out(char c) { 
    *(opt++) = c;
    if(opt == opt_end) out();
}

int a[100002], n;

void sort(int l, int r) { 
    int i = l, j = r, x = a[(l + r) >> 1];
    do { 
        while(a[i] < x) ++i;
        while(a[j] > x) --j;
        if(i <= j) swap(a[i], a[j]), i++, j--;
    } while(i <= j);
    if(l < j) sort(l, j);
    if(i < r) sort(i, r);
} 

int main() { 
    n = gn();
    for(int i = 1; i <= n; i++) a[i] = gn();
    sort(1, n);
    for(int i = 1; i <= n; i++) out(a[i]);
    out('\n');
    out();
    return 0;
}
