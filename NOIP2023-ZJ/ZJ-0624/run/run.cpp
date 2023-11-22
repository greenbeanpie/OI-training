#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e4+10;
int c,t;
int n,m,k,d;
int x,y,v;
int ans;
int qu[M];
bool dp[M][M];
struct node{
	int st,ed,en;
}a[M];
int kk=0;
bool cmp(node q1,node q2){return q1.st==q2.st?q1.ed<q2.ed:q1.st<q2.st;}
void init()
{
	for(int i=1;i<=kk;i++) dp[i][i]=true;
	for(int i=1;i<=kk;i++)
	{
		for(int j=i+1;j<=kk;j++)
		{
			if(a[i].ed<a[j].st) dp[i][j]=dp[j][i]=true;
			else if(a[j].ed-a[i].st+1<=k) dp[i][j]=dp[j][i]=true;
			else dp[i][j]=dp[j][i]=false;
		}
	}
}
void juece()
{
	int maxans=0;
	for(int i=1;i<n;i++)
	{
		int tail=0;
		qu[++tail]=i;
		maxans=a[qu[tail]].en;
		ans=max(maxans,ans);
		for(int j=i+1;j<=n;j++)
		{
			bool flag=true;
			for(int o=1;o<=tail;o++)
			{
				if(!dp[qu[o]][j])
				{
					flag=false;
				}
			}
			if(flag)
			{
				qu[++tail]=j;
				maxans+=a[qu[tail]].en;
				ans=max(maxans,ans);
			}
		}
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			int st1=x-y+1,ed1=x;
			if((ed1-st1+1)*d<v&&ed1-st1+1<=k)
			{
				kk++;
				a[kk].st=st1;
				a[kk].ed=ed1;
				a[kk].en=v-(ed1-st1+1)*d;
			}
		}
		if(kk==0)
		{
			printf("0");
			continue;
		}
		sort(a+1,a+kk+1,cmp);
		init();
		juece();
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}