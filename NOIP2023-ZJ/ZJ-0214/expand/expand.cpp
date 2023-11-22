#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=1e5+10; 
int c,n,m,q,a[N],b[N],kx,ky,p,v,x[N],y[N],ans[N]; 
bool flag=true;
bool f[2010][2010]; 

bool dfs(int qx,int qy)
{
	
	if (qx==n&&qy==m) return true; 
	if (qx==n) return false; 
	
	bool res=false; 
	int tot=qy;
	
	if (flag) 
	{
		while (x[qx+1]>y[tot]&&tot<=m) 
		{
			res=res||(dfs(qx+1,tot)); tot++; 
			
			if (res) break; 
		}
	}
	else 
	{
		while (x[qx+1]<y[tot]&&tot<=m) 
		{
			res=res||(dfs(qx+1,tot)); tot++;
			
			if (res) break; 
		}
	}
	

	return res; 
}

int main()
{
	freopen("expand.in","r",stdin); 
	freopen("expand.out","w",stdout); 
	
	scanf("%d%d%d%d",&c,&n,&m,&q); 
	
	for (int i=1;i<=n;i++) scanf("%d",&a[i]); 
	for (int i=1;i<=m;i++) scanf("%d",&b[i]); 

	for (int i=1;i<=n;i++) x[i]=a[i];
	for (int i=1;i<=m;i++) y[i]=b[i];
	
	if ((x[1]>y[1]&&x[n]<y[m])||(x[1]<y[1]&&x[n]>y[m])||(x[1]==y[1])||(x[n]==y[m])) ans[0]=0; 
	else 
	{
		if (x[1]>y[1]) flag=true; else flag=false; 
	
		if (dfs(0,1)) ans[0]=1; else ans[0]=0;
	}
	
	for (int cnt=1;cnt<=q;cnt++)
	{
		memset(f,0,sizeof(f)); 
		
		for (int i=1;i<=n;i++) x[i]=a[i];
		for (int i=1;i<=m;i++) y[i]=b[i];  
		scanf("%d%d",&kx,&ky); 
		
		for (int i=1;i<=kx;i++)
		{
			scanf("%d%d",&p,&v); x[p]=v;	
		} 
		
		for (int i=1;i<=ky;i++) 
		{
			scanf("%d%d",&p,&v); y[p]=v;
		}
		
		if ((x[1]>y[1]&&x[n]<y[m])||(x[1]<y[1]&&x[n]>y[m])||(x[1]==y[1])||(x[n]==y[m])) 
		{
			ans[cnt]=0; 
			continue; 
		}
		
		if (x[1]>y[1]) flag=true; else flag=false; 
		
		if (dfs(0,1)) ans[cnt]=1; else ans[cnt]=0;
	}	
	
	for (int i=0;i<=q;i++) cout<<ans[i]; 
	
	fclose(stdin); fclose(stdout); 
	return 0; 
}











