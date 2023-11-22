#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R read()
#define pc putchar
#define pb push_back
#define MT int TTT=R;while(TTT--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
inline int read()
{
	int x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') flag=1;ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(flag) return -x;
	return x;
}
template<typename T> inline void write(T x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+'0');
}

const int N=1e5+10,M=1010;
int C,T;
int n,m,k,d,ans;
int x[N],y[N],v[N];
int f[M][M],w[M][M];
void solve()
{
	if(C>=17&&C<=18)
	{
		ans=0;
		n=R,m=R,k=R,d=R;
		fo(i,1,m)
		{
			x[i]=R,y[i]=R,v[i]=R;
			if(y[i]<=k) ans+=max(0ll,v[i]-d*y[i]);
		}
		write(ans),puts("");
		return;
	}
	memset(w,0,sizeof w);
	n=R,m=R,k=R,d=R;
	fo(i,1,m) x[i]=R,y[i]=R,v[i]=R,w[x[i]][y[i]]+=v[i];
	fo(i,1,n) fo(j,1,k) w[i][j]+=w[i][j-1];
	memset(f,-0x3f,sizeof f),f[0][0]=0;
	fo(i,1,n) fo(j,0,k) if(i>=j)
	{
		f[i][j]=0;
		if(j==0) fo(l,0,k) f[i][j]=max(f[i][j],f[i-1][l]);
		else f[i][j]=f[i-1][j-1]-d+w[i][j];
	}
	int ans=0;
	fo(i,0,min(k,n)) ans=max(ans,f[n][i]);
	write(ans),puts("");
}
signed main(){
	freopen("run5.in","r",stdin);
	freopen("run.out","w",stdout);
	C=R,T=R;
	while(T--) solve();
}