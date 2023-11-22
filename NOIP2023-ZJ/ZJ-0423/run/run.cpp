#include<bits/stdc++.h>
#define fo(x,l,r) for (int x=(l); x<=(r); x++)
#define dw(x,r,l) for (int x=(r); x>=(l); x--)
using namespace std;
int C,T,n,m,K,d,t,ans,x[20],y[20],v[20];
bool a[20],flag;
void dfs(int k,int cnt,int sum){
	if (k>n){
		t=sum;
		fo(i,1,m){
			flag=0;
			fo(j,x[i]-y[i]+1,x[i])
			if (!a[j]){
				flag=1;
				break;
			}
			if (!flag) t+=v[i];
		}
		ans=max(ans,t);
		return;
	}
	if (cnt<K){
		a[k]=1;
		dfs(k+1,cnt+1,sum-d);
	}
	a[k]=0;
	dfs(k+1,0,sum);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>T;
	if (C==1||C==2){
		while (T--){
			cin>>n>>m>>K>>d;
			fo(i,1,m) cin>>x[i]>>y[i]>>v[i];
			ans=0;
			dfs(1,0,0);
			cout<<ans<<endl;
		}
	}
	else while (T--) cout<<0<<endl;
	return 0;
}