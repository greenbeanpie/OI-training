#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
inline int read()
{
	int num=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') num=(num<<1)+(num<<3)+(ch^48),ch=getchar();
	return f?-num:num;
}*/

//
int n,m;
//
char cc[3005];
struct node{
	int val,num;
}ree[4005][4005],aft[4005][4005],pre[4005][4005];
int noww[4005];
int vis[4005],ans[4005];
inline bool cmp(node x,node y){return x.val<y.val;}
inline void swapnd(node &x,node &y)
{
	node z=x;
	x=y,y=z;
}

signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){printf("1");return 0;}
	int nowbh=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",cc+1);
		for(int j=1;j<=m;j++)
			aft[i][j].val=pre[i][j].val=ree[i][j].val=cc[j]-'a'+1,
			aft[i][j].num=pre[i][j].num=ree[i][j].num=j;
			//printf("val%d num%d",ree[i][j].val,ree[i][j].num);
		//putchar(10);
	}	 
	for(int i=1;i<=n;i++)
		sort(ree[i]+1,ree[i]+1+m,cmp);
	//for(int i=1;i<=n;i++,putchar(10)) 
		//for(int j=1;j<=m;j++)
		//printf("val%d num%d",ree[i][j].val,ree[i][j].num);
	memset(noww,0x3f,sizeof noww);
	for(int i=1;i<=n;i++)
	{
		int j,targ;
		memset(vis,0,sizeof vis);
		for(j=1;j<=m;j++)
		{
			if(aft[i][j].val!=ree[i][m-j+1].val) break;
			else vis[ree[i][m-j+1].num]=1;
		}targ=j;
		int mxn=0,mxnum=0;
		for(j=m;j>0;j--) 
		{
			if(!vis[ree[i][j].num])
			{
				if(mxn<ree[i][j].val)
				{
					mxn=ree[i][j].val;
					mxnum=ree[i][j].num;
				}
				if(mxn==ree[i][j].val)
				{
					mxnum=max(mxnum,ree[i][j].num);
				}
			}
		}
		if(mxn==0)
		{
			//puts("00");
			//for(j=1;j<=m;j++) printf("val%d num%d ",aft[i][j].val,aft[i][j].num);
			for(j=1;j<=m;j++)
			{
				if(noww[j]>aft[i][j].val)
				{
					nowbh=i;
					for(int k=1;k<=m;k++)
						noww[k]=aft[i][k].val;
					break;
				}
				else if(noww[j]<aft[i][j].val) break;
			}
			continue;
			//for(j=1;j<=m;j++) printf("val%d ",noww[j]);puts("");
		}
		//for(j=1;j<=m;j++) printf("val%d ",noww[j]);
		//putchar(10);
		//continue;
		//printf("i%d mxn%d mxnum%d\n",i,mxn,mxnum);
		swapnd(aft[i][targ],aft[i][mxnum]);
		//for(j=1;j<=m;j++) printf("val%d num%d ",aft[i][j].val,aft[i][j].num);
		//putchar(10);
		for(j=1;j<=m;j++)
		{
			if(noww[j]>aft[i][j].val)
			{
				nowbh=i;
				for(int k=1;k<=m;k++)
					noww[k]=aft[i][k].val;
				break;
			}
			else if(noww[j]<aft[i][j].val) break;
		}
		//for(j=1;j<=m;j++) printf("val%d ",noww[j]);
		//putchar(10);
	}
	for(int i=1;i<=n;i++)
	{
		int j,targ;
		memset(vis,0,sizeof vis);
		for(j=1;j<=m;j++)
		{
			if(pre[i][j].val!=noww[j]) break;
			else vis[j]=1;
		}targ=j;
		//printf("targ%d\n",j);
		int mxn=0,mxnum=0;
		for(j=m;j>=0;j--)
		{
			if(!vis[ree[i][j].num]&&ree[i][j].val<noww[targ])
			{
				if(mxn<ree[i][j].val)
				{
					mxn=ree[i][j].val;
					mxnum=ree[i][j].num;
				}
				if(mxn==ree[i][j].val)
				{
					mxnum=max(mxnum,ree[i][j].num);
				}
			}
		}
		if(nowbh==i)
		{
			//puts("11");
			ans[i]=1;
			continue;
		}  
		if(mxn==0)
		{
			//printf("00\n");
			ans[i]=0;
			continue;
		}
		//printf("");
		ans[i]=1;
		//printf("i%d mxn%d mxnum%d\n",i,mxn,mxnum);
		//swapnd(pre[i][targ],pre[i][mxnum]);
		//for(j=1;j<=m;j++) printf("val%d num%d ",pre[i][j].val,pre[i][j].num);
		//putchar(10);
		//for(j=1;j<=m;j++) printf("val%d num%d ",pre[i][j].val,pre[i][j].num);
		//puts("");
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	puts("");
	return 0;
}
