# include <bits/stdc++.h>
using namespace std;

stack <int> ans;
int temp;

int main() { 
    while(1) { 
        scanf("%d", &temp);
        if(!temp) break;
        else ans.push(temp);
    }
    while(!ans.empty()) { 
        printf("%d ", ans.top());
        ans.pop();
    }
}
