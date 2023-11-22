#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define maxm 500005


int X[maxn],Y[maxm];
int t_X[maxn],t_Y[maxm];
bool t_3_4_f[305][305];

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C,n,m,q;
	scanf("%d%d%d%d",&C,&n,&m,&q);
	if(C==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&X[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&Y[i]);
		}
		if(X[1]!=Y[1])
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		for(int i=1;i<=q;i++)
		{
			int K1,K2;
			scanf("%d%d",&K1,&K2);
			for(int j=1;j<=K1;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				X[tmp1]=tmp2;
			}
			for(int j=1;j<=K2;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				Y[tmp1]=tmp2;
			}
			if(X[1]!=Y[1])
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
	}
	else if(C==2)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&X[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&Y[i]);
		}
		if((X[1]-Y[1])*(X[2]-Y[2])>0)
		{
			printf("1");
		}
		else
		{
//			printf("1");
			printf("0");
		}
		for(int i=1;i<=q;i++)
		{
			int K1,K2;
			scanf("%d%d",&K1,&K2);
			for(int j=1;j<=K1;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				X[tmp1]=tmp2;
			}
			for(int j=1;j<=K2;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				Y[tmp1]=tmp2;
			}
			if((X[1]-Y[1])*(X[2]-Y[2])>0)
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
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&X[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&Y[i]);
		}
		if((X[1]-Y[1])*(X[n]-Y[m])>0)
		{
			bool com=(X[1]-Y[1]>0)?1:0;
			t_3_4_f[0][0]=1;
			t_3_4_f[1][0]=1;
			t_3_4_f[0][1]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if((X[i]>Y[j])==com)
					{
						t_3_4_f[i][j]=t_3_4_f[i-1][j]||t_3_4_f[i][j-1]||t_3_4_f[i-1][j-1];
					}
					else 
					{
						t_3_4_f[i][j]=0;
					}
				}
			}
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=1;j<=m;j++)
//				{
//					printf("%d ",t_3_4_f[i][j]);
////					else 
////					{
////						t_3_4_f[i][j]=0;
////					}
//				}
//				printf("\n");
//			}
			printf("%d",t_3_4_f[n][m]);
		}
		else
		{
			printf("0");
		}
		for(int k=1;k<=q;k++)
		{
			for(int i=1;i<=n;i++)
			{
				t_X[i]=X[i];
			}
			for(int i=1;i<=m;i++)
			{
				t_Y[i]=Y[i];
			}
			int K1,K2;
			scanf("%d%d",&K1,&K2);
			for(int j=1;j<=K1;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				t_X[tmp1]=tmp2;
			}
			for(int j=1;j<=K2;j++)
			{
				int tmp1,tmp2;
				scanf("%d%d",&tmp1,&tmp2);
				t_Y[tmp1]=tmp2;
			}
			if((t_X[1]-t_Y[1])*(t_X[n]-t_Y[m])>0)
			{
//				t_3_4_f[0][0]=1;
				bool com=(t_X[1]-t_Y[1]>0)?1:0;
				memset(t_3_4_f,0,sizeof(t_3_4_f));
				t_3_4_f[0][0]=1;
				t_3_4_f[1][0]=1;
				t_3_4_f[0][1]=1;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						if((t_X[i]>t_Y[j])==com)
						{
							t_3_4_f[i][j]=t_3_4_f[i-1][j]||t_3_4_f[i][j-1]||t_3_4_f[i-1][j-1];
						}
						else 
						{
							t_3_4_f[i][j]=0;
						}
					}
				}
				printf("%d",t_3_4_f[n][m]);
			}
			else
			{
				printf("0");
			}
		}
	}
	
	return 0;
}