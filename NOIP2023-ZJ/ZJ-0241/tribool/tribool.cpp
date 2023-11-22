#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int head[N*4],ver[N*8],Next[N*8],tot,w[N*8];

void add(int x,int y,int z)
{
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;w[tot]=z;
}

int numm[N*4],Numm,col[N*4];

int T;

int n,m;

int read()
{
	char c;int f=1,res=0;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;res=c-'0';
	while(isdigit(c=getchar()))res=(res<<3)+(res<<1)+c-'0';
	return f*res;
}

bool foundd[N*4],viss[N*4],gonn[N*4];

int f[N*4];

int dfs(int x)
{
	viss[x]=1;
	if(col[x]!=0)	return x;
	for(int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if(viss[y]==1)	continue;
		int res=dfs(y);
		if(res!=0)	return res;
	}
	return 0;
}

void colll(int x,int coloo)
{
	foundd[x]=1;
	col[x]=coloo;
	for(int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if(foundd[y])	continue;
		if(coloo==3)
		{
			colll(y,3);
		}else	if(w[i]==0)	{
			colll(y,coloo);
		}else	if(coloo==1) {
			colll(y,2);
		}else{
			colll(y,1);
		}
	}
}

bool check(int x,int siz)
{
	if(gonn[x])
	{
		if((f[x]+siz)%2==0)	return 0;
		else return 1;
	}
	f[x]=siz;
	gonn[x]=1;
	for(int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if(check(y,siz+w[i]))	return 1;
	}
	return 0;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	T=read();T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			numm[i]=i;
		memset(head,0,sizeof(head));
		memset(col,0,sizeof(col));
		memset(foundd,0,sizeof(foundd));
		memset(viss,0,sizeof(viss));
		memset(gonn,0,sizeof(gonn));
		memset(f,0,sizeof(f));
		Numm=n;
		tot=0;
		for(int i=1;i<=m;i++)
		{
			char op;int x,y;
			cin>>op;x=read();
			if(op=='T')
			{
				numm[x]=++Numm;
				col[Numm]=1;
			}
			if(op=='F')
			{
				numm[x]=++Numm;
				col[Numm]=2;
			}
			if(op=='U')
			{
				numm[x]=++Numm;
				col[Numm]=3;
			}
			if(op=='+')
			{
				y=read();y=numm[y];
				numm[x]=++Numm;
				add(numm[x],y,0);
				add(y,numm[x],0);
			}
			if(op=='-')
			{
				y=read();y=numm[y];
				numm[x]=++Numm;
				add(numm[x],y,1);
				add(y,numm[x],1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(numm[i]!=i)
			{
				add(numm[i],i,0);
				add(i,numm[i],0);
			}
		}
		for(int i=1;i<=n;i++)	if(foundd[i]==0) {
			int res=dfs(i);
			if(res!=0)
			{
				colll(res,col[res]);
			}
			if(res==0)
			{
				bool b=check(i,0);
				if(b==0){
					col[i]=1;
					colll(i,1);
				}
				else{
					col[i]=3;
					colll(i,3);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(col[i]==3)	ans++;
		cout<<ans<<"\n";
	}
	return 0;
}












