#include<bits/stdc++.h>
#define endl '\n'
#define fir first
#define sec second
#define ri register
#define pb push_back
#define mp make_pair
#define int long long
#define inf 2147483647
#define Swap(x,y) ((x)^=(y)^=(x)^=(y))
#define reset(x,y) memset((x),(y),sizeof((x)))
#define fastcin ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
inline int read()
{
	ri int x=0,f=0;ri char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c-'0'),c=getchar();
	return f?-x:x;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=3e3+10;
int n,m,a[N][N],min1,min2;
char ch;
inline bool Cmp(int x,int y) {return x>y;}
inline bool Check(int x,int y)
{
	for(ri int i=1;i<=m;++i)
		if(a[x][i]<a[y][i]) return 1;
			else if(a[x][i]>a[y][i]) return 0;
	return 0;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	fastcin,cin>>n>>m,min1=1;
	for(ri int i=1;i<=n;++i)
		for(ri int j=1;j<=m;++j)
			cin>>ch,a[i][j]=ch-'a';
	for(ri int i=1;i<=n;++i)
		sort(a[i]+1,a[i]+m+1,Cmp);
	for(ri int i=2;i<=n;++i)
		if(Check(i,min1)) min2=min1,min1=i;
			else if(Check(i,min2)) min2=i;
	for(ri int i=1;i<=n;++i)
	{
		sort(a[i]+1,a[i]+m+1);
		if(i!=min1) cout<<Check(i,min1);
			else cout<<Check(i,min2);
		sort(a[i]+1,a[i]+m+1,Cmp);
	}
	return 0;
}
