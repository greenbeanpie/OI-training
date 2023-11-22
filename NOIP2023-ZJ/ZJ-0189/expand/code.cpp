#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int c,n,m,q,a[maxn],b[maxn],k1,k2,px[maxn],py[maxn],vx[maxn],vy[maxn],x[maxn],y[maxn];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}
void input(){
	c = read(),n = read(),m = read(),q = read();
	for(int i = 1;i <= n;i++)	a[i] = read(),x[i] = a[i];
	for(int j = 1;j <= m;j++)	b[j] = read(),y[j] = b[j];
}
namespace sub1{
	int s[205][205];
	void solve(){
		if(x[1] == y[1])
		{
			putchar('0');return ;
		}
		bool fl = 0;
		if(x[1] < y[1])
		{
			fl = 1;
			for(int i = 1;i <= max(n,m);i++)	swap(x[i],y[i]);
			swap(n,m);
		}
		for(int i = 0;i <= n;i++)	for(int j = 0;j <= m;j++)	s[i][j] = 0;
		s[1][1] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)	if(s[i - 1][j]&&x[i] > y[j])	s[i][j] = 1;
			for(int j = 1;j < m;j++)	if(s[i][j]&&x[i] > y[j + 1])	s[i][j + 1] = 1;
		}
		putchar(s[n][m] ? '1' : '0');
		if(fl)	swap(n,m);
	}
	void main(){
		solve();
		while(q--)
		{
			int u,v;
			for(int i = 1;i <= n;i++)	x[i] = a[i];
			for(int i = 1;i <= m;i++)	y[i] = b[i];
			k1 = read(),k2 = read();
			for(int i = 1;i <= k1;i++) 	u = read(),v = read(),x[u] = v;
			for(int i = 1;i <= k2;i++)	u = read(),v = read(),y[u] = v;
			solve();
		}
	}
}
namespace sub2{
	int t[maxn << 2],s[maxn],tot,nxt[maxn],lim[maxn],w[maxn];
//	void update(int pos){
//		t[pos] = max(t[pos << 1],t[pos << 1 | 1]);
//	}
//	void build(int l,int r,int pos){
//		if(l == r)
//		{
//			t[pos] = y[l];return ;
//		}
//		int mid = (l + r) >> 1;
//		build(l,mid,pos << 1);build(mid + 1,r,pos << 1 | 1);
//		update(pos);
//	}
//	int query(int L,int R,int l,int r,int pos){
//		if(L > r||R < l)	return -1;
//		if(L >= l&&R <= r)	return t[pos];
//		int mid = (L + R) >> 1;
//		return max(query(L,mid,l,r,pos << 1),query(mid + 1,R,l,r,pos << 1 | 1));
//	}
	void solve(){
//		build(1,m,1);
		tot = 0;
		for(int i = m;i;i--)
		{
			while(tot&&y[s[tot]] >= y[i])	
			{
				w[tot - 1] = max(w[tot - 1],w[tot]);
				tot--;
			}
			nxt[i] = tot ? s[tot] : 0;
			lim[i] = tot ? max(w[tot],y[i]) : 0;
//			if(nxt[i])
//			{
//				int tmp = query(1,m,i,nxt[i],1);
//				assert(tmp == lim[i]);
//			}
			s[++tot] = i,w[tot] = y[i];
		}
		int pos = 1;
		for(int i = 1;i <= n;i++)
		{
			if(x[i] <= y[pos])
			{
				putchar('0');return ;
			}
			while(nxt[pos]&&lim[pos] < x[i])	pos = nxt[pos];
		}
		putchar(pos == m ? '1' : '0');
	}
	void main(){
		swap(n,m);
		for(int i = 1;i <= max(n,m);i++)	swap(a[i],b[i]),swap(x[i],y[i]);
		solve();
		while(q--)
		{
			int u,v;
			for(int i = 1;i <= n;i++)	x[i] = a[i];
			for(int i = 1;i <= m;i++)	y[i] = b[i];
			k1 = read(),k2 = read();
			for(int i = 1;i <= k1;i++) 	u = read(),v = read(),y[u] = v;
			for(int i = 1;i <= k2;i++)	u = read(),v = read(),x[u] = v;
			solve();
		}
	}
}
int main()
{
	freopen("expand4.in","r",stdin);
//	freopen("expand.out","w",stdout);
	input();
	if(c <= 5)	sub1::main();
	else if(c >= 8&&c <= 14)	sub2::main();
	
	return 0  ;
}

