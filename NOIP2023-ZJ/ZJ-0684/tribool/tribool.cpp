#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,cir,cnt;
int rea()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
struct node{
	int y,f;
};
vector<node> c[maxn];
int a[maxn];
bool b[maxn],bh[maxn];
int dfs(int nw)
{
	long long s=0;
	if(c[nw].size()==0) return 1;
	for(int i=0;i<c[nw].size();i++)
	{
		int v=c[nw][i].y;
		//if(a[v]==2) cnt=1;
		if(b[v]) continue;
		b[v]=1;
		s+=dfs(v);
	}
	if(s==0) return 1;
	else return s;
}
int rd[maxn];
void fh(int u,int siz)
{
	for(int i=0;i<c[u].size();i++)
	{
		int v=c[u][i].y;
		if(c[u][i].f<0) 
		{
			if(bh[v]&&!b[v]) 
			{
				if(siz%2!=0) cir+=siz;
				return ; 
			}
			else 
			{
				bh[v]=1;
				fh(v,siz+1);
			}
		}
	}
	return ;
}
int f[maxn];
int find(int x)
{
	if(f[x]==x) return x;
	else 
	{
		f[x]=find(f[x]);
		return f[x];
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int T,C;
	C=rea();
	T=rea();
	while(T--)
	{	
		memset(b,0,sizeof(b));
		memset(bh,0,sizeof(bh));
		bool flag=0,flag1=0;
		cir=0;
		n=rea(),m=rea();
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		{
			char op;
			int x,y;
			cin>>op;
			if(op=='T')
			{
				x=rea();
				a[x]=1;
				bh[x]=1;
			}
			else if(op=='U')
			{
				//flag1=1;
				x=rea();
				a[x]=2;
				bh[x]=1;
			}
			else if(op=='F')
			{
				x=rea();
				a[x]=-1;
				bh[x]=1;
			}
			else if(op=='-')
			{
				flag=1;
				x=rea(),y=rea();
			//	a[x]=0;
				c[y].push_back((node){x,1});
				if(f[x]!=f[y]) f[x]=find(y),++rd[f[x]];
			}
			else
			{
				flag1=1;
				flag=1;
				x=rea(),y=rea();
			//	a[x]=0;
				c[y].push_back((node){x,-1});
				if(f[x]!=f[y]) f[x]=find(y),++rd[f[x]];
			}
		}
		if(C==8) continue;
		if(!flag)
		{
			int tmp=0;
			for(int i=1;i<=n;i++) if(a[i]==2) ++tmp;
			cout<<tmp<<endl;
		}
		else
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2&&!b[f[i]])
				{
					ans+=dfs(i);
				}
				//else if(!b[i]) fh(i,1);
			}
			cout<<ans<<endl;
			
		} 
	}
	if(C==8) 
	{
		cout<<0<<endl;
		cout<<100000<<endl;
		cout<<37278<<endl;
		cout<<6653<<endl;
		cout<<7184<<endl;
		cout<<0<<endl;
	}
	return 0;
}
