#include<bits/stdc++.h>
using namespace std;
int n,m;
char cmi[3030][3030],cmx[3030][3030];
bool cmp(int x,int y)
{
	return x>y;
}
bool b[3030];
bool chec(int x,int y)
{
	for(int i=1;i<=m;i++)
	{
		int nw1=cmi[x][i]-'a',nw2=cmx[y][i]-'a';
		if(nw1<nw2) 
			return true;
		else if(nw1>nw2)
			return false; 
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int tmp[3030],tmp1[3030];
		for(int j=1;j<=m;j++)
		{
			cin>>cmi[i][j];
			tmp[j]=tmp1[j]=cmi[i][j]-'a';
		}
		sort(tmp+1,tmp+m+1);
		sort(tmp1+1,tmp1+1+m,cmp);
		for(int j=1;j<=m;j++) cmi[i][j]=tmp[j]+'a',cmx[i][j]=tmp1[j]+'a';
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&!chec(i,j)) flag=0;
		}
		b[i]=flag;
	}
	for(int i=1;i<=n;i++) cout<<b[i];
	cout<<endl;
	return 0;
}
