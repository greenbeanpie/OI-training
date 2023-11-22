#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500005],y[500005],cnt1[500005],cnt2[500005],w1,w2;
bool f,flag;
void dfs(int nowx,int nowy)
{
	if(nowx==n+1&&nowy==m+1)
	{
		if(w1<w2)
		{
			for(int i=w1+1;i<=w2;i++) cnt1[i]=cnt1[i-1];
		}
		if(w1>w2)
		{
			for(int i=w2+1;i<=w1;i++) cnt2[i]=cnt2[i-1];
		}
		if(cnt1[w2]!=x[n]||cnt2[w2]!=y[m]) return;
		//for(int i=1;i<=w2;i++) cout<<cnt1[i];
		//cout<<"\n";
		bool ff=1;
		if(f==0)
		{
			for(int i=1;i<=w2;i++)
			{
				if(cnt1[i]>=cnt2[i]) ff=0;
			}
		}
		if(f==1)
		{
			for(int i=1;i<=w2;i++)
			{
				if(cnt1[i]<=cnt2[i]) ff=0;
			}
		}
		if(ff==1)
		{
			flag=1;
		}
		return;
	}
	if(nowx<n+1&&nowy<m+1)
	{
		for(int i=1;i<=n*m;i++)
		{
			int ww1=w1;
			for(int k=1;k<=i;k++) cnt1[++w1]=x[nowx];
			for(int j=1;j<=n*m;j++)
			{
				int ww2=w2;
				for(int k=1;k<=j;k++) cnt2[++w2]=y[nowy];
				dfs(nowx+1,nowy+1);
				w2=ww2;
			}
			w1=ww1;
		}
	}
	if(nowx<n+1&&nowy==m+1)
	{
		for(int i=1;i<=n*m;i++)
		{
			int ww1=w1;
			for(int k=1;k<=i;k++) cnt1[++w1]=x[nowx];
			dfs(nowx+1,nowy);
			w1=ww1;
		}
	}
	if(nowy<n+1&&nowx==m+1)
	{
		for(int i=1;i<=n*m;i++)
		{
			int ww2=w2;
			for(int k=1;k<=i;k++) cnt2[++w2]=y[nowy];
			dfs(nowx,nowy+1);
			w2=ww2;
		}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	if(c==1)
	{
		if(x[1]==y[1]) cout<<"0";
		else cout<<"1";
		while(q--)
		{
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				int p,v;
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,v;
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]==y[1]) cout<<"0";
			else cout<<"1";
		}
	}
	if(c==2)
	{
		if(n==2&&m==2)
		{
			if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2])) cout<<"1";
			else cout<<"0";
			while(q--)
			{
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2])) cout<<"1";
				else cout<<"0";
			}
		}
		if(n==1&&m==2)
		{
			if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2])) cout<<"1";
			else cout<<"0";
			while(q--)
			{
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2])) cout<<"1";
				else cout<<"0";
			}
		}
		if(n==2&&m==1)
		{
			if((x[1]>y[1]&&x[2]>y[1])||(x[1]<y[1]&&x[2]<y[1])) cout<<"1";
			else cout<<"0";
			while(q--)
			{
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if((x[1]>y[1]&&x[2]>y[1])||(x[1]<y[1]&&x[2]<y[1])) cout<<"1";
				else cout<<"0";
			}
		}
		if(n==1&&m==1)
		{
			if(x[1]==y[1]) cout<<"0";
			else cout<<"1";
			while(q--)
			{
				int kx,ky;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++)
				{
					int p,v;
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++)
				{
					int p,v;
					cin>>p>>v;
					y[p]=v;
				}
				if(x[1]==y[1]) cout<<"0";
				else cout<<"1";
			}
		}
	}
	if(c>=3&&c<=4)
	{
		if(x[1]<y[1])
		{
			f=0;
			flag=0;
			dfs(1,1);
		}
		if(x[1]>y[1])
		{
			f=1;
			flag=0;
			dfs(1,1);
		}
		if(x[1]==y[1]||flag==0) cout<<"0";
		else cout<<"1";
		while(q--)
		{
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++)
			{
				int p,v;
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,v;
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]<y[1])
			{
				f=0;
				flag=0;
				dfs(1,1);
			}
			if(x[1]>y[1])
			{
				f=1;
				flag=0;
				dfs(1,1);
			}
			if(x[1]==y[1]||flag==0) cout<<"0";
			else cout<<"1";
		}
	}
	return 0;
}
