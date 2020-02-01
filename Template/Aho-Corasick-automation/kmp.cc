# include <bits/stdc++.h>
using namespace std;

char a[1000023], b[1023];
int ne[1023], n, m;

void get_next() {
	ne[0] = -1;
	for(int i = 1, j = 0; i <= m; i++) {
		for(j = ne[i - 1]; b[i] != b[j + 1] && j >= 0; j = ne[j]);
		ne[i] = j + 1;
	}
}

void check() {
	for(int i = 1, j = 0; i <= n; i++) {
		for(; a[i] != b[j + 1] && j >= 0; j = ne[j]);
		j++;
		if(j == m) printf("%d\n", i - m + 1);
	}
}

int main() {
	scanf("%s", b + 1);
    m = strlen(b + 1);
	get_next();
	for(int i = 1; i <= m; i++) {
		printf("%d ", ne[i]);
	}
}
/*
ABABABC
ABA
*/
