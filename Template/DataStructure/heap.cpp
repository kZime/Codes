# include <bits/stdc++.h>
using namespace std;

int h[100001], n;

inline void sd(int i) {
	int t = i;
	while(i << 1 <= n) {
		if(h[i] > h[i << 1]) t = i << 1;
		if((i << 1 | 1) <= n && h[t] > h[i << 1 | 1]) t = i << 1 | 1;
		if(t ^ i) swap(h[i], h[t]), i = t;
		else break;
	}
}

void creat() {
	for(int i = n >> 1; i >= 1; i--) sd(i);
}

int dt() {
	int t = h[1];
	h[1] = h[n--];
	sd(1);
	return t;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	creat();
	while(n) {
		printf("%d ", dt());
	}
}