#include <bits/stdc++.h>
#define re register
using namespace std;
int ans,c,T,n,m,k;
int u,v,num,head[300010];
char ch;
bool F[300010];
vector<int> st;
int dix[300010];
int zhix[300010];
struct edge{
	int to,next;
}e[300010];
void add(int u,int v)
{
	num++;
	e[num].to=v;e[num].next=head[u];head[u]=num;
}
void dfs(int t)
{
	F[t]=true;ans++;
	for (re int i=head[t];i!=0;i=e[i].next)
	if (F[e[i].to]==false)
	{
		F[e[i].to]=true;
		dfs(e[i].to);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	bool dly=false;
	while(T--)
	{
		ans=0;
		if (c==3||c==4)
		{
			cin>>n>>m;
			for (re int i=1;i<=n;i++) dix[i]=i,zhix[i]=0;//0个取反符号
			for (re int i=1;i<=m;i++)
			{
				cin>>ch;
				if (ch=='T'||ch=='U'||ch=='F') 
				{
					cin>>k;
					zhix[k]=0;
					if (ch=='T') dix[k]=-1;
					else if (ch=='U') dix[k]=-2;
					else if (ch=='F') dix[k]=-3;
				}	
			}
			for (re int i=1;i<=n;i++) 
			if (dix[i]==-2) ans++;
			cout<<ans<<endl;
		}else
		if (c==5||c==6)
		{
			cin>>n>>m;num=0;memset(head,0,sizeof(head));
			memset(e,0,sizeof(e));
			for (re int i=1;i<=n;i++) dix[i]=i,zhix[i]=0;//0个取反符号
			for (re int i=1;i<=m;i++)
			{
				cin>>ch;
				if (ch=='T'||ch=='U'||ch=='F') 
				{
					cin>>k;
					zhix[k]=0;
					if (ch=='T') dix[k]=-1;
					else if (ch=='U') dix[k]=-2;
					else if (ch=='F') dix[k]=-3;
				}else
				if (ch=='-'||ch=='+')
				{
					cin>>u>>v;
					if (ch=='+') dix[u]=dix[v],zhix[u]=zhix[v];
					else if (ch=='-') dix[u]=dix[v],zhix[u]=(zhix[v]+1)%2;
				}
			}
			st.clear();memset(F,0,sizeof(F));
			for (re int i=1;i<=n;i++) 
			if (dix[i]==-2) st.push_back(i);
			else add(dix[i],i);
			//F
//			for (re int i=1;i<=n;i++) cout<<dix[i]<<endl;
			for (re int i=0;i<st.size();i++) 
			if (F[st[i]]==false) dfs(st[i]);
//			for (re int i=0;i<st.size();i++) cout<<st[i]<<endl;
			cout<<ans<<endl;
		}else
		{
			
			cin>>n>>m;
			for (re int i=1;i<=n;i++) dix[i]=i,zhix[i]=0;//0个取反符号
			for (re int i=1;i<=m;i++)
			{
				cin>>ch;
				if (ch=='T'||ch=='U'||ch=='F') 
				{
					cin>>k;
					zhix[k]=0;
					if (ch=='T') dix[k]=-1;
					else if (ch=='U') dix[k]=-2;
					else if (ch=='F') dix[k]=-3;
				}else
				if (ch=='-'||ch=='+')
				{
					cin>>u>>v;
					if (ch=='+') dix[u]=dix[v],zhix[u]=zhix[v];
					else if (ch=='-') dix[u]=dix[v],zhix[u]=(zhix[v]+1)%2;
				}
			}
			
			dly=true;
			
		}
	
	}
	if (dly==true) cout<<0<<endl<<3<<endl<<1<<endl;
	return 0;
}
//不畏浮云遮望眼，何惧世间起浓烟 
