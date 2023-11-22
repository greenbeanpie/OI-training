#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,INF=0x3f3f3f3f3f3f3f3f;
int opt,t,n,m,k,d,x[N],y[N],v[N];
namespace solve1{
	bool check(){
		return n<=1000;
	}
	static int const N=1010;
	int f[N][N],p[N][N];
	void solve36pts(){
		memset(f,0xc0,sizeof f);
		memset(p,0,sizeof p);
		for(int i=1;i<=m;i++)
			p[x[i]][y[i]]+=v[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				p[i][j]+=p[i][j-1];
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i-1,k);j++)
				f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=1;j<=min(i,k);j++)
				f[i][j]=f[i-1][j-1]-d+p[i][j];
		}
		int res=f[n][0];
		for(int i=1;i<=k;i++)
			res=max(res,f[n][i]);
		cout<<res<<"\n";
	}
}
namespace solve2{
	bool check(){
		bool flg=true;
		for(int i=1;i<m;i++)
			flg&=x[i]<x[i+1]-y[i+1]+1;
		return flg;
	}
	void solve8pts(){
		int res=0;
		for(int i=1;i<=m;i++)
			if(y[i]<=k)
				res+=max(v[i]-y[i]*d,0ll);
		cout<<res<<"\n";
	}
}
namespace solve3{
	bool check(){
		return n<=100000;
	}
	struct segtree{
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define mid (((l)+(r))>>1)
		static int const T=N<<2;
		int tr[T],lt1[T],lt2[T];
		void update(int x){
			tr[x]=max(tr[ls(x)],tr[rs(x)]);
		}
		void add1(int x,int k){
			tr[x]=lt1[x]=k;
		}
		void add2(int x,int k){
			tr[x]+=k,lt2[x]+=k;
		}
		void pushdown(int x){
			if(lt1[x]){
				add1(ls(x),lt1[x]);
				add1(rs(x),lt1[x]);
				lt1[x]=0;
			}
			if(lt2[x]){
				add2(ls(x),lt2[x]);
				add2(rs(x),lt2[x]);
				lt2[x]=0;
			}
		}
		void modify1(int x,int l,int r,int ql,int qr,int k){
			if(ql<=l&&r<=qr)
				return add1(x,k);
			pushdown(x);
			if(ql<=mid)
				modify1(ls(x),l,mid,ql,qr,k);
			if(qr>mid)
				modify1(rs(x),mid+1,r,ql,qr,k);
			update(x);
		}
		void modify2(int x,int l,int r,int ql,int qr,int k){
			if(ql>qr)
				return;
			if(ql<=l&&r<=qr)
				return add2(x,k);
			pushdown(x);
			if(ql<=mid)
				modify2(ls(x),l,mid,ql,qr,k);
			if(qr>mid)
				modify2(rs(x),mid+1,r,ql,qr,k);
			update(x);
		}
		int query(int x,int l,int r,int ql,int qr){
			if(ql<=l&&r<=qr)
				return tr[x];
			pushdown(x);
			int res=-INF;
			if(ql<=mid)
				res=max(res,query(ls(x),l,mid,ql,qr));
			if(qr>mid)
				res=max(res,query(rs(x),mid+1,r,ql,qr));
			return res;
		}
#undef ls
#undef rs
#undef mid
	};
	segtree f;
	map<int,int>p[N];
	void solve20pts(){
		f.modify1(1,0,n,0,n,-INF);
		for(int i=1;i<=n;i++)
			p[i].clear();
		for(int i=1;i<=m;i++)
			p[x[i]][y[i]]+=v[i];
		f.modify1(1,0,n,0,0,0);
		for(int i=1;i<=n;i++){
			f.modify1(1,0,n,i,i,f.query(1,0,n,max(0ll,i-k-1),i-1));
			if(i-k-1>=0)f.modify1(1,0,n,0,i-k-1,-INF);
			f.modify2(1,0,n,max(i-k,0ll),i-1,-d);
			int pre=1,s=0;
			for(auto&j:p[i]){
				if(j.first<=k){
					f.modify2(1,0,n,i-j.first+1,i-pre,s);
					s+=j.second,pre=j.first;
				}
			}
			f.modify2(1,0,n,i-k,i-pre,s);
		}
		cout<<f.query(1,0,n,n-k,n)<<"\n";
	}
}
namespace solve4{
	bool check(){
		return k<=100;
	}
	static int const N=105;
	int f[N],g[N];
	map<int,map<int,int>>p;
	void solve8pts(){
		memset(f,0xc0,sizeof f),f[0]=0;
		p.clear();
		for(int i=1;i<=m;i++)
			p[x[i]][y[i]]+=v[i];
		int pre=0,mx=0;
		for(auto&ii:p){
			int i=ii.first;
			auto&&pp=ii.second;
			int s=0,j=1,w=0;
			for(int j=0,t=i-pre-1;j<=k;j++)
				w=max(w,g[j]=j<t?mx-j*d:f[j-t]-t*d);
			mx=f[0]=w;
			for(auto&&cur:pp){
				for(;j<=k&&j<cur.first;j++)
					mx=max(mx,f[j]=g[j-1]-d+s);
				if(j>k)break;
				s+=cur.second;
			}
			for(;j<=k;j++)
				mx=max(mx,f[j]=g[j-1]-d+s);
			pre=i;
		}
		cout<<mx<<"\n";
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	for(cin>>opt>>t;t--;){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
			cin>>x[i]>>y[i]>>v[i];
		if(solve1::check())
			solve1::solve36pts();
		else if(solve2::check())
			solve2::solve8pts();
		else if(solve3::check())
			solve3::solve20pts();
		else if(solve4::check())
			solve4::solve8pts();
	}
}
