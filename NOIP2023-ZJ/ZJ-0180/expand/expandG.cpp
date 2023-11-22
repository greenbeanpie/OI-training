#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;

struct Seg
{
	#define mid ((l+r)>>1)
	#define ls o<<1
	#define rs o<<1|1
	int tr[500009*4];
	int gen[500009];
	int a[500009];
	int n;
	inline int get(int x,int y)
	{
		return a[x]>a[y]?x:y;
	}
	inline void build(int l,int r,int o)
	{
		if(l==r) return gen[l]=o,tr[o]=l,void();
		build(l,mid,ls);
		build(mid+1,r,rs);
		tr[o]=get(tr[ls],tr[rs]);
	}
	inline void modify(int x,int y)
	{
		int o=gen[x]>>1;
		while(o)
		{
			tr[o]=get(tr[ls],tr[rs]);
			o>>=1;
		}
	}
	inline int query(int l,int r,int o,int A,int B)
	{
		if(A<=l && r<=B)return tr[o];
		if(A>mid) return query(mid+1,r,rs,A,B);
		if(B<=mid) return query(l,mid,ls,A,B);
		return get(query(l,mid,ls,A,B),query(mid+1,r,rs,A,B));
	}
}A,B;
int A_querymin(int l,int r,int l1,int r1)
{
	if(l>r) return l1-1;
	int mx=A.query(1,A.n,1,l,r);
	int mx2=B.query(1,B.n,1,l1,r1);
	if(A.a[mx]>B.a[mx2])
	{
		int tmp=A_querymin(l,mx-1,l1,r1);
		
	}
	
}
bool solve()
{
	if(A.a[A.tr[1]]==B.a[B.tr[1]])return 0;
	if(A.a[A.tr[1]]>B.a[B.tr[1]]) return A_querymin(1,A.tr[1]-1,1,B.n)+1<A_querymax(A.tr[1]+1,A.n,1,B.n);
	else return B_querymin(1,B.tr[1]-1,1,A.n)+1<B_querymax(B.tr[1]+1,B.n,1,A.n)
}
int main()
{
	ios::sync_with_stdio(false);
	int c,q;
	cin>>c>>A.n>>B.n>>q;
	F(i,1,A.n) cin>>A.a[i];
	F(i,1,B.n) cin>>B.a[i];
	cout<<solve();
	F(CC,1,q)
	{
		int k;
		cin>>k;
		F(i,1,k) cin>>x>>y,A.modify(x,y);
		cin>>k;
		F(i,1,k) cin>>x>>y,B.modify(x,y);
	}
} 