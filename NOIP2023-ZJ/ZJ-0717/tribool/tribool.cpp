//¶à²âÒªÇå¿Õ
//freopen("tribool.in","r",stdin);
//freopen("tribool.out","w",stdout); 
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
int T,c;
int n,m;
struct node{
	int from,to,wei;
}edge[N];
int a[N];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout); 	
//	cout<<int (0 xor 1);
	cin>>c>>T;
	
	if (c==1 || c==2)
	{
		while(T--)
		{
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof(a));
			int ans=inf,cnt=0;
			for(int i=1;i<=m;i++)
				edge[i].from=edge[i].to=edge[i].wei=0;
			for(int i=1;i<=m;i++)
			{
				char op;
				cin>>op;
				int u,v;
				if(op=='+')
				{
					scanf("%d%d",&edge[i].from,&edge[i].to);
					edge[i].wei=1;
				}		
				else if(op=='-')
				{		
					scanf("%d%d",&edge[i].from,&edge[i].to);
					edge[i].wei=-1;						
				}
				else if(op=='T')
				{	
					scanf("%d",&edge[i].to);
					edge[i].wei=4;				
				}
				else if(op=='F')
				{
					scanf("%d",&edge[i].to);
					edge[i].wei=5;						
				}
				else if(op=='U')
				{
					scanf("%d",&edge[i].to);
					edge[i].wei=3;						
				}
			}
			for(int aa=1;aa<=3;aa++)    //1 -> T  2 -> F  3 -> U 
			{
				for(int bb=1;bb<=3;bb++)
				{
					for(int cc=1;cc<=3;cc++)
					{
						for(int dd=1;dd<=3;dd++)
						{
							for(int ee=1;ee<=3;ee++)
							{
								for(int ff=1;ff<=3;ff++)
								{
									for(int gg=1;gg<=3;gg++)
									{
										for(int hh=1;hh<=3;hh++)
										{
											for(int ii=1;ii<=3;ii++)
											{
												for(int jj=1;jj<=3;jj++)
												{
													a[1]=aa,a[2]=bb,a[3]=cc,a[4]=dd,a[5]=ee,a[6]=ff,a[7]=gg,a[8]=hh,a[9]=ii,a[10]=jj;
													for(int i=1;i<=m;i++)
													{
														if(edge[i].wei==-1)
														{
															if(a[edge[i].to]==1)
																a[edge[i].from]=2;
															else if(a[edge[i].to]==2)
																a[edge[i].from]=1;
															else
																a[edge[i].from]=3;
														}
														else if(edge[i].wei==1)
															a[edge[i].from]=a[edge[i].to];
														else if(edge[i].wei==3)
															a[edge[i].to]=3;
														else if (edge[i].wei==4)
															a[edge[i].to]=1;
														else
															a[edge[i].to]=2;
													}
													if(aa==a[1] && bb==a[2] && cc==a[3] && dd==a[4] && ee==a[5] && ff==a[6] && gg==a[7] && hh==a[8] && ii==a[9] && jj==a[10])
													{
														for(int i=1;i<=n;i++)
															if(a[i]==3)
																cnt++;
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
			if(ans==inf)
				cout<<0<<endl;
			else
				cout<<ans<<endl;
		}		
	}
	else{
		while(T--)
		{
			int cnt=0;
			memset(a,0,sizeof(a));
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				char op;
				int x;
				cin>>op>>x;
				if(op=='U')
					a[x]=3;
				if(op=='F')
					a[x]=1;
				if(op=='T')
					a[x]=2;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==3)
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}



/*
3 1
2 2
T 2
U 2
						int x=i,y=j,z=k;
						for(int ha=1;ha<=m;ha++)
						{
							if(edge[ha].wei==1)
							{
								
							}				
						
						}
						if(i==x && y==j && z==k)
*/
