#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=1e5+10;
int c,T,n,m,ans=114514,q[N],a[N],tot[N],v[N],w[N],ton[N]; 
char op[2]; 

void dfs(int idx,int cnt) 
{
	if (idx==n) 
	{
		for (int i=1;i<=n;i++) a[i]=q[i]; 
		
		for (int i=1;i<=m;i++) 
		{
			if (tot[i]==4) a[v[i]]=a[w[i]]; 
			else if (tot[i]==5) 
			{
				if (a[w[i]]==1) a[v[i]]=2; 
				else if (a[w[i]]==2) a[v[i]]=1;
				else a[v[i]]=3; 
			}
			else a[v[i]]=tot[i]; 
		}
		
		for (int i=1;i<=n;i++)
		{
			if (a[i]!=q[i]) return ;
			if (i==n) ans=min(ans,cnt); 
		}
		
		return ;
	}
	
	{
		q[idx+1]=1; dfs(idx+1,cnt); 
		q[idx+1]=2; dfs(idx+1,cnt); 
		q[idx+1]=3; dfs(idx+1,cnt+1); 
	}
}

int main()
{
	freopen("tribool.in","r",stdin); 
	freopen("tribool.out","w",stdout); 
	
	scanf("%d%d",&c,&T); 
	
	if (c<=2) 
	{
		while (T--) 
		{
			ans=114514;
			scanf("%d%d",&n,&m); 
			
			for (int i=1;i<=m;i++) 
			{
				scanf("%s",op); 
				if (op[0]=='+') {tot[i]=4; scanf("%d%d",&v[i],&w[i]); }
				if (op[0]=='-') {tot[i]=5; scanf("%d%d",&v[i],&w[i]);}	
				
				if (op[0]=='U') {tot[i]=3; scanf("%d",&v[i]);}
				if (op[0]=='F') {tot[i]=2; scanf("%d",&v[i]);}
				if (op[0]=='T') {tot[i]=1; scanf("%d",&v[i]);}
			} 
			
			dfs(0,0);
			cout<<ans<<endl; 
		}
	}
	
	if (c==3||c==4)
	{
		while (T--)
		{
			for (int i=1;i<=n;i++) ton[i]=0; 
			
			ans=0; 
			scanf("%d%d",&n,&m); 
			
			for (int i=1;i<=m;i++)
			{
				cin>>op>>v[i]; 
				if (op[0]=='U') ton[v[i]]=1; else ton[v[i]]=0; 
				
			}
			
			for (int i=1;i<=n;i++) if (ton[i]) ans++; 
			
			cout<<ans<<endl; 
		}
	}
	
	if (c==5||c==6)
	{
		while (T--) 
		{
			for (int i=1;i<=n;i++) ton[i]=0; 
			
			ans=0; 
			scanf("%d%d",&n,&m); 
			
			for (int i=1;i<=m;i++) 
			{
				cin>>op; 
				
				if (op[0]=='U') {scanf("%d",&v[i]); ton[v[i]]=1;}
				else {scanf("%d%d",&v[i],&w[i]); ton[v[i]]=ton[w[i]];}
				
			}
			for (int i=1;i<=n;i++) if (ton[i]) ans++; 
			
			cout<<ans<<endl; 
		}
		
		
	}
	
	fclose(stdin); fclose(stdout);  
	return 0; 
}




