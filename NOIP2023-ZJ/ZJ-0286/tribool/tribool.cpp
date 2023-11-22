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


#define PII pair<int,int>
const int N=1e5+10;
int C,T,n,m,ans;
int p[N],siz[N];
PII sta[N];
char op[5];
char a[N],b[N];
char g[]={'T','F','U'};
bool vis[N],col[N];
char Op[N][5];
int X[N],Y[N];
int f(char x)
{
	if(x=='T') return 'F';
	if(x=='F') return 'T';
	return 'U';
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
void meg(int x,int y)
{
	int px=find(x),py=find(y);
	if(px!=py) p[py]=px,siz[px]+=siz[py];
}
bool dfs(int st,int x,int d)
{
//	cout<<st<<' '<<x<<' '<<d<<endl;
	vis[x]=1;
	int fa=sta[x].first,delt=sta[x].second;
	if(fa==n+1||fa==n+2) return 0;
	else if(fa==n+3) return 1;
	else if(fa==st&&(d^delt)==1) return 1;
	else if(fa==st) return 0;
	else if(fa==x) return 0;
	else if(vis[fa]) return 0;
	return dfs(st,fa,d^delt);
}
bool check()
{
	fo(i,1,m) b[i]=a[i];
	fo(i,1,m)
	{
		if(*Op[i]=='T') b[X[i]]='T';
		if(*Op[i]=='F') b[X[i]]='F';
		if(*Op[i]=='U') b[X[i]]='U';
		if(*Op[i]=='+') b[X[i]]=b[Y[i]];
		if(*Op[i]=='-') b[X[i]]=f(b[Y[i]]);
	}
	fo(i,1,m) if(a[i]!=b[i]) return 0;
	return 1;
}
void dfs2(int x)
{
	if(x>n)
	{
		if(check())
		{
			int sum=0;
			fo(i,1,n) if(a[i]=='U') sum++;
			ans=min(ans,sum);
		}
		return;
	}
	a[x]='T';
	dfs2(x+1);
	a[x]='F';
	dfs2(x+1);
	a[x]='U';
	dfs2(x+1);
}
void solve()
{
	n=R,m=R;
	if(n<=10)
	{
		ans=2e9;
		fo(i,1,m)
		{
			scanf("%s",Op[i]);
			if(*Op[i]=='T') X[i]=R;
			if(*Op[i]=='F') X[i]=R;
			if(*Op[i]=='U') X[i]=R;
			if(*Op[i]=='+') X[i]=R,Y[i]=R;
			if(*Op[i]=='-') X[i]=R,Y[i]=R;
		}
		dfs2(1);
		write(ans),puts("");
		return;
	}
	fo(i,1,n+3) vis[i]=0;
	fo(i,1,n+3) p[i]=i,siz[i]=1;
	fo(i,1,n+3) sta[i]={i,0};
	while(m--)
	{
		scanf("%s",op);
		int x,y;
		if(*op=='T') x=R,sta[x]={n+1,0};
		else if(*op=='F') x=R,sta[x]={n+2,0};
		else if(*op=='U') x=R,sta[x]={n+3,0};
		else if(*op=='+')
		{
			x=R,y=R;
			if(x==y) continue;
			else sta[x]={y,0},meg(x,y);
		}
		else
		{
			x=R,y=R;
			if(x==y) sta[x].second^=1;
			else sta[x]={y,1},meg(x,y);
		}
	}
	int ans=0;
	fo(i,1,n)
	{
//		if(i==3) cout<<sta[i].first<<' '<<sta[i].second<<endl;
		if(sta[i].first==n+3) ans+=siz[find(i)],siz[find(i)]=0,col[find(i)]=1;
		else if(sta[i].first==i&&sta[i].second==1) ans+=siz[find(i)],siz[find(i)]=0,col[find(i)]=1;
		else if(!vis[i]&&!col[find(i)])
		{
			bool res=dfs(i,i,0);
			if(res==1) ans+=siz[find(i)],siz[find(i)]=0,col[find(i)]=1;
		}
	}
	write(ans),puts("");
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=R,T=R;
	while(T--) solve();
}