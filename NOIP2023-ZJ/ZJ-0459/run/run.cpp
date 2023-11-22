#include<bits/stdc++.h>
using namespace std;
#define pd push_back
#define all(x) x.begin(),x.end()
#define allA(x,l,r) x+l,x+r+1
#define mpr make_pair
typedef long long ll;
int id,T;
int n,m,k;ll d;
namespace As{
	const int N=1e3+10;
	vector<pair<ll,ll> > v[N];
	ll f[N][2];
	void mian(){
		while(T--){
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			memset(f,~0x3f,sizeof(f));f[0][0]=0;
			for(int i=1;i<=n;i++)v[i].clear();
			for(int i=1;i<=m;i++){
				ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
				for(int j=x;j<=n;j++)
					v[j].pd({y+j-x,z});
			//	v[x].pd({y,z});
			}
			for(int i=1;i<=n;i++)sort(all(v[i]));
			for(int i=1;i<=n;i++){
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				ll S=0,pos=0;
				for(int j=1;j<=min(i,k);j++){
					while(pos<v[i].size()&&v[i][pos].first<=j)
						S+=v[i][pos].second,pos++;
					f[i][1]=max(f[i-j][0]+S-1ll*j*d,f[i][1]);
				}
			}
			ll ans=0;
			for(int i=1;i<=n;i++)
				ans=max({ans,f[i][1],f[i][0]});
			printf("%lld\n",ans);
		}
	}
}namespace Bs{
	const int N=1e3+10;
	vector<pair<ll,ll> > v[N];
	ll f[N][2],g[N][N];
	void mian(){
		while(T--){
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			memset(f,~0x3f,sizeof(f));f[0][0]=0;
			memset(g,0,sizeof(g));
			for(int i=1;i<=n;i++)v[i].clear();
			for(int i=1;i<=m;i++){
				ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
			//	for(int j=x;j<=n;j++)
			//		v[j].pd({y+j-x,z});
				g[x][y]+=z;
			//	for(int j=x;j<=n;j++){
			//		if(y+j-x>k)break;
			//		g[j][y+j-x]+=z;
			//	}
				//v[x].pd({y,z});
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					g[i][j]+=g[i-1][j-1];
			//for(int i=1;i<=n;i++)sort(all(v[i]));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					g[i][j]+=g[i][j-1];
			}
			for(int i=1;i<=n;i++){
				f[i][0]=max(f[i-1][0],f[i-1][1]);
				ll S=0,pos=0;
				for(int j=1;j<=min(i,k);j++){
				//	while(pos<v[i].size()&&v[i][pos].first<=j)
				//		S+=v[i][pos].second,pos++;
					f[i][1]=max(f[i-j][0]+g[i][j]-1ll*j*d,f[i][1]);
				}
				/*for(int j=0;j<=k;j++){
					g[i][j]=f[i][j];
					if(j)g[i][j]=max(g[i][j-1],g[i][j]);
				}*/
			}
			ll ans=0;
			for(int i=1;i<=n;i++)
				ans=max({ans,f[i][1],f[i][0]});
			printf("%lld\n",ans);
		}
	}
}namespace Cs{
	void mian(){
		while(T--){
			vector<pair<pair<ll,ll>,ll> > L;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++){
				ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
				L.pd({{x-y+1,x},z});
			}
			sort(all(L));
			ll ans=0;
			for(auto y:L)
				ans+=max(0ll,y.second-1ll*(y.first.second-y.first.first+1)*d);
			printf("%lld\n",ans);
		}
	}
}namespace Ds{
	const int N=1e5+10;
	ll f[N];
	ll S[N];
	struct SgTree{
		struct node{
			ll val,tag;
		}tr[N<<2];
		void pushup(int rt){
			tr[rt].val=max(tr[rt<<1].val,tr[rt<<1|1].val);
		}void addson(int rt,ll x){
			tr[rt].val+=x;tr[rt].tag+=x;
		}void pushdown(int rt){
			if(!tr[rt].tag)return;
			addson(rt<<1,tr[rt].tag);addson(rt<<1|1,tr[rt].tag);
			tr[rt].tag=0;
		}
		void build(int rt,int l,int r){
			tr[rt].tag=tr[rt].val=0;
			if(l==r)return;
			auto mid=l+r>>1;
			build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
		}
		void change(int rt,int l,int r,int x,int y,ll z){
			if(x<=l&&r<=y)return addson(rt,z);
			auto mid=l+r>>1;pushdown(rt);
			if(x<=mid)change(rt<<1,l,mid,x,y,z);
			if(y>mid)change(rt<<1|1,mid+1,r,x,y,z);
			pushup(rt);
		}
		ll query(int rt,int l,int r,int x,int y){
			if(x<=l&&r<=y)return tr[rt].val;
			auto mid=l+r>>1;pushdown(rt);ll ans=0;
			if(x<=mid)ans=max(ans,query(rt<<1,l,mid,x,y));
			if(y>mid)ans=max(ans,query(rt<<1|1,mid+1,r,x,y));
			return ans;
		}
	}Tr;
	void solve(){
		while(T--){
			vector<pair<pair<ll,ll>,ll> > L;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++){
				ll x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
				L.pd({{x-y+1,x},z});
			}
			sort(all(L));ll ans=0;
			Tr.build(1,1,m);
			vector<pair<ll,ll> > v;
			for(int i=0;i<m;i++)v.pd(L[i].first);
			for(int i=1;i<=m;i++){
				if(i!=1)Tr.change(1,1,m,1,i-1,-1ll*(L[i-1].first.second-
					L[i-2].first.second)*d);
				Tr.change(1,1,m,1,i,L[i-1].second-(L[i-1].first.second-
					L[i-1].first.first+1)*d);
				int pos=lower_bound(all(v),mpr(L[i].first.second-k+1,0ll))-v.begin()+1;
				ans=max(ans,Tr.query(1,1,m,pos,i));
			}
			printf("%lld\n",ans);
		}
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&id,&T);
	if(id<=4)return As::mian(),0;
	else if(id<=9)return Bs::mian(),0;
	else if(id==17||id==18)return Cs::mian(),0;
	else if(id>=19&&id<=21)return Ds::solve(),0;
	return 0;
}
/*
1 1
5 3 2 2
2 1 2
3 1 3
4 1 4

*/
