# include <bits/stdc++.h>
using namespace std;

priority_queue < int, vector<int>, greater<int> > q;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int tmp;
			scanf("%d", &tmp);
			q.push(tmp);
		} else if(op == 2) {
			cout << q.top() << '\n';
		} else {
			q.pop();
		}
	}
}