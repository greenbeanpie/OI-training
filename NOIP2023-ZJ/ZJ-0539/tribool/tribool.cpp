#include<bits/stdc++.h>
using namespace std;
#define LL long long
char cz[100500],ch;
int numu[100500],numv[100500],ans[100500],fa[100500];
int find(int x)
{
	return fa[x]==x? fa[x]=fa[x]:find(fa[x]);
} 
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,t;
	cin>>c>>t;
	if(c<=2)
	{
		while(t--)
		{
			int yuan[15],no[15],anns=9999;
			yuan[0]=0;
			cin>>n>>m;
			int i;
			for(i=1;i<=n;i++) yuan[i]=no[i]=-1;
			for(i=1;i<=m;i++)
			{
				cin>>cz[i];
				if(cz[i]=='U'||cz[i]=='T'||cz[i]=='F')cin>>numu[i];
				if(cz[i]=='+'||cz[i]=='-') cin>>numu[i]>>numv[i];
			}
			while(!yuan[0])
			{
				int cnt=0;
				for(i=1;i<=m;i++)
				{
					if(cz[i]=='U') no[numu[i]]=0;
					if(cz[i]=='T') no[numu[i]]=1;
					if(cz[i]=='F') no[numu[i]]=-1;
					if(cz[i]=='+') no[numu[i]]=no[numv[i]];
					if(cz[i]=='-') no[numu[i]]=(-no[numv[i]]);
				}
				for(i=1;i<=n;i++)
				{
					if(no[i]!=yuan[i]) {cnt=99999;break;}
					if(!no[i]) cnt++;
				}
				anns=min(anns,cnt);
				i=n;
				yuan[i]++;
				while(yuan[i]>=2)
				{
					yuan[i]=-1;
					i--;
					yuan[i]++;	
				}
				for(i=1;i<=n;i++) no[i]=yuan[i];
			}
			cout<<anns<<endl;
		}
	}
	if(c==5||c==6)
	{
		while(t--)
		{
			int cnt=0;
			cin>>n>>m;
			//fa[n+1]=n+1,ans[n+1]=2;
			for(int i=1;i<=n;i++) ans[i]=2,fa[i]=i;
			for(int u,v,i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='U')
				{
					cin>>u;
					ans[u]=0;
					fa[u]=u;
				}
				if(ch=='+')
				{
					cin>>u>>v;
					int fx=find(u),fy=find(v);
					ans[fx]=ans[fy];
					fa[fx]=fa[fy];
				}
			}
			for(int i=1;i<=n;i++) if(!ans[find(i)]) cnt++;
			cout<<cnt<<endl;
		}
	}
	if(c==4||c==3)
	{
		while(t--)
		{
			int cnt=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++) ans[i]=2;
			for(int u,v,i=1;i<=m;i++)
			{
				cin>>ch>>u;
				if(ch=='T') ans[u]=1;
				if(ch=='F') ans[u]=-1;
				if(ch=='U') ans[u]=0;
			}
			for(int i=1;i<=n;i++) if(!ans[i]) cnt++;
			cout<<cnt<<endl;
		}
	}
	else
	{
		cin>>n>>m;
		while(t--) cout<<rand()%n<<endl;
	}
	return 0;
}
