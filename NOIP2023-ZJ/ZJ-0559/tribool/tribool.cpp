#include<bits/stdc++.h>
using namespace std;
int x[100010],yy[100010];
int c,t,p,n,m;
char v;
string vv;
int pp[100010],qq[100010];
int no(int x)
{
	if(x == 2)
	 return 2;
	return 1 - x;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c == 3 || c == 4)
	{
		while(t--)
		{
			int ans = 0;
			scanf("%d%d",&n,&m);
			memset(x,0,sizeof(x));
			for(int i=1;i<=m;i++)
			{
				cin>>v>>p;
				x[p] = 0;
				if(v == 'U')
				{
					x[p] = 1;
				}
			}
			for(int i=1;i<=n;i++)
			  if(x[i])
			  {
			    ans++;
			  }
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c <= 2)
	{
		while(t--)
		{
			scanf("%d%d",&n,&m);
			int k = 1;
			int minn = 9999;
			for(int i=1;i<=n;i++)
			  k *= 3;
			for(int i=1;i<=m;i++)
			{
				cin>>vv[i]>>pp[i];
				if(vv[i] == '+' || vv[i] == '-')
				  cin>>qq[i];
			}
			for(int i=0;i<k;i++)
			{
				for(int j=1;j<=n;j++)
				  x[j] = 0;
				int cnt = 0,ans = 0,temp;
				temp = i;
				while(temp)
				{
					cnt++;
					x[cnt] = temp % 3;
					temp /= 3;
				}
				for(int j=1;j<=n;j++)
				  yy[j] = x[j];
				for(int j=1;j<=m;j++)
				{
					if(vv[j] == '+')
					{
						x[pp[j]] = x[qq[j]];
					}
					if(vv[j] == '-')
					{
						x[pp[j]] = no(x[qq[j]]);
					}
					if(vv[j] == 'U')
					{
						x[pp[j]] = 2;
					}
					if(vv[j] == 'F')
					{
						x[pp[j]] = 0;
					}
					if(vv[j] == 'T')
					{
						x[pp[j]] = 1;
					}
				}
				bool flag = 1;
				for(int j=1;j<=n;j++)
				{
					if(x[j] != yy[j])
					{
						flag = 0;
						break;
					}
					if(x[j] == 2)
					  ans++;
				}
				if(flag && ans < minn)
				  minn = ans;
			}
			printf("%d\n",minn);
		}
		return 0;
	}
	if(c == 6 || c == 5)
	{
		while(t--)
		{
			int ans = 0;
			scanf("%d%d",&n,&m);
			memset(x,0,sizeof(x));
			for(int i=1;i<=m;i++)
			{
				cin>>vv[i]>>pp[i];
				if(vv[i] == '+')
				  cin>>qq[i];
			}
			for(int i=1;i<=n;i++)
			  if(x[i])
			  {
			    ans++;
			  }
			printf("%d\n",ans);
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}