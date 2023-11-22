#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+7,p1=233,p2=131,p=1e7+7;
char ch[MAXN][MAXN],str1[MAXN][MAXN],str2[MAXN][MAXN];
int hash1[MAXN][MAXN][2],hash2[MAXN][MAXN][2];
bool cmp1(char x_,char _x)
{
	return x_<_x;
}
bool cmp2(char x_,char _x)
{
	return x_>_x;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>ch[i][j];
			str1[i][j]=ch[i][j];
			str2[i][j]=ch[i][j];
		}
		sort(str1[i]+1,str1[i]+m+1,cmp1);
		sort(str2[i]+1,str2[i]+m+1,cmp2);
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	if(n<=300&&m<=300)
	{
		for(int i=1;i<=n;++i)
		{
			bool op=0;
			for(int j=1;j<=n;++j)
			{
				if(j==i)
				continue;
				for(int k=1;k<=m;++k)
				{
					if(str1[i][k]<str2[j][k])
						break;
					if(str1[i][k]>str2[j][k])
					{
						op=1;
						break;
					}
				}
				if(op==1)
				{
					printf("0");
					break;
				}
			}
			if(op==0)
			printf("1");
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;j+=8)
			{
				hash1[i][j][0]=((hash1[i][j-1][0]*p1)%p+(str1[i][j]-'a'+1)+p)%p;
				hash1[i][j][1]=((hash1[i][j-1][1]*p2)%p+(str1[i][j]-'a'+1)+p)%p;
				hash2[i][j][0]=((hash2[i][j-1][0]*p1)%p+(str2[i][j]-'a'+1)+p)%p;
				hash2[i][j][1]=((hash2[i][j-1][1]*p2)%p+(str2[i][j]-'a'+1)+p)%p;
				hash1[i][j+1][0]=((hash1[i][j][0]*p1)%p+(str1[i][j+1]-'a'+1)+p)%p;
				hash1[i][j+1][1]=((hash1[i][j][1]*p2)%p+(str1[i][j+1]-'a'+1)+p)%p;
				hash2[i][j+1][0]=((hash2[i][j][0]*p1)%p+(str2[i][j+1]-'a'+1)+p)%p;
				hash2[i][j+1][1]=((hash2[i][j][1]*p2)%p+(str2[i][j+1]-'a'+1)+p)%p;
				hash1[i][j+2][0]=((hash1[i][j+1][0]*p1)%p+(str1[i][j+2]-'a'+1)+p)%p;
				hash1[i][j+2][1]=((hash1[i][j+1][1]*p2)%p+(str1[i][j+2]-'a'+1)+p)%p;
				hash2[i][j+2][0]=((hash2[i][j+1][0]*p1)%p+(str2[i][j+2]-'a'+1)+p)%p;
				hash2[i][j+2][1]=((hash2[i][j+1][1]*p2)%p+(str2[i][j+2]-'a'+1)+p)%p;
				hash1[i][j+3][0]=((hash1[i][j+2][0]*p1)%p+(str1[i][j+3]-'a'+1)+p)%p;
				hash1[i][j+3][1]=((hash1[i][j+2][1]*p2)%p+(str1[i][j+3]-'a'+1)+p)%p;
				hash2[i][j+3][0]=((hash2[i][j+2][0]*p1)%p+(str2[i][j+3]-'a'+1)+p)%p;
				hash2[i][j+3][1]=((hash2[i][j+2][1]*p2)%p+(str2[i][j+3]-'a'+1)+p)%p;
				hash1[i][j+4][0]=((hash1[i][j+3][0]*p1)%p+(str1[i][j+4]-'a'+1)+p)%p;
				hash1[i][j+4][1]=((hash1[i][j+3][1]*p2)%p+(str1[i][j+4]-'a'+1)+p)%p;
				hash2[i][j+4][0]=((hash2[i][j+3][0]*p1)%p+(str2[i][j+4]-'a'+1)+p)%p;
				hash2[i][j+4][1]=((hash2[i][j+3][1]*p2)%p+(str2[i][j+4]-'a'+1)+p)%p;
				hash1[i][j+5][0]=((hash1[i][j+4][0]*p1)%p+(str1[i][j+5]-'a'+1)+p)%p;
				hash1[i][j+5][1]=((hash1[i][j+4][1]*p2)%p+(str1[i][j+5]-'a'+1)+p)%p;
				hash2[i][j+5][0]=((hash2[i][j+4][0]*p1)%p+(str2[i][j+5]-'a'+1)+p)%p;
				hash2[i][j+5][1]=((hash2[i][j+4][1]*p2)%p+(str2[i][j+5]-'a'+1)+p)%p;
				hash1[i][j+6][0]=((hash1[i][j+5][0]*p1)%p+(str1[i][j+6]-'a'+1)+p)%p;
				hash1[i][j+6][1]=((hash1[i][j+5][1]*p2)%p+(str1[i][j+6]-'a'+1)+p)%p;
				hash2[i][j+6][0]=((hash2[i][j+5][0]*p1)%p+(str2[i][j+6]-'a'+1)+p)%p;
				hash2[i][j+6][1]=((hash2[i][j+5][1]*p2)%p+(str2[i][j+6]-'a'+1)+p)%p;
				hash1[i][j+7][0]=((hash1[i][j+6][0]*p1)%p+(str1[i][j+7]-'a'+1)+p)%p;
				hash1[i][j+7][1]=((hash1[i][j+6][1]*p2)%p+(str1[i][j+7]-'a'+1)+p)%p;
				hash2[i][j+7][0]=((hash2[i][j+6][0]*p1)%p+(str2[i][j+7]-'a'+1)+p)%p;
				hash2[i][j+7][1]=((hash2[i][j+6][1]*p2)%p+(str2[i][j+7]-'a'+1)+p)%p;
			}
		}
		for(int i=1;i<=n;++i)
		{
			bool op=0;
			for(int j=1;j<=n;++j)
			{
				if(i==j)
				continue;
				int l=1,r=m;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(hash1[i][mid][0]==hash2[j][mid][0]&&hash1[i][mid][1]==hash2[j][mid][1])
					l=mid+1;
					else
					r=mid-1;
				}
				if(r==m||str1[i][r+1]>str2[j][r+1])
				{
					printf("0");
					op=1;
					break;
				}
			}
			if(op==0)
			printf("1");
		}
	}
	return 0;
}
