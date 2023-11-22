#include<bits/stdc++.h>
using namespace std;
int buc[27];
bool mxid[3005];
int main()
{
	//ios::sync_with_stdio(false);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	string x[3005],mn[3005],mx[3005],minmx="";
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		minmx+='z';
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		memset(buc,0,sizeof(buc));
		for(int j=0;j<m;j++)
		{
			buc[(int)(x[i][j]-'a'+1)]++;
		}
		for(int j=26;j>=1;j--)
		{
			for(int k=1;k<=buc[j];k++)
			{
				mn[i]=(char)(j+'a'-1)+mn[i];
				mx[i]=mx[i]+(char)(j+'a'-1);
			
			}
		}	
		minmx=min(minmx,mx[i]);//cout<<"minx:"<<minmx<<endl;
		//cout<<mx[i]<<endl<<mn[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(mx[i]==minmx)
		{
			mxid[i]=true;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		//cout<<endl<<mn[i]<<' '<<i<<endl;
		
		
		if(mn[i]<minmx)
		{
			printf("1");
		}
		else
		{
			if(mxid[i])
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			
		}
	}
	return 0;
}