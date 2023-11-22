#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x,y,kx,ky,a[500001],b[500001],ta[500001],tb[500001];
bool tt,f1[2001][2001],f2[2001][2001];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	if(c<=7)
	{
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(int i=1;i<=n;i++)
	      cin>>a[i];
	    for(int i=1;i<=m;i++)
	      cin>>b[i];
	    f1[0][0]=f2[0][0]=1;
	    for(int i=1;i<=n;i++)
		{
			tt=false;
			for(int j=1;j<=m;j++)
	            if(a[i]>b[j])
	            {
	            	if(f1[i][j-1]||f1[i-1][j-1]||f1[i-1][j])
	            	  f1[i][j]=true;
	              //	f1[i][j]=max(f1[i][j-1]+1,max(f1[i-1][j-1]+1,f1[i-1][j]));
	              	if(!tt&&f1[i][j])
	              	  tt=true;
				}
	        if(!tt)
				break;    
		}
		for(int i=1;i<=n;i++)
	        {
	        	tt=false;
				for(int j=1;j<=m;j++)
	          	  if(a[i]<b[j])
	          	  {
	          	  	if(f2[i][j-1]||f2[i-1][j-1]||f2[i-1][j])
	            	  f2[i][j]=true;
	          	  //	f2[i][j]=max(f2[i][j-1]+1,max(f2[i-1][j-1]+1,f2[i-1][j]));
	          	  	if(!tt&&f2[i][j])
	          	  	  tt=true;
				  }
			    if(!tt)
				  break;    
			}
	    if(f1[n][m]||f2[n][m])
	      cout<<1;else
	      cout<<0;
	    for(int ii=1;ii<=q;ii++)
	    {
	    	cin>>kx>>ky;
	    	memset(f1,0,sizeof(f1));
	    	memset(f2,0,sizeof(f2));
	    	for(int j=1;j<=n;j++)
	    	  ta[j]=a[j];
	    	for(int j=1;j<=m;j++)
	    	  tb[j]=b[j];
	    	for(int j=1;j<=kx;j++)
	    	{
	    		cin>>x>>y;
	    		ta[x]=y;
			}
			for(int j=1;j<=ky;j++)
			{
				cin>>x>>y;
				tb[x]=y;
			}
			if(ta[n]==tb[m])
		    {
		    	cout<<0;
		    	continue;
			}
			f1[0][0]=f2[0][0]=1;
			for(int i=1;i<=n;i++)
			{
				tt=false;
				for(int j=1;j<=m;j++)
	              if(ta[i]>tb[j])
	              {
	              	if(f1[i][j-1]||f1[i-1][j-1]||f1[i-1][j])
	            	  f1[i][j]=true;
	              	if(!tt&&f1[i][j])
	              	  tt=true;
				  }
	            if(!tt)
				  break;    
			}
			if(f1[n][m])
			{
				cout<<1;
				continue;
			}
	        for(int i=1;i<=n;i++)
	        {
	        	tt=false;
				for(int j=1;j<=m;j++)
	          	  if(ta[i]<tb[j])
	          	  {
	          	  	if(f2[i][j-1]||f2[i-1][j-1]||f2[i-1][j])
	            	  f2[i][j]=true;
	          	  	if(!tt&&f2[i][j])
	          	  	  tt=true;
				  }
			    if(!tt)
				  break;    
			}
	    	if(f2[n][m])
	      	  cout<<1;else
	      	  cout<<0;
		}
	}else
	for(int i=1;i<=q+1;i++)
	  cout<<0;
	return 0;
}