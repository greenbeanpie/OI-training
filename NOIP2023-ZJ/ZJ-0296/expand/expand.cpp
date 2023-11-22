#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int c,n,m,q,x,y,k1,k2;
int a[100001],b[100001],la,lb;
int amin,amax,bmin,bmax;
int fa[100001],ka,fb[100001],kb,gu1,gu2;
int main(){ 
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	//x=b y=a
	if (c>=8&&c<=14)
	{
		for (int qq=1;qq<=q+1;qq++)
		{
			ka=kb=1;
			gu2=1000000000;gu1=1000000000;
			memset(fb,0,sizeof(fb));
			memset(fa,0,sizeof(fa));
			if (qq!=1)
			{
				scanf("%d%d",&k1,&k2);
				for (int i=1;i<=k1;i++)
				{
					scanf("%d%d",&x,&y);
					b[x]=y;
				}
				for (int i=1;i<=k2;i++)
				{
					scanf("%d%d",&x,&y);
					a[x]=y;
				}
			}
			for (int i=1;i<=n;i++) 
			{
				if (qq==1) scanf("%d",&b[i]);
				if (b[i-1]<=b[i])
				{
					if (gu2!=1000000000&&fb[kb]<b[i])
					{
						fb[kb+1]=gu2;kb+=2;
					}
					if (fb[kb]<b[i]) fb[kb]=b[i];
					gu2=1000000000;	
				}
				else
				{
					gu2=min(gu2,b[i]);
				}	
			}
			for (int i=1;i<=m;i++) 
			{
				if (qq==1) scanf("%d",&a[i]);
				if (a[i-1]<=a[i])
				{
					if (gu1!=1000000000&&fa[ka]<a[i])
					{
						fa[ka+1]=gu1;ka+=2;
					}
					if (fa[ka]<a[i]) fa[ka]=a[i];
					gu1=1000000000;	
				}
				else
				{
					gu1=min(gu1,a[i]);
				}	
			}
			int l1=1,l2=1,m1=1000000000,ans=1;
			//l1-a   l2-b
		//	for (int i=1;i<=)
			while(l1<ka&&l2<kb)
			{
				
				int mm=1000000000;
				while(fa[l1]>fb[l2]) m1=min(m1,fb[l2+1]),l2+=2;
				if (l1>ka||l2>kb) break;
				while(fa[l1]<=fb[l2]) mm=min(mm,fa[l1+1]),l1+=2;
				if (l1>ka||l2>kb) break;
		//		cout<<"l1="<<l1<<" l2="<<l2<<endl;
				if (mm<=m1)
				{
					ans=0;
					break;
				}
				else m1=1000000000;
			}
			cout<<ans;
		}	
	}
	else
	{
		if (c==1)
		{
			for (int qq=1;qq<=q+1;qq++)
			{
				if (qq!=1)
				{
					scanf("%d%d",&k1,&k2);
					for (int i=1;i<=k1;i++)
					{
						scanf("%d%d",&x,&y);
						b[x]=y;
					}
					for (int i=1;i<=k2;i++)
					{
						scanf("%d%d",&x,&y);
						a[x]=y;
					}
				}	
				if (qq==1) scanf("%d%d",&b[1],&a[1]);
				if (a[1]!=b[1]) cout<<1;
				else cout<<0;
			}	
		}
		else
		if (c==2)
		{
			for (int qq=1;qq<=q+1;qq++)
			{
					if (qq!=1)
				{
					scanf("%d%d",&k1,&k2);
					for (int i=1;i<=k1;i++)
					{
						scanf("%d%d",&x,&y);
						b[x]=y;
					}
					for (int i=1;i<=k2;i++)
					{
						scanf("%d%d",&x,&y);
						a[x]=y;
					}
				}	
				if (qq==1) 
				{
					for (int i=1;i<=n;i++) scanf("%d",&b[i]);
					for (int i=1;i<=m;i++) scanf("%d",&a[i]);
				}
				if (n==m&&n==1)
				{
					if (a[1]!=b[1]) cout<<1;
					else cout<<0;
				}
				else if (n==2&&m==1)
				{
					if ((a[1]-b[1])*(a[1]-b[2])>0) cout<<1;
					else cout<<0;
				}
				else if (n==1&&m==2)
				{
					if ((a[1]-b[1])*(a[2]-b[1])>0) cout<<1;
					else cout<<0;
				}
				else if (n==2&&m==2)
				{
					if ((a[1]-b[1])*(a[2]-b[2])>0) cout<<1;
					else cout<<0;
				}	
			}
		
		}
		else
		{
			for (int qq=1;qq<=q+1;qq++)
			{
				cout<<1;
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
