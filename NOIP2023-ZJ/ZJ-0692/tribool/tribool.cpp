#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t;
char tb[N];
int now[N];
int ans=0;
vector<pair<int,int> > G[N];
int du[N];
void build(int gong)
{
	for(int i=1;i<=gong;i++)
	{
		G[i].clear();
		du[i]=0;
		tb[i]='0';
	}
	for(int i=1;i<=gong;i++)
	{
		//cout<<now[i]<<endl;
		if(now[i]>0 && now[i]<=100000)
		{
			G[now[i]].push_back({i,1});
			du[i]++;
			if(now[i]==i) du[i]--;
        }
		else if(now[i]<0)
		{
			G[(-now[i])].push_back({i,2});
			du[i]++;
			if((-now[i])==i) du[i]--;
		}
	}
	//cout<<du[1]<<" "<<du[2]<<" "<<du[3];
	cout<<endl;
	//cout<<G[1][0].second<<" "<<G[1][1].second<<" "<<G[1][2].second<<endl;
}
int siz=0;
bool flag=false;
void work(int k,int fa,int op)
{
	if(k!=fa) siz++;
	else if(k==fa && op==2){
		flag=true;return;
	}
	for(int i=0;i<G[k].size();i++) 
	{
		work(G[k][i].first,k,G[k][i].second);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3 || c==4)
	{
		while(t--)
        {
			ans=0;
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++) tb[i]='0';
			for(int i=1;i<=m;i++)
			{
				char s;
				int x;
				cin>>s>>x;
				tb[x]=s;
			}
			for(int i=1;i<=n;i++) if(tb[i]=='U') ans++;
			cout<<ans<<endl;
		}
	}
	else
	{
		while(t--)
        {
			ans=0;
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++) now[i]=0;
			for(int i=1;i<=m;i++)
			{
				char s;
				int x,y;
				cin>>s>>x;
				if(s=='T') now[x]=100001;
				else if(s=='F') now[x]=100002;
				else if(s=='U') now[x]=100003;
				else if(s=='-')
				{
					cin>>y;
					if(now[y]==0) now[x]=-y;
					else if(now[y]==100001) now[x]=100002;
					else if(now[y]==100002) now[x]=100001;
					else if(now[y]==100003) now[x]=100003;
					else now[x]=-now[y];
				}
				else
				{
					cin>>y;
					if(now[y]==0) now[x]=y;
					else now[x]=now[y];
				}
			}
			build(n);
			for(int i=1;i<=n;i++)
			{
				if(du[i]==0) 
				{
					siz=0;flag=false;
					if(now[i]==100003) flag=true;
					work(i,0,0);
					//cout<<siz;
					if(flag) ans+=siz;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}