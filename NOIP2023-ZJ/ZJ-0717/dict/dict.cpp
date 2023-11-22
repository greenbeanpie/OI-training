#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=3010;

char a[N][N];
int liemin[N],liemax[N];    //一开始每一列的最小值 
int n,m;
int b[N][27];

void Prework123()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(b[i][j]>=1)
			{
				liemin[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=26;j>=1;j--)
		{
			if(b[i][j]>=1)
			{
				liemax[i]=j;
				break;
			}
		}
	}
}


int main()
{
	freopen("dict.in","r",stdin);       ///////////////////// 
	freopen("dict.out","w",stdout);		////////////////////	
	scanf("%d %d",&n,&m);
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[i][int(a[i][j]-'a'+1)]++;		//统计每个字符串出现的单词个数 
		}
	}
	Prework123();
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			
			if(liemin[i]<liemax[j] || i==j)
				continue;
			else if (liemin[i]==liemax[j])
			{
				b[i][liemin[i]]--,b[j][liemax[j]--];
				while(1==1)
				{	
					int x,y,cnt=0;
					for(int k=1;k<=26;k++)
					{
						if(b[i][k]>=1 && cnt==0)
						{
							x=k;
							cnt++;	
						}
						if(b[j][k]>=1)
							y=k;			
					}
					if(x<y)
					{
						break;
					}
					else if(x==y)	
					{
						b[i][x]--,b[j][y]--;
						continue;
					}
					else
					{
						flag=false;
						break;
					}
				}	
			}
			else
			{
				flag=false;	
				break;			
			}
		}
		if(flag==true)
		{
			printf("1");
			continue;
		}
		else
		{
			printf("0");
			continue;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=26;j++)
//			cout<<b[i][j]<<" ";
//		cout<<endl;
//	}
//		
//	for(int i=1;i<=n;i++)
//		cout<<liemin[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//		cout<<liemax[i]<<" ";
//	cout<<endl;	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<a[i][j];
//		cout<<endl;
//	}	
	return 0;
}
