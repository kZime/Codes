# include <bits/stdc++.h>
using namespace std;
char str[1000];
int ne[1000];
void getn(char *str) {
	int n = strlen(str);
	ne[0]= -1;
	int j = -1, i = 0;
	while(i < n) {
		while(~j && str[i] != str[j]) j = ne[j];
		ne[++i] = ++j;
	}
}
int main() {
	cin >> str;
	getn(str);
	for(int i = 0; i < strlen(str); i++) {
		cout << ne[i];
	}
}
