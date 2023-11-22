#include<bits/stdc++.h>
using namespace std;
#define N 101010
int n,m,ans;
int id,T;
int f[N],flag[N];//n+1=T,n+2=F,n+3=U
int g(char c)
{
	if(c=='T') return n+1;
	if(c=='F') return n+2;
	if(c=='U') return n+3;
}
struct edge
{
	int v,u,w,nxt;
}a[100101010];
int hd[2020202],tot;
int used[2020202],num[2020220],in[2022020];
int ygg[2020202];
void add(int u,int v,int w)
{
	a[++tot].w=w;
	a[tot].u=u;
	a[tot].v=v;
	a[tot].nxt=hd[u];
	in[v]++;
//	cout<<hd[u]<<endl;
	hd[u]=tot;
}
void clear()
{
	for(int i=1;i<=n+4;i++) {hd[i]=0;a[i].nxt=0;a[i].v=0;a[i].w=0;}
	memset(used,0,sizeof(used));
	memset(num,0,sizeof(num));
	memset(ygg,0,sizeof(ygg));
	memset(f,0,sizeof(f));
	tot=0;
}
void dfs(int x,int beg,int ttmp,int len)
{
//	cout<<x<<" "<<ttmp<<endl;
	if(ttmp==0&&x!=n+3) ans++;
	if(x==beg&&len!=0)
	{
//		cout<<beg<<" "<<x<<" "<<ttmp<<" "<<len<<endl;
		if(ttmp==-1) ans+=len;
		return ;
	}
	for(int i=hd[x];i;i=a[i].nxt)
	{
//		cout<<i<<endl;
//		cout<<x<<" "<<i<<" "<<a[i].v<<" "<<ttmp<<endl;
//		system("pause");
		if(used[i]) continue;
		int v=a[i].v;
		if(ygg[v]) continue;
		ygg[v]=1;
		dfs(v,beg,ttmp*a[i].w,len+1);
	}
	return;
}
int main()
{
	//?pts
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
//	ios::sync_with_stdio(0);
	cin>>id>>T;
	while(T--)
	{
		ans=0;
		clear();
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			char opt;
			cin>>opt;
			if(opt=='+')
			{
				int x,y;
				cin>>x>>y;
				add(y,x,1);
			}
			else if(opt=='-')
			{
				int x,y;
				cin>>x>>y;
				add(y,x,-1);
			}
			else
			{
				int tmp;
				cin>>tmp;
				f[tmp]=g(opt);
				add(g(opt),tmp,1);
			}
			// for(int i=1;i<=n;i++)
			// {
			// 	cout<<setw(3)<<find(i);
			// }
			// cout<<endl;
		}
		for(int j=tot;j>=1;j--)
		{
			if(num[a[j].v]!=0) {used[j]=1;continue;}
			num[a[j].v]=1;
//			cout<<a[j].v<<endl;
		}
//	for(int i=hd[13];i;i=a[i].nxt)
//	{
////		cout<<i<<endl;
////		cout<<13<<" "<<i<<" "<<a[i].nxt<<endl;
////		system("pause");
//		
//	}
//		for(int i=1;i<=tot;i++) cout<<i<<" "<<a[i].u<<" "<<a[i].v<<" "<<a[i].nxt<<endl;
		dfs(n+3,n+3,0,0);
		if(id!=5&&id!=6)for(int i=1;i<=n;i++) if(!ygg[i])dfs(i,i,1,0);
		cout<<ans<<endl;
	}
	return 0;
}
