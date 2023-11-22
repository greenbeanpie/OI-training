#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb	push_back
const int maxn = 1e5 + 5;
const ll inf = 1e15;
ll c,n,m,k,d;
struct node{int x,y,v;}a[maxn];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}
void chkmin(ll &x,const ll y){if(y<x)x=y;}
void chkmax(ll &x,const ll y){if(y>x)x=y;}
namespace sub1{
	struct zyp{int y,v;friend bool operator < (zyp a,zyp b){return a.y < b.y;}};	
	vector <zyp> b[1003];
	ll f[1003][1003],g[1003];
	void clear(){
		for(int i = 1;i <= n;i++)	b[i].clear();
		for(int i = 0;i <= n;i++)	for(int j = 0;j <= n;j++)	f[i][j] = -inf;
	}
	void solve(){
		f[0][0] = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j <= i&&j <= k;j++)	chkmax(f[i][0],f[i - 1][j]);
			for(int j = 0;j < i&&j < k;j++)	chkmax(f[i][j + 1],f[i - 1][j] - d);
			for(int j = 0;j <= i;j++)	g[j] = 0;
			for(auto x : b[i])	g[x.y] += x.v;
			for(int j = 1;j <= i&&j <= k;j++)	g[j] += g[j - 1],f[i][j] += g[j];
		}
		ll ans = -inf;
		for(int i = 0;i <= n;i++)	chkmax(ans,f[n][i]);
		printf("%lld\n",ans);
	}
	void main(){
		int T = read();
		while(T--)
		{
			n = read(),m = read(),k = read(),d = read();
			clear();
			for(int i = 1;i <= m;i++)	a[i] = (node){read(),read(),read()};
			for(int i = 1;i <= m;i++)	b[a[i].x].pb((zyp){a[i].y,a[i].v});
			for(int i = 1;i <= n;i++)	if((int) b[i].size())	sort(b[i].begin(),b[i].end());
			solve();
		}
	}
}
namespace sub2{
	struct Tree{ll tag,val;}t[maxn << 2];
	struct zyp{int y,v;friend bool operator < (zyp a,zyp b){return a.y < b.y;}};	
	vector <zyp> b[1003];
	void clear(){
		for(int i = 1;i <= n;i++)	b[i].clear();
	}
	void update(int pos){
		t[pos].val = max(t[pos << 1].val,t[pos << 1 | 1].val);
	}
	void pushdown(int pos){
		if(!t[pos].tag)	return ;
		t[pos << 1].tag += t[pos].tag;
		t[pos << 1].val += t[pos].tag;
		t[pos << 1 | 1].tag += t[pos].tag;
		t[pos << 1 | 1].val += t[pos].tag;
		t[pos].tag = 0 ;
	}
	void build(int l,int r,int pos){
		t[pos].tag = 0;
		if(l == r)
		{
			if(l == 0)	t[pos].val = 0;
			else t[pos].val = -inf;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l,mid,pos << 1),build(mid + 1,r,pos << 1 | 1);
		update(pos);
	}
	void add(int L,int R,int l,int r,int pos,ll k){
		if(L > r||R < l)	return ;
		if(L >= l&&R <= r)
		{
			t[pos].val += k;t[pos].tag += k;
			return ;
		}
		pushdown(pos);
		int mid = (L + R) >> 1;
		add(L,mid,l,r,pos << 1,k);
		add(mid + 1,R,l,r,pos << 1 | 1,k);
		update(pos);
	}
	void change(int l,int r,int x,int pos,ll k){
		if(l > x||r < x)	return ;
		if(l == r)
		{
			t[pos].val = k;return ;
		}
		pushdown(pos);
		int mid = (l + r) >> 1;
		change(l,mid,x,pos << 1,k);
		change(mid + 1,r,x,pos << 1 | 1,k);
		update(pos);
	}
	ll query(int L,int R,int l,int r,int pos){
		if(L > r||R < l)	return -inf;
		if(L >= l&&R <= r)	return t[pos].val;
		pushdown(pos);
		int mid = (L + R) >> 1;
		return max(query(L,mid,l,r,pos << 1),query(mid + 1,R,l,r,pos << 1 | 1));
	}
	void main(){
		int T = read();
		while(T--)
		{
			n = read(),m = read(),k = read(),d = read();
			clear();
			for(int i = 1;i <= m;i++)	a[i] = (node){read(),read(),read()};
			for(int i = 1;i <= m;i++)	b[a[i].x].pb((zyp){a[i].y,a[i].v});
			build(0,n,1);
			for(int i = 1;i <= n;i++)
			{
				int limm = max(0ll,i - k - 1);
				ll res = query(0,n,limm,i - 1,1);
				change(0,n,i,1,res);
				for(auto x : b[i])
				{
					int l = i - x.y;
					add(0,n,0,l,1,x.v);
				}
				add(0,n,0,i - 1,1,-d);
			}
			ll ans = query(0,n,n - k,n,1);
			printf("%lld\n",ans);
		}
	}
}
namespace sub3{
	struct nodee{int l,r,w;}b[maxn];
	bool cmp(nodee a,nodee b){return a.l < b.l;}
	ll tot,w[maxn],f[maxn],hd,tl,v[maxn],le[maxn];
	ll solve(int l,int r){
		ll len = r - l + 1,sum = 0,pos = 0,slen = 0;
		for(int i = l;i <= r;i++)	w[i - l + 1] = b[i].w,le[i - l + 1] = b[i].r - b[i].l + 1;
		for(int i = 1;i <= len;i++)	sum += w[i],f[i] = inf;
		hd = 1,tl = 1,v[1] = 0;
		for(int i = 1;i <= len;i++)
		{
			while(pos < i&&slen - le[pos] >= k)	slen -= le[pos],pos++;
			while(hd < tl&&v[hd] < pos)	hd++;
			f[i] = f[v[hd]] + w[i];
			while(hd <= tl&&f[v[tl]] >= f[i])	--tl;
			v[++tl] = i;
			slen += le[i];
		}
		while(slen - le[pos] >= k)	slen -= le[pos],pos++;
		sum -= f[v[hd]];
		return sum;
	}
	void main(){
		int T = read();
		while(T--)
		{
			n = read(),m = read(),k = read(),d = read();
//			clear();
			for(int i = 1;i <= m;i++)	a[i] = (node){read(),read(),read()};
			tot = 0;
			for(int i = 1;i <= m;i++)
			{
				int r = a[i].x,l = r - a[i].y + 1,w = a[i].v;
				if(r - l + 1 >= k)	continue;
				w -= (r - l + 1) * d;
				if(w <= 0)	continue;
				b[++tot] = (nodee){l,r,w};
			}
			ll ans = 0,las = 1;
			for(int i = 1;i <= tot;i++)	if(i == tot||b[i].r != b[i + 1].l - 1)	
				ans += solve(las,i),las = i + 1;
			printf("%lld\n",ans);
		}
	}
}
int main()
{
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
//	c = read();
//	if(c <= 9)	
//	sub1::main();
//	else if(c <= 14)	
	sub2::main();
//	else if(c >= 17&&c <= 18)	sub3::main();
	return 0  ;
}

