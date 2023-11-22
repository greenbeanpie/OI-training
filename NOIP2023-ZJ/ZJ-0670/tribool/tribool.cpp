#include<bits/stdc++.h>
using namespace std;

int a[1000000],a1[10000];

char opp[10000];
int ppp[10000];
int readTFU(char op,int i)
{
	if(op=='T')
	a[i]=1;
	if(op=='F')
	a[i]=2;
	if(op=='U')
	a[i]=3;
}

int slowmi(int x,int n)
{
	if(n==0)
	return 1;
	else
	return x*slowmi(x,n-1);
}


int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	int c,t,n,m;
	cin>>c>>t>>n>>m;
	char op;
	int op1;
	
	if(c==1||c==2)
	{
		while(t)
		{
			memset(a,0,sizeof(a));
			//记忆读入
			int tail=1;
			int tail0=1;
			for(int i=1;i<=m;i++)
			{
				cin>>opp[tail];
				tail++;
				if(opp[tail-1]=='T'||opp[tail-1]=='U'||opp[tail-1]=='F')
				{
					cin>>ppp[tail0];
					tail0++;
				}
				if(opp[tail-1]=='+'||opp[tail-1]=='-')
				{
					cin>>ppp[tail0];
					tail0++;
					cin>>ppp[tail0];
					tail0++;
				}
			} 
			//超级暴力 
			int min=99;
			for(int i=1;i<=slowmi(3,n);i++)
			{//daxunhuan
				int i0=i,n0=n,count0=0;
				//枚举初始化a[] 
				while(n0)
				{
					a[n0]=i0%3-1;
					if(a[n0]==0)
					count0++;
					i0=i0/3;
					n0--;
				}
				//存档a1[]
				for(int k=1;k<=n;k++)
				{
					a1[k]=a[k];
				} 
				//暴力模拟 
				int tail1=1,tail2=1;
				for(int i=1;i<=m;i++)
				{
					op=opp[tail1]; 
					tail1++;
					if(op=='T'||op=='U'||op=='F')
					{
						int x=ppp[tail2];
						tail2++;
						if(op=='T')
						a[x]=1;
						if(op=='F')
						a[x]=-1;
						if(op=='U')
						a[x]=0;
					}
					
					if(op=='+'||op=='-')
					{
						int x=ppp[tail2],y=ppp[tail2+1];
						tail2+=2;
						if(op=='+')
						{
							a[x]=a[y];
						}
						if(op=='-')
						{
							a[x]=-a[y];
						}
					}
				} 
				//核对结果 
				int flag=1;
				for(int i=1;i<=n;i++)
				{
					if(a[i]!=a1[i])
					{
						flag=0;
						break;
					}
				} 
				if(flag)
				{
					if(count0<min)
					min=count0;
				}	
			}
			cout<<min<<endl;
			t--;
		}
		return 0;
	}
		
	if(c==3||c==4)
	{
		while(t)
		{
			memset(a,0,sizeof(a));
			for(int i=1;i<=m;i++)
			{
				cin>>op;
				cin>>op1;
				readTFU(op,op1);
			}
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==3)
				sum++;
			}
			cout<<sum<<endl;
			t--;
		}
		return 0;
	}
	
	return 0;	
}
