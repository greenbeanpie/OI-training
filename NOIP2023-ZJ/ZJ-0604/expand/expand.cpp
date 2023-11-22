#include<bits/stdc++.h>

using namespace std;

int c,n,m,q;
int Px,Py,Kx,Ky;

int a[2010],b[2010],aa[2010],bb[2010];


int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		aa[i]=a[i];
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		bb[i]=b[i];
	}
	
	if (c==1)
	{
		if (a[1]!=b[1]) printf("1");
		else printf("0");
		
		for (int i=1;i<=q;i++)
		{
			scanf("%d%d",&Kx,&Ky);
			for (int j=1;j<=n;j++) a[j]=aa[j];
			for (int j=1;j<=m;j++) b[j]=bb[j];
			for (int j=1;j<=Kx;j++)
			{
				scanf("%d%d",&Px,&Py);
				a[Px]=Py;
			}
			for (int j=1;j<=Ky;j++)
			{
				scanf("%d%d",&Px,&Py);
				b[Px]=Py;
			}
			if (a[1]!=b[1]) printf("1");
			else printf("0");
		}
		
		return 0;
	}
	
	if (c==2)
	{
		if ((a[1]-b[1]) * (a[n]-b[m])>0) printf("1");
		else printf("0");
		
		for (int i=1;i<=q;i++)
		{
			scanf("%d%d",&Kx,&Ky);
			for (int j=1;j<=n;j++) a[j]=aa[j];
			for (int j=1;j<=m;j++) b[j]=bb[j];
			for (int j=1;j<=Kx;j++)
			{
				scanf("%d%d",&Px,&Py);
				a[Px]=Py;
			}
			for (int j=1;j<=Ky;j++)
			{
				scanf("%d%d",&Px,&Py);
				b[Px]=Py;
			}
			if ((a[1]-b[1]) * (a[n]-b[m])>0) printf("1");
			else printf("0");
		}
		
		return 0;
	}
	
	if (c>=3)
	{
		int l=1,r=1;
		bool T=false;
		
		if ((a[1]-b[1]) * (a[n]-b[m])<=0) printf("0");
		else 
		{
			if (a[l]<b[r])
			{
				while (l<n || r<m)
				{
					if (a[min(l+1,n)]>=b[min(r+1,m)])
					{
	
						if(a[min(l+1,n)]<b[min(r,m)]) l++;
						else if (b[min(r+1,m)]<=a[min(l,n)]) r++;
						else
						{
							T=true;
							break;
						}
					}
					else
					{
						l++;r++;
					}
				}
			}
			else
			{
				while (l<n || r<m)
				{
					if (b[min(r+1,m)]>=a[min(l+1,n)])
					{
	
						if(b[min(r+1,m)]<a[min(l,n)]) r++;
						else if (a[min(l+1,n)]<=b[min(r,m)]) l++;
						else
						{
							T=true;
							break;
						}
					}
					else
					{
						l++;r++;
					}
				}
			}
			if (T) printf("0");
			else printf("1");
		}
		
		for (int i=1;i<=q;i++)
		{
			scanf("%d%d",&Kx,&Ky);
			for (int j=1;j<=n;j++) a[j]=aa[j];
			for (int j=1;j<=m;j++) b[j]=bb[j];
			for (int j=1;j<=Kx;j++)
			{
				scanf("%d%d",&Px,&Py);
				a[Px]=Py;
			}
			for (int j=1;j<=Ky;j++)
			{
				scanf("%d%d",&Px,&Py);
				b[Px]=Py;
			}
			
			if ((a[1]-b[1]) * (a[n]-b[m])<=0) printf("0");
			else 
			{
				T=false;
				if (a[l]<b[r])
				{
					while (l<n || r<m)
					{
						if (a[min(l+1,n)]>=b[min(r+1,m)])
						{
	
							if(a[min(l+1,n)]<b[min(r,m)]) l++;
							else if (b[min(r+1,m)]<=a[min(l,n)]) r++;
							else
							{
								T=true;
								break;
							}
						}
						else
						{
							l++;r++;
						}
					}
				}
				else
				{
					while (l<n || r<m)
					{
						if (b[min(r+1,m)]>=a[min(l+1,n)])
						{
	
							if(b[min(r+1,m)]<a[min(l,n)]) r++;
							else if (a[min(l+1,n)]<=b[min(r,m)]) l++;
							else
							{
								T=true;
								break;
							}
						}
						else
						{
							l++;r++;
						}
					}
			    }
				if (T) printf("0");
				else printf("1");
			}
		}
	}
	
	return 0;
}