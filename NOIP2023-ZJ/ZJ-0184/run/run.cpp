#include <bits/stdc++.h>
#define OK
using namespace std;
namespace Run
{
#define inf 1000000000000000005ll
#define int long long
	int C,T,n,m,k,d,now,ans;
	int dp[2][100005];
	class challenge
	{
	public:
		int x,y,v,l;
		challenge (int x=0,int y=0,int v=0):
			x(x),y(y),v(v) { l=x-y+1; }
		challenge read ()
		{
			scanf ("%lld%lld%lld",&x,&y,&v);
			l=x-y+1;
			return *this;
		}
	} ch[100005];
	bool operator< (challenge a,challenge b)
	{
		if (a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	}
	int main ()
	{
#ifdef OK
		freopen ("run.in","r",stdin);
		freopen ("run.out","w",stdout);
#endif
		scanf ("%lld%lld",&C,&T);
		while (T--)
		{
			scanf ("%lld%lld%lld%lld",&n,&m,&k,&d);
			for (int i=1;i<=m;i++) ch[i].read();
			if (C<=14) // 其实应该只能过 1~9 
			{
				sort (ch+1,ch+m+1);
				for (int i=0;i<2;i++)
					for (int j=0;j<=k;j++)
						dp[i&1][j]=-inf;
				dp[0][0]=0;
				now=1;
				for (int i=1;i<=n;i++)
				{
					dp[i&1][0]=dp[!(i&1)][0];
					for (int j=1;j<=min(i,k);j++)
					{
						dp[i&1][0]=max(dp[i&1][0],dp[!(i&1)][j]);
						dp[i&1][j]=dp[!(i&1)][j-1]-d;
						for (int t=now;ch[t].x==i && ch[t].y<=j;t++)
							dp[i&1][j]+=ch[t].v;
//						printf ("dp[%d][%d]=%d\n",i,j,dp[i&1][j]);
					}
//					printf ("dp[%d][0]=%d\n",i,dp[i&1][0]);
					while (ch[now].x==i) now++;
				}
				ans=0;
				for (int i=0;i<=k;i++)
					ans=max(ans,dp[n&1][i]);
				printf ("%lld\n",ans);
			}
			else if (C==17 || C==18) // B 假的 
			{
				ans=0;
				for (int i=1;i<=m;i++)
					if (ch[i].y<=k && ch[i].y*d<ch[i].v)
						ans+=ch[i].v-ch[i].y*d;
//				ch[0].x=-1;
//				for (int i=1;i<=m;i++)
//				{
//					dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
//					if (ch[i].y<=k && ch[i].y*d<ch[i].v)
//					{
//						if (ch[i].l==ch[i-1].x+1)
//							dp[i][1]=dp[i-1][0]+ch[i].v-ch[i].y*d;
//					}
//				}
				printf ("%lld\n",ans);
			}
//			else if (C>=19 && C<=21) // C
//			{
//				ans=now=0;
//				int sum=0,start=0;
//				bool cont=0;
//				for (int i=1;i<=m;i++)
//				{
//					if (ch[i].l>ch[now].x)
//					{
//						cont=sum=0;
//						start=ch[i].l;
//					}
//					sum+=ch[i].y;
//					if (cont)
//					{
//						if (ch[i].x-ch[now].x<=k && (ch[i].x-ch[now].x)*d<sum)
//						{
//							ans+=sum-(ch[i].x-ch[now].x)*d;
//							now=i;
//						}
//					}
//					else
//					{
//						if (ch[i].y<=k && ch[i].y*d<ch[i].v)
//						{
//							ans+=ch[i].v-ch[i].y*d;
//							cont=1;
//							now=i;
//						}
//					}
//				}
//				printf ("%lld\n",ans);
//			} // 假的 
			else
			{
				int t[200005],top=0;
				map<int,int> fun;
				for (int i=1;i<=m;i++)
				{
					if (ch[i].l>1)
						t[++top]=ch[i].l-1;
					t[++top]=ch[i].x;
				}
				t[++top]=n;
				sort (t+1,t+top+1);
				top=unique (t+1,t+top+1)-t-1;
				for (int i=1;i<=top;i++)
				{
//					printf ("%d ",t[i]);
					fun[t[i]]=i;
				}
//				putchar (10);
				sort (ch+1,ch+m+1);
				for (int i=0;i<2;i++)
					for (int j=0;j<=top;j++)
						dp[i&1][j]=-inf;
				dp[0][0]=0;
				now=1;
				for (int i=1;i<=top;i++)
				{
					dp[i&1][0]=dp[!(i&1)][0];
					for (int j=1;j<=i && t[i]-t[i-j]<=k;j++)
					{
						dp[i&1][0]=max(dp[i&1][0],dp[!(i&1)][j]);
						dp[i&1][j]=dp[!(i&1)][j-1]-d*(t[i]-t[i-1]);
//						printf ("dp[%d][%d]=%d\n",i,j,dp[i&1][j]);
						for (int tt=now;fun[ch[tt].x]==i && fun[ch[tt].l-1]>=i-j;tt++)
							dp[i&1][j]+=ch[tt].v;
//						printf ("dp[%d][%d]=%d\n",i,j,dp[i&1][j]);
					}
//					printf ("dp[%d][0]=%d\n",i,dp[i&1][0]);
					while (fun[ch[now].x]==i) now++;
				}
				ans=0;
				for (int i=0;i<=top;i++)
				{
					if (t[top]-t[top-i]>k) break;
					ans=max(ans,dp[top&1][i]);
				}
				printf ("%lld\n",ans);
			}
		}
#ifndef OK
		printf ("\n%d\n",clock());
#endif
		exit(0);
	}
#undef inf
#undef int
}
int main ()
{
	Run::main();
	return 0;
}
/*
Hack:
17 1
15 15 5 1
1 1 100
2 1 100
3 1 100
4 1 100
5 1 100
6 1 100
7 1 100
8 1 100
9 1 100
10 1 100
11 1 100
12 1 100
13 1 100
14 1 100
15 1 100
Answer: 1287
*/
