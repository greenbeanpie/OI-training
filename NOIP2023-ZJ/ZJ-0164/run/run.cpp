#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson p<<1
#define rson p<<1|1
const int maxn=1e5+10;
vector<int>e[maxn];
int x[maxn],y[maxn],v[maxn],T,id,n,m,k;
ll dp[maxn],d;
const ll INF=1e17;
struct seg{
	ll v[maxn<<2],lazy[maxn<<2];
	void clear(){
		memset(v,0,sizeof(v));
		memset(lazy,0,sizeof(lazy));
	}
	void pushdown(int p){
		if(lazy[p]){
			v[lson]+=lazy[p],v[rson]+=lazy[p];
			lazy[lson]+=lazy[p],lazy[rson]+=lazy[p];
			lazy[p]=0;
		}
	}
	void update(int l,int r,ll d,int cl=1,int cr=n,int p=1){
		if(l<=cl&&cr<=r){
			v[p]+=d;
			if(cl!=cr)lazy[p]+=d;
			return;
		}
		pushdown(p);
		int mid=(cl+cr)>>1;
		if(mid>=l){
			update(l,r,d,cl,mid,lson);
		}
		if(mid<r){
			update(l,r,d,mid+1,cr,rson);
		}
		v[p]=max(v[lson],v[rson]);
	}
	ll qury(int l,int r,int cl=1,int cr=n,int p=1){
		if(l<=cl&&cr<=r){
			return v[p];
		}
		pushdown(p);
		int mid=(cl+cr)>>1;
		ll res=-INF;
		if(mid>=l){
			res=max(res,qury(l,r,cl,mid,lson));
		}
		if(mid<r){
			res=max(res,qury(l,r,mid+1,cr,rson));
		}
		return res;
	}
}Tr;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>id>>T;
	while(T--){	
		cin>>n>>m>>k>>d;
		Tr.clear();
		for(int i=1;i<=n;++i){
			dp[i]=0;e[i].clear();
		}
		for(int i=1;i<=m;++i){
			cin>>x[i]>>y[i]>>v[i];
			e[x[i]].push_back(i);
		}
		dp[0]=0;
		for(int i=1;i<=n;++i){
			for(int j:e[i]){
				Tr.update(1,x[j]-y[j]+1,v[j]);
			}
			dp[i]=max(dp[i-1],Tr.qury(max(1,i-k+1),i)-d);
			if(i<n-1){
				Tr.update(i+2,i+2,dp[i]);			
			}
			Tr.update(1,i,-d);
		}
		cout<<dp[n]<<"\n";
	}
}
