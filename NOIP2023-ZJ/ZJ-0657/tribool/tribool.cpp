#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],n,m,u,v,sum,ans;
int f[MAXN],sz[MAXN];
char opt;string s;
pair<int,int>last[MAXN];
struct qwq
{
	int l;int r;int cz;
}go[11];
int get(char c)
{
	if(c=='T') return 1;
	if(c=='F') return -1;
	return 0;
}
int Find(int x)
{
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}
void F(int x,int y)
{
	int fx=Find(x);
	int fy=Find(y);
	//cout<<"F"<<x<<" "<<y<<" "<<fx<<" "<<fy<<endl;
	if(fx==fy) return;
	f[fx]=fy;
	sz[fy]++;
	//if(a[x]!=100||a[y]!=100)
}
void init()
{
	//memset(sz,0,sizeof(sz));
	for(int i=1;i<=n;i++) last[i]=make_pair(-1,i),f[i]=i,f[i+n]=i+n,a[i]=100,sz[i]=sz[i+n]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>opt;
		if(opt=='-')
		{
			scanf("%d%d",&u,&v);
			last[u]=make_pair(2,v);
		}
		else if(opt=='+')
		{
			scanf("%d%d",&u,&v);
			last[u]=make_pair(1,v);
			//br[v]=u;
		}
		else
		{
			scanf("%d",&v);
			last[v]=make_pair(0,get(opt));
		}
	}
}
void mian()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<last[i].first<<" "<<last[i].second<<endl;
		if(last[i].first==-1) continue;
		else if(last[i].first==0) a[i]=last[i].second;
		else if(last[i].first==1) F(i,last[i].second),F(i+n,last[i].second+n);
		else F(i+n,last[i].second),F(i,last[i].second+n);
	}
	//for(int i=1;i<=n*2;i++) cout<<f[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++)
		if(f[i]==f[i+n]) a[f[i]]=0,sz[f[i]]--;
	for(int i=1;i<=n;i++)
		if(f[i]==i)
			ans+=(a[i]==0)*sz[i];
	printf("%d\n",ans);
}
bool check()
{
	int b[21];
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		//cout<<go[i].cz<<" "<<go[i].l<<" "<<go[i].r<<endl;
		if(go[i].cz==1) b[go[i].l]=go[i].r;
		if(go[i].cz==2) b[go[i].l]=b[go[i].r];
		if(go[i].cz==3) b[go[i].l]=-b[go[i].r];	
	} 
	for(int i=1;i<=n;i++) if(a[i]!=b[i]) return 0;
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 1;
}
void dfs(int x,int sum)
{
	
	if(sum>ans) return;
	if(x==n)
	{
		if(check()) ans=min(ans,sum);
		return;
	}
	a[x+1]=1;
	dfs(x+1,sum);
	a[x+1]=-1;
	dfs(x+1,sum);
	a[x+1]=0;
	dfs(x+1,sum+1);
}
void mm()
{
	//cin>>s;
	scanf("%d%d",&n,&m);
	ans=n;
	for(int i=1;i<=m;i++)
	{
		cin>>opt;
		if(opt=='-')
		{
			scanf("%d%d",&u,&v);
			go[i].l=u;go[i].r=v;go[i].cz=3;
		}
		else if(opt=='+')
		{
			scanf("%d%d",&u,&v);
			go[i].l=u;go[i].r=v;go[i].cz=2;
		}
		else
		{
			scanf("%d",&v);
			go[i].l=u;go[i].r=get(opt);go[i].cz=1;
		}
	}
	dfs(0,0);
	cout<<ans<<endl;
}
void QWQ()
{
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) last[i]=make_pair(-1,i),a[i]=100;
	for(int i=1;i<=m;i++)
	{
		cin>>opt;
		if(opt=='-')
		{
			scanf("%d%d",&u,&v);
			last[u]=make_pair(2,v);
		}
		else if(opt=='+')
		{
			scanf("%d%d",&u,&v);
			last[u]=make_pair(1,v);
			//br[v]=u;
		}
		else
		{
			scanf("%d",&v);
			last[v]=make_pair(0,get(opt));
		}
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<last[i].first<<" "<<last[i].second<<endl;
		if(last[i].first==-1) continue;
		else if(last[i].first==0) a[i]=last[i].second;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0) ans++;
	printf("%d\n",ans);
}
void QAQ()
{
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) last[i]=make_pair(-1,i),a[i]=100;
	for(int i=1;i<=m;i++)
	{
		cin>>opt;
		if(opt=='+')
		{
			scanf("%d%d",&u,&v);
			last[u]=make_pair(v,i);
			//br[v]=u;
		}
		else
		{
			scanf("%d",&v);
			//a[v]=0;
			last[v]=make_pair(0,i);
		}
	}
	int fl=1,k=0;
	while(fl&&k<=n)
	{
		k++;
		fl=0;
		for(int i=1;i<=n;i++)
		{
			if(last[i].first==0||a[i]==0)
			{
				a[i]=0;
				for(int j=1;j<=n;j++)
					if(last[j].first==i) a[j]=0,fl=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0) ans++;
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	//cout<<c<<endl;
	while(t--)
	{
		if(c<=2) mm();
		if(c==3||c==4) QWQ();
		if(c==5||c==6) QAQ();
		if(c>=7) mian();
	}
	return 0;
}
