#include<bits/stdc++.h>

using namespace std;

int n,m;

string s[3010];
int t[150];
string a[3010],b[3010];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	
	if (n==1)
	{
		printf("1");
		return 0;
	}
	if (m==1)
	{
		int x=1;
		for (int i=2;i<=n;i++)
		{
			if (s[i]<s[x]) 
			{
				x=i;
			}
		}
		
		for (int i=1;i<=n;i++)
		{
			if (i==x) printf("1");
			else printf("0");
		}
		
		return 0;
	}
	
	if (m==2)
	{
		char ch;
		bool T;
		
		for (int i=1;i<=n;i++)
		{
			T=true;
			if (s[i][0]>s[i][1]) ch=s[i][1];
			else ch=s[i][0];
			
			for (int j=1;j<=n;j++)
			    if (j!=i)
			    {
			    	if (s[j][0] <= ch and s[j][1] <= ch)
			    	{
			    		T=false;
			    		break;
					}
				}
				
			if (T) printf("1");
			else printf("0");
		}
		
		return 0;
	}
	
	for (int i=1;i<=n;i++)
	{
		for (int j=(int)('a');j<=(int)('z');j++) t[j]=0;
		
		for (int j=0;j<m;j++)
		    t[(int)(s[i][j])]++;
		
		for (int j=(int)('a');j<=(int)('z');j++)
		{
			for (int l=1;l<=t[j];l++) a[i]+=char(j);
		}
		for (int j=(int)('z');j>=(int)('a');j--)
		{
			for (int l=1;l<=t[j];l++) b[i]+=char(j);
		}
	}
	
	bool T;
	for (int i=1;i<=n;i++)
	{
		T=true;
		for (int j=1;j<=n;j++)
		    if (i!=j)
		    {
		    	if (b[j]<a[i])
		    	{
		    		T=false;
		    		break;
				}
			}
			
		if (T) printf("1");
		else printf("0");
	}
	
	return 0;
}