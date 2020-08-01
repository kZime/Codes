//
//  main.cpp
//  acm
//
//  Created by kzime on 2020/7/28.
//  Copyright © 2020 kzime. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define all(A) A.begin(), A.end()
#define fi first
#define se second
#define MP make_pair
#define rep(i,n) for(register int i=0;i<(n);++i)
#define repi(i,a,b) for(register int i=int(a);i<=(b);++i)
#define repr(i,b,a) for(register int i=int(b);i>=(a);--i)
template<typename T>
inline T read(){
    T s=0,f=1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f=-1;ch = getchar();}
    while(isdigit(ch)) {s=(s<<3)+(s<<1)+ch-48;ch = getchar();}
    return s*f;
}
#define gn() read<int>()
#define gl() read<ll>()
template<typename T>
inline void print(T x) {
    if(x<0) putchar('-'), x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
////////////////////////////////////////////////////////////////////////
const int N=1e5+100;
const int mod=1e9+7;
int n,p;
int a[N];
map<int,int> mp;
set<int> st;
void solve(){
    mp.clear();
    st.clear();
    n=gn(),p=gn();
    repi(i,1,n){
        a[i]=gn();
        a[i]=a[i]%p;
    }
    int sum=0;
    int cnt=0;
    repi(i,1,n){
        sum=(sum+a[i])%p;
        cerr << sum << ' ';
        if(mp[sum]||sum==0){
            if(sum==0&&!mp[sum]){
                if(a[i]==0||st.size()==0){
                    ++cnt;
                    mp[0]=i;
                    st.insert(i);
                }
                else continue;
            }
            else if(st.upper_bound(mp[sum])==st.end()){
                st.insert(i);
                mp[sum]=i;
                ++cnt;
            }
        }
        else mp[sum]=i;
    }
    print(cnt),putchar(10);
}
////////////////////////////////////////////////////////////////////////
int main(){
    int _;
    cin>>_;
    while(_--)
        solve();
}
/**
* In every life we have some trouble
* When you worry you make it double
* Don't worry,be happy.
**/

/*
 
 1
 7 5
 1 2 3 2 3 4 5
 
 
 9 5
 1 2 3 4 5 2 3 5 4
 
 4
 
5 5
3 1 1 3 1
 
 */
