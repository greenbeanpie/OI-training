#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
struct node {
	int x,y;
	char z;
} order[N];
int n,m;
int a[N],b[N];
bool sp;
void init() {
	sp=1;
	for(int x,y,i=1; i<=m; i++) {
		cin>>order[i].z;
		if(order[i].z=='+'|| order[i].z=='-') {
			cin>>order[i].x>>order[i].y;
			sp=0;
		} else
			cin>>order[i].x;
	}
}
bool check() {
	for(int i=1; i<=n; i++)
		b[i]=a[i];
	for(int i=1; i<=m; i++) {
		if(order[i].z=='+')
			b[order[i].x]=b[order[i].y];
		else if(order[i].z=='-')
			b[order[i].x]=2-b[order[i].y];
		else if(order[i].z=='T')
			b[order[i].x]=2;
		else if(order[i].z=='U')
			b[order[i].x]=1;
		else if(order[i].z=='F')
			b[order[i].x]=0;
	}
	for(int i=1; i<=n; i++)
		if(a[i]!=b[i])
			return 0;

	return 1;
}
int doo(int now,int one) {
	if(now>n) {
		if(check())	return one;
		else		return inf;
	}
	int cnt=inf;
	a[now]=0;
	cnt=min(cnt,doo(now+1,one));
	a[now]=1;
	cnt=min(cnt,doo(now+1,one+1));
	a[now]=2;
	cnt=min(cnt,doo(now+1,one));

	return cnt;
}
signed main() {
		freopen("tribool.in","r",stdin);
		freopen("tribool.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) {
		cin>>n>>m;
		init();
		if(!sp) {
			int ans=doo(1,0);
			cout<<ans<<endl;
		} else {
			int ans=0;
			for(int i=1; i<=m; i++)
				if(order[i].z=='U')
					ans++;
			cout<<ans<<endl;
		}
	}


	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/

