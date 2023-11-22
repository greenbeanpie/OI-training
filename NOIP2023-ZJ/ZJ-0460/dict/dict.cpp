#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[3005][3005],mami1[3005],mami2[3005],pos1,pos2;
bool cmp(int x,int y)
{
	return x>y;
}
bool cmpstr(int a[],int b[])
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(mami1,0x3f,sizeof(mami1));
	memset(mami2,0x3f,sizeof(mami2));
	char x;
	for(int i=1;i<=n;i++)
	{
		int j=1;
		x=getchar();
		while(x<'a'||x>'z') x=getchar();
		while(x>='a'&&x<='z')
		{
			w[i][j++]=int(x-'a');
			x=getchar();
		}
		sort(w[i]+1,w[i]+1+m,cmp);
		if(cmpstr(w[i],mami1))
		{
			memcpy(mami2,mami1,sizeof(int)*(m+2));pos2=pos1;
			memcpy(mami1,w[i],sizeof(int)*(m+2));pos1=i;
		}
		else if(cmpstr(w[i],mami2))
		{
			memcpy(mami2,w[i],sizeof(int)*(m+2));pos2=i;
		}
		sort(w[i]+1,w[i]+1+m);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==pos1)
		{
			if(cmpstr(w[i],mami2)) cout<<1;
			else cout<<0;
		}
		else
		{
			if(cmpstr(w[i],mami1)) cout<<1;
			else cout<<0;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<w[i][j]<<' ';
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
		cout<<mami1[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=m;i++)
		cout<<mami2[i]<<" ";*/
	return 0;
}
