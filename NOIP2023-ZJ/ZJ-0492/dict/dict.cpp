#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,flag=0;
int tot[3001][26];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(tot,0,sizeof(tot));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			tot[i][c-'a']++;
		}
	for(int i=1;i<=n;i++)
	{
		flag=1;
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				int l=0,r=25;
				while(l<26&&r>=0)
				{
					while(tot[i][l]==0) l++;
					while(tot[j][r]==0) r--;
					if(l>r||l==r&&tot[i][l]>tot[j][r])
					{
						flag=0;break;
					}
					if(l<r) break;
					l++,r--;
				}
			}
		}
		cout<<flag;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
