#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
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

#define maxn 500005
#define inf 0x3f3f3f3f

int n,m,Q,O;
int a[maxn],b[maxn],aa[maxn],bb[maxn];
int res[maxn];

namespace BR
{
	int a[maxn],b[maxn],n,m;
	bool solve()
	{
		int ra=1,rb=1;
		int va=a[1],vb=b[1];
//	cout<<"solve\n";
//	For(i,1,n)cout<<a[i]<<" ";cout<<"\n";
//	For(i,1,m)cout<<b[i]<<" ";cout<<"\n";
		while(1){
			if(ra==n || rb==m)return 1;
			if(a[ra+1]>=vb && b[rb+1]<=va)return 0;
			int na=va,nb=vb;
			while(ra+1<=n && a[ra+1]<vb) ++ra,va=min(va,a[ra]);
			if(ra==n || rb==m)return 1;
			while(rb+1<=m && b[rb+1]>va) ++rb,vb=max(vb,b[rb]);
			if(ra==n || rb==m)return 1;
		}
	}
}

bool solve(int*a,int*b,int n,int m){
	if(a[1]==b[1])return 0;
	if(a[1]>b[1]) return solve(b,a,m,n);
	assert(a[1]<b[1]);
//	cout<<"ab "<<a[1]<<" "<<b[1]<<" "<<a[n]<<' '<<b[m]<<"\n";
	if(a[n]>=b[m])return 0;
	int mn=2e9,mx=-1;
	For(i,1,n)mn=min(mn,a[i]),mx=max(mx,a[i]);
	For(i,1,m)mn=min(mn,b[i]),mx=max(mx,b[i]);
	For(i,1,m)if(b[i]==mn)return 0;
	For(i,1,n)if(a[i]==mx)return 0;
	int la=0,lb=0,ra=0,rb=0;
	For(i,1,n)if(a[i]==mn){
		if(!la)la=i;
		ra=i;
	}
	For(i,1,m)if(b[i]==mx){
		if(!lb)lb=i;
		rb=i;
	}
//	cout<<la<<" "<<lb<<" "<<ra<<" "<<rb<<" qwq\n";
	For(i,1,la)BR::a[i]=a[i]; BR::n=la;
	For(i,1,lb)BR::b[i]=b[i]; BR::m=lb;
	if(!BR::solve())return 0;
	Rep(i,n,ra)BR::a[n-i+1]=a[i]; BR::n=n-ra+1;
	Rep(i,m,rb)BR::b[m-i+1]=b[i]; BR::m=m-rb+1;
	if(!BR::solve())return 0;
	return 1;
}

signed main()
{
	freopen("expand5.in","r",stdin);
	freopen("my.out","w",stdout);
	O=read(),n=read(),m=read(),Q=read();
	For(i,1,n)aa[i]=read(),a[i]=aa[i];
	For(i,1,m)bb[i]=read(),b[i]=bb[i];
//	cout<<"slv "<<0<<"\n";
	res[0]=solve(a,b,n,m);
	For(j,1,Q){
		int kx=read(),ky=read();
		For(i,1,n)a[i]=aa[i];
		For(i,1,m)b[i]=bb[i];
		For(_,1,kx){
			int x=read(),y=read();
			a[x]=y;
		}
		For(_,1,ky){
			int x=read(),y=read();
			b[x]=y;
		}
	//	cout<<"slv "<<j<<"\n";
		res[j]=solve(a,b,n,m);
	}
	For(j,0,Q)cout<<res[j];cout<<"\n";
	return 0;
}
/*
4 6 6 1
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
6 6
3 20666649
1 599175376
6 287382408
5 421035992
2 805423796
4 767604039
3 284182396	
1 732011630
4 934948587
2 840870596
6 557335931
5 388591777
6 6
6 909678381
4 966742067
1 950087990
2 922968889
5 834991722
3 880355772
6 845896874
3 791681101
4 956185939
1 918655047
5 941339699
2 930778126
*/