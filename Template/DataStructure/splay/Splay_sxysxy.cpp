# include <bits/stdc++.h>
using namespace std;
struct node 
{
    node *ch[2];
    int data;
    int size;
    int maxv, minv;
    node(int v):data(v)
    {
        ch[0] = ch[1] = NULL;
        maintain();
    }
    #define SIZE(x) ((x)?(x)->size:0)
    int cmp(int s)
    {
        if(s == SIZE(ch[0])+1)return -1;
        return s > SIZE(ch[0])+1;
    }
    void maintain()
    {
        size = 1;
        maxv = minv = data;
        for(int i = 0; i <= 1; i++)
        {
            if(ch[i])
            {
                size += ch[i]->size;
                maxv = max(maxv, ch[i]->maxv);
                minv = min(minv, ch[i]->minv);
            }
        }
    }
};
void rotate(node *&o, int d)
{
    node *k = o -> ch[d];   
    o -> ch[d] = k -> ch[d^1];
    k -> ch[d^1] = o;
    o -> maintain();
    k -> maintain();
    o = k;
}
//spaly
void splay(node *&o, int k)
{
    if(!o)return;
    int d = o -> cmp(k);
    if(d == -1)return;
    if(d)
        k -= (SIZE(o -> ch[0]) + 1); 
    int d2 = o -> ch[d] -> cmp(k);
    if(d2 != -1)
    {
        if(d2)k -= (SIZE(o -> ch[d] -> ch[0]) + 1);
        splay(o -> ch[d] -> ch[d2], k);
        if(d == d2)
            rotate(o, d);
        else 
            rotate(o -> ch[d], d2);
    }
    rotate(o, d);
}
#define MAXN 1000002
int data[MAXN];
node *build(int l, int r)
{
    if(l == r)return new node(data[l]);
    int m = (l+r)>>1;
    node *u = new node(data[m]);
    if(m-1 >= l)u -> ch[0] = build(l, m-1);
    if(m+1 <= r)u -> ch[1] = build(m+1, r);
    u -> maintain();
    return u;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", data+i);
    node *t = build(0, n+1);
    while(m--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        splay(t, l);
        splay(t->ch[1], r-l+2);
        node *p = t->ch[1]->ch[0];
        printf("%d\n", p->maxv - p->minv);
    }
    return 0;
}
