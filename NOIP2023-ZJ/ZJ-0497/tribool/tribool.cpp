#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int c,t,n,m,fa[400001],q[400001][2],s[400001];char opt[400001],v[200001];
bool vis[400001];
int ans;
int find(int k)
{
	return fa[k]==k?k:fa[k]=find(fa[k]);
}
void unionn(int u,int v)
{
	int r1=find(u),r2=find(v);
	if(r1==r2)return;
	fa[r1]=r2;
	s[r2]+=s[r1];
	s[r1]=0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	IOS;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=2*n;i++)fa[i]=i,s[i]=(i<=n),v[i]=' ',vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			cin>>opt[i];
			if(opt[i]=='+'||opt[i]=='-')cin>>q[i][0]>>q[i][1];
			else cin>>q[i][0];
		}
		for(int i=m;i>=1;i--)
		{
			if(vis[q[i][0]])continue;
			if(opt[i]=='+')
			{
			//	if(q[i][0]==q[i][1])continue;
				unionn(q[i][0],q[i][1]);
				unionn(q[i][0]+n,q[i][1]+n);
				vis[q[i][0]]=1;
			}
			else if(opt[i]=='-')
			{
			//	if(q[i][0]==q[i][1])continue;
				unionn(q[i][0],q[i][1]+n);
				unionn(q[i][0]+n,q[i][1]);
				vis[q[i][0]]=1;
			}
			else v[q[i][0]]=opt[i],vis[q[i][0]]=1;
		}
		for(int i=1;i<=n;i++)
		{
		//	cout<<i<<' '<<v[i]<<endl;
			if(v[i]=='U')
			{
				int r1=find(i),r2=find(i+n);
				ans+=s[r1]+s[r2];
				s[r1]=0;s[r2]=0;
			}
			else if(find(i)==find(i+n))
			{
				int r1=find(i);
				if(!s[r1])continue;
				ans+=s[r1];
				s[r1]=0;
			}
		}
		cout<<ans<<'\n';
	}
}
