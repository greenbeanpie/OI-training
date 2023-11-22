#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+88;
vector<int> G[MAXN];
int N,M,siz[MAXN],root[MAXN] ;
bool vis[MAXN];
char val[MAXN],f[MAXN];
void equal(int X,int Y,bool mode)
{
	if(mode||val[Y]=='U')
		{
			val[X]=val[Y];
			return ;
		}
	else
		{
			if(val[Y]=='T') val[X]='F';
			else
				{
					val[X]='T';
				}
			return ;
		}
}
int Find(int X,int sum=0,int vv=-1)
{
	if(vv==-1) vv=siz[X];
	if(X==root[X]) return X;
	else
	{
		int tt=Find(root[X]);
		if(root[X]!=tt)
		{
			siz[root[X]]-=siz[X];
		}
 
 		root[X]=tt;
		return tt;
	}
}
void Onion(int X,int Y)
{

	X=Find(X,siz[X]),Y=Find(Y,siz[Y]);
	if(X==Y) return ;
	else
		{
			siz[Y]+=siz[X];
			root[X]=Y;
		}
}
void devide(int X)
{
	if(Find(X,siz[X])!=X)
		{
			int tt=Find(X,siz[X]);
			root[X]=X;
			siz[tt]-=siz[X];
 		}
}
struct node
{
	char mode;
	int X,Y;
} que[MAXN];
void solve(int zu)
{
	cin>>N>>M;
	for(int i=0; i<=N*4; ++i)
		{
			vis[i]=0;
			val[i]=0;
			root[i]=i;
			siz[i]=1;
			f[i]=0;
		}
	for(int i=1; i<=M; ++i)
		{
			char  mode=0;
			int X=0,Y=0;
			cin>>mode>>X;
			if(mode=='+'||mode=='-')
				{
					cin>>Y;
					int fx=Find(X,siz[X]);
					for(int j=0; j<3; ++j)
						{
							devide(X+j*N);
						}
					if(mode=='-')
						{
							Onion(X+N,Y+2*N);
							Onion(X+2*N,Y+N);
						}
					else
						{
							for(int j=1; j<=2; ++j ) Onion(X+j*N,Y+j*N);
						}
					Onion(X,Y);
					val[X]=0;
				}
			else
				{
					for(int j=0; j<3; ++j)
						{
							devide(X+j*N);
						}
					val[X]=mode;
				}
		}
	int ans=0;
	memset(vis,0,sizeof vis);
	for(int i=1; i<=N; ++i)
		{
			if(vis[Find(i,siz[i])]) continue;
			if(Find(i+2*N,siz[i+2*N])==Find(i+N,siz[i+N])||val[i]=='U')
				{
					ans+=siz[Find(i,siz[i])];
					vis[Find(i,siz[i])]=1;
				}
			else
				{
					if(val[i]!=0 )
						{
							int t1=Find(i+N,siz[i+N]);
							if(f[t1]!=val[i]&&f[t1]!=0)
								{
									ans+=siz[Find(i,siz[i])];
									vis[Find(i,siz[i])]=1;
									continue;
								}
							f[t1]=val[i];
							t1=Find(i+2*N,siz[i+2*N]);
							if(f[t1]==val[i]&&f[t1]!=0)
								{
									ans+=siz[Find(i,siz[i])];
									vis[Find(i,siz[i])]=1;
									continue;
								}
							if(val[i]!='T')
								{
									f[t1]='T';
								}
							else f[t1]='F';
						}
				}
		}

	cout<<ans<<"\n";
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T;
	cin>>C>>T;
	for(int i=1; i<=T; ++i)
		{
			solve(i);
		}
}