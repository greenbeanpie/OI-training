//骗分是人类智慧的结晶 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int c,n,m,q;
int x[N],y[N];
int kx,ky;
map<int,int> mpx,mpy;
priority_queue<int,vector<int> > qx;
priority_queue<int,vector<int>,greater<int> > qy;
int mx=-1,mi=9999999;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		qx.push(x[i]);
		mpx[x[i]]++;
		mx=max(mx,x[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		qy.push(y[i]);
		mpy[y[i]]++;
		mi=min(mi,y[i]);
	}
	if(n==1&&m==1)
	{
		if(x[1]!=y[1])
		{
			printf("1");
		}else{
			printf("0");
		}
		while(q--)
		{
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				x[p]=q;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				y[p]=q;
			}
			if(x[1]!=y[1])
			{
				printf("1");
			}else{
				printf("0");
			}	
		}
		return 0;
	}
	if(n<=2&&m<=2)
	{
		int ax=x[1],bx=x[n],ay=y[1],by=y[m];
		int mx=ax-ay,my=bx-by;
		if(mx*my>0)
		{
			printf("1");
		}else{
			printf("0");
		}
		while(q--)
		{
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				x[p]=q;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				y[p]=q;
			}
			ax=x[1],bx=x[n],ay=y[1],by=y[m];
			mx=ax-ay,my=bx-by;
			if(mx*my>0)
			{
				printf("1");
			}else{
				printf("0");
			}	
		}
		return 0;
	}
	if(mx>=y[m]||mi<=x[n])
	{
		printf("0");
	}else{
		printf("1");
	}
	while(q--)
	{
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			mpx[x[p]]--;
			if(x[p]==mx)
			{
				qx.pop();
				while(mpx[qx.top()]<0)
				{
					qx.pop();
				}
			}
			qx.push(q);
			x[p]=q;
			mx=qx.top();
		}
		for(int i=1;i<=ky;i++)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			mpx[x[p]]--;
			if(x[p]==mi)
			{
				qy.pop();
				while(mpx[qy.top()]>0)
				{
					qy.pop();
				}
			}
			qy.push(q);
			y[p]=q;
			mi=qy.top();
		}
		if(mx>=y[m]||mi<=x[n])
		{
			printf("0");
		}else{
			printf("1");
		}
	}
 	return 0;
}
