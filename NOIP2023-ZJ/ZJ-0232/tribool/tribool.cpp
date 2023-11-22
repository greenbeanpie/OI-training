#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
const int N=100010;
using namespace std;
int n,m;
struct llz{int type;int val;int id1,id2;}a[11];
int now_state[11],start_state[11];
int now_state_2[N],now_state_3[N],fa[N];
void solve1()
{
	cin>>n>>m;
	For(i,1,m)
	{
		string opt;cin>>opt;
		int &type=a[i].type;
		if(opt=="T"){type=1;cin>>a[i].id1;a[i].val=1;}
		if(opt=="F"){type=1;cin>>a[i].id1;a[i].val=0;}
		if(opt=="U"){type=1;cin>>a[i].id1;a[i].val=2;}
		if(opt=="+"){type=2;cin>>a[i].id1>>a[i].id2;}
		if(opt=="-"){type=3;cin>>a[i].id1>>a[i].id2;}
	}
	int lim=0,base=1;For(i,1,n){lim+=(2*base);base*=3;}
	int ans=n;
	For(state,0,lim)
	{
		{
			int x=state;
			For(i,1,n)
			{
				now_state[i]=(x%3);
				x/=3;
			}
			For(i,1,n)start_state[i]=now_state[i];
		};
		For(i,1,m)
		{
			if(a[i].type==1)now_state[a[i].id1]=a[i].val;
			if(a[i].type==2)
			{
				now_state[a[i].id1]=now_state[a[i].id2];
			}
			if(a[i].type==3)
			{
				now_state[a[i].id1]=now_state[a[i].id2];
				if(now_state[a[i].id2]!=2)now_state[a[i].id1]^=1;
			}
		}
		bool flag=true;
		For(i,1,n)
		{
			if(now_state[i]!=start_state[i]){flag=false;break;}
		}
		if(flag==true)
		{
			int cnt=0;
			For(i,1,n)cnt+=(start_state[i]==2);
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<"\n";return;
}
void solve2()
{
	cin>>n>>m;For(i,1,n)now_state_2[i]=-1;
	For(i,1,m)
	{
		string opt;cin>>opt;
		if(opt=="T"){int id;cin>>id;now_state_2[id]=1;}
		if(opt=="F"){int id;cin>>id;now_state_2[id]=0;}
		if(opt=="U"){int id;cin>>id;now_state_2[id]=2;}
	}
	int ans=0;
	For(i,1,n)ans+=(now_state_2[i]==2);
	cout<<ans<<"\n";return;
}
vector<int> G[N];
int cnt;
int siz_e[N],dfn[N];
void solve3()
{
	cin>>n>>m;For(i,1,n){now_state_3[i]=-1;fa[i]=-1;G[i].clear();}
	For(i,1,m)
	{
		string opt;cin>>opt;
		if(opt=="U"){int id;cin>>id;now_state_3[id]=2;}
		if(opt=="+"){int id1,id2;cin>>id1>>id2;if(id1!=id2)fa[id1]=id2;}
	}
	For(i,1,n){if(fa[i]!=-1){G[fa[i]].emplace_back(i);}}
	int ans=0;
	auto dfs=[&](int x,auto self)->void
	{
		dfn[x]=++cnt;siz_e[x]=1;
		for(auto y:G[x])
		{
			self(y,self);
			siz_e[x]+=siz_e[y];
		}
	};
	auto dfs1=[&](int x,auto self)->void
	{
		if(now_state_3[x]==2){ans+=siz_e[x];return;}
		for(auto y:G[x])self(y,self);
	};
	For(i,1,n)dfn[i]=0;
	For(i,1,n){if(dfn[i]==0){dfs(i,dfs);dfs1(i,dfs1);}}
	cout<<ans<<"\n";return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
	while(t--)
	{
		if(c<=2)solve1();
		if(c>=3 && c<=4)solve2();
		if(c>=5 && c<=6)solve3();
	}
	return 0;
}