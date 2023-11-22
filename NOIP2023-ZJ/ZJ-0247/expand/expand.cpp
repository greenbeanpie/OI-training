#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long ya[N],yb[N],a[N],b[N],vis[2005],viss[2005];
int n,m;
inline int rd()
{
	char c; int x = 0;
	do c = getchar(); while (!isdigit(c));
	do x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	while (isdigit(c));
	return x;
}
void pf35()
{
	if (n<=1 && m<=1)
		{
			printf("1");
			return;
		}
		if (a[1]>b[1] && a[n]<b[m] || a[1]<b[1] && a[n]>b[m] || a[1]==b[1] || a[n]==b[m])
		{
			printf("0");
			return;
		}
		bool flag;
		memset(vis,0,sizeof(vis));
		for (int j = 1; j <= m; j++)
		  if ((a[1]-b[j])*(a[1]-b[1])>0)
		    vis[j]=1;
		  else break;
		for (int i = 2; i <= n; i++)
		{
		    flag=false;
			for (int j = 1; j <= m; j++)
			  if (vis[j])
			  {
			  	if ((a[i]-b[j])*(a[1]-b[1])>0)
			  	  viss[j]=1,flag=true;
			    for (int k = j+1; k <= m; k++)
			      if ((a[i]-b[k])*(a[1]-b[1])>0)
			        viss[k]=1,flag=true;
			      else break;
			  }
			for (int j = 0; j <= m; j++)
			  vis[j]=viss[j];
			/*cout<<endl;
			cout<<i<<"? "; 
			for (int j = 1; j <= m; j++)
			  cout<<vis[j]<<" ";
			cout<<endl;*/
			memset(viss,0,sizeof(viss));
			if (!flag)
			  break;
		}
		if (!flag || !vis[m])
		  printf("0");
		else printf("1");
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;
	cin>>c>>n>>m>>q;
	for (int i = 1; i <= n; i++)
	  ya[i]=rd(),a[i]=ya[i];
	for (int i = 1; i <= m; i++)
	  yb[i]=rd(),b[i]=yb[i];
	yb[m+1]=yb[m];
	b[m+1]=b[m];
	if (n<=2000)
	{
		pf35();
		while (q--)
		{
			for (int i = 1; i <= n; i++)
			  a[i]=ya[i];
			for (int i = 1; i <= m+1; i++)
			  b[i]=yb[i];
			int kx = rd(), ky = rd();
			for (int i = 1; i <= kx; i++)
			{
				int x = rd(), v = rd();
				a[x]=v;
			}
			for (int i = 1; i <= ky; i++)
			{
				int x = rd(), v = rd();
				b[x]=v;
			}
			pf35();
	    }
	}
	return 0;
}
