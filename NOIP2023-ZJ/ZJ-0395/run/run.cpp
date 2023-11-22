#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
struct node {
	int x,y,z;
} task[N];
int n,m,k,d;
int a[N];
int check() {
	int cnt=0;
	for(int i=1; i<=m; i++)
		if(a[task[i].x]-a[task[i].x-task[i].y]==task[i].y)
			cnt+=task[i].z;
	return cnt-a[n]*d;
}
int doo(int now,int con) {
	if(now==n) 
		return check();
	
	int cnt=-inf;
	a[now+1]=a[now];
	cnt=max(cnt,doo(now+1,0));
	if(con<k) {
		a[now+1]++;
		cnt=max(cnt,doo(now+1,con+1));
	}
	return cnt;
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) {
		cin>>n>>m>>k>>d;
		for(int i=1; i<=n; i++)
			a[i]=0;
		for(int date,con,i=1; i<=m; i++)
			cin>>task[i].x>>task[i].y>>task[i].z;
		cout<<doo(0,0);
	}
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3

*/
