# include <bits/stdc++.h>
using namespace std;

//sliding window 单调队列 

void dandiao(){
	int front =1,tail=0;
	for(int a=1;a<=k;a++)
	{
		while(tail>=front && z[a]<q[tail][0])
			tail--;
		tail++； 
		q[tail][0]=z[a];q[tail][1]=a;//0是数，1是位置； 
	}
	
	for(int a=k+1;a<=n;a++)
	{
		while(tail>=front && z[a]<q[tail][0])
			tail--;
		q[tail][0]=z[a];q[tail][1]=a;
		if (q[front][0]==a-k) front++;
	}
}
