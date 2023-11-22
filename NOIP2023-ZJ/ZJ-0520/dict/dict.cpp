#include<bits/stdc++.h>
#define re register
using namespace std;

const int N=3005,M=3005;

int a[M],c_mi[N][M],c_ma[N][M];

inline void swp(int &x,int &y)
{
	re int t=x;x=y;y=t;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=m;j++)
		{
			re char ch;
			cin>>ch;
			c_mi[i][j]=c_ma[i][j]=a[j]=ch-'a';
		}
		
		re int mi=100,k=0;
		for(re int j=1;j<=m;j++)
			if(a[j]<=mi)mi=a[j],k=j;
		for(re int j=1;j<k;j++)
			if(a[j]!=mi){
				swp(c_mi[i][j],c_mi[i][k]);
				break;
			}
		
		re int ma=-100;k=0;
		for(re int j=1;j<=m;j++)
			if(a[j]>=ma)ma=a[j],k=j;
		for(re int j=1;j<k;j++)
			if(a[j]!=ma){
				swp(c_ma[i][j],c_ma[i][k]);
				break;
			}
	}
	for(re int i=1;i<=n;i++)
	{
		bool flag=1;
		for(re int j=1;j<=n;j++)
		{
			if(j==i)continue;
			for(re int L=1;L<=m;L++)
				if(c_ma[j][L]<c_mi[i][L]){flag=0;break;}
				else if(c_ma[j][L]>c_mi[i][L])break;
			if(!flag)break;
		}
		if(flag)putchar('1');
		else putchar('0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
