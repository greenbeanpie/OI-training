#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 100039
bool m1;
int n,m,k,x,y,v; ll d;
namespace SGT{
	struct node{
		ll maxx,lazy; int ls,rs;
	}s[maxn*120]; int K,L,R,mv; ll C;
	void down(int rt){
		if(s[rt].lazy){
			if(s[rt].ls) s[s[rt].ls].lazy+=s[rt].lazy,s[s[rt].ls].maxx+=s[rt].lazy;
			if(s[rt].rs) s[s[rt].rs].lazy+=s[rt].lazy,s[s[rt].rs].maxx+=s[rt].lazy;
		} s[rt].lazy=0; return;
	}
	void up(int rt){ s[rt].maxx=mmax(s[s[rt].ls].maxx,s[s[rt].rs].maxx); return; }
	int ins(int l,int r,int rt){
		if(!rt) s[rt=++K]=(node){(ll)-1e18,0ll,0,0};
		if(l==r){ s[rt]=(node){mmax(C,s[rt].maxx),0ll,0,0}; return rt; }
		int mid=(l+r)>>1; down(rt);
		if(L<=mid) s[rt].ls=ins(l,mid,s[rt].ls);
		else s[rt].rs=ins(mid+1,r,s[rt].rs);
		up(rt); return rt;
	}
	void update(int l,int r,int rt){
		if(L<=l&&r<=R){ s[rt].lazy+=C; s[rt].maxx+=C; return; } int mid=(l+r)>>1;
		down(rt); if(L<=mid&&s[rt].ls) update(l,mid,s[rt].ls);
		if(mid<R&&s[rt].rs) update(mid+1,r,s[rt].rs); up(rt); return;
	}
	ll query(int l,int r,int rt){
		if(L<=l&&r<=R) return s[rt].maxx; int mid=(l+r)>>1; ll mx=-1e18;
		down(rt); if(L<=mid&&s[rt].ls) mx=mmax(mx,query(l,mid,s[rt].ls));
		if(mid<R&&s[rt].rs) mx=mmax(mx,query(mid+1,r,s[rt].rs)); return mx;
	}
	void build(){
		s[0].maxx=-1e18;
		K=1; s[1].maxx=s[1].lazy=s[1].ls=s[1].rs=0;
		mv=n; L=n,C=0; ins(1,n,1);
		return;
	}
	ll que(){ L=1+mv,R=mmin(k+mv,n); if(L<=R) return query(1,n,1); else return 0ll; }
	void addi(int l,int r,ll val){
		L=l+mv,R=mmin(r+mv,n),C=val; if(L<=R) update(1,n,1); return;
	}
	void addp(int x,ll val){
		L=x+mv; C=val; if(L<=n) ins(1,n,1); return;
	}
}
struct JTZ{
	int x,y,v;
	bool operator < (const JTZ &x) const {
		return this->x < x.x;
	}
}ch[maxn];
int ti[maxn<<1],tcnt; ll f0;
void work(){
	cin>>n>>m>>k>>d; int i,j=1,las; f0=0; tcnt=0;
	for(i=1;i<=m;i++){
		cin>>ch[i].x>>ch[i].y>>ch[i].v;
		ti[++tcnt]=ch[i].x-ch[i].y; ti[++tcnt]=ch[i].x;
	}
	//for(i=1;i<=tcnt;i++) cout<<ti[i]<<" \n"[i==tcnt];
	sort(ch+1,ch+m+1);
	sort(ti+1,ti+tcnt+1);
	las=ti[1]; SGT::build();
	for(i=2;i<=tcnt;i++) if(ti[i]!=las){
		f0=mmax(f0,SGT::que());
		SGT::mv-=ti[i]-las;
		SGT::addi(1,k,1ll*(las-ti[i])*d);
		while(j<=m&&ch[j].x<=ti[i]) SGT::addi(ch[j].y,k,ch[j].v),j++;
		SGT::addp(0,f0);
		las=ti[i];
		//cout<<f0<<' '<<SGT::que()<<'\n';
	} cout<<mmax(f0,SGT::que())<<'\n';
}
bool m2;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
//	cerr<<((ll)&m1-(ll)&m2)/1024./1024.<<'\n';
	int id,T; cin>>id>>T; while(T--) work(); return 0;
}
