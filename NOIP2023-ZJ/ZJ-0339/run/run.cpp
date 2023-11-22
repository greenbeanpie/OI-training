//虚空调试15min 
//多测不清空，亲人两行泪
//开考2h了，预计得分100+40+0+[28,36]=[168,176]
//我去数组没开够，再次虚空调试15min 
#include<bits/stdc++.h>
#define N 1020
#define M 100020
#define ll long long
using namespace std;
int c,T;
int n,m,k;
ll d;
ll ans;
/*
//c<=2
namespace sub1
{
	struct qwq{int x,y;ll v;}a[N];
	bool operator <(qwq q1,qwq q2){return q1.x<q2.x;}
	void dfs(int now,ll sum,int lst,int cnt)
	{
//		cerr<<now<<' '<<sum<<" "<<lst<<" "<<cnt<<endl;
		//第now天结算前一天 
		if(now==n+2)
		{
			ans=max(ans,sum);
			return;
		}
		if(now==n+1)
		{
			while(a[lst].x==now-1)
			{
				if(cnt>=a[lst].y)sum+=a[lst].v;
				++lst;
			}
			dfs(now+1,sum,lst,cnt);
			return;
		}
		while(a[lst].x==now-1)
		{
			if(cnt>=a[lst].y)sum+=a[lst].v;
			++lst;
		}
		if(cnt+1<=k)dfs(now+1,sum-d,lst,cnt+1);
		dfs(now+1,sum,lst,0);
	}
	void main()
	{
		while(T--)
		{
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
			sort(a+1,a+m+1);
			ans=0;
			dfs(1,0,1,0);
			printf("%lld\n",ans);
		}
	}
}
*/
namespace sub2
{
	struct qwq{int x,y;ll v;}a[M];
	bool operator <(qwq q1,qwq q2){return q1.x<q2.x;}
	ll f[N][N];//f[i][j]表示到第i天连续跑了j天的最大能量
	int pos[N]; 
	void main()
	{
		while(T--)
		{
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
			sort(a+1,a+m+1);
			memset(pos,0,sizeof(pos));
			for(int i=1;i<=m;i++)if(!pos[a[i].x])pos[a[i].x]=i;
			ans=0;
			memset(f,0,sizeof(f));
			ll maxn=0;
			for(int i=1;i<=n;i++)
			{
				f[i][0]=maxn;
				maxn=0;
				for(int j=0;j<=min(i,k);j++)
				{
					if(j)f[i][j]=f[i-1][j-1]-d;
					for(int k=pos[i];a[k].x==i&&k<=m;k++)
					{
						if(j>=a[k].y)f[i][j]+=a[k].v;
					}
					maxn=max(f[i][j],maxn);
				}
			}
			/*
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i,k);j++)printf("%d ",f[i][j]);
				printf("\n");
			}
			*/
			for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
			printf("%lld\n",ans);
		}
	}
}
namespace sub3
{
	struct qwq{int x,y;ll v;}a[M];
	bool operator <(qwq q1,qwq q2){return q1.x<q2.x;}
	void main()
	{
		while(T--)
		{
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
			sort(a+1,a+m+1);
			ans=0;
			for(int i=1;i<=m;i++)if(a[i].y<=k)ans+=max(0ll,a[i].v-a[i].y*d);
			printf("%lld\n",ans);
		}
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
//	if(c<=2)sub1::main();
	if(c<=9)sub2::main();//36pts 
	else if(c==17||c==18)sub3::main();//8pts
}
