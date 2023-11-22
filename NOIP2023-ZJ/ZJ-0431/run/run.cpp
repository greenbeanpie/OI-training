#include<bits/stdc++.h>
using namespace std;
int pnt,T;
const int N=1e5+10;
namespace B{
	inline void work()
	{
		while(T--)
		{
			register int n,m,k,d;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			register int ans=0;
			for(register int i=1;i<=m;i++)
			{
				register int pos,ke,val;
				scanf("%d%d%d",&pos,&ke,&val);
				register int l,r;
				r=pos,l=r-ke+1;
				if(r-l+1<=k) ans=max(ans,ans-(r-l+1)*d+val);
			}
			printf("%d\n",ans);
		}
	}
}
namespace S{
	int ans=0;
	struct node{
		int l,r,val;
	}cl[N];
	inline bool cmp(register node x,register node y)
	{
		return x.l<y.l;
	}
	struct now{
		int pos,k,en,ask;
		inline void print()
		{
			printf("test:%d %d %d %d\n",pos,k,en,ask);
		}
	};
	inline void work()
	{
		while(T--)
		{
			register int n,m,k,d;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			ans=0;
			for(register int i=1;i<=m;i++)
			{
				register int pos,ke,val;
				scanf("%d%d%d",&pos,&ke,&val);
				cl[i]={pos-ke+1,pos,val};
			}
			sort(cl+1,cl+1+m,cmp);
			queue<now> q;
			q.push({1,0,0,0});
			while(!q.empty())
			{
				register now p=q.front();q.pop();
//				p.print();
				register int nxt=p.ask+1;
				if(nxt>m)
				{
					ans=max(ans,p.en);
					continue;
				}
				if(p.pos>=cl[nxt].r and p.pos-p.k+1<=cl[nxt].l)
				{
					q.push({p.pos,p.k,p.en+cl[nxt].val,nxt});
					continue;
				}
				if(cl[nxt].l-1>p.pos)
				{
					register int len=cl[nxt].r-cl[nxt].l+1;
					if(len<=k)
					{
						q.push({cl[nxt].r,len,p.en-d*len+cl[nxt].val,nxt});
					}
				}
				else if(cl[nxt].r-p.pos<=k-p.k)
				{
					q.push({cl[nxt].r,p.k+cl[nxt].r-p.pos,p.en-(cl[nxt].r-p.pos)*d+cl[nxt].val,nxt});
				}
				if(nxt<m) q.push({cl[nxt+1].l,0,p.en,nxt});
			}
			printf("%d\n",ans);
		}
	}
}
signed main(void)
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&pnt,&T);
	B::work();
	return 0;
}