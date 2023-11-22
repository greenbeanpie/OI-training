#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
#define maxm 3005

int n,m;
int cnt_ch[maxn][maxm];
int t_tar[maxm];
int t_com[maxm];
int test1_4_min_ch=100;

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	//每个单词都是一个小写字母构成的字符串
	char absorb;
	scanf("%d%d",&n,&m);
	absorb=getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char tmp=getchar();
			test1_4_min_ch=min(tmp-'a',test1_4_min_ch);
			cnt_ch[i][tmp-'a']++;
		}
		absorb=getchar();
	}
	if(n==1)
	{
		printf("1");
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(cnt_ch[i][test1_4_min_ch])
			{
				printf("1");
			}
			else 
			{
				printf("0");
			}
		}
	}
	else 
	{
//		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=0;j<=25;j++)
//			{
//				printf("%d ",cnt_ch[i][j]);
//			}
//			printf("\n");
//		}
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=1;j<=n;j++)
			{
				int flag_turn=0;
				if(j!=i)
				{
					int p=(int)'z'-(int)'a';
					for(int k=0;k<=p;k++)
					{
						t_com[k]=cnt_ch[j][k];
						t_tar[k]=cnt_ch[i][k];
//						printf("%d ",t_com[k]);
					}
//					printf("\n");
					int goal_ch=p;
					for(int k=p;k>=0;k--)
					{
						if(t_com[k]>0)
						{
							goal_ch=k;
							break;
						}
					}
					for(int k=0;k<=p;k++)
					{
						if(k<goal_ch&&t_tar[k]>=1)
						{
							flag_turn=1;
							break;
						}
					}
//					printf("%d:%d ",flag_turn,goal_ch);
					if(flag_turn==0)flag=0;
				}
			}
//			printf("\n");
			if(flag==1)printf("1");
			else printf("0");
		}
	}
	return 0;
}