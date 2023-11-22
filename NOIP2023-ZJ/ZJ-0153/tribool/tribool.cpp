#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int op,t,n,m;
struct Q{
	int op,x,y;
}q[N];
namespace P20{
	int a[15],b[15],ans;
	bool check(){
		for(int i=1;i<=n;i++)b[i]=a[i];
		for(int i=1;i<=m;i++){
			int op=q[i].op,x=q[i].x,y=q[i].y;
			if(op==0)b[x]=b[y];
			else if(op==1){
				if(b[y]<=1)b[x]=!b[y];
				else b[x]=2;
			}
			else b[x]=y;
		}
		for(int i=1;i<=n;i++)if(a[i]!=b[i])return false;
		return true;
	}
	void dfs(int now,int cnt){
		if(now==n+1){
			if(check())ans=min(ans,cnt);
			return;
		}
		a[now]=0;
		dfs(now+1,cnt);
		a[now]=1;
		dfs(now+1,cnt);
		a[now]=2;
		dfs(now+1,cnt+1);
	}
	void solve(){
		ans=1e9;
		dfs(1,0);
		cout<<ans<<endl;
	}
}
namespace P40{
	int tmp[N];
	void solve(){
		for(int i=1;i<=n;i++)tmp[i]=-1;
		for(int i=1;i<=m;i++){
			int x=q[i].x,y=q[i].y;
			tmp[x]=y;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(tmp[i]==2)++cnt;
		cout<<cnt<<endl;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1,x,y;i<=m;i++){
			char c;
			cin>>c;
			if(c=='+')cin>>x>>y,q[i]=<%0,x,y%>;
			else if(c=='-')cin>>x>>y,q[i]=<%1,x,y%>;
			else {
				cin>>x;
				if(c=='F')q[i]=<%2,x,0%>;
				if(c=='T')q[i]=<%2,x,1%>;
				if(c=='U')q[i]=<%2,x,2%>;
			}
		}
		if(op==1||op==2)P20::solve();
		else if(op==3||op==4)P40::solve();
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
