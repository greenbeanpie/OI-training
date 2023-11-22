#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,m,k;
long long d,ans;
bool hav[205];
struct ren{
	int l,r;
	long long v;
}tsk[114514];
struct qu{
	int lt,rt,R;
}jian[114514];

bool cmp(ren a,ren b)
{
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}

void dfs(int now,int len)
{
	if(now>n)
	{
		long long sum=0;
		for(int i=1;i<=m;i++)
		{
			bool ok=true;
			for(int j=tsk[i].l;j<=tsk[i].r;j++)
			{
				if(!hav[j])
				{
					ok=false;
					break;
				}
			}
			if(ok) sum+=tsk[i].v;
		}
		for(int i=1;i<=n;i++) if(hav[i]) sum-=d;
		
		ans=max(ans,sum);
		return;
	}
	if(len==k)
	{
		hav[now]=false;
		dfs(now+1,0);
	}
	else
	{
		hav[now]=true;
		dfs(now+1,len+1);
		hav[now]=false;
		dfs(now+1,0);
	}
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	cin >> c >> t;
	
	if(c<=2)
	{
		while(t--)
		{
			memset(hav,false,sizeof(hav));
			ans=0;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				int x,y;
				long long vv;
				scanf("%d%d%lld",&x,&y,&vv);
				
				tsk[i].l=x-y+1,tsk[i].r=x,tsk[i].v=vv;
			}
			
			dfs(1,0);
			
			printf("%lld\n",ans);
		}
	}
	else if(c==17 || c==18)
	{
		while(t--)
		{	
			ans=0;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				int x,y;
				long long vv;
				scanf("%d%d%lld",&x,&y,&vv);
				
				if(y*d<vv && y<=k) ans+=vv-y*d;
			}
			
			printf("%lld\n",ans);
		}
	}
	else if(c<=14)
	{
		while(t--)
		{
			int tot=0;
			ans=0;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			
			for(int i=1;i<=m;i++)
			{
				int x,y;
				long long vv;
				scanf("%d%d%lld",&x,&y,&vv);
				tsk[i].l=x-y+1,tsk[i].r=x,tsk[i].v=vv;
			}
			
			sort(tsk+1,tsk+m+1,cmp);
			
			for(int i=1;i<=m;i++)
			{
				int now=i,nowr=tsk[i].r;
				while(nowr>=tsk[now+1].l-1 && now<m) now++,nowr=max(nowr,tsk[now].r);
				jian[++tot].lt=i,jian[tot].rt=now,jian[tot].R=nowr;
				i=now;
			}
			
			for(int i=1;i<=tot;i++)
			{
				long long mx=0;
				for(int j=jian[i].lt;j<=jian[i].rt;j++)
				{
					long long lin=0;
					int now=j,nowr=tsk[j].r;
					if(nowr-jian[i].lt+1<=k) lin+=tsk[now].v;
					while(now<jian[i].rt && nowr-jian[i].lt+1<=k)
					{
						now++,nowr=max(nowr,tsk[now].r);
						lin+=tsk[now].v;
					}
					lin-=(nowr-tsk[j].l+1)*d;
					mx=max(mx,lin);
					
					while(nowr>=tsk[now+1].l-1 && now<jian[i].rt) now++;
					if(tsk[now].l>nowr+1)
					{
						int lll=tsk[now].l;
						nowr=tsk[now].r;
						while(now<jian[i].rt && nowr-lll+1<=k)
						{
							now++,nowr=max(nowr,tsk[now].r);
							lin+=tsk[now].v;
						}
						lin-=(nowr-lll+1)*d;
						mx=max(mx,lin);
					}
				}
				
				ans+=mx;
			}
			
			printf("%lld\n",ans);
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			scanf("%d%d%d%lld",&n,&m,&k,&d);
			for(int i=1;i<=m;i++)
			{
				int x,y;
				long long vv;
				scanf("%d%d%lld",&x,&y,&vv);
				
				if(y*d<vv && y<=k) ans+=vv-y*d;
			}
			
			printf("%lld\n",ans);
		}
	}
	
	
	return 0;
	
}