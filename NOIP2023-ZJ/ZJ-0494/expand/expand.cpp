#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define inl inline
#define rep(i,l,r) for(re int i=l;i<=r;i++)
#define N 100005
#define inf 1000000009
int c,n,m,q,tot=0;
int a[N],b[N];
int oa[N],ob[N];
int prea[N],preb[N];
int ans[N];
void fre(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
signed main(){
	fre();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	rep(i,1,n) cin>>a[i],oa[i]=a[i];
	rep(i,1,m) cin>>b[i],ob[i]=b[i];
	if(n==1&&m==1){
		if(oa[1]==ob[1]) ans[1]=0; 
		else ans[1]=1;
		rep(p,2,q+1){
			a[1]=oa[1];b[1]=ob[1];
			int pos,val;
			int xk,yk;cin>>xk>>yk;
			rep(i,1,xk){cin>>pos>>val;a[pos]=val;}
			rep(i,1,yk) {cin>>pos>>val;b[pos]=val;}
			if(a[1]!=b[1])ans[p]=1;
			else ans[p]=0;
		}
		rep(i,1,q+1) cout<<ans[i];
		return 0;
	}
	if(n<=2&&m<=2){
		if((oa[1]-ob[1])*(oa[n]-ob[m])>0) ans[1]=1;
		else ans[1]=0;
		rep(p,2,q+1){
			rep(i,1,n) a[i]=oa[i];
			rep(i,1,m) b[i]=ob[i];
			int pos,val;
			int xk,yk;cin>>xk>>yk;
			rep(i,1,xk){cin>>pos>>val;a[pos]=val;}
			rep(i,1,yk) {cin>>pos>>val;b[pos]=val;}
			if((a[1]-b[1])*(a[n]-b[m])>0)ans[p]=1;
			else ans[p]=0;
		}
		rep(i,1,q+1) cout<<ans[i];
		return 0;
	}
	
	
	return 0;
}