#include <cstdio>
#include <iostream>
using namespace std;
 
const int N = 100010;
char cc;
int ret,a[N],c[N],k;
 
int read(){
	cc = getchar();
	while ((cc < '0' || cc > '9') && cc != '-') cc = getchar();
	if (cc == '-'){
		cc = getchar();
		ret = -(cc-48);
		while (isdigit(cc = getchar()))
			(ret *= 10) -= cc-48;
	}
	else{
		ret = cc-48;
		while (isdigit(cc = getchar()))
			(ret *= 10) += cc-48;
	}	
	return ret;
}
 
int find(int l,int r){
    if (l == r) return c[l];
    int temp;
    int i = l,j = r,mid = c[(l+r)>>1];
    do{
        while (c[i] < mid) ++i;
        while (c[j] > mid) --j;
        if (i <= j){
            temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            i++; j--;
        }
    }while(i<=j);
    if (k <= j) return find(l,j);
    if (i <= k) return find(i,r);
    return temp;
}
 
int main(){
	int n,i,m,l,r,j,ll;
	n = read(); m = read();
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 0; i < m; i++){
		l = read(); r = read(); k = read();
		ll = l-1;
		for (j = l; j <= r; j++) c[j-ll] = a[j];
		printf("%d\n",find(1,r-ll));
	}
	return 0;
}
