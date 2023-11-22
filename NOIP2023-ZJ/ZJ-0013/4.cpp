#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;

int read(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 400005
#define inf 0x3f3f3f3f3f3f3f3f

int n,m,k,d;
int l[maxn],r[maxn],v[maxn];
int t[maxn],len;
vector<pii>vec[maxn];

int mx[maxn<<2],tag[maxn<<2];
void up(int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void pt(int p,int v){
	tag[p]+=v;
	mx[p]+=v;
}
void down(int p){
	if(tag[p]){
		pt(p<<1,tag[p]),pt(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void mdf(int p,int l,int r,int ql,int qr,int v){
	if(l>=ql&&r<=qr)return pt(p,v);
	int mid=l+r>>1; down(p);
	if(ql<=mid)mdf(p<<1,l,mid,ql,qr,v);
	if(qr>mid)mdf(p<<1|1,mid+1,r,ql,qr,v);
	up(p);
}
void upd(int p,int l,int r,int x,int y){
	if(l==r)return mx[p]=y,tag[p]=0,void();
	int mid=l+r>>1; down(p);
	if(x<=mid)upd(p<<1,l,mid,x,y);
	else upd(p<<1|1,mid+1,r,x,y);
	up(p);
}
int ask(int p,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return mx[p];
	int mid=l+r>>1,res=-inf; down(p);
	if(ql<=mid)res=max(res,ask(p<<1,l,mid,ql,qr));
	if(qr>mid)res=max(res,ask(p<<1|1,mid+1,r,ql,qr));
	return res;
}
void build(int p,int l,int r){
	tag[p]=0,mx[p]=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void dfs(int p,int l,int r){
	if(l==r)return cout<<mx[p]<<" \n"[r==len],void();
	int mid=l+r>>1; down(p);
	dfs(p<<1,l,mid),dfs(p<<1|1,mid+1,r);
}

void work()
{
	n=read(),m=read(),k=read(),d=read();
	len=0;
	For(i,1,m){
		r[i]=read();
		l[i]=r[i]-read()+1;
		v[i]=read();
		t[++len]=l[i]-1;
		t[++len]=r[i];
	}
	sort(t+1,t+len+1),len=unique(t+1,t+len+1)-t-1;
//	For(i,1,len)cout<<t[i]<<" ";cout<<"\n";
	For(i,1,len)vec[i].clear();
	For(i,1,m){
		int ql=lower_bound(t+1,t+len+1,l[i]-1)-t;
		int qr=lower_bound(t+1,t+len+1,r[i])-t;
		vec[qr].pb(mkp(ql,v[i]));
	}
	int res=0;
	build(1,1,len);
	int p=1;
	For(i,2,len){
		int mx=0;
		mx=max(mx,ask(1,1,len,1,i-1));
		res=max(res,mx);
//		cout<<"mx "<<i<<" "<<mx<<"\n";
		upd(1,1,len,i,mx);
		mdf(1,1,len,1,i-1,-(t[i]-t[i-1])*d);
		for(auto it:vec[i]){
			int l=it.fi,v=it.se;
			mdf(1,1,len,1,l,v);
		}
		while(p<=len && t[i]-t[p]>k){
			upd(1,1,len,p,-inf);
			++p;
		}
	//	dfs(1,1,len);
	}
//	cout<<"res "<<res<<"\n";
	res=max(res,ask(1,1,len,1,len));
	cout<<res<<"\n";
}

signed main()
{
	freopen("run6.in","r",stdin);
	freopen("my.out","w",stdout);
	int O=read();int T=read();
	while(T--)work();
	return 0;
}
/*
shaber dayangli.
a
b
c
d
e
fg

a+b+c=2
b+c+d=2
c+d+e=2
e+f=1
f+g=1
c=1
*/