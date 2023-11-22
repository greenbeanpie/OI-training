#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+5;
const int INF = 0x3f3f3f3f3f3f3f;
inline int read() {
	int x;
	scanf("%lld",&x);
	return x;
}
int n, m,TY,K,d;
struct Node {
	int x,y,w;
	friend bool operator < (Node fi,Node se) {
		return fi.x==se.x ? fi.y<se.y : fi.x<se.x;
	}
} a[N];
namespace point1 {
	const int M = 25;
	int b[M],da[M];
	inline int js(int st) {
		int tot=0;
		for(int i=1; i<=n; ++i) b[i]=(st>>i-1)&1,tot-=b[i]*d;
		for(int i=1; i<=n; ++i) {
			da[i]=b[i]?da[i-1]+1:0;
			if(da[i]>K) return 0;
		}
		for(int i=1; i<=m; ++i) {
			int x=a[i].x,y=a[i].y,w=a[i].w;
			if(da[x]>=y) tot+=w;
		}
		return tot;
	}
	inline void solve() {
		int up=(1<<n)-1,ans=0;
		for(int i=0; i<=up; ++i) ans=max(ans,js(i));
		cout<<ans<<"\n";
	}
}

namespace point2 {
	const int M = 1e3+5;
	int f[M][M];
	inline void solve() {
		memset(f,0,sizeof f);
		int now=1,mx=0;
		for(int i=1; i<=n; ++i) {
			f[i][0]=max(f[i][0],f[i-1][0]);
			for(int j=1; j<=min(i,K); ++j) {
				f[i][j]=f[i-1][j-1]-d;
				f[i][0]=max(f[i][0],f[i-1][j]);
			}
			while(now<=m&&a[now].x==i) {
				for(int j=a[now].y; j<=min(i,K); ++j) f[i][j]+=a[now].w;
				++now;
			}
			for(int j=0; j<=min(i,K); ++j) mx=max(mx,f[i][j]);
		}
		cout<<mx<<"\n";
	}
}

namespace point3 {
	inline void solve() {
	}
}

namespace point4 {
	inline void solve() {
		int tot=0;
		for(int i=1; i<=m; ++i) {
			int x=a[i].x,y=a[i].y,w=a[i].w;
			if(y<=K&&y*d<w) tot+=w-y*d;
		}
		cout<<tot<<"\n";
	}
}

namespace point5 {
	struct node {
		int L,R,w;
		friend bool operator < (node fi,node se) {
			return fi.R<se.R;
		}
	} b[N];

	struct Tree {
#define ls p<<1
#define rs p<<1|1
		int c[N<<2],tag[N<<2];
		inline void pushup(int p) {
			c[p]=max(c[ls],c[rs]);
		}

		inline void cl(int p,int x) {
			c[p]+=x;
			tag[p]+=x;
		}

		inline void pushdown(int p) {
			cl(ls,tag[p]),cl(rs,tag[p]);
			tag[p]=0;
		}

		inline void build(int p,int L,int R) {
			c[p]=tag[p]=0;
			if(L==R) return ;
			int mid=L+R>>1;
			build(ls,L,mid),build(rs,mid+1,R);
		}

		inline void change(int p,int L,int R,int l,int r,int x) {
			if(l<=L&&R<=r) return cl(p,x);
			int mid=L+R>>1;
			pushdown(p);
			if(l<=mid) change(ls,L,mid,l,r,x);
			if(mid<r)  change(rs,mid+1,R,l,r,x);
			pushup(p);
		}


		inline int query(int p,int L,int R,int l,int r) {
			if(l<=L&&R<=r) return c[p];
			int mid=L+R>>1,res=-INF;
			pushdown(p);
			if(l<=mid) res=max(res,query(ls,L,mid,l,r));
			if(mid<r)  res=max(res,query(rs,mid+1,R,l,r));
			return res;
		}
	} tree;

	int num[N],cnt_num;
	inline int lsh(int x) {
		return lower_bound(num,num+cnt_num+1,x)-num;
	}

	inline int find(int x) {
		return num[lsh(x)]==x;
	}

	inline void Lsh() {
		cnt_num=0;
		num[++cnt_num]=1;
		for(int i=1; i<=m; ++i) num[++cnt_num]=b[i].L,num[++cnt_num]=b[i].R;
		for(int i=1; i<=m; ++i) num[++cnt_num]=b[i].R+2;
		sort(num+1,num+cnt_num+1);
		cnt_num=unique(num+1,num+cnt_num+1)-num-1;
		for(int i=1; i<=m; ++i) b[i].L=lsh(b[i].L),b[i].R=lsh(b[i].R);
	}

	struct Bit {
		int c[N+2];
		inline int lowbit(int x) {
			return x&-x;
		}

		inline void change(int x,int y) {
			for(int i=x; i<=N; i+=lowbit(i)) c[i]=max(c[i],y);
		}

		inline int query(int x) {
			int tot=0;
			for(int i=x; i; i-=lowbit(i)) tot=max(tot,c[i]);
			return tot;
		}

		inline void clear(int x) {
			for(int i=x; i<=N; i+=lowbit(i)) c[i]=0;
		}
	} bit;

	inline void solve() {
		for(int i=1; i<=m; ++i) b[i]=<%a[i].x-a[i].y+1,a[i].x,a[i].w%>;
		Lsh();
		tree.build(1,0,cnt_num);
		int now=1,ans=0;
		for(int i=1; i<=cnt_num; ++i) {
			if(i>1) tree.change(1,1,cnt_num,1,i-1,-d*(num[i]-num[i-1]));
			tree.change(1,1,cnt_num,i,i,-d);
			while(now<=m&&b[now].R<=i)
				tree.change(1,1,cnt_num,1,b[now].L,b[now].w),++now;
			int x=0,xxx=lsh(num[i]-K+1);
			if(xxx<=i) x=tree.query(1,1,cnt_num,xxx,i);
			ans=max(ans,x);
			int xx=lsh(num[i]+2);
			if(num[xx]==num[i]+2) {
				int y=bit.query(xx);
				if(y<x) {
					tree.change(1,1,cnt_num,xx,cnt_num,x-y),bit.change(xx,x);
				}
			}
		}
		for(int i=1; i<=cnt_num; ++i) bit.clear(i);
		cout<<ans<<"\n";
	}
}
inline void solve() {
	n=read(),m=read(),K=read(),d=read();
	for(int i=1; i<=m; ++i) a[i]=<%read(),read(),read()%>;
	sort(a+1,a+m+1);
	if( 1<=TY&&TY<= 2) return point1 :: solve();
	if( 3<=TY&&TY<= 9) return point2 :: solve();
//	if(15<=TY&&TY<=16) return point3 :: solve();
	if(17<=TY&&TY<=18) return point4 :: solve();
	return point5 :: solve();
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int x=TY=read(),T=read();
	while(T--) solve();
	return 0;
}
/*
1 1
5 3 2 6
4 1 2
1 1 10
4 1 5


*/
