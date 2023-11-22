#include<bits/stdc++.h>
using namespace std;

int rd()
{
	int f=1,k=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}


/*
3 1
4 4
U 1
F 1
U 3
U 4

*/
int c,t;

namespace tenpts
{
	bool ued[100010];
	void work()
	{
		while(t--)
		{
			int n=rd(),m=rd();
			while(m--)
			{
				char v=getchar();
				while(v==' '||v=='\n') v=getchar();
				int k=rd();
				if(v=='U')
				{
					ued[k]=1;
				}
				else
				{
					ued[k]=0;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=ued[i];
			}
			cout<<ans<<"\n";
		}
	}
}

struct rec
{
	char v;
	int i,j;
 } cz[1000];
 
 int val[1000];

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=rd(),t=rd();
	if(c==3||c==4)
	{
		tenpts::work();
		return 0;
	}
	else
	{
		while(t--)
		{
			memset(val,0,sizeof(val));
			int n=rd(),m=rd();
			for(int i=1;i<=m;i++)
			{
				cz[i].v=getchar();
				while(cz[i].v==' '||cz[i].v=='\n')
					cz[i].v=getchar();
				cz[i].i=rd();
				if(cz[i].v=='+'||cz[i].v=='-')
				{
					cz[i].j=rd();
				}
			}
			//DENG SHEN CHANG JIE
			int ans=0x3f3f3f3f;
			for(int a1=1;a1<=3;a1++)
			{
				for(int a2=1;a2<=3;a2++)
				{
					for(int a3=1;a3<=3;a3++)
					{
						for(int a4=1;a4<=3;a4++)
						{
							for(int a5=1;a5<=3;a5++)
							{
								for(int a6=1;a6<=3;a6++)
								{
									for(int a7=1;a7<=3;a7++)
									{
										for(int a8=1;a8<=3;a8++)
										{
											for(int a9=1;a9<=3;a9++)
											{
												for(int a10=1;a10<=3;a10++)
												{
													val[1]=a1;
													val[2]=a2;
													val[3]=a3;
													val[4]=a4;
													val[5]=a5;
													val[6]=a6;
													val[7]=a7;
													val[8]=a8;
													val[9]=a9;
													val[10]=a10;
													for(int i=1;i<=m;i++)
													{
														char v=cz[i].v;
														int k=cz[i].i;
														int l=cz[i].j;
														if(v=='+')
														{
															val[k]=val[l];
														}
														if(v=='-')
														{
															if(val[l]==1)
															{
																val[k]=2;
															}
															if(val[l]==2)
															{
																val[k]=1;
															}
															if(val[l]==3)
															{
																val[k]=3;
															}
															
														}
														if(v=='U')
														{
															val[k]=3;
														}
														if(v=='T')
														{
															val[k]=1;
														}
														if(v=='F')
														{
															val[k]=2;
														}
													}
													int cnt=0;
													if(
													val[1]==a1&&
													val[2]==a2&&
													val[3]==a3&&
													val[4]==a4&&
													val[5]==a5&&
													val[6]==a6&&
													val[7]==a7&&
													val[8]==a8&&
													val[9]==a9&&
													val[10]==a10)
													{
														for(int i=1;i<=n;i++)
														{
															if(val[i]==3) cnt++;
														}
														ans=min(ans,cnt);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}