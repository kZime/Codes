#include <cstdio>
#include <iostream>
using namespace std;

int a = 0, b = 1, n;

int main() { 
    cin >> n;
    for (int i = 1; i <= n; i++, a++)
        if (a == b) a = 0, b++;
    cout << b + 1 - a << "/" << a << endl;
}
