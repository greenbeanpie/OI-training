#include<bits/stdc++.h>
using namespace std;
int x[500001],y[500001],z[500001][2],xx[500001],yy[500001];
int main()
{
	freopen("expand.in ","r",stdin);
	freopen("expand.out","w",stdout);
	int n,m,c,q,i,j,mi,ls,fr,fl,kx,ky,p,v,k,aa,bb;
	string s="";
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
	}
	if(c==1)
	{
		if(x[1]==y[1])
		{
			s+='0';
		}
		else
		{
			s+='1';
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			aa=x[1];
			bb=y[1];
			for(j=1;j<=kx;j++)
			{
				scanf("%d%d",&p,&v);
				aa=v;
			}
			for(j=1;j<=ky;j++)
			{
				scanf("%d%d",&p,&v);
				bb=v;
			}
			if(aa==bb)
			{
				s+='0';
			}
			else
			{
				s+='1';
			}
		}
		cout<<s<<endl;
		return 0;
	}
	if(c==2)
	{
		if((x[1]<y[1]&&x[2]<y[2])||(x[1]>y[1]&&x[2]>y[2]))
		{
			s+='1';
		}
		else
		{
			s+='0';
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			xx[1]=x[1];
			yy[1]=y[1];
			xx[2]=x[2];
			yy[2]=y[2];
			for(j=1;j<=kx;j++)
			{
				scanf("%d%d",&p,&v);
				xx[p]=v;
			}
			for(j=1;j<=ky;j++)
			{
				scanf("%d%d",&p,&v);
				yy[p]=v;
			}
			if((xx[1]<yy[1]&&xx[2]<yy[2])||(xx[1]>yy[1]&&xx[2]>yy[2]))
			{
				s+='1';
			}
			else
			{
				s+='0';
			}
		}
		cout<<s<<endl;
		return 0;
	}
	if(c!=1&&c!=2)
	{
		if(x[1]<y[1])
		{
			for(i=1;i<=n;i++)
			{
				z[i][0]=m+1;
				for(j=1;j<=m;j++)
				{
					if(y[j]>x[i])
					{
						z[i][0]=j;
						break;
					}
				}
				z[i][1]=m+1;
				for(j=z[i][0];j<=n;j++)
				{
					if(y[j]<=x[i])
					{
						z[i][1]=j-1;
						break;
					}
				}
			}
			ls=z[1][1];
			fr=1;
			fl=1;
			for(i=2;i<=n;i++)
			{
				if(z[i][0]>ls||z[i][1]<fr)
				{
					fl=0;
					s+='0';
					break;
				}
				ls=z[i][1];
				fr=z[i][0];
			}
			if(fl==1)
			{
				s+='1';
			}
		}
		if(x[1]>y[1])
		{
			for(i=1;i<=n;i++)
			{
				z[i][0]=m+1;
				for(j=1;j<=m;j++)
				{
					if(y[j]<x[i])
					{
						z[i][0]=j;
						break;
					}
				}
				z[i][1]=m+1;
				for(j=z[i][0];j<=n;j++)
				{
					if(y[j]>=x[i])
					{
						z[i][1]=j-1;
						break;
					}
				}
			}
			ls=z[1][1];
			fr=1;
			fl=1;
			for(i=2;i<=n;i++)
			{
				if(z[i][0]>ls||z[i][1]<fr)
				{
					fl=0;
					s+='0';
					break;
				}
				ls=z[i][1];
				fr=z[i][0];
			}
			if(fl==1)
			{
				s+='1';
			}
		}
		if(x[1]==y[1])
		{
			s+='0';
		}
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&kx,&ky);
			for(j=1;j<=n;j++)
			{
				xx[j]=x[j];
			}
			for(j=1;j<=m;j++)
			{
				yy[j]=y[j];
			}
			for(j=1;j<=kx;j++)
			{
				scanf("%d%d",&p,&v);
				xx[p]=v;
			}
			for(j=1;j<=ky;j++)
			{
				scanf("%d%d",&p,&v);
				yy[p]=v;
			}
			if(xx[1]<yy[1])
			{
				for(k=1;k<=n;k++)
				{
					z[k][0]=m+1;
					for(j=1;j<=m;j++)
					{
						if(yy[j]>xx[k])
						{
							z[k][0]=j;
							break;
						}
					}
					z[k][1]=m+1;
					for(j=z[k][0];j<=n;j++)
					{
						if(yy[j]<=xx[k])
						{
							z[k][1]=j-1;
							break;
						}
					}
				}
				ls=z[1][1];
				fr=1;
				fl=1;
				for(k=2;k<=n;k++)
				{
					if(z[k][0]>ls||z[k][1]<fr)
					{
						fl=0;
						s+='0';
						break;
					}
					ls=z[k][1];
					fr=z[k][0];
				}
				if(fl==1)
				{
					s+='1';
				}
			}
			if(xx[1]>yy[1])
			{
				for(k=1;k<=n;k++)
				{
					z[k][0]=m+1;
					for(j=1;j<=m;j++)
					{
						if(yy[j]<xx[k])
						{
							z[k][0]=j;
							break;
						}
					}
					z[k][1]=m+1;
					for(j=z[k][0];j<=n;j++)
					{
						if(yy[j]>=xx[k])
						{
							z[k][1]=j-1;
							break;
						}
					}
				}
				ls=z[1][1];
				fr=1;
				fl=1;
				for(k=2;k<=n;k++)
				{
					if(z[k][0]>ls||z[k][1]<fr)
					{
						fl=0;
						s+='0';
						break;
					}
					ls=z[k][1];
					fr=z[k][0];
				}
				if(fl==1)
				{
					s+='1';
				}
			}
			if(xx[1]==yy[1])
			{
				s+='0';
			}
		}
		cout<<s<<endl;
	}
}