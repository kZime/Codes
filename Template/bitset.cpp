# include <bits/stdc++.h>
# include <bitset>
using namespace std;

// 1
// bitset<n> b;
// b有n位，每位都为0.参数n可以为一个表达式
bitset <5> b;
// 如bitset<5> b0;则"b0"为"00000";

// 2
// bitset<n> b(unsigned long)
// b  b有n位,并用u赋值;如果u超过n位,则顶端被截除
// 如:
bitset <5> b0(5);
// 则"b0"为"00101";


int mian() {
	cout << to_string(b0) << endl;
}