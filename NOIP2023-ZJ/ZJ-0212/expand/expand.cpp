#include<bits/stdc++.h>
using namespace std;
namespace bf{
	int n,m,q,a[2005],b[2005],t1[2005],t2[2005];
	bitset<2005> f[2005];
	bool ddp()
	{
		if(a[1]<=b[1]) return 0;
		for(int i=0;i<=n;i++)
		{
			f[i].reset();
		}
		f[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!f[i][j]) continue ;
				if(i!=n&&a[i+1]>b[j]) f[i+1][j]=1;
				if(j!=m&&a[i]>b[j+1]) f[i][j+1]=1;
			}
		}
		// cerr<<"\n";
		return f[n][m];
	}
	bool dp()
	{
		bool f1=ddp();
		for(int i=1;i<=n;i++) a[i]=-a[i];
		for(int i=1;i<=m;i++) b[i]=-b[i];
		bool f2=ddp();
		for(int i=1;i<=n;i++) a[i]=-a[i];
		for(int i=1;i<=m;i++) b[i]=-b[i];
		return f1||f2;
	}
	void solve()
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		cout<<dp();
		while(q--)
		{
			// cerr<<"query:"<<q<<"\n";
			memcpy(t1,a,sizeof(a));
			memcpy(t2,b,sizeof(b));
			int k1,k2;
			cin>>k1>>k2;
			for(int i=1;i<=k1;i++)
			{
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int i=1;i<=k2;i++)
			{
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			cout<<dp();
			memcpy(a,t1,sizeof(a));
			memcpy(b,t2,sizeof(b));
		}
	}
}
namespace TTT{
	int n,m,q,a[500005],b[500005],t1[500005],t2[500005],pmin[500005],mn[500005],s[500005],t[500005];
	int sta[500005],top;
	struct st{
		int st[500005][20];
		void build()
		{
			memset(st,-0x3f,sizeof(st));
			for(int i=1;i<=m;i++)
			{
				st[i][0]=b[i];
			}
			for(int i=1;(1<<i)<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					st[j][i]=max(st[j][i-1],st[min(j+(1<<(i-1)),n)][i-1]);
				}
			}
		}
		int query(int l,int r)
		{
			int k=__lg(r-l+1);
			return max(st[l][k],st[r-(1<<k)+1][k]);
		}
	}T;
	bool ddp()
	{
		T.build();
		top=0;
		int mx=*max_element(b+1,b+1+m);
		pmin[m]=b[m];
		for(int i=m-1;i>=1;i--)
		{
			pmin[i]=min(pmin[i+1],b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			mn[i]=2e9;
			s[i]=1e9;
			while(top&&a[i]>a[sta[top]])
			{
				mn[i]=min(mn[i],mn[sta[top]]);
				top--;
			}	
			if(a[i]>mx) s[i]=i;
			if(top)
			{
				int l=0,r=m;
				while(l<r)
				{
					int mid=(l+r+1)>>1;
					if(mn[i]>pmin[mid]) l=mid;
					else r=mid-1; 
				}

				if(l&&a[i]>T.query(l,m)) s[i]=s[sta[top]];
			} 
			// cerr<<i<<" "<<s[i]<<"\n";
			mn[i]=min(mn[i],a[i]);
			sta[++top]=i;
		}	
		top=0;
		pmin[1]=b[1];
		for(int i=1;i<=m;i++)
		{
			pmin[i]=min(pmin[i-1],b[i]);
		}
		for(int i=n;i>=1;i--)
		{
			mn[i]=a[i];
			t[i]=0;
			while(top&&a[i]>a[sta[top]]) 
			{
				mn[i]=min(mn[i],mn[sta[top]]);
				top--;
			}
			if(a[i]>mx) t[i]=i;
			if(top)
			{
				int l=1,r=m+1;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(a[i]>pmin[mid]) r=mid;
					else l=mid+1;
				}
				if(l!=m+1&&a[i]>T.query(1,m)) t[i]=t[sta[top]];
			}
			// cerr<<i<<" "<<t[i]<<"\n";
			sta[++top]=i;
		}
		return t[1]>=s[n];
	}
	bool dp()
	{
		bool f1=ddp();
		for(int i=1;i<=n;i++) a[i]=-a[i];
		for(int i=1;i<=m;i++) b[i]=-b[i];
		bool f2=ddp();
		for(int i=1;i<=n;i++) a[i]=-a[i];
		for(int i=1;i<=m;i++) b[i]=-b[i];
		return f1||f2;
	}
	void solve()
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		cout<<dp();
		while(q--)
		{
			memcpy(t1,a,sizeof(a));
			memcpy(t2,b,sizeof(b));
			int k1,k2;
			cin>>k1>>k2;
			for(int i=1;i<=k1;i++)
			{
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int i=1;i<=k2;i++)
			{
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			cout<<dp();
			memcpy(a,t1,sizeof(a));
			memcpy(b,t2,sizeof(b));
		}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int id;
	cin>>id;
	if(id<=7) bf::solve();
	else TTT::solve();
}