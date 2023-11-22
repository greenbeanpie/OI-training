#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int N=1e5+5;
int n,m,x[N],tx[N],i,j,c1,c2,ans,num[N];
char op,s[N];
void work(int unk)
{
	for(int I=1,p1=0,p2=0;I<=m;++I)
	{
		op=s[++p1],i=num[++p2];
		if(op=='+')
		{
			j=num[++p2];
			x[i]=x[j];
		}
		else if(op=='-')
		{
			j=num[++p2];
			if(x[j]==1)
				x[i]=2;
			else if(x[j]==2)
				x[i]=1;
			else if(x[j]==3)
				x[i]=3;
		}
		else if(op=='T')
			x[i]=1;
		else if(op=='F')
			x[i]=2;
		else if(op=='U')
			x[i]=3;
	}
	bool flag=true;
//	int k=0;
	for(int I=1;I<=n;++I)
		if(x[I]!=tx[I])
		{
//			k=I;
			flag=false;
//			printf("@%d:%d!=%d\n",k,x[k],tx[k]);
			break;
		}
	if(flag==true)
	{
//		cout<<"unk:"<<unk<<"@";
//		for(int I=1;I<=n;++I)
//			cout<<x[I]<<':'<<tx[I]<<' ';
//		puts("");
		ans=min(ans,unk);
	}
		
	return;
}
void dfs(int t,int un)
{
	if(t==n+1)
	{
//		for(int I=1;I<=n;++I)
//			printf("%d ",tx[I]);
//		puts("@@@");
		work(un);
		return;
	}
	x[t]=tx[t]=1;dfs(t+1,un);
	x[t]=tx[t]=2;dfs(t+1,un);
	x[t]=tx[t]=3;dfs(t+1,un+1);
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C=rd(),T=rd();
	if(C<=2)
	{
		while(T--)
		{
			memset(x,0,sizeof(x));
			memset(tx,0,sizeof(tx));
			memset(num,0,sizeof(num));
			n=rd(),m=rd(),c1=0,c2=0;
			for(int I=1;I<=m;++I)
			{
				cin>>s[++c1];
				if(s[c1]=='+'||s[c1]=='-')
					cin>>num[++c2]>>num[++c2];
				else
					cin>>num[++c2];
			}
			ans=INT_MAX;
			dfs(1,0);
			printf("%d\n",ans);
		}
		return 0;
	}
//	while(T--)
//	{
//		memset(x,0,sizeof(x));
//		n=rd(),m=rd();
//		while(m--)
//		{
//			cin>>op;
//			if(op=='+')
//			{
//				i=rd(),j=rd();
//				x[i]=x[j];
//			}
//			else if(op=='-')
//			{
//				i=rd(),j=rd();
//				if(x[j]==1)
//					x[i]=2;
//				else if(x[j]==2)
//					x[i]=1;
//				else//if(x[j]==3)
//					x[i]=3;
//			}
//			else if(op=='T')
//				x[i]=1;
//			else if(op=='F')
//				x[i]=2;
//			else if(op=='U')
//				x[i]=3;
//		}
//		for(int i=1;i<=n;++i)
//		{
//			 
//		}
//	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 2
2 2
T 2
U 2
*/