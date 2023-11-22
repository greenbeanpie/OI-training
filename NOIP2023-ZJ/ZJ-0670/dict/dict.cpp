#include<bits/stdc++.h>
using namespace std;
int a[3000][30];

int n,m,x;

int compare(int i,int j)
{
	int mini,maxj;
	//i最小值 
	int k;
	k=1;
	while(k<=26)
	{
		if(a[i][k]!=0)
		{
			mini=k;
			break;
		}
		k++;
	}
	//j最大值 
	k=26;
	while(k>=1)
	{
		if(a[j][k]!=0)
		{
			maxj=k;
			break;
		}
		k--;
	}
	//比较
	if(mini<maxj)
	return 1; 
	if(mini>maxj)
	return 0;
	if(mini==maxj)
	{
		if(a[i][mini]<a[j][maxj])
		return 1;
		if(a[i][mini]>=a[j][maxj])
		return 0;
	}
	
}


int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	//读入 
	cin>>n;
	cin>>m;
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			x=int(getchar())-96;
			a[i][x]++;
		}
		getchar();
	}
	//吃回车
	
	//、、、、输出
	//特判保10分 
	if(n==1&&m==1)
	{
		cout<<1;
		return 0; 
	}
	
	//正常来 
	else
	{
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				continue;
				if(compare(i,j)==0)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			cout<<"1";
			if(flag==0)
			cout<<"0";
		}
		return 0;	
	}
	return 0;
}
