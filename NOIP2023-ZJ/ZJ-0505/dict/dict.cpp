#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,x,y,z,min_first,min_second,now;
char s[3050][3050];
bool flag;
bool cmp(char x,char y)
{
	return x<y;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n==1)
	  {
	  	printf("1");
	  	return 0;
	  }
	for (i=1;i<=n;i++)
	  scanf("%s",s[i]);
	for (i=1;i<=n;i++)
	  sort(s[i]+0,s[i]+0+m,cmp);
	min_first=1;
	for (i=2;i<=n;i++)
	  {
	  	now=-1;
	  	for (j=(m-1);j>=0;j--)
	  	  if (s[i][j]!=s[min_first][j])
	  	    {
	  	    	now=j;
	  	    	break;
			}
		if (now!=-1)
		  {
		  	if (s[i][now]<s[min_first][now]) min_first=i;
		  }
	  }
	if (min_first==1)
	  {
	  	min_second=2;
	  	for (i=3;i<=n;i++)
	      {
	  	    now=-1;
	  	    for (j=(m-1);j>=0;j--)
	  	      if (s[i][j]!=s[min_second][j])
	  	        {
	  	    	  now=j;
	  	    	  break;
			    }
		    if (now!=-1)
		      {
		  	    if (s[i][now]<s[min_second][now]) min_second=i;
		      }
	      }
	  }
	else
	  {
	  	min_second=1;
	  	for (i=2;i<=n;i++)
	  	  if (i!=min_first)
	        {
	  	      now=-1;
	  	      for (j=(m-1);j>=0;j--)
	  	        if (s[i][j]!=s[min_second][j])
	  	          {
	  	    	    now=j;
	  	    	    break;
			      }
		      if (now!=-1)
		        {
		  	      if (s[i][now]<s[min_second][now]) min_second=i;
		        }
	        }
	  }
	for (i=1;i<=n;i++)
	  if (i!=min_first)
	    {
	    	flag=true;
	    	for (j=0;j<m;j++)
	    	  if (s[i][j]!=s[min_first][m-1-j])
	    	    {
	    	    	if (s[i][j]>s[min_first][m-1-j]) flag=false;
	    	    	break;
				}
			if (flag==true) printf("1"); else printf("0");
		}
	  else
	    {
	    	flag=true;
	    	for (j=0;j<m;j++)
	    	  if (s[i][j]!=s[min_second][m-1-j])
	    	    {
	    	    	if (s[i][j]>s[min_second][m-1-j]) flag=false;
	    	    	break;
				}
			if (flag==true) printf("1"); else printf("0");
		}
	return 0;
}